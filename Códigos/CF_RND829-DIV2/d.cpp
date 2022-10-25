#include <bits/stdc++.h>
using namespace std;

template<typename Q>
void print_queue(std::string_view name, Q q) {
    // NB: q is passed by value because there is no way to traverse
    // priority_queue's content without erasing the queue.
    for (std::cout << name << ": \t"; !q.empty(); q.pop())
        std::cout << q.top() << ' ';
    std::cout << '\n';
}

int solve(){
	int n, x; cin >> n >> x;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 0; i < n; i++){
		int y; cin >> y; pq.push(y);
	}
	while(1){
		int prim = pq.top();
		if(prim >= x)
			return 1;
		if(pq.size() < prim+1)
			return 0;
		for(int i = 0; i < prim; i++){
			pq.pop();
		}
		if(pq.top() == prim)
			pq.pop();
		else
			return 0;
		pq.push(prim+1);
	}
}

int main(){
	if(solve())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

