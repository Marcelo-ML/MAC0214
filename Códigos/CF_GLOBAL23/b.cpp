#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a = {};
        int num1 = 0, num0 = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x; a.pb(x);
            if(x == 1) num1++;
            else num0++;
        }
        int passados1 = 0;
        int passados0 = 0;
        int i = 0;
        while(passados1 < num0 - passados0){
            if(a[i] == 0)
                passados0++;
            if(a[i] == 1)
                passados1++;
            i++;
        }
        cout << passados1 << endl;
    }
}
