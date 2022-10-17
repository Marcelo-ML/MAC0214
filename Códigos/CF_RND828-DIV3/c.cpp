#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;
    int max_tempo = 0;
    int ult_c = -1;
    for(int i = 0; i < 3*n; i++){
        int I = i % n;
        if(s[I] == c && ult_c == -1)
            ult_c = I;
        if(s[I] == 'g' && ult_c != -1){
            int dist = (I - ult_c);
            dist = ( ( dist % n ) + n ) % n;
            max_tempo = max(dist, max_tempo);
            ult_c = -1;
        }
    }
    cout << max_tempo << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
