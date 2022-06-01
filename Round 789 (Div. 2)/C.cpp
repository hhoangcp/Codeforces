/// hhoangcpascal
/// cun_thich_lap_trinh
 
#include <iostream>
#include <algorithm>
#define llong long long
 
using namespace std;
 
int n, a[5006], bit[2][5006];
 
void Update(int block, int p, int val) {
    for(; p <= n; p += (p & (-p))) bit[block][p] += val;
}
 
int Query(int block, int p) {
    int ans = 0;
    for(; p > 0; p -= (p & (-p))) ans += bit[block][p];
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n - 2; ++i) Update(0, a[i], 1);
 
        llong ans = 0;
        for(int i = n - 2; i >= 2; --i) {
            Update(0, a[i], -1);
 
            for(int j = i + 2; j <= n; ++j) Update(1, a[j], 1);
 
            for(int j = i + 1; j < n; ++j) {
                ans += Query(0, a[j]) * Query(1, a[i]);
                Update(1, a[j+1], -1);
            }
        }
 
        Update(0, a[1], -1);
 
        cout << ans << '\n';
    }
 
    return 0;
}
