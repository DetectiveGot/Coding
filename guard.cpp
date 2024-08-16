#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1, mxN = 1e6+1;;
int a[N], p[N], g[N], deg[N], ans[N];
bool vis[N], pr[mxN];
vector<int> vec;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	for(int i=2;i*i<mxN;i++){
		if(pr[i]) continue;
		for(int j=i*i;j<mxN;j+=i) pr[j]=1;
	}
	vec.push_back(2);
	for(int i=3;i<mxN;i+=2) if(!pr[i]) vec.push_back(i);
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		cin >> p[i], g[i]=p[i];
		if(p[i]!=-1) deg[p[i]]++;
	}
	for(int i=0;i<n;i++){
		if(vis[i]) continue;
		if(deg[i]==0){
			int u = i;
			while(u>0){
				int t = a[u];
				for(auto &e:vec){
					if(e*e>t) break;
					while(t%e==0)
				}
			}
		}
	}

	return 0;
}
