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
    int n, k; cin >> n >> k;
    map<int,int> prim_apar;
    map<int,int> ult_apar;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(prim_apar.find(x) == prim_apar.end())
            prim_apar[x] = i;
        ult_apar[x] = i;
    }
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        if(prim_apar.find(a) == prim_apar.end() || prim_apar.find(b) == prim_apar.end()){
            cout << "NO" << endl;
            continue;
        }
        if( ult_apar[b] < prim_apar[a] ){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}

signed main(){_
    int t; cin >> t; while(t--)
	solve();
}

