/*
 * AA Iniciante 2022.1 - Lista 01: Ad-Hoc 1
 * G. Gravity Flip
 * author: uncoded
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int h[n + 1];
    for (int i = 0; i < n; ++i)
        scanf("%d", &h[i]);
    sort(h, h + n);
    for (int i = 0; i < n; ++i)
        printf("%d ", h[i]);
    printf("\n");
    return 0;
}
