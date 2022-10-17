#include <bits/stdc++.h>
using namespace std;
#define pb push_back

void solve(){
    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x; a.pb(x);
    }
    string s; cin >> s;
    map<int, char> m;
    for(int i = 0; i < n; i++){
        if(m.find(a[i]) == m.end()){
            m[a[i]] = s[i];
        }
        else{
            if(m[a[i]] != s[i]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main(){
    int t; cin >> t;
    while(t--)
        solve();
}
