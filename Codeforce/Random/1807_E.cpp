#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n+1);
	int l=1, r=n;
	for(int i=1;i<=n;i++) cin >> v[i];
	while(l<r){
		int mid=(l+r+1)/2,sum=0;
		cout << "?";
		for(int i=l;i<mid;i++){
			cout << " " << i;
			sum+=v[i];
		}
		cout << "\n";
		int x;
		cin >> x;
		if(sum==x) l=mid;
		else r=mid-1;
	}
	cout <<  "! " << l << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
