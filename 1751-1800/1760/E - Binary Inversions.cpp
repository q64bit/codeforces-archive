#include <bits/stdc++.h>
using namespace std;
using ll =  long long;

ll cntinv(vector<int>& v, int n) {
    ll res = 0;
    
    vector<int> arr(n);
    arr[0] = 0;
    
    for(int i=1; i<n; i++) {
        arr[i] = (v[i-1] == 1) ? arr[i-1] + 1 : arr[i-1];
        if(v[i] == 0)
            res += arr[i];
    }
    
    return res;
}

void solve() {
    int n; cin >> n;
    
    vector<int> v(n);
    for(int& i: v) cin >> i;
    
    ll inv = cntinv(v, n);
    vector<int> bef(n), aft(n);
    
    bef[0] = 0;
    for(int i=1; i<n; i++)
        bef[i] = (v[i-1] == 1) ? bef[i-1] + 1 : bef[i-1];
    aft[n-1] = 0;
    for(int i=n-2; i>=0; i--)
        aft[i] = (v[i+1] == 0) ? aft[i+1] + 1 : aft[i+1];
    
    ll res = inv;
    for(int i=0; i<n; i++) {
        if(v[i] == 0) {
            res = max(res, inv - bef[i] + aft[i]);
        }
        else {
            res = max(res, inv + bef[i] - aft[i]);
        }
    }
    
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst; cin >> tst;
    while(tst--)
        solve();
        
    return 0;
}
