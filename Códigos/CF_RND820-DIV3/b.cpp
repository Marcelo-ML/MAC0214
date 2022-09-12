#include<bits/stdc++.h>

using namespace std;

int main(){
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		string s; cin >> s;
		stack<char> pilha;
		int i = n-1;
		while(i >= 0){

			if(s[i] != '0'){
				pilha.push(s[i]-'1'+'a');
				i--;
				continue;
			}
			char letra = (s[i-1]-'1'+1)+10*(s[i-2]-'1'+1) + 'a' - 1;
			pilha.push(letra);
			i -= 3;
		}
		while(!pilha.empty()){
			char letra = pilha.top();
			pilha.pop();
			cout << letra;
		}
		cout << endl;
	}
}


