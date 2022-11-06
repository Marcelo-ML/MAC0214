#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
// #define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>
#define NAO {cout << -1 << endl; return;}

vector<int> V(int tamanho, int soma){
    // supondo soma <= 9*tamanho
    vector<int> resp;
    int num9 = soma/9;
    for(int i = 0; i < soma/9; i++)
        resp.pb(9);
    if(num9 == tamanho) return resp;
    resp.pb(soma-9*num9);
    for(int i = num9+1; i < tamanho; i++)
        resp.pb(0);

}

void solve(){
    int n, s; cin >> n >> s;
    if(s > 9*n) NAO
    if(n==1) {cout << s << endl; return;}
    
    if(!(n&1)){
        if(s&1) NAO
        vector<int> comeco = V(n/2, s/2);
        for(int i = 0; i < n/2; i++){
            cout << comeco[i];
        }
        for(int i = n/2-1; i >= 0; i--){
            cout << comeco[i];
        }
        cout << endl;
        return;
    }

    // agora n ímpar

    if(!(s&1)){
        // s par
        int cara_do_meio = max((ll) 0,s-9*(n-1));
        if(cara_do_meio&1) NAO
        vector<int> comeco = V(n/2, (s-cara_do_meio)/2);
        for(int i = 0; i < n/2; i++){
            cout << comeco[i];
        }
        cout << cara_do_meio;
        for(int i = n/2-1; i >= 0; i--){
            cout << comeco[i];
        }
        cout << endl;
        return;
    }

    // n ímpar, s ímpar

    int cara_do_meio = max((ll) 1,s-9*(n-1));
    if(!(cara_do_meio&1) || s==1) NAO

    vector<int> comeco = V(n/2, (s-cara_do_meio)/2);
    for(int i = 0; i < n/2; i++){
        cout << comeco[i];
    }
    cout << cara_do_meio;
    for(int i = n/2-1; i >= 0; i--){
        cout << comeco[i];
    }
    cout << endl;
    return;
}

signed main(){
    fastio();

    int t; cin >> t; while(t--) solve();

    return 0;
}

