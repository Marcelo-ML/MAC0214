#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a = {};
        int num1 = 0, num0 = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x; a.pb(x);
            if(x == 1) num1++;
            else num0++;
        }
        if(num1 == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}

