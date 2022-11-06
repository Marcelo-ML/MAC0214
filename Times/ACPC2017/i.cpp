#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>


signed main(){
    fastio();

    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n&1 || m&1)
            cout << "hasan" << endl;
        else
            cout << "abdullah" << endl;
    }

    return 0;
}

