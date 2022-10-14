#include <bits/stdc++.h>
using namespace std;

int n, c;

int main(){
    cin >> n >> c;
    vector<string> palavras;
    for(int i = 0; i < n; i++){
        string s; cin >> s; palavras.push_back(s);
    }
    string resp = "a";
    int result = -1;
    unordered_map<string,int> atual;
    for(char ch = 'a'; ch <= 'z'; ch++){
        for(int i = 0; i < n; i++){
            string s = palavras[i];
            for(int j = 0; j < c; j++){
                if(s[j] == '*')
                    s[j] = ch;
            }
            if(atual.find(s) == atual.end()){
                atual.insert({s,1});
            }
            else
                atual[s]++;
        }
        for(auto it : atual){
            if(it.second > result){
                result = it.second;
                resp = it.first;
            }
            if(it.second == result && it.first < resp){
                result = it.second;
                resp = it.first;
            }
        }
    }
    cout << resp << " " << result << endl;
}
