#include <bits/stdc++.h>
#define ll long long
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main(){_
	set<char> s;
	set<char> bom = {'T', 'i', 'm', 'u', 'r'};
	int t; cin >> t;
	while(t--){
		s.clear();
		int n; cin >> n;
		if(n != 5){
			for(int i = 0; i < n; i ++){
				char ch; cin >> ch;
			}
			cout << "NO" << endl;
			continue;
		}
		for(int i = 0; i < 5; i ++){
			char ch; cin >> ch;
			s.insert(ch);
		}
		/*
		cout << "taqui ó" << endl;
		for(auto x : s)
			cout << x << " ";
		cout << endl;
		*/
		if(s == bom)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
 
