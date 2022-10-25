#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	int num_blocos = 0;
	string s; cin >> s;
	for(int i = 0; i < n; i++){
		if(i == n-1 || s[i] != s[i+1])
			num_blocos++;
	}
	if(s[0] == '0' && num_blocos)
		num_blocos--;
	cout << max(0,num_blocos - 1) << endl;
}

int main(){
	int t; cin >> t;
	while(t--) solve();
}
