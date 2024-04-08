#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+2;
int pa[N];
bool ch[N];

int fp(int x){
	if(pa[x]==x) return x;
	return pa[x]=fp(pa[x]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int m,n; cin >> m >> n;
	string s; cin >> s;
	iota(pa, pa+m, 0);
	for(int i=0;i<m;i++){
		if(s[i]=='1'){
			int u=fp(i);
			for(int j=1;j<=n;j++){
				int p=(i+j)%m,v=fp((i+j)%m);
				if(s[p]=='1' || pa[u]==pa[v]) break;
				pa[v]=u;
			}
			for(int j=1;j<=n;j++){
				int p=(i-j+m)%m,v=fp((i-j+m)%m);
				if(s[p]=='1' || pa[u]==pa[v]) break;
				pa[v]=u;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<m;i++){
		int u=fp(i);
		if(!ch[u]) cnt++, ch[u]=1;
	}
	cout << cnt;
	
	return 0;
}
