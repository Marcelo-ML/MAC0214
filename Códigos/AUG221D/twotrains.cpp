#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int T; cin >> T;
    int N, sum, maxi;
    int P;
    while(T --){
        cin >> N;
        sum = 0; maxi = 0;
        while(-- N){
            cin >> P;
            sum += P;
            maxi = max(maxi,P);
        }
        cout << sum + maxi << endl;
    }

}

