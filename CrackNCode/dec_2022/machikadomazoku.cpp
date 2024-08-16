#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 502;
ll dist[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,u,v,w; cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dist[i][j]=1e18;
	while(m--){
		cin >> u >> v >> w;
		dist[u][v]=dist[v][u]=w;
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	int lim,cnt=0; cin >> lim;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(dist[i][j]<=lim) cnt++;
		}
	}
	if(cnt){
		int div=(n*(n-1))/2, gd=__gcd(div, cnt);
		cout << cnt/gd << "/" << div/gd;
	} else cout << "0/1";
	
	return 0;
}