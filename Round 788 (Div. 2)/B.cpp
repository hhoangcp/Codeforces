/// cun_thich_lap_trinh
 
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int dp[100006];
bool tick[26];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
 
        for(int i = 0; i < 26; ++i) tick[i] = false;
 
        int k; cin >> k;
        for(int i = 0; i < k; ++i) {
            char c; cin >> c;
            tick[c - 'a'] = true;
        }
 
        dp[n-1] = -n;
        for(int i = n - 2; i >= 0; --i)
        if (tick[s[i + 1] - 'a']) dp[i] = 1;
        else dp[i] = dp[i+1] + 1;
 
        int ans = 0;
        for(int i = 0; i < n; ++i) ans = max(ans, dp[i]);
 
        cout << ans << '\n';
    }
 
    return 0;
}
