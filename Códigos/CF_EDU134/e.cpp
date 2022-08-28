///
/// VERDICT:
/// "TIME LIMIT EXCEEDED ON TEST 17"
///




#include <bits/stdc++.h>
#define N 1000100
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
char s[N];
int lps[N];
 
void calcula_pos(int pos){
    if(pos <= 1){
        lps[pos] = pos-1;
        return;
    }
    int j = pos-1;
    while(s[lps[j]+1] != s[pos] && j > 0)
        j = lps[j];
    lps[pos] = lps[j]+1;
    return;
}
 
 
void calcula_lps(int tam){
    // lps[0] = -1; lps[1] = 0;
    for(int i = 0; i <= tam; i++){
        calcula_pos(i);
        /*
        int j = i-1;
        while(s[lps[j]+1] != s[i] && j > 0)
            j=lps[j];
        lps[i] = lps[j]+1;
        */
    }
}
 
int main(){_
    
    string str; cin >> str;
 
    int tams = str.size();
    for(int i = 1; i <= tams; i ++)
        s[i] = str[i-1];
    calcula_lps(tams);
    int q; cin >> q;
    while(q--){
        string ttr; cin >> ttr;
        int tamt = ttr.size();
        for(int i = tams+1; i <= tams+tamt; i++){
            s[i] = ttr[i-tams-1];
            calcula_pos(i);
            cout << lps[i] << " ";
        }
        cout << endl;
    }
}
