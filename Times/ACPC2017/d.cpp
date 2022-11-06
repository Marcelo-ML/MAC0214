#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>

#define MAXN 100010
const ll MOD = 1000000007;

ll extGcd(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1; y = 0; return a;
    }
    else {
        ll g = extGcd(b, a%b, y, x);
        y -= a / b * x; return g;
    }
}

ll modInv(ll a, ll b){
    long long x, y;
    extGcd(a, MOD, x, y);
    return (x%MOD + MOD) % MOD;
}

ll modDiv(ll a, ll b){
    return ((a%MOD) * modInv(b, MOD))%MOD;
}

ll fat[MAXN];
void preprocessafat(){
    fat[0] = 1;
    for(ll i = 1; i < MAXN; i++){
        fat[i] = (i*fat[i-1])%MOD;
    }
}

ll pascal(ll n, ll k){
    return modDiv(fat[n], (fat[k]*fat[n-k])%MOD);
}

void solve(){
    ll a, b; cin >> a >> b;
    cout << (pascal(a-1, b)*2)%MOD << endl;
}

signed main(){
    fastio();
    preprocessafat();

    int t; cin >> t;
    while(t--) solve();    

    return 0;
}

