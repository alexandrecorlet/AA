/*
 * AA Iniciante 2022.1 - Lista 01: Ad-Hoc 1
 * F. Lineland Mail
 * author: uncoded
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int x[n + 10];
    for (int i = 0; i < n; ++i)
        scanf("%d", &x[i]);

    for (int i = 0; i < n; ++i) {

        int min_dist, max_dist;
        if (i == 0) {
            min_dist = x[i + 1] - x[0];
            max_dist = x[n - 1] - x[0];
        } else if (i == n - 1) {
            min_dist = x[i] - x[i - 1]; 
            max_dist = x[i] - x[0];
        } else {
            min_dist = min(x[i] - x[i - 1], x[i + 1] - x[i]);
            max_dist = max(x[i] - x[0], x[n - 1] - x[i]);
        }

        printf("%d %d\n", min_dist, max_dist);

    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

