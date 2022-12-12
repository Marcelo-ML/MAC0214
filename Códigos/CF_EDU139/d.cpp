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

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const int MAXN = 1e7+10;

int mfp[MAXN];
//vector<int> primos;

void crivo(){
    memset(mfp, -1, sizeof(mfp));
    for(int i = 2; i < MAXN; i++){
        if(mfp[i] != -1)
            continue;
        mfp[i] = i;
//        primos.pb(i);
        for(int j = 2; i*j < MAXN; j++)
            mfp[i*j] = i;
    }
}

void solve(){
    int x, y; cin >> x >> y;
    if(y-x == 1){
        cout << "-1" << endl;
        return;
    }
    int falta = INF;
    int z = y-x;
    for(; z > 1; z = z/mfp[z]){
        int falta_ = mfp[z] - (x%mfp[z] ? x%mfp[z] : mfp[z]);
        falta = min(falta, falta_);
    }
    cout << falta << endl;
}

signed main(){_
    crivo();
    int t; cin >> t; while(t--)
    solve();
}


