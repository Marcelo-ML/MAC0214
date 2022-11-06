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
    int n; cin >> n;
    map<int, int> channels;
    vector<int> canais;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int number; cin >> number;      
        channels[number]++;
        canais.pb(number);
    }

    int maior = 0;
    int canalmaior = 1123456;

    for(auto v : canais){
        if(channels[v] > maior || (channels[v] == maior && canalmaior > v)){
            maior = channels[v];
            canalmaior = v;
        }
    }

    cout << canalmaior << endl;

}

signed main(){
    fastio();
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

