#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back

#define fr(i, n) for(int i = 0; i < n; i ++)

using namespace std;

// two matrices are changeable iff the multisets of cells of
// each parity are the same

void print(vector<int> a){
    fr(i,a.size()) cout << a[i] << " ";
    cout << endl;
}

int main(){_
    int T; cin >> T;
    while(T --){
        int N, M;
        cin >> N >> M;
        vector<int> A_even = {};
        vector<int> A_odd = {};
        vector<int> B_even = {};
        vector<int> B_odd = {};
        
        if(N == 1 || M == 1){
            int X;
            fr(i, N*M){
                cin >> X;
                A_even.pb(X);
            }
            fr(i, N*M){
                cin >> X;
                B_even.pb(X);
            }
            
            bool equal = true;
            fr(i, N*M)
                if(A_even[i] != B_even[i])
                    equal = false;
                
            if(equal) cout << "YES" << endl;
            else cout << "NO" << endl;
            
            continue;
        }

        int X;
        fr(i,N){
             fr(j, M){
                 cin >> X;
                 if((i+j)%2) A_odd.pb(X);
                 else A_even.pb(X);
             }
        }

        fr(i,N){
             fr(j, M){
                 cin >> X;
                 if((i+j)%2) B_odd.pb(X);
                 else B_even.pb(X);
             }
        }

        sort(A_even.begin(), A_even.end());
        sort(A_odd.begin(), A_odd.end());
        sort(B_even.begin(), B_even.end());
        sort(B_odd.begin(), B_odd.end());
        // print(A_even);print(A_odd);print(B_even);print(B_odd);
 
        bool changeable = true;
        fr(i, A_even.size())
            if(A_even[i] != B_even[i])
                changeable = false;
        fr(i, A_odd.size())
            if(A_odd[i] != B_odd[i])
               changeable = false;

        if(changeable)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
     }  
}
