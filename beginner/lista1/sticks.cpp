/*
 * AA Iniciante 2022.1 - Lista 01
 * C. Game With Sticks
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%s\n", min(n, m) & 1 ? "Akshat" : "Malvika");
}

// Time Complexity: O(1)
// Space Complexity: O(1)
