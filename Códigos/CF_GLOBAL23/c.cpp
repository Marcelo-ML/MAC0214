#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fs first
#define sc second

// parece que sempre dá pra fazer... mas qual a estratégia?
// olhar para deltas (a[i] - a[i+1]) -> quando eu tenho que te operar?

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a;
        vector<pair<int,int>> delta_pos;
        a.pb(0);
        for(int i = 0; i < n; i++){
            int x; cin >> x; a.pb(x);
        }
        for(int i = 0; i < n; i++){
            delta_pos.pb({a[i+1]-a[i],i+1});
        }
        sort(delta_pos.begin(), delta_pos.end());
        vector<int> order;
        for(int i = 0; i < n; i++){
            order.pb(delta_pos[n-1-i].sc);
        }
        for(int i = 0; i < n; i++){
            cout << order[i] << " ";
        }
        cout << endl;
    }
}


