#include <bits/stdc++.h>

using namespace std;

int abs(int x){
	return (x>0? x : -x);
}

int main(){
	int t; cin >> t;
	while(t--){
		int a, b, c; cin >> a >> b >> c;
		int tempo1 = abs(a-1);
		int tempo2;
		if(c <= b)
			tempo2 = abs(b-1);
		else
			tempo2 = abs(b-c)+abs(c-1);
		if(tempo1 < tempo2)
			cout << 1 << endl;
		if(tempo2 < tempo1)
			cout << 2 << endl;
		if(tempo1 == tempo2)
			cout << 3 << endl;
	}
}

