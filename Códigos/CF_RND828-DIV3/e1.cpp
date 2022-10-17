#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
#define pb push_back
#define fs first
#define sc second
#define int long long

/*
bool eh_primo[MAXN];
vector<int> primos;

void crivo(){
    memset(eh_primo, 1, sizeof(eh_primo));
    for(int i = 2; i < MAXN; i++){
        if(!eh_primo[i])
            continue;
        primos.pb(i);
        for(int j = 2; j*i < MAXN; j++){
            eh_primo[j*i] = 0;
        }
    }
}

vector<pair<int,int>> fatora(int n){
    vector<pair<int,int>> resp;
    for(auto p : primos){
        if(n == 1)
            break;
        if(n%p)
            continue;
        pair<int,int> pp = {p,0};
        while(!(n%p)){
            n /= p;
            pp.sc++;
        }
        resp.pb(pp);
    }
    if(n > 1)
        resp.pb({n,1});
    return resp;
}
*/

vector<int> divisores(int n){
    vector<int> resp;
    for(int i = 1; i*i <= n; i++){
        if(n%i)
            continue;
        resp.pb(i);
        if(i != n/i)
            resp.pb(n/i);
    }
    return resp;
}

pair<int,int> fatora_no_intervalo(int M, int a, int b, int c, int d){
    pair<int,int> resp = {-1,-1};
    for(auto div : divisores(M)){
        if(div <= a || div > c)
            continue;
        if(M/div <= b || M/div > d)
            continue;
        resp = {div, M/div};
    }
    return resp;
}

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c >= 2*a && d >= 2*b){
        cout << 2*a << " " << 2*b << endl;
        return;
    }

    for(int i = 2; i*a*b <= c*d; i++){
        pair<int,int> pp = fatora_no_intervalo(i*a*b,a,b,c,d);
        if(pp.fs != -1){
            cout << pp.fs << " " << pp.sc << endl;
            return;
        }
    }
    cout << "-1 -1" << endl;
}

signed main(){
    int t; cin >> t;
    while(t--) solve();
}

