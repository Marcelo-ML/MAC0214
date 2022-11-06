#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>



void solve(){
    int palavra[26];
    for(int i = 0; i < 26; i++)
        palavra[i] = 0;

    string a; cin >> a;
    string s; cin >> s;

    for(int j = 0; j < s.size(); j++){
        palavra[s[j] - 'a']++;
    }

    int sum = 0;

    for(int i = 0; i < a.size(); i++){
        if(palavra[a[i] - 'a'] > 0){
            palavra[a[i] - 'a']--;
            sum++;
        }
        else break;
    }

    cout << sum << endl;

}

signed main(){
    fastio();
    int t; cin >> t;
    while(t--) solve();    

    return 0;
}

