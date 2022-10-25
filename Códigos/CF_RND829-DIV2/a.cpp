#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	for(int i = 0; i < n; i++){
		if(s[i] == 'Q'){
		// tem que ter mais 'A' daqui pra frente
		int delta = 0;
			for(int j = i+1; j < n; j++){
				if(s[j] == 'A')
					delta++;
				else
					delta--;
			}
			if(delta <= 0){
				cout << "No" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
}

int main(){
	int t; cin >> t;
	while(t--) solve();
}
