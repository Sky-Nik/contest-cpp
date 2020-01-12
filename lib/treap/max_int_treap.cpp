struct TreapNode {
    int k, p;
    TreapNode *l, *r;
    int cnt;
    TreapNode() { }
    TreapNode(int k, int p) : k(k), p(p), l(nullptr), r(nullptr), cnt(1) { }
}

typedef TreapNode* MaxTreap;

auto cnt(MaxTreap t) {
    return t ? t->cnt : 0;
}

auto update_cnt(MaxTreap t) {
    if (t) t->cnt = cnt(t->l) + 1 + cnt(t->r);
}

auto split(MaxTreap t, int k, MaxTreap& l, MaxTreap& r) {
    if (!t) l = r = nullptr;
    else if (k < t->k) split(t->l, k, l, t->l), r = t;
    else split(t->r, k, t->r, r), l = t;
    update_cnt(t);
}

auto insert(MaxTreap& t, TreapNode* it) {
    if (!t) t = it;
    else if (it->p > t->p) split(t, it->k, it->l, it->r), t = it;
    else Insert(it->k < t->k ? t->l : t->r, it);
    update_cnt(t);
}

auto merge(MaxTreap& t, MaxTreap l, MaxTreap r) {
    if (!l || !r) t = l ? l : r;
    else if (l->p < r->p) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    update_cnt(t);
}

auto erase(MaxTreap& t, int k) {
    if (t->k == k) merge(t, t->l, t->r);
    else erase(k < t->k ? t->l : r->r, k);
    update_cnt(t);
}
