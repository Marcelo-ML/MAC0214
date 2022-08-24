#include <bits/stdc++.h>
#define MAXN 123
using namespace std;

int photo[MAXN][MAXN];
bool vis[MAXN][MAXN];

bool iguais(int x1, int y1, int x2, int y2, int w, int h){
    if(w != h){
        bool result1 = true, result2 = true;
        for(int i = 0; i < w; i++)
            for(int j = 0; j < h; j++)
                if(photo[x1+i][y1+j] != photo[x2+i][y2+j])
                    result1 = false;
        for(int i = 0; i < w; i++)
            for(int j = 0; j < h; j++)
                if(photo[x1+i][y1+j] != photo[x2+w-1-i][y2+h-1-j])
                    result2 = false;
        return (result1 || result2);
    }
    if(w == h){
        bool result1 = true, result2 = true, result3 = true, result4 = true;
        for(int i = 0; i < w; i++)
            for(int j = 0; j < h; j++)
                // cout << photo[x1 + i][y1 + j] << " e " << photo[x2 + i][y2 + j] << endl;
                if(photo[x1+i][y1+j] != photo[x2+i][y2+j])
                    result1 = false;
        for(int i = 0; i < w; i++)
            for(int j = 0; j < h; j++)
                if(photo[x1+i][y1+j] != photo[x2+w-1-i][y2+h-1-j])
                    result2 = false;
        for(int i = 0; i < w; i ++)
            for(int j = 0; j < h; j ++)
                if(photo[x1+i][y1+j] != photo[x2+w-1-j][y2+i])
                    result3 = false;
        for(int i = 0; i < w; i ++)
            for(int j = 0; j < h; j ++)
                if(photo[x1+i][y1+j] != photo[x2+j][y2+h-1-i])
                    result4 = false;
        /*
        if(result1) cout << "1!" << endl;
        if(result2) cout << "2!" << endl;
        if(result3) cout << "3!" << endl;
        if(result4) cout << "4!" << endl;
        */
        return(result1 || result2 || result3 || result4);
    }
}

int main(){
    int r, c; cin >> r >> c;
    int w = 0, h = 0;
    for(int i = 0; i < r; i ++){
        int num_h = 0;
        for(int j = 0; j < c; j ++){
            char ch; cin >> ch;
            if(ch == '#'){
                photo[j][i] = -1;
                num_h ++;
            }
            if(ch == '.') photo[j][i] = 0;
            if(ch == '+') photo[j][i] = 1;
        }
        if(num_h == c && h == 0 && i > 0)
            h = i - 1;
        if(num_h < c && w == 0)
            w = (c - num_h)/(num_h - 1);
    }
    // for(int i = 0; i < r; i ++){
    //     for(int j = 0; j < c; j ++){
    //         cout << photo[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << w << " " << h << endl;
    int diferentes = 0;
    for(int x1 = 1; x1 < c; x1 += w+1){
        for(int y1 = 1; y1 < r; y1 += h+1){
            if(vis[x1][y1]) continue;
            for(int x2 = 1; x2 < c; x2 += w+1){
                for(int y2 = 1; y2 < r; y2 += h+1){
                    if(x1 == x2 && y1 == y2) continue;
                    if(iguais(x1,y1,x2,y2,w,h)){
                        vis[x2][y2] = 1;
                    }
                }
            }
            diferentes ++;
        }
    }
    cout << diferentes << endl;
}
