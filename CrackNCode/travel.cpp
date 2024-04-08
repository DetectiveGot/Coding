#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

const int N = 1e6+2;
ll c[N], s[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll n, x1=0,x2=0; cin >> n;
	for(int i=1;i<=n;i++){
		cin >> c[i], x1=max(x1, c[i]);
	}
	for(int i=2;i<=n;i++){
		cin >> s[i];
		s[i]+=s[i-1];
		x2=max(x2, s[i]);
	}
	ll mx=0,idx=0;
	for(int i=1;i<=n;i++){
		if(c[i]+s[i]+c[idx]-s[idx]>mx){
			mx=c[i]+s[i]+c[idx]-s[idx];
//			cout << "------\nidx " << idx << "\ni: " << i << "\n";
//			cout << c[idx] << " + " << c[i] << " + " << s[i] << " - " << s[idx] << "\n--------\n";
		}	
		if(c[i]-s[i]>c[idx]-s[idx]){
			idx=i;
		}
	}
	cout << mx;
	
	return 0;
}
/*
2 (5) 7 9 8 3 (3)
   1 4 8 9 14 15
*/
