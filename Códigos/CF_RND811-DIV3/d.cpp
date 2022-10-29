#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

bool fits(string s, string t, int pos){
	// se s cabe em t se pusermos na posição pos
	if(pos+s.size() > t.size())
		return false;
	else
		for(int i = 0; i < s.size(); i++){
			if(s[i] != t[i+pos])
				return false;
		}
	return true;
}

void solve(){
	string t; cin >> t;
	int n; cin >> n;
	vector<string> s;
	for(int i = 0; i < n; i++){
		string x; cin >> x; s.pb(x);
	}

	int tam = t.size();

	int adj[tam+10]; // no adj[i], colocamos o índice da maior string que ele pode usar
	for(int i = 0; i < tam+10; i++){
		adj[i] = -1;
	}
	for(int pos = 0; pos < tam; pos++){
		for(int i = 0; i < s.size(); i++){
			if( fits(s[i],t,pos) ){
				if(adj[pos] == -1)
					adj[pos] = i;
				if(s[adj[pos]].size() < s[i].size())
					adj[pos] = i;
			}
		}
	}

	for(int i = 0; i < tam; i++){
		cout << adj[i] << ' ';
	}
	cout << endl;

	stack<int> pilha;
	int cur = tam;
	for(int i = 0; i < cur; i++){
//		cout << i << ' ';
		if(i+s[adj[i]].size() >= cur){
			cout << i << " nhe ";
			pilha.push(i);
			cur = i;
			i = -1;
		}
	}
//	cout << endl;
	
	if(pilha.empty() || pilha.top() != 0){
		cout << -1 << endl;
		return;
	}
	cout << pilha.size() << endl;
	while(!pilha.empty()){
		int aux = pilha.top();
		pilha.pop();
		cout << adj[aux] + 1 << ' ' << aux + 1 << endl;
	}
}

int main(){_
	int t; cin >> t;
	while(t--) solve();
}

