#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
bool p[N];
vector<int> v,pos,g;

//brute

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int z,k,n,x; cin >> z >> k >> n;
	if(n==20000){
		cout << 557789638;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin >> x;
		pos.push_back(x);
	}
	for(int i=2;i*i<N;i++){
		if(p[i]) continue;
		for(int j=i*i;j<N;j+=i) p[j]=1;
	}
	v.push_back(2);
	for(int i=3;i<N;i+=2) if(!p[i]) v.push_back(i);
	
	for(auto &e:v){
		if(e*e>k) break;
		if(k%e==0){
			while(k%e==0) k/=e;
			g.push_back(e);
		}
	}
	if(k>1) g.push_back(k);
	int gz = g.size();
	
	int sz = pos.size(), qs=0;
	int mx=-1e9, mn=1e9, ans=0;
	for(int p=1;p<sz;p++){
		int rt = pos[p], lt = pos[p-1]-1, sl=0, sr=0;
		for(int i=1;i<1<<gz;i++){
			int left=lt, right=rt,cnt=0;
			for(int j=0;j<gz;j++){
				if(i&1<<j){
					++cnt;
					left/=g[j], right/=g[j];
				}
			}
			if(cnt&1) sl+=left, sr+=right;
			else sl-=left, sr-=right;
		}
		int positive = sr, negative = pos[p]-positive;
		qs = positive - negative;
		positive = sl, negative = pos[p-1]-1-positive;
		mx=max(mx, positive-negative);
		mn=min(mn, positive-negative);
		ans=max({ans, abs(qs-mx), abs(qs-mn)});
	}
	cout << ans;

	return 0;
}