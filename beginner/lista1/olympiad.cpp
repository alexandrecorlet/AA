/*
 * AA Iniciante 2022.1 - Lista 01: Ad Hoc 1
 * A. Olympiad
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 650;

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0, seen[MAXN];
    memset(seen, 0, sizeof seen);
    while (n--) {
        int x;
        scanf("%d", &x);
        if (x && !seen[x]) { 
            ++cnt;
            seen[x] = 1;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

// time complexity: O(N)
// space complexity: O(1)
