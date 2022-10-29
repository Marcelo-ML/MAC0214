#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

void solve(){
	int s; cin >> s;
	stack<int> pilha;
	for(int i = 9; i >= 1 && s > 0; i--){
		if(s >= i){
			s -= i;
			pilha.push(i);
		}
	}
	while(!pilha.empty()){
		int prox = pilha.top();
		pilha.pop();
		cout << prox;
	}
	cout << endl;
}

int main(){
	int t; cin >> t;
	while(t--) solve();
}

