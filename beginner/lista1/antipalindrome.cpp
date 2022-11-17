/*
 * AA Iniciante 2022.1: Lista 01: Ad-Hoc
 * B. Antipalindrome
 */
 
#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 55;
 
char s[MAXN];
 
int is_palindrome(int l, int r) {
    if (l > r) swap(l, r);
    int flag = 1;
    for (int i = l; i < r; ++i)
        if (s[i] != s[r - i]) flag = 0;
    return flag;
}
 
int main() {
    scanf("%s", s);
    int ans = 0, n = strlen(s);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j<n; ++j)
            if (!is_palindrome(i, j))
                ans = max(ans, abs(i - j) + 1);
    printf("%d\n", ans);
    return 0;
} 

