/*
 * AA 2022.1 - Lista 01: Ad-Hoc 1
 * H. Splitting Into Digits
 * author: uncoded
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    printf("%d\n", n);
    while (sum < n) {
        printf("1 ");
        ++sum;
    }
    printf("\n");
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

