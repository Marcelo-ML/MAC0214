#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pii pair<int,int>
#define int long long
 
void solve(){
    int c, r, s;
    cin >> c >> r >> s;
    int total = (c+r+ s-1)/s;
    int max_ruim = min(total, r);
    int min_ruim = (r + s-1)/s;
    cout << total - min_ruim << ' ' << total - max_ruim << endl;
}
 
signed main(){
    fastio();
 
    int t; cin >> t;
    while(t--) solve();
}

