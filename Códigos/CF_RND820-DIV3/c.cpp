#include<bits/stdc++.h>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pb push_back
#define fs first
#define sc second
#define mp make_pair
#define all(x) (x).begin(),(x).end()

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s; int tam = s.size();
        comeco_bom:
        int prim = s[0]-'a'+1;
        int ult = s[tam-1]-'a'+1;
        vpii let_pos = {};
        for(int i = 0; i < tam; i++)
            let_pos.pb(mp(s[i]-'a'+1,i+1));
        sort(all(let_pos));
        if(prim <= ult){
            int comeca = -1, termina = -1;
            for(int i = 0; i < tam; i++){
                if(let_pos[i].fs == prim && comeca == -1)
                    comeca = i;
                if(let_pos[i].fs == ult)
                    termina = i;
            }
            cout << ult-prim << " " << termina-comeca+1 << endl;
             for(int i = 0; i < tam; i++){
                if(let_pos[i].fs < prim)
                    continue;
                if(let_pos[i].fs > ult)
                    break;
                cout << let_pos[i].sc << " ";
            }
        }
        else{
            for(int i = 0; i < tam; i++)
                s[i] = 'z'-s[i]+'a';
            goto comeco_bom;
        }
        cout << endl;
    }
}


