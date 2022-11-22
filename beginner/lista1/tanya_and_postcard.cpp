/*
 * AA Iniciante 2022.1 - Lista 01: Ad-Hoc 1
 * L. Tanya and Postcard
 * author: uncoded
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200100;

int main() {
    char s[MAXN], t[MAXN]; 
    scanf("%s %s", s, t);
    int cnt1[130], cnt2[130];
    for (int i = 0; s[i]; ++i)
        ++cnt1[s[i]];
    for (int i = 0; t[i]; ++i)
        ++cnt2[t[i]];
    int yay = 0, whoops = 0;
    for (int i = 0; s[i]; ++i) {
        if (cnt2[s[i]] > 0) {
            --cnt1[s[i]];
            --cnt2[s[i]];
            ++yay;
        }
    }
    for (int i = 0; s[i]; ++i) {
        char temp = islower(s[i]) ? toupper(s[i]) : tolower(s[i]);
        if (cnt1[s[i]] > 0 && cnt2[temp] > 0) {
            --cnt1[s[i]];
            --cnt2[temp];
            ++whoops;
        }
    }
    printf("%d %d\n", yay, whoops);
    return 0;
}

// Time Complexity O(|s| + |t|)
// space complexity O(1)

