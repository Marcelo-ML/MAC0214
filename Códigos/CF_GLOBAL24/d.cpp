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
const int MAXN = 5010;

int p;
int fat[MAXN];
int binomi[MAXN][MAXN];
void prec(){
    fat[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fat[i] = i*fat[i-1];
        fat[i] %= p;
    }
    for(int j = 0; j < MAXN; j++){
        for(int i = j; i < MAXN; i++){
            if(!j || i == j) {binomi[i][j] = 1; continue; }
            binomi[i][j] = (binomi[i-1][j]+binomi[i-1][j-1]) % p;
        }
    }
}
/*
int fastexpo(int b, int e){
    if(!e) return 1;
    int resp = fastexpo(b, e/2);
    resp *= resp;
    resp %= p;
    if(e&1) resp *= b;
    return resp % p;
}

int inv(int n){
    return fastexpo(n, p-2);
}
*/
int binom(int a, int b){
    return binomi[a][b];
    /*if(binomi[a][b] != -1)
        return binomi[a][b];
    return binomi[a][b] = (((fat[a]*inv(fat[b])) % p) * inv(fat[a-b]))%p;
    */
}

void solve(){
    int n; cin >> n >> p;
    prec();
//    cout << binom(0,0) << " @*$* " << endl;
    if(!(n&1)){
        // caso n par
        int resp;
        // a = 1
        resp = fat[n-2];
        // cout << resp << " -- ";
        // a > 1
        for(int a = 2; a <= n/2; a++){
            int s = 0;
            for(int i = 0; i <= a-2; i++){
                s += ( binom(a-2, i)*fat[n-i-3] )%p;
            }
            resp += a*s;
            resp %= p;
        }
        resp *= n;
        resp %= p;
        cout << resp << endl;
        return;
    }
    // caso n ímpar
    // a > 1 sempre
    int resp = 0;
    for(int a = 2; a <= (n+1)/2; a++){
        int s = 0;
        for(int i = 0; i <= a-2; i++){
            s += ( binom(a-2, i)*fat[n-i-3] )%p;
        }
        resp += (a-1)*s;
        resp %= p;
    }
    resp *= n;
    resp %= p;
    cout << resp << endl;
}

signed main(){_
    solve();
}

