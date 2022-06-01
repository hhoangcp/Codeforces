/// hhoangcpascal
/// cun_thich_lap_trinh
 
#include <iostream>
#include <algorithm>
#define llong long long
 
using namespace std;
 
int a[200006];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
 
        int numZero = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            numZero += a[i] == 0;
        }
 
        if (numZero == 0) {
            bool eq = false;
 
            sort(a + 1, a + n + 1);
            for(int i = 1; i < n; ++i)
            if (a[i] == a[i+1]) eq = true;
 
            if (eq) cout << n << '\n';
            else cout << n + 1 << '\n';
        } else cout << n - numZero << '\n';
    }
 
    return 0;
}
