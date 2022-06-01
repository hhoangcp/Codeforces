/// cun_thich_lap_trinh
 
#include <iostream>
#include <algorithm>
#define llong long long
 
using namespace std;
 
const int mod = 1e9+7;
 
int Nxt[200006];
int a[200006], b[200006], d[200006];
bool tick[200006];
 
llong Sum(int x) {
    --x;
    llong sum = 0;
 
    int r = x / 3 * 2;
    sum += 1LL * r * (r + 1);
    sum += 1LL * (r / 2) * (r / 2 + 1) * 2;
 
    if (x % 3 == 1) sum += 2 * r + 2;
    else if (x % 3 == 2) sum += 4 * r + 6;
 
    return sum;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
 
        int l = 2, r = 10000000, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
 
            if (Sum(mid) >= n) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}
