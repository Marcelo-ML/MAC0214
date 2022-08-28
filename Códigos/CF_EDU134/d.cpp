#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fs first
#define sc second
#define MAXN 112345
#define MAXM 30
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

ll arr[MAXN], brr[MAXN];
ll narr[MAXN], nbrr[MAXN];
int t;

bool funciona(ll seletor, int n){
    for(int i = 0; i < n; i++){
        narr[i] = arr[i] & seletor;
        nbrr[i] = brr[i] & seletor;
    }
    sort(narr, narr + n);
    sort(nbrr, nbrr + n);
    /*
    cout << "Caso " << t << ": o seletor " << seletor << "gerou: " << endl;
    for(int i = 0; i < n; i++){
        cout << narr[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << nbrr[i] << " ";
    }
    cout << endl << endl;
    */
    for(int i = 0; i < n; i++)
        if(narr[i] + nbrr[n-1-i] != seletor)
            return false;
    return true;
}


int main(){_
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++)
            cin >> brr[i];
        ll x = 0;
        for(int i = MAXM; i >= 0; i--){
            ll candx = x | (1 << i);
            if(funciona(candx, n))
                x = candx;
        }
        cout << x << endl;
    }
}





