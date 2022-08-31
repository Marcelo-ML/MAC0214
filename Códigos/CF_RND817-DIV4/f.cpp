#include <bits/stdc++.h>
#define MAXN 60

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dxadj[4] = {-1, 0, 0, 1};
int dyadj[4] = {0, -1, 1, 0};

int tab[MAXN][MAXN];
int tabmarcado[MAXN];
int somaviz[MAXN][MAXN];
int somaadj[MAXN][MAXN];


int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        bool bom = true;
        memset(tab, 0, sizeof(tab));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char ch; cin >> ch;
                tab[i][j] = (ch == '.' ? 0 : 1);
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                somaviz[i][j] = 0;
                somaadj[i][j] = 0;
                for(int k = 0; k < 8; k++)
                    somaviz[i][j] += tab[i+dx[k]][j+dy[k]];
                for(int k = 0; k < 4; k++)
                    somaadj[i][j] += tab[i+dxadj[k]][j+dyadj[k]];
            }
        }

        int adjacosos=0;
        int tudo=0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!tab[i][j])
                    continue;
                tudo++;
                if(somaadj[i][j] == 2)
                    adjacosos++;
                if(somaviz[i][j] != 2 || somaadj[i][j] == 0)
                    bom = false;
            }
        }
        /*
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j++){
                cout << tab[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j++){
                cout << somaviz[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j++){
                cout << somaadj[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        cout << adjacosos << " " << tudo << endl;
        */
        if(3*adjacosos != tudo)
            bom = false;
        

        if(bom)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

