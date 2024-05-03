#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 2e5+1;
bool contain[N], in[N];

struct DATA{
	int l,r,id;
	bool operator < (const DATA &dt) const{
		if(l==dt.l) return r>dt.r;
		return l<dt.l;
	}
};

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	vector<DATA> a(n);
	for(int i=0;i<n;i++) cin >> a[i].l >> a[i].r, a[i].id = i;
	sort(a.begin(), a.end());
	int l=0,mx=0;
	for(int i=0;i<n;i++){
		if(a[i].r<=mx) in[a[i].id]=1;
		mx=max(mx, a[i].r);
	}
	int mn=INT_MAX;
	for(int i=n-1;i>=0;--i){
		if(a[i].r>=mn) contain[a[i].id]=1;
		mn=min(mn, a[i].r);
	}
	for(int i=0;i<n;i++) cout << contain[i] << " "; cout << "\n";
	for(int i=0;i<n;i++) cout << in[i] << " ";

	return 0;
}
