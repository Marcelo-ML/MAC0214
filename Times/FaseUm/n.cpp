    #include <bits/stdc++.h>
    using namespace std;
     
    #define MAXN 100010
     
    int n, A[MAXN], B[MAXN], k, l;
    long long acck, accl, res;
    multiset<int> l_up, l_down;
     
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
     
     	cin >> n;
    	for(int i = 0; i < n; i++)
    		cin >> A[i];
    	for(int i = 0; i < n; i++)
    		cin >> B[i];
    	cin >> k >> l;
     
    	acck = 0; accl = 0; 
    	for(int i = k-1; i >= 0; i--){
    		acck += A[i];
    	
    		if(i >= k-l){
    			l_up.insert(B[i]);
    			accl += B[i];
    		} else if(B[i] > *l_up.begin()){
    			int aux = *l_up.begin();
    			l_up.erase(l_up.begin());
    			l_down.insert(aux);
    			l_up.insert(B[i]);
     
    			accl += B[i];
    			accl -= aux;
    		} else
    			l_down.insert(B[i]);
    	}
     
    	res = acck + accl;
     
    	for(int i = k-1; i >= 0; i--){
    		acck -= A[i];
    		acck += A[n-k+i];
     
    		if(l_up.find(B[i]) != l_up.end()){
    			l_up.erase(l_up.find(B[i]));
    			accl -= B[i];
     
    			if(B[n-k+i] > *l_down.rbegin()){
    				l_up.insert(B[n-k+i]);
    				accl += B[n-k+i];
    			} else {
    				int aux = *l_down.rbegin();
    				l_down.erase(l_down.find(aux));
    				l_down.insert(B[n-k+i]);
    				l_up.insert(aux);
    				accl += aux;
    			}
    		} else {
    			l_down.erase(l_down.find(B[i]));
    			
    			if(B[n-k+i] > *l_up.begin()){
    				int aux = *l_up.begin();
    				l_up.erase(l_up.begin());
    				l_up.insert(B[n-k+i]);
    				l_down.insert(aux);
    				accl -= aux;
    				accl += B[n-k+i];
    			} else {
    				l_down.insert(B[n-k+i]);
    			}
    		}
     
    		res = max(res, acck+accl);
    	}
     
    	cout << res << "\n";
     
    	return 0;
    }
