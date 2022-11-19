#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long
#define int long long
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
#define endl '\n'

const int MOD = 1e9+7;
const int MAXK = 1e6+10;

int pot2[MAXK];
vector<int> div_primos[MAXK];
bool eh_primo[MAXK];
void crivo(){
    pot2[0] = 1;
    for(int i = 1; i < MAXK; i++){
        pot2[i] = 2*pot2[i-1];
        pot2[i] %= MOD;
    }
    memset(eh_primo, 1, sizeof(eh_primo));
    for(int i = 2; i < MAXK; i++){
        if(!eh_primo[i])
            continue;
        for(int j = 1; i*j < MAXK; j++){
            eh_primo[i*j] = 0;
            div_primos[i*j].pb(i);
        }
    }
}

int fastexpo(int b, int e){
    if(!e) return 1;
    int resp = fastexpo(b, e/2);
    resp *= resp;
    resp %= MOD;
    if(e&1) resp *= b;
    return resp % MOD;
}

void solve(){
    int k; cin >> k;
    if(k == 1){ cout << 0 << endl; return; }

    vector<int> v = div_primos[k];
    int qtd = v.size();

    int resp = pot2[k];
    for(int i = 0; i < (1 << qtd); i++){
        int expo = k;
        int sinal = 1;
        for(int j = 0; j < qtd; j++){
            if( (1<<j) & i ){
                expo /= v[j];
                sinal *= -1;
            }
        }
        resp -= sinal*pot2[expo];
        resp %= MOD;
    }
    cout << (resp + MOD) % MOD << endl;
}

signed main(){_
    crivo(); int t; cin >> t; while(t--) solve();
}
