/// cun_thich_lap_trinh
 
#include <iostream>
#include <algorithm>
#define llong long long
 
using namespace std;
 
const int mod = 1e9+7;
 
int Nxt[200006];
int a[200006], b[200006], d[200006];
bool tick[200006];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; ++i) {
            tick[i] = false;
            Nxt[i] = d[i] = 0;
        }
 
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) {
            cin >> b[i];
            Nxt[a[i]] = b[i];
        }
        for(int i = 1; i <= n; ++i) {
            cin >> d[i];
            if (d[i] > 0) tick[d[i]] = true;
        }
 
        for(int i = 1; i <= n; ++i)
        if (d[i] == 0) {
            if (tick[a[i]] && !tick[b[i]]) {
                int x = a[i];
 
                do {
                    tick[x] = true;
                    x = Nxt[x];
                } while (x != a[i]);
            } else if (tick[b[i]] && !tick[a[i]]) {
                int x = a[i];
 
                do {
                    tick[x] = true;
                    x = Nxt[x];
                } while (x != a[i]);
            }
        }
 
        llong ans = 1;
        for(int i = 1; i <= n; ++i)
        if (d[i] == 0 && !tick[a[i]]) {
            if (a[i] == b[i]) continue;
 
            int x = a[i];
 
            do {
                tick[x] = true;
                x = Nxt[x];
            } while (x != a[i]);
 
            (ans *= 2) %= mod;
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}
