#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int x[n+10]; for(int i = 0; i < n; i++) cin >> x[i];
		int y[n+10]; for(int i = 0; i < n; i++) cin >> y[i];
		priority_queue<int,vector<int>,less<int>> positivos;
		priority_queue<int,vector<int>,greater<int>> negativos;
		priority_queue<int,vector<int>,greater<int>> saldos_disponiveis;
		for(int i = 0; i < n; i++){
			int saldo = y[i]-x[i];
			if(saldo < 0){
				negativos.push(saldo);
			//	cout << saldo << " - " << endl;
			}
			else{
				positivos.push(saldo);
			//	cout << saldo << " + " << endl;
			}
		}
		int resp = 0;
		while(!positivos.empty()){
			if(negativos.empty()){
				positivos.pop();
				if(!positivos.empty()){
					resp++;
					positivos.pop();
				}
			}
			else{
				int saldo_grupo = positivos.top()+negativos.top();
				if(saldo_grupo >= 0){
					negativos.pop();
					positivos.pop();
					saldos_disponiveis.push(saldo_grupo);
					resp++;
				}
				else{
					if(!saldos_disponiveis.empty())
						if(saldos_disponiveis.top()+negativos.top() >= 0){
							int tmp = saldos_disponiveis.top();
							saldos_disponiveis.pop();
							tmp+=negativos.top();
							saldos_disponiveis.push(tmp);
						}
					negativos.pop();
				}
			//	if(!saldos_disponiveis.empty())
			//		cout << saldos_disponiveis.size() << " dfjak " << saldos_disponiveis.top() << endl;
			}
		}
		cout << resp << endl;
	}
}

				

