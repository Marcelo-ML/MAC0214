#include <bits/stdc++.h>
#define int long long
using namespace std;
#define EPS 

int tamanho(int n, int base){
    if(n == 0)
        return 0;
    return 1 + tamanho(n/base, base);
}

int fours(int n, int base){
    if(n == 0)
        return 0;
    if(n % base == 4)
        return 1 + fours(n/base, base);
    return fours(n/base, base);
}
signed main(){
    int N; cin >> N;
    pair<int,int> fouriest = make_pair(0,1);
    int winner = N;
    if(N < 100){
        for(int i = 5; i < N; i++){
            if(fours(N,i) * fouriest.second >= tamanho(N,i) * fouriest.first){
                fouriest = make_pair(fours(N,i) , tamanho(N,i));
                winner = i;
            }
        }
        cout << winner << endl;
        return 0;
    }
    // dá pra otimizar pra N^(1/2)
    for(int i = 5; i*i < N; i++){
        if(fours(N,i) * fouriest.second >= tamanho(N,i) * fouriest.first){
            fouriest = make_pair(fours(N,i) , tamanho(N,i));
            winner = i;
        }
    }
    if(N%4 == 0){
        cout << N/4 - 1 << endl;
        return 0;
    }
    if(2*fouriest.first <= fouriest.second){
        cout << N-4 << endl;
        return 0;
    }
    else
        cout << winner << endl;
}




