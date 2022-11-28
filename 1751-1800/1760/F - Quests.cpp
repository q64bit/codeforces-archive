#include <bits/stdc++.h>
using namespace std;
using ll =  long long;

int solve() {
    int n; cin >> n;
    ll c; cin >> c;
    int d; cin >> d;
    
    vector<int> arr(n);
    for(int& i: arr) cin >> i;
    sort(arr.begin(), arr.end(), greater<int>());
    
    ll tmp = accumulate(arr.begin(), arr.begin() + min(n, d), 0ll);
    if(tmp >= c) return -2;
    
    int lo = 0, hi = d-1, k = -1;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        int div = d / (mid + 1);
        int rem = d % (mid + 1);
        
        ll s1 = accumulate(arr.begin(), arr.begin() + min(n, mid + 1), 0ll);
        s1 = s1 * div;
        
        ll s2 = accumulate(arr.begin(), arr.begin() + min(n, rem), 0ll);
        ll s = s1 + s2;
        
        if(s >= c) {
            k = mid;
            lo = mid + 1;
        }
        
        else {
            hi = mid - 1;
        }
    }
    
    return k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst; cin >> tst;
    while(tst--) {
        int res = solve();
        
        if(res == -1) cout << "Impossible";
        else if(res == -2) cout << "Infinity";
        else cout << res;
        cout << '\n';
    }
        
    return 0;
}
