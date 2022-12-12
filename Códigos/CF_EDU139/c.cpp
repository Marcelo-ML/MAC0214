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
    int m; cin >> m;
    int ult_10 = 0;
    int ult_01 = 0;
    int p[4][m+10];
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= m; j++){
            char ch; cin >> ch;
            p[i][j] = (ch == 'B' ? 1 : 0);
        }
    }
    for(int i = 1; i <= m; i++){
        if(p[1][i] == p[2][i])
            continue;
        if(p[1][i] == 1){ // caso [1 0]
            if(ult_10 > ult_01)
                if( !((i-ult_10)&1) ){
                    cout << "NO" << endl;
                    return;
                }
            if(ult_01 > ult_10)
                if( (i-ult_01)&1 ){
                    cout << "NO" << endl;
                    return;
                }
            ult_10 = i;
        }
        if(p[2][i] == 1){ // caso [0 1]
            if(ult_01 > ult_10)
                if( !((i-ult_01)&1) ){
                    cout << "NO" << endl;
                    return;
                }
            if(ult_10 > ult_01)
                if( (i-ult_10)&1 ){
                    cout << "NO" << endl;
                    return;
                }
            ult_01 = i;
        }
    }
    cout << "YES" << endl;
}

signed main(){_
    int t; cin >> t; while(t--)
	solve();
}

