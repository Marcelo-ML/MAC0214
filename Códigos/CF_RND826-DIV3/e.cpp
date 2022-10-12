// ESSE CÓDIGO FOI ACEITO NOS PRETESTES, MAS DEPOIS FOI HACKEADO


#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010

int n;
int pd_funfa[MAXN];
int a[MAXN];
int funfa(int ini){
    if(ini == n)
        return 1;
    if(ini > n)
        return 0;
    if(pd_funfa[ini] != -1)
        return pd_funfa[ini];
    // se a[ini] é o contador, o próximo só começa em a[ini+a[ini]+1]
    int f1 = funfa(ini+a[ini]+1);
    // se a[ini] não é o contador, iteramos até achar um possível contador
    int f2 = 0;
    for(int j = ini+1; j < n; j++)
        if(a[j] == j-ini)
            f2 |= funfa(j+1);
    return pd_funfa[ini] = (f1 | f2);
}
int main(){
    int t; cin >> t;
    memset(pd_funfa, -1, sizeof(pd_funfa));
    while(t--){
        for(int i = 0; i < n; i++)
            pd_funfa[i] = -1;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(funfa(0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
    

