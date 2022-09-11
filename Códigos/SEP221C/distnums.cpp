// se o número inicial é N = prod (pi^ai)
// em K passos dá pra chegar em prod(pi^bi)
// onde ai<=bi<=(2^K)*ai

// então, a soma no final é prod (pi^ai+pi^(ai+1)+...+pi^((2^K)*ai))
// = N * prod (1+pi+...+pi^((2^K - 1)*ai))
// = N * prod (pi^((2^K)*ai -ai+1)-1)/(pi-1)

#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

using namespace std;

const int MAXN = 11234;
const int MODP = 1e9 + 7;
const int MODQ = 5e8 + 3;

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
    return;
}

vpii fatora(int x){
    vpii result = {};
    for(int i = 0; i < primos.size(); i++){
        int p = primos[i];
        if(x%p)
            continue;
        pii novofator = mp(p,0);
        while(!(x%p)){
            x /= p;
            novofator.sc++;
        }
        result.pb(novofator);
    }
    if(x > 1)
        result.pb(mp(x,1));
    return result;
}

int fast_exp(int b, int e, int mod){
    int result;
    if(e == 0)
        return 1;
    int f = fast_exp(b,e/2,mod);
    result = (f*f) % mod;
    if(e%2){
        result *= b;
        result = result % mod;
    }
    return result;
}

signed main(){
    crivo();
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vpii fatorado = fatora(n);
        //for(int i = 0; i < fatorado.size(); i++)
            //cout << "(" << fatorado[i].fs << ", " << fatorado[i].sc << ") ";
        //cout << endl;
        int result = n;
        for(int i = 0; i < fatorado.size(); i++){
            int pi = fatorado[i].fs;
            int ai = fatorado[i].sc;
            // = N * prod (pi^((2^K)*ai -ai+1)-1)/(pi-1)
            //                 -----expo-----
            //                  (mód 2*MODQ)
            int expo = fast_exp(2,k,MODQ);
            if(expo%2) expo += MODQ;
            expo = (expo*ai - ai + 1) % (2*MODQ);
            // = N * prod (pi^((2^K)*ai -ai+1)-1)/(pi-1)
            //             ---------num---------   -den
            int num = fast_exp(pi, expo, MODP) - 1;
            // cout << "num : " << num << endl;
            int den = fast_exp(pi-1, MODP-2, MODP);
            // cout << "den : " << den << endl;
            result = result * ((num*den) % MODP);
            result = result % MODP;
        }
        cout << result << endl;
    }
}

