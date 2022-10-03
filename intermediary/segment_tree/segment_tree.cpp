/*
 * Segment Tree
 *
 * author: uncoded
 */

#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    
    int n;
    vector<long long> tree;

    void init(vector<int> &a) {
        n = a.size();
        tree.resize(n << 2);
        build(a, 1, 0, n-1);
    }

    int get_left(int i) {
        return i << 1;
    }

    int get_right(int i) {
        return (i << 1) | 1;
    }

    void build(vector<int> &a, int i, int tl, int tr) {
        if (tl == tr) {
            tree[i] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(a, get_left(i), tl, tm);
        build(a, get_right(i), tm+1, tr);
        tree[i] = tree[get_left(i)] + tree[get_right(i)];
    }

    long long query(int l, int r) {
        return query(l, r, 1, 0, n-1);
    }

    long long query(int l, int r, int i, int tl, int tr) {
        if (tr < l || r < tl)
            return 0;
        else if (l <= tl && tr <= r)
            return tree[i]; 
        int tm = (tl + tr) >> 1;
        return query(l, r, get_left(i), tl, tm) 
            + query(l, r, get_right(i), tm+1, tr);
    }
    
    void update(int pos, int new_val) {
        update(pos, new_val, 1, 0, n-1);
    }

    void update(int pos, int new_val, int i, int tl, int tr) {
        if (tl == tr) {
            tree[i] = new_val;
            return;
        }
        int tm = (tl + tr) >> 1;
        if (pos <= tm)
            update(pos, new_val, get_left(i), tl, tm);
        else
            update(pos, new_val, get_right(i), tm+1, tr);

        tree[i] = tree[get_left(i)] + tree[get_right(i)];
    }

};

int main() {
    int n, nb_queries;
    scanf("%d %d", &n, &nb_queries);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    segment_tree st;
    st.init(a);
    while(nb_queries--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int pos, val;
            scanf("%d %d", &pos, &val);
            st.update(pos, val);
        } else if (op == 2) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", st.query(l, r-1));
        }
    }
    return 0;
}
