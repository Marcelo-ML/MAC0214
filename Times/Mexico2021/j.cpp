#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>

const int MAXA = 510;
const int MAXT = 1000010;

int A, T;

int h[MAXA], d[MAXA];
vector<int> t[MAXA];

int memo[MAXT];
int pd(int tempo){
    if(memo[tempo] != -1)
        return memo[tempo];
    if(tempo >= T)
        return 0;
    
    int resp = 0;
    for(int i = 0; i < A; i++){
        auto it = lower_bound(t[i].begin(), t[i].end(), tempo);
        if(it == t[i].end())
            continue;
        resp = max(resp, h[i] + pd(*it+d[i]));
    }
    // cout << "memo[" << tempo << "] = " << resp << endl;
    return memo[tempo] = resp;
}

signed main(){
    fastio();

    cin >> A >> T;

    for(int i = 0; i < A; i++){
        cin >> h[i] >> d[i];
        int j; cin >> j;
        while(j--){
            int x; cin >> x; t[i].pb(x);
        }
        for(auto x : t[i]){
//            cout << x << ' ' << x + d[i] << endl;
        }
    }

    memset(memo, -1, sizeof(memo));

    cout << pd(0) << endl;

    return 0;
}

