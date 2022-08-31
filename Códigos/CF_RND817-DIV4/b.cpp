#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		bool igual = true;
		string s, t; cin >> s; cin >> t;
		for(int i = 0; i < n; i++){
			if(s[i] != t[i])
				if(!((s[i] == 'G' && t[i] == 'B') || (s[i] == 'B' && t[i] == 'G')))
					igual = false;

		}
		if(igual)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

 
