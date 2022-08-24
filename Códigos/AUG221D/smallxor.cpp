#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

// given a sorted array, we perform on the last non operated element
// if it is greater than the minimum left by the operation on the
// elements before it. when we recognize a valley, we operate on it
// once or we don't, depending on the parity of remaining number of
// operations

int main(){_
    int T; cin >> T;
    int N, X, Y;
    while(T --){
        cin >> N >> X >> Y;
        int A[N + 10];
        for(int i = 0; i < N; i ++) cin >> A[i];
        sort(A, A + N);
       
        int valley = 0; // position of valley
        int last_operated = 0;
        while(Y --){
            if(last_operated != 0 && A[last_operated] >= A[valley]){
                Y ++;
                break;
            }
            A[last_operated] = A[last_operated] ^ X;
            if(last_operated == 0 || A[last_operated] < A[valley]){
                valley = last_operated;
            }
            last_operated ++;
            if(last_operated == N)
                break;
        }
        
        if(Y % 2 == 1) A[valley] = A[valley] ^ X;
        
        sort(A, A + N);
        for(int i = 0; i < N; i ++) cout << A[i] << " ";
        cout << endl;
    }
            
}

