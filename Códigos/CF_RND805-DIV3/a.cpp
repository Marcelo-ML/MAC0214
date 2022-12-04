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
    int x = 1;
    while(10*x <= n) x *= 10;
    cout << n - x << endl;
}

signed main(){_
    int t; cin >> t; while(t--)
	solve();
}

