#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fs first
#define sc second

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        int l, r, u, D;
        l = (sx - 1 <= d ? 1 : 0);
        r = (n - sx <= d ? 1 : 0);
        D = (sy - 1 <= d ? 1 : 0);
        u = (m - sy <= d ? 1 : 0);
        // cout << l << u << r << D << endl;
        if((!l && !u) || (!r && !D))
            cout << n+m-2 << endl;
        else
            cout << -1 << endl;
     }

}

