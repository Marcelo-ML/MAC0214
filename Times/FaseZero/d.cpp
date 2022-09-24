#include <bits/stdc++.h>

using namespace std;

int dist(string s, string t){
    if(s.size() == 0 || t.size() == 0)
        return max(s.size(),t.size());
    if(s[0] == t[0])
      return dist(s.substr(1,s.size()-1), t.substr(1,t.size()-1));
      return (1 + min(min(dist(s.substr(1,s.size()-1),t), dist(s,t.substr(1,t.size()-1))), dist(s.substr(1,s.size()-1),t.substr(1,t.size()-1))));
}

int main(){
    int N; cin >> N;
    double notas[10];
    memset(notas, 0, sizeof(notas));
    while(N--){
        string gab; cin >> gab;
        int dists[10];
        for(int i = 1; i <= 5; i++){
            string s; cin >> s;
            dists[i] = dist(s,gab);
        }
        int min_dist = 10000;
        for(int i = 1; i <= 5; i++){
            min_dist = min(min_dist,dists[i]);
        }
        for(int i = 1; i <= 5; i++){
            if(dists[i] == min_dist){
                notas[i] += 0.5;
                if(min_dist == 0)
                    notas[i] += 0.5;
            }
        }
        //for(int i = 1; i <= 5; i++){
        //    cout << notas[i] << " ";
        //}
        //cout << endl;
    }
    double max_nota = -1;
    for(int i = 1; i <= 5; i++){
        max_nota = max(max_nota, notas[i]);
    }
    cout << fixed << setprecision(1) << max_nota << endl;
    int maior_vencedor = -1;
    for(int i = 1; i <= 5; i++){
        if(notas[i] == max_nota)
            maior_vencedor = i;
    }
    for(int i = 1; i <= 5; i++){
        if(notas[i] == max_nota){
            cout << i;
            if(i != maior_vencedor)
            	cout << " ";
        }
    }
    cout << endl;
}
