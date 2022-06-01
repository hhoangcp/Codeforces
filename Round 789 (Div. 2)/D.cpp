/// hhoangcpascal
/// cun_thich_lap_trinh
 
#include <iostream>
#include <algorithm>
#define llong long long
 
using namespace std;
 
int n, m, dp[1000006], ans[1000006], ans1[1000006];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        string s; cin >> s;
 
        for(int i = 0; i <= n * m; ++i) dp[i] = ans[i] = ans1[i] = 0;
 
        for(int i = 0; i < n * m; ++i) dp[i+1] = dp[i] + s[i] - '0';
 
        for(int i = 0; i < m; ++i)
        for(int j = i; j < n * m; j += m)
        if (s[j] == '1') {
            ans1[j+1]++;
            break;
        }
 
        for(int i = 1; i <= n * m; ++i) {
            ans1[i] += ans1[i-1];
 
            if (i < m) {
                if (dp[i] > 0) ++ans[i];
                else ans[i] = 0;
            } else {
                ans[i] = ans[i-m];
                if (dp[i] - dp[i-m] > 0) ++ans[i];
            }
 
            cout << ans[i] + ans1[i] << ' ';
        }
 
        cout << '\n';
    }
 
    return 0;
}
