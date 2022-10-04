/*
 * AA intermediario: Lista 01 (Segment Tree)
 * Questao B: Interval Product
 * author: uncoded
 */

#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    
    int n;
    vector<int> tree;
    
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

    int solve(int a) {
        return (!a) ? 0 : (a > 0) ? 1 : -1;
    }

    void build(vector<int> &a, int i, int tl, int tr) {
        if (tl == tr) {
            tree[i] = solve(a[tl]);
        } else {
            int tm = (tl + tr) >> 1;
            build(a, left(i), tl, tm);
            build(a, right(i), tm+1, tr);
            tree[i] = tree[left(i)] * tree[right(i)];
        }
    }

    int RPQ(int l, int r) {
        return RPQ(l, r, 1, 1, n); 
    }

    int RPQ(int l, int r, int i, int tl, int tr) {
        if (tr < l || r < tl)
            return 1;
        if (l <= tl && tr <= r)
            return tree[i];
        int tm = (tl + tr) >> 1;
        return RPQ(l, r, left(i), tl, tm) * RPQ(l, r, right(i), tm+1, tr);
    }
    
    void update(int pos, int new_val) {
        update(pos, new_val, 1, 1, n);
    }

    void update(int pos, int new_val, int i, int tl, int tr) {
        if (tl == tr) {
            tree[i] = solve(new_val);
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                update(pos, new_val, left(i), tl, tm);
            else
                update(pos, new_val, right(i), tm+1, tr);
            tree[i] = tree[left(i)] * tree[right(i)];
        }
    }
};

int main() {
    int n, k;
    while (scanf("%d %d\n", &n, &k) != EOF) {
        vector<int> a(n+10);
        for (int i = 1; i <= n; ++i)
            scanf("%d\n", &a[i]);
        segment_tree st;
        st.init(a);
        while (k--) {
            char command;
            int x, y;
            scanf("%c %d %d\n", &command, &x, &y);
            if (command == 'C') {
                st.update(x, y);
            } else {
                int prod = st.RPQ(x, y);
                printf("%c", !prod ? '0' : prod > 0 ? '+' : '-');
            }
        }
        printf("\n");
    }
    return 0;
}
