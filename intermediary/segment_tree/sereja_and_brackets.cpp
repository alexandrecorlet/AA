/*
 * AA Intermediario: Lista 01 (Segment Tree)
 * Questao A: Sereja and Brackets
 * author: uncoded
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e6 + 500;

struct Node {
    int op =0 ;
    int cl= 0;
    int p=0;
};

int l, r, m;
char s[MAXN];
Node tree[MAXN<<2];

Node merge(Node left_kid, Node right_kid) {
    Node node;
    int res = min(left_kid.op, right_kid.cl);
    node.p = left_kid.p + right_kid.p + res;
    node.op = left_kid.op + right_kid.op - res;
    node.cl = left_kid.cl + right_kid.cl - res;
    return node;
}

void build(char s[], int i, int tl, int tr) {
    if (tl == tr) {
        Node node;
        if (s[tl-1] == '(')
            node.op++;
        else
            node.cl++;
        tree[i] = node;
        return;
    }
    int mid = (tl + tr) / 2;
    build(s, i*2, tl, mid);
    build(s, i*2+1, mid+1, tr);
    tree[i] = merge(tree[2*i], tree[2*i+1]);
}

Node query(int l, int r, int i, int tl, int tr) {
    if (tr < l || r < tl) {
        Node nil;
        return nil;
    } else if (l <= tl && tr <= r) {
        return tree[i]; 
    } 
    int mid = (tl + tr) / 2;
    return merge(
        query(l, r, i*2, tl, mid),
        query(l, r, i*2+1, mid+1, tr)
    );
}

int query(int l, int r, int n) {
    Node res = query(l, r, 1, 1, n);
    return res.p * 2;
}

int32_t main() {
    scanf("%s", s);
    int n = strlen(s);
    build(s, 1, 1, n);
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l, r, n));
    }
    return 0;
}
