#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		multiset<string> tudo = {};
		vector<string> v[3];
		int n; cin >> n;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < n; j++){
				string s; cin >> s;
				v[i].push_back(s);
				tudo.insert(s);
			}
		}
		for(int i = 0; i < 3; i++){
			int pontos = 0;
			for(auto w : v[i]){
				if((tudo.count(w)) == 1)
					pontos+=3;
				if((tudo.count(w)) == 2)
					pontos++;
			}
			cout << pontos << " ";
		}
		cout << endl;
	}
}
 
