#include <bits/stdc++.h>

using namespace std;

int cron_to_int(string s){
    int resp;
    if(s[1] == ':')
        resp = stoi(s.substr(0,1)) * 60*1000 + stoi(s.substr(2,2)) * 1000 + stoi(s.substr(5,3));
    else
        resp = stoi(s.substr(0,2)) *60* 1000 + stoi(s.substr(3,2)) * 1000 + stoi(s.substr(6,3));
    return resp;
}

int main(){
    int N, V; cin >> N >> V;
    int num_piloto[N+10];
    vector<pair< pair<int,int> ,int>> tempo_piloto;
    vector<pair<int,int>> ordem_chegada;
    for(int i = 0; i < N; i++){
        cin >> num_piloto[i];
        int melhor_volta = 123456789;
        int tempo_na_melhor = 0;
        int tempo_atual = 0;
        for(int j = 0; j < V; j++){
            string s; cin >> s;
            int volta_atual = cron_to_int(s);
            tempo_atual += volta_atual;
            if(volta_atual < melhor_volta){
                melhor_volta = volta_atual;
                tempo_na_melhor = tempo_atual;
            }
        }
        tempo_piloto.push_back(make_pair(make_pair(melhor_volta, tempo_na_melhor), num_piloto[i]));
        ordem_chegada.push_back(make_pair(tempo_atual, num_piloto[i]));
    }
    sort(ordem_chegada.begin(), ordem_chegada.end());
    sort(tempo_piloto.begin(), tempo_piloto.end());
    int piloto_veloz = tempo_piloto[0].second;
    for(int i = 0; i < 10; i++){
        if(ordem_chegada[i].second == piloto_veloz){
            cout << piloto_veloz << endl;
            return 0;
        }
    }
    cout << "NENHUM" << endl;
}

