#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>

#define INF 112345678

void solve(){
    string s; cin >> s;
    int sum = 0;
    int minsum = 0;
    int caraqmin = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B') sum++;
        else sum--;

        if(sum < minsum){
            minsum = sum;
            caraqmin = i+1;
        }
    }

    if(sum < 0) cout << -1 << endl;

    else cout << caraqmin << endl;

}

signed main(){
    fastio();

    int t; cin >> t;
    while(t--) solve();

    return 0;
}

