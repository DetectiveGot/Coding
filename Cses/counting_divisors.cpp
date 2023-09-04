#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+2;
int cnt[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,t; cin >> n;
	for(int i=2;i<=N-2;i++){
		for(int j=i;j<=N-2;j+=i){
			cnt[j]++;
		}
	}
	while(n--){
		cin >> t;
		cout << cnt[t]+1 << "\n";
	}
	
	return 0;
}
