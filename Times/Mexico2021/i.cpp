#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>

int f(int n){
    int resp = 1;
    if(n == 0)
    return 0;
    while(n > 0){
        resp *= (n%10);
        n /= 10;
    }
    return resp;
}

void solve(){
    int n; cin >> n;
    int resp = 0;
    while(n != f(n)){
        resp++;
        n = f(n);
    }
    cout << resp << endl;
}

signed main(){
    fastio();

    int n; cin >> n; 
    while(n--) solve();
    return 0;
}

