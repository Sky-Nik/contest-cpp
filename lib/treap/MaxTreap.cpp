template<typename key_t, typename priority_t>
struct TreapNode {
    key_t key;
    priority_t priority;
    TreapNode *lhs, *rhs;
    int cnt;

    TreapNode() { }

    TreapNode(key_t key, priority_t priority) :
        key(key), priority(priority), lhs(nullptr), rhs(nullptr), cnt(1) { }
}

template<typename key_t, typename priority_t>
using MaxTreap = TreapNode<key_t, priority_t>*;

template<typename key_t, typename priority_t>
auto Cnt(MaxTreap<key_t, priority_t> treap) {
    if (treap) {
        return treap->cnt;
    } else {
        return 0;
    }
}

template<typename key_t, typename priority_t>
auto UpdateCnt(MaxTreap<key_t, priority_t> treap) {
    if (treap) {
        treap->cnt = Cnt(treap->lhs) + 1 + Cnt(treap->rhs);
    }
}

template<typename key_t, typename priority_t>
auto Split(MaxTreap<key_t, priority_t> treap, key_t key,
           MaxTreap<key_t, priority_t>& out_lhs,
           MaxTreap<key_t, priority_t>& out_rhs) {
    if (!treap) {
        out_lhs = nullptr;
        out_rhs = nullptr;
    } else if (key < treap->key) {
        Split(treap->lhs, key, out_lhs, treap->lhs);
        out_rhs = treap;
    } else {
        Split(treap->rhs, key, treap->rhs, out_rhs);
        out_lhs = treap;
    }

    UpdateCnt(treap);
}

template<typename key_t, typename priority_t>
auto Insert(MaxTreap<key_t, priority_t>& treap,
            TreapNode<key_t, priority_t>* node) {
    if (!treap) {
        treap = node;
    } else if (node->priority > treap->priority) {
        Split(treap, node->key, node->lhs, node->rhs);
        treap = node;
    } else if (node->key < treap->key) {
        Insert(treap->lhs, node);
    } else {
        Insert(treap->rhs, node);
    }

    UpdateCnt(treap);
}

template<typename key_t, typename priority_t>
auto Merge(MaxTreap<key_t, priority_t>& out,
           MaxTreap<key_t, priority_t> lhs,
           MaxTreap<key_t, priority_t> rhs) {
    if (!lhs) {
        out = rhs;
    } else if (!rhs) {
        out = lhs;
    } else if (lhs->priority < rhs->priority) {
        Merge(lhs->rhs, lhs->rhs, rhs);
        out = lhs;
    } else {
        Merge(rhs->lhs, lhs, rhs->lhs);
        out = rhs;
    }

    UpdateCnt(out);
}

template<typename key_t, typename priority_t>
auto Erase(MaxTreap<key_t, priority_t>& treap, key_t key) {
    if (treap->key == key) {
        Merge(treap, treap->lhs, treap->rhs);
    } else if (key < treap->key) {
        Erase(treap->lhs, key);
    } else {
        Erase(treap->rhs, key);
    }

    UpdateCnt(treap);
}
