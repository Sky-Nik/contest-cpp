struct TreapNode {
    int key, priority;
    TreapNode *lhs, *rhs;
    int cnt;

    TreapNode() { }

    TreapNode(int key, int priority) :
        key(key), priority(priority), lhs(nullptr), rhs(nullptr), cnt(1) { }
}

typedef TreapNode* MinTreap;

auto Cnt(MinTreap treap) {
    if (treap) {
        return treap->cnt;
    } else {
        return 0;
    }
}

auto UpdateCnt(MinTreap treap) {
    if (treap) {
        treap->cnt = Cnt(treap->lhs) + 1 + Cnt(treap->rhs);
    }
}

auto Split(MinTreap treap, int key, MinTreap& out_lhs, MinTreap& out_rhs) {
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

auto Insert(MinTreap& treap, TreapNode* node) {
    if (!treap) {
        treap = node;
    } else if (node->priority < treap->priority) {
        Split(treap, node->key, node->lhs, node->rhs);
        treap = node;
    } else if (node->key < treap->key) {
        Insert(treap->lhs, node);
    } else {
        Insert(treap->rhs, node);
    }

    UpdateCnt(treap);
}

auto Merge(MinTreap& out, MinTreap lhs, MinTreap rhs) {
    if (!lhs) {
        out = rhs;
    } else if (!rhs) {
        out = lhs;
    } else if (lhs->priority > rhs->priority) {
        Merge(lhs->rhs, lhs->rhs, rhs);
        out = lhs;
    } else {
        Merge(rhs->lhs, lhs, rhs->lhs);
        out = rhs;
    }

    UpdateCnt(out);
}

auto Erase(MinTreap& treap, int key) {
    if (treap->key == key) {
        Merge(treap, treap->lhs, treap->rhs);
    } else if (key < treap->key) {
        Erase(treap->lhs, key);
    } else {
        Erase(treap->rhs, key);
    }

    UpdateCnt(treap);
}
