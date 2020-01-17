#include <algorithm>
#include <vector>

struct item {
    item *l, *r;
    int f, t, v;
    item() { }
    item(int f, int t, int v) : l(nullptr), r(nullptr), f(f), t(t), v(v) { }
}

typedef item* pitem;

int get(const item& node) {
    return node ? node.v : 0;
}

pitem build(const std::vector<int>& a, int f, int t) {
    int m = (f + t) >> 1;
    auto rt = new item(f, t, 0);
    if (f + 1 != t) rt->l = build(a, f, m), rt->r = build(a, m, t);
    rt->v = get(rt->l) + get(rt->r);
    return rt;
}

int get(const pitem& tr, int f, int t) {
    if (f >= t) return 0;
    if (f == tr->f && t == tr->t) return tr->v;
    return get(tr->l, f, std::min(t, tr->l->t)) + get(tr->r, std::max(f, tr->r->f), t);
}

void update(pitem& tr, int p, int nv) {
    if (tr->f + 1 == tr->t) tr->v = nv;
    else if (p < tr->l->t) update(tr->l, p, nv);
    else update(tr->r, p, nv);
    tr->v = get(tr->l) + get(tr->r);
}
