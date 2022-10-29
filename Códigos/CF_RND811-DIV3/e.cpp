#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

void solve(){
	int n; cin >> n;
	int a[n+10];
	int num_m5 = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(!(a[i]%5))
			num_m5++;
	}

	if(num_m5){
	//	cout << "hip" << endl;
		if(num_m5 < n){
			cout << "No" << endl;
			return;
		}
		int menor_m10 = -1;
		int maior_num = 0;
		for(int i = 0; i < n; i++){
			if(a[i]%10)
				a[i]+=5;
		}
		bool iguais = 1;
		for(int i = 0; i+1 < n; i++)
			if(a[i] != a[i+1])
				iguais = 0;
		if(iguais)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		return;
	}
	
	int tipo1 = 0, tipo2 = 0;
	for(int i = 0; i < n; i++){
		int x = a[i] % 20;
		if(x == 2 || x == 4 || x == 8 || x == 16 || x == 1 || x == 13 || x == 17 || x == 19)
			tipo1++;
		else
			tipo2++;
	}
	if(tipo1 && tipo2)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}

int main(){
	int t; cin >> t;
	while(t--) solve();
}

