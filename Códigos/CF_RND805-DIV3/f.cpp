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

bool pareavel(int a, int b){ // a é prefixo de b na base 2
    if(a == b) return true;
    if(a > b) return false;
    return pareavel(a, b>>1);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        while(!(a[i]&1)) a[i] >>= 1;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        cin >> b[i];
        while(!(b[i]&1)) b[i] >>= 1;
    }
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) pq.push(b[i]);
    int i = 0;
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        if(x == a[i]){
            i++;
            continue;
        }
        if(x > a[i]){
            pq.push(x>>1);
            continue;
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

signed main(){_
    int t; cin >> t; while(t--)
	solve();
}

