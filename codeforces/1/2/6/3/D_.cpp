#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> p,r;

    dsu(int sz) {
        p.resize(sz);
        r.resize(sz);
        for (int i=0;i<sz;++i) make_set(i);
    } 

    void make_set(int v) {
        p[v]=v; r[v]=0;
    }

    int find_set(int v) {
        return v==p[v]?v:p[v]=find_set(p[v]);
    }

    void union_sets(int a, int b) {
        a=find_set(a);
        b=find_set(b);
        if (a!=b) {
            if (r[a]<r[b]) swap(a,b);
            p[b]=a;
            if (r[a]==r[b]) ++r[a];
        }
    }

    int count_sets() {
        unordered_set<int> s;
        for (int i=0;i<p.size();++i) {
            s.insert(find_set(i));
        }
        return s.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string> s(n);
    for (auto& si:s) cin>>si;
    unordered_map<char,vector<int>> e;
    for (char c='a';c<='z';++c) e[c]={};
    for (int i=0;i<n;++i) for (auto c:s[i]) e[c].push_back(i);
    dsu d(n);
    for (auto& [c,v]:e) {
        int i0 = v[0];
        for (int i=0;i+1<v.size();++i) d.union_sets(v[i], v[i+1]);
    }
    cout<<d.count_sets();
    return 0;
}
