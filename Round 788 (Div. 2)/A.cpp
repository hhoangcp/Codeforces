/// cun_thich_lap_trinh
 
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int a[200006];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
 
        int j = n;
        for(int i = 1; i <= n; ++i)
        if (a[i] > 0) {
            while (j > i && a[j] >= 0) --j;
 
            if (j > i) {
                a[i] = -a[i];
                a[j] = -a[j];
            }
        }
 
        bool ok = true;
        for(int i = 2; i <= n && ok; ++i)
        if (a[i] < a[i-1]) ok = false;
 
        if (ok) cout << "YES\n"; else cout << "NO\n";
    }
 
    return 0;
}
