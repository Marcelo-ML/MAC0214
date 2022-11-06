#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    if(a > b){
        if(b > c){
            cout << "Third\n";
        } else {
            cout << "Second\n";
        }
    } else {
        if(a > c){
            cout << "Third\n";
        } else {
            cout << "First\n";
        }
    }


}

signed main(){
    fastio();

    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}

