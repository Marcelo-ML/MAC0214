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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    // se fossem todos diferentes, seria (n+1/2)*(n/2)
    // se tiver caras iguais no meio do vetor, tem que tomar um pouco de cuidado
    int resp = n/2;
    for(int i = 0; i < n; i++){
        while(i < n-1 && a[i] == a[i+1]) i++;
        resp = max(resp, (i+1)*(n-1-i));
    }
    cout << resp << endl;
}

signed main(){_
    int t; cin >> t;
    // t = 1;
    while(t--) solve();
}

