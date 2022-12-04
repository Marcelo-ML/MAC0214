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
    string s; cin >> s;
    int p; cin >> p;
    map<int,vector<int>> m; // {0..25} -> lugar em que a letra aparece
    for(int i = 0; i < 26; i++) m[i] = {};
    vector<pii> ps;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        ps.pb({s[i] - 'a' + 1,i});
    }
    sort(ps.begin(), ps.end());
//    for(auto pp : ps)
  //      cout << pp.fs << ' '<< pp.sc << endl;
    //cout << endl;
    vector<pii> sp;
    int q = 0, i = 0;
    while(i < ps.size() && q + ps[i].fs <= p){
        q += ps[i].fs;
        sp.pb({ps[i].sc, ps[i].fs});
        i++;
    }
    sort(sp.begin(), sp.end());
//    for(auto pp : sp)
  //      cout << pp.fs << ' '<< pp.sc << endl;

    for(auto x : sp)
        cout << s[x.fs];
    cout << endl;

}

signed main(){_
    int t; cin >> t; while(t--)
	solve();
}

