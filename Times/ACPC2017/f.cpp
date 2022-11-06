#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
//#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>
#define INF 0x3f3f3f3f

void solve(){
    int n, k, resp = 0; cin >> n >> k;
    vector<int> a; //aparições
    map<int, queue<int>> m;
    for(int i = 0; i < n; i++){
        int x; cin >> x; a.pb(x);
        m[x].push(i);
    }

    for(auto x : a)
        m[x].push(INF);

    set<int> s;

    for(int i = 0; i < n; i++){
        m[a[i]].pop();
        int aux = m[a[i]].front();
        
        if(s.find(i) != s.end()){
            s.erase(s.find(i));
            s.insert(aux);
            continue;
        }

        if(s.size() < k){
            resp++;
            s.insert(aux);
            continue;
        }

        //cout << "i = " << i << " caraquevaisair = " << *s.rbegin() << endl;
        s.erase(*s.rbegin());
        s.insert(aux);
        resp++;
    }

    cout << resp << endl;
}

signed main(){
    fastio();

    int t; cin >> t; while(t--) solve();

    return 0;
}

