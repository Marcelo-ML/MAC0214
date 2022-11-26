#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long
#define int long long
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
#define endl '\n'

const int MOD = 1e9+7;
const int MAXN = 200010;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int GCD = a[0];
    int maxi = a[0];
    for(auto x : a){
        GCD = __gcd(GCD, x);
        maxi = max(maxi, x);
    }
    cout << maxi / GCD << endl;
}

signed main(){_
    int t; cin >> t;
    // t = 1;
    while(t--) solve();
}

