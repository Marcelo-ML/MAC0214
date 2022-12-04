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
const int MAXN = 200010;

void solve(){
    string s;
    cin >> s;
    int tam = s.size();
    int i = 0;
    int dia = 0;
    while(i < s.size()){
        set<int> b = {};
        while(i < s.size()){
            b.insert(s[i]);
            if(b.size() >= 4)
                break;
            i++;
        }
        dia++;
    }
    cout << dia << endl;
}

signed main(){_
    int t; cin >> t; while(t--)
	solve();
}

