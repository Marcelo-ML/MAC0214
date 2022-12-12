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

int num_digitos(int n){
    if(n < 10)
        return 1;
    return 1 + num_digitos(n/10);
}

int prim_digito(int n){
    while(n >= 10)
        n/=10;
    return n;
}

void solve(){
    int n; cin >> n;
    cout << 9*(num_digitos(n)-1) + prim_digito(n) << endl;
}

signed main(){_
    int t; cin >> t; while(t--)
	solve();
}

