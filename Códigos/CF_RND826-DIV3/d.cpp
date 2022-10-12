#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int main(){
    int t; cin >> t;
    while(t--){
        int m; cin >> m;
        vector<int> tree = {};
        int result = 0;
        for(int i = 0; i < m; i++){
            int x; cin >> x; tree.push_back(x);
        }
        for(int N = m; N > 1; N/=2){
            for(int i = 0; i < N/2; i++){
                if(tree[2*i] - tree[2*i+1] != -1 && tree[2*i] - tree[2*i+1] != 1){
                    cout << -1 << endl; goto volta;
                }
                if(tree[2*i] - tree[2*i+1] == 1)
                    result++;
                tree[i] = max(tree[2*i],tree[2*i+1])/2;
            }
            /*
            for(int i = 0; i < N/2; i++)
                cout << tree[i] << " ";
            cout << endl;
            */

        }
        cout << result << endl;

        
        volta:
        int lixo = 0;
    }
}

