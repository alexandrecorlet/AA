/*
 * AA Iniciante 2022.1 - Lista 01: Ad-Hoc 1
 * D. Elephant
 * author: uncoded
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    scanf("%d", &x);
    int ans = 0;
    for (int i = 5; i > 0; --i) {
        ans += x / i;
        x %= i;
    }
    printf("%d\n", ans);
    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)

