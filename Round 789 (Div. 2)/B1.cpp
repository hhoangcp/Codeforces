/// hhoangcpascal
/// cun_thich_lap_trinh
 
#include <iostream>
#include <algorithm>
#define llong long long
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
 
        string s; cin >> s;
 
        int ans = 0;
        for(int i = 0, j = 0; i < n - 1; ++i)
        if (s[i] != s[i+1]) {
            if ((i - j + 1) % 2 == 0) {
                j = i + 1;
                continue;
            }
 
            ++ans;
            j = i;
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}
