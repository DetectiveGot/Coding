#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+2;
int a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,mx=0; cin >> n;
	for(int i=1;i<=n;i++){
		int t; cin >> t;
		a[t]++;
		mx=max(mx, t);
	}
	for(int i=mx;i>=1;--i){
		int cnt=0;
		for(int j=i;j<=mx;j+=i){
			cnt+=a[j];
			if(cnt>=2){
				cout << i;
				return 0;
			}
		}
	}
	
	return 0;
}
