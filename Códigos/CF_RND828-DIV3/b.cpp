#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long

void solve(){
    int n, q; cin >> n >> q;
    int num_pares = 0, num_impares = 0;
    int soma = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x%2 == 1)
            num_impares++;
        else
            num_pares++;
        soma += x;
    }
    for(int i = 0; i < q; i++){
        int l, x;
        cin >> l >> x;
        if(l == 1){
            soma += num_impares*x;
            if(x%2 == 1){
                num_impares = 0;
                num_pares = n;
            }
        }
        else{ // l == 0
            soma += num_pares*x;
            if(x%2 == 1){
                num_pares = 0;
                num_impares = n;
            }
        }

        cout << soma << endl;
    }
}

signed main(){
    int t; cin >> t;
    while(t--) solve();
}
