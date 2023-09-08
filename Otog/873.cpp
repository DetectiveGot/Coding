#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
int a[N], ans[N], fw[N];
vector<int> v;

void upd(int i, int val){
	for(;i<=(int)1e5;i+=i&-i) fw[i]+=val;
}

int qry(int i){
	int res=0;
	for(;i>=1;i-=i&-i) res+=fw[i];
	return res;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	for(int i=1;i<=n;i++){
		int it = lower_bound(v.begin(), v.end(), a[i])-v.begin()+1;
		ans[i]=qry(it);
		upd(it, 1);
	}
	for(int i=1;i<=n;i++) cout << ans[i] << " ";
	
	return 0;
}
