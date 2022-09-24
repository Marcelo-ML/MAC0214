#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin >> N;
    while(N--){
        int t; cin >> t;
        string s; cin >> s;
        if(s[0] == '1'){
            if(t > 45){
                cout << "45+" << t-45 << endl;
            }
            else
                cout << t << endl;
        }
        else{
            if(t > 45){
                cout << "90+" << t-45 << endl;
            }
            else
                cout << t + 45 << endl;
        }
    }
}
