#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int dif = (a*y)-(b*x);
        if(dif == 0)
            cout << "EQUAL" << endl;
        if(dif < 0)
            cout << "BOB" << endl;
        if(dif > 0)
            cout << "ALICE" << endl;
    }
}



