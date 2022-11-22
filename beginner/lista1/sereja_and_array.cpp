/*
 * AA 2022.1 - Lista 01: Ad-hoc 1
 * I. Sereja and Array
 * author: uncoded
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n + 10];
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int add = 0;
    while (m--) {
        int t, i;
        scanf("%d %d", &t, &i);
        if (t == 1) {
            int x;
            scanf("%d", &x);
            a[i] = x - add;
        } else if (t == 2) {
            add += i; 
        } else {
            printf("%d\n", a[i] + add);  
        }
    }
    return 0;
}

// Time Complexity: O(N+M) | Space Complexity: O(1), where
// N is the size of the input and M is the number of queries
