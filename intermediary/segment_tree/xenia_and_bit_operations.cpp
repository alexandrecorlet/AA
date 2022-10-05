/*
 * AA Intermediario: Lista 01
 * Questao F: Xenia and Bit Operations
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

    int mid(int tl, int tr) {
        return (tl + tr) >> 1;
    }

    int merge(int left_idx, int right_idx, int operation) {
        long long result = tree[left_idx] | tree[right_idx];        // assume operation is bitwise OR
        if (operation)
            // XOR
            result = tree[left_idx] ^ tree[right_idx];
        return result;
    }

    int build(vector<int> &a, int i, int tl, int tr) {
        if (tl == tr) {
            tree[i] = a[tl]; 
            return 0;
        }
        int tm = mid(tl, tr), operation;
        operation = build(a, left(i), tl, tm);
        build(a, right(i), tm+1, tr);
        tree[i] = merge(left(i), right(i), operation);
        return !operation;
    }

    int update(int pos, int new_val) {
        return update(pos, new_val, 1, 1, n);
    }

    int update(int pos, int new_val, int i, int tl, int tr) {
        if (tl == tr) {
            tree[i] = new_val;
            return 0;
        }
        int tm = mid(tl, tr), operation;
        if (pos <= tm)
            operation = update(pos, new_val, left(i), tl, tm);
        else
            operation = update(pos, new_val, right(i), tm+1, tr);
        tree[i] = merge(left(i), right(i), operation);
        return !operation;
    }

    int root() {
        return tree[1];
    }

};

int32_t main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int size = pow(2, n);
    vector<int> a(size);
    for (int i = 1; i <= size; ++i)
        scanf("%d", &a[i]);
    segment_tree st;
    st.init(a);
    while (m--) {
        int pos, val;
        scanf("%d %d", &pos, &val);
        st.update(pos, val);
        printf("%d\n", st.root());
    }
    return 0;
}
