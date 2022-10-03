/*
 * AA intermediario: Lista 01 (Segment Tree)
 *
 * author: uncoded
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> lli;

lli mymax(lli p, lli q) {
    return p.first > q.first ? p : q;
}

struct segment_tree {
    
    int n;
    vector<lli> tree;

    void init(vector<int> &a) {
        n = a.size();
        tree.resize(n << 2);
        build(a, 1, 1, n);
    }

    int left(int i) {
        return i << 1;
    }

    int right(int i) {
        return (i << 1) | 1;
    }

    void build(vector<int> &a, int i, int tl, int tr) {
        if (tl == tr) {
            tree[i] = {a[tl], tl};
        } else {
            int tm = (tl + tr) >> 1;
            build(a, left(i), tl, tm);
            build(a, right(i), tm+1, tr);
            tree[i] = mymax(tree[left(i)], tree[right(i)]);
        }
    }

    lli RMQ(int l, int r) {
        return RMQ(l, r, 1, 1, n);
    }

    lli RMQ(int l, int r, int i, int tl, int tr) {
        if (tr < l || r < tl)
            return {-1, -1};
        if (l <= tl && tr <= r)
            return tree[i];
        int tm = (tl + tr) >> 1;
        return mymax(RMQ(l, r, left(i), tl, tm),
            RMQ(l, r, right(i), tm+1, tr));
    }

    void update(int pos, int new_val) {
        update(pos, new_val, 1, 1, n);
    }

    void update(int pos, int new_val, int i, int tl, int tr) {
        if (tl == tr) {
            tree[i] = {new_val, tl};
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                update(pos, new_val, left(i), tl, tm);
            else
                update(pos, new_val, right(i), tm+1, tr);
            tree[i] = mymax(tree[left(i)], tree[right(i)]);
        }
    }

};

int main() {
    int n;
    scanf("%d\n", &n);
    
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i)
        scanf("%d\n", &a[i]);

    segment_tree seg_tree;
    seg_tree.init(a);

    int m;
    scanf("%d\n", &m);
    while (m--) {
        char query;
        scanf("%c\n", &query);
        if (query == 'Q') {
            int l, r;
            scanf("%d %d\n", &l, &r);
            lli p = seg_tree.RMQ(l, r);
            lli q = seg_tree.RMQ(p.second+1, r);
            lli s = seg_tree.RMQ(l, p.second-1);
            printf("%lld\n", p.first + mymax(q, s).first);
        } else if (query == 'U') {
            int pos, x;
            scanf("%d %d\n", &pos, &x);
            seg_tree.update(pos, x);
        }
    }

    return 0;
}
