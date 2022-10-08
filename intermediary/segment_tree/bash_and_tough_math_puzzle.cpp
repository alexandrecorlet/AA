/*
 * AA Intermediario: Lista 01
 * Questao D: Bash and a tough Math Puzzle
 * author: uncoded
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

int a[MAXN], tree[MAXN << 2];

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
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

void build(int i, int tl, int tr) {
    if (tl == tr) {
        tree[i] = a[tl];
        return;
    }

    int m = mid(tl, tr);

    build(left(i), tl, m);
    build(right(i), m+1, tr);

    tree[i] = gcd(tree[left(i)], tree[right(i)]);
}

void update(int pos, int value, int i, int tl, int tr) {
    if (tl == tr) {
        tree[i] = value;
        return;
    }

    int m = mid(tl, tr);
    if (pos <= m)
        update(pos, value, left(i), tl, m);
    else
        update(pos, value, right(i), m+1, tr);
    
    tree[i] = gcd(tree[left(i)], tree[right(i)]);
}

int guess(int l, int r, int x, int i, int tl, int tr) {


    int m = mid(tl, tr);
    if ( (tr < l || r < tl) )
        return 0;
    if (l <= tl && tr <= r) {
        
        if (tl == tr && tree[i] % x != 0)
            return 1;
        else if (tree[left(i)] % x != 0 && tree[right(i)] % x != 0)
            return 2;
        else if (tree[left(i)] % x != 0) 
            return guess(l, r, x, left(i), tl, m);
        else if (tree[right(i)] % x != 0)
            return guess(l, r, x, right(i), m+1, tr);

        return 0;
    }

    return guess(l, r, x, left(i), tl, m)
        + guess(l, r, x, right(i), m + 1, tr);

}



int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    while (q--) {
        int t;
        scanf("%d", &t);

        if (t == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            int ans = guess(l, r, x, 1, 1, n);
            printf("%s\n", ans < 2 ? "YES" : "NO");
        } else {
            int pos, value;
            scanf("%d %d", &pos, &value);
            update(pos, value, 1, 1, n);
        }

    }

    return 0;
}
