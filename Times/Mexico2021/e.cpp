#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>

#define MAXN 1000010

ll sizes[MAXN];
ll checks[MAXN];

signed main(){
    fastio();

    ll n, limite = 0;
    char c;

    cin >> n;
    while(1){
        cin >> c;
        if(c >= '0' && c <= '9'){
            limite *= 10;
            limite += (c-'0');
        } else {
            if(c == 'G') limite *= 1024;
            else if(c == 'T') limite *= 1024*1024;
            break;
        }
    }

    for(int i = 1; i <= n; i++)
        cin >> sizes[i];

    ll tras = 1, frente = 0, soma = 0, cont = 0, bst = n;
    for(int i = 1; i <= n; i++){
        soma += sizes[i];
        frente++; cont++;
        while(soma > limite){
            soma -= sizes[tras];
            checks[tras] = cont;
            tras++; cont--;
            bst = min(bst, cont);
        }
    }

    ll ind = -1;
    for(int i = 1; i <= n; i++){
        if(checks[i] == 0) break;
        if(checks[i] <= bst+1){
            ind = i;
            break;
        }
    }

    cout << bst << " " << ind << "\n";

    return 0;
}

