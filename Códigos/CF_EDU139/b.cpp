#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long
#define int long long
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
// #define endl '\n'

const int MOD = 1e9+7;
const int MAXN = 200010;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(n <= 3){
        cout << "NO" << endl;
        return;
    }
    set<pair<char,char>> m;
    for(int i = 0; i < n-1; i++){
        pair<char,char> prox = {s[i],s[i+1]};
        if(i-2 >= 0) m.insert({s[i-2],s[i-1]});
        if(m.find(prox) != m.end()){
            cout << "YES" << endl; return;
        }
    }
    cout << "NO" << endl;
}

signed main(){_
    int t; cin >> t; while(t--)
	solve();
}

