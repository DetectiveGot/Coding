#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
int a[N], fw[N];
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
	int n,m,t; cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> t;
		v.push_back(t);
		upd(i, 1);
	}	
	sort(v.begin(), v.end());
	for(int i=1;i<=n-m;i++){
		cin >> t;
		t = lower_bound(v.begin(), v.end(), t)-v.begin()+1;
		cout << qry(t) << "\n";
		upd(t,1);
	}
	
	return 0;
}
/*
1 2 3 4 5
1 2 3 4 5 10
1 2 3 4 5 9 10
1 2 3 4 5 8 9 10
*/
