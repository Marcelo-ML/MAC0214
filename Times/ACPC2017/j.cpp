#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>

string s;

void solve(){
    getline(cin, s);

    int n = s.size()+1;

    for(int i = 2; i*i <= n; i++){
        if(n%i != 0) continue;

        // i
        bool flag = true;
        int aux = n/i;
        for(int j = 1; j <= i-1; j++){
            if(s[(aux*j)-1] != ' '){
                flag = false;
                break;
            }
        }

        if(flag){
            cout << "YES\n";
            return;
        }

        // n/i
        flag = true;
        aux = i;
        for(int j = 1; j <= (n/i)-1; j++){
            if(s[(aux*j)-1] != ' '){
                flag = false;
                break;
            }
        }

        if(flag){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main(){
    fastio();

    int t; cin >> t;
    getline(cin, s);
    while(t--)
        solve();

    return 0;
}

