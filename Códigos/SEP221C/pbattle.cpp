// basta decidir para cada cara, de quantos ele x perde TOTALMENTE
// isto é, (a1,b1)<(a2,b2) em cada entrada
// o poder dele é n-1-x
// o que queremos é o número de caras que NÃO PERDEM TOTALMENTE PARA NINGUÉM


// geoemtricamente, é fácil ver o que está acontecendo e fazer em O(N)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){_
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v = {};
        vector<pair<int,int>> vp = {};
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            vp.push_back(make_pair(a,0));
        }
        for(int i = 0; i < n; i++){
            int b; cin >> b; vp[i].second = b;
        }
        sort(vp.begin(),vp.end());
        /*
        for(int i = 0; i < vp.size(); i++)
            cout << "(" << vp[i].first << ", " << vp[i].second << ")" << endl;
          */  
        for(int i = 0; i < vp.size(); i++){
            while(!v.empty()){
                if(vp[i].second > v[v.size()-1])
                    v.pop_back();
                else
                    break;
            }
            v.push_back(vp[i].second);
            //cout << "após " << i+1 <<  ":" << endl;
            //for(int j = 0; j < v.size(); j++)
            //    cout << v[j] << " ";
            //cout << endl;
        }

        cout << v.size() << endl;
    }
}
           

