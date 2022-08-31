#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		char ch;
		int line[n+10];
		for(int i = 0; i < n; i++){
			cin >> ch;
			line[i] = (ch == 'L' ? -1 : 1);
		}
		int valor = 0;
		for(int i = 0; i < n; i++)
			valor += (line[i] == -1 ? i : n-1-i);
		int mudados = 0;
		for(int i = 0; i < n/2; i++){
			if(line[i] == -1){
				line[i] = 1;
				mudados++;
				valor += n-1-(2*i);
				cout << valor << " ";
			}
			int j=n-1-i;
			if(line[j] == 1){
				line[j] = -1;
				mudados++;
				valor += (2*j)-n+1;
				cout << valor << " ";
			}
		}
		while(mudados<n){
			cout << valor << " "; mudados++;
		}
		cout << endl;
	}
}
 
