#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int v2(int x){
    if(x&1)
        return 0;
    return (1 + v2(x/2));
}

void solve(){
    int n; cin >> n;
    vector<int> a;
    int v2_atual = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x; a.pb(x);
        v2_atual += v2(x);
    }
    int v2_disponivel[40];
    for(int i = 0; i < 40; i++){
        v2_disponivel[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        v2_disponivel[v2(i)]++;
    }
    int ops = 0;
    for(int i = 39; i >= 0; i--){
        if(v2_atual >= n)
            break;
        if(v2_disponivel[i] > 0){
            v2_atual += i;
            v2_disponivel[i]--;
            i++;
            ops++;
        }
    }
    if(v2_atual < n)
        cout << -1 << endl;
    else
        cout << ops << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}

