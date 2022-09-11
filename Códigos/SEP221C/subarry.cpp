#include <bits/stdc++.h>
#define int long long
#define INF 0xffffffff
using namespace std;

/*  mínimo possível
    se tem negativo e positivo, é o mais negativo vezes o mais positivo
    se não tem negativo ou não tem positivo, é o quadrado do de menor módulo

    máximo possível
    é o quadrado do de maior módulo
*/
signed main(){
    int t; cin >> t;
    while(t--){
        int naotempositivo = 1, naotemnegativo = 1, maisnegativo = 0, maispositivo = 0, menormodulo = INF, maiormodulo = 0, temzero = 0;
        int n; cin >> n;
        while(n--){
            int a; cin >> a;
            if(a < 0){
                naotemnegativo = 0;
                maisnegativo = min(a, maisnegativo);
            }
            if(a > 0){
                naotempositivo = 0;
                maispositivo = max(a, maispositivo);
            }
            if(a == 0) temzero=1;
            
            maiormodulo = max(abs(a), abs(maiormodulo));
            if(a != 0)
                menormodulo = min(abs(a), abs(menormodulo));
        }
        if(naotempositivo || naotemnegativo){
            menormodulo *= (1-temzero);
            cout << menormodulo * menormodulo << " ";
        }
        else
            cout << maisnegativo*maispositivo << " ";
        cout << maiormodulo*maiormodulo << endl;
    }
}

            



