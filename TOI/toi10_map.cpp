#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 406, mxN = 40002, ofs = 202;
int a[N][N], d[mxN], l[mxN], u[mxN], r[mxN];
bool vis[mxN];
queue<tuple<int,int,int>> q;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m,t1,t2; cin >> n >> m;
	char c;
	for(int i=0;i<n*m;i++) l[i]=r[i]=d[i]=u[i]=-1;
	for(int i=1;i<n*m;i++){
		cin >> t1 >> c >> t2;
		if(c=='L') l[t2]=t1, r[t1]=t2;
		else if(c=='U') u[t2]=t1, d[t1]=t2;
		else if(c=='D') d[t2]=t1, u[t1]=t2;
		else if(c=='R') r[t2]=t1, l[t1]=t2;
	}
	int x,y,w,xx=ofs,yy=ofs;
	q.emplace(ofs, ofs, 0); vis[0]=1;
	while(!q.empty()){
		tie(x,y,w)=q.front();
		q.pop();
		a[x][y]=w;
		xx=min(xx, x);
		yy=min(yy, y);
		if(u[w]!=-1 && !vis[u[w]]) q.emplace(x-1, y, u[w]), vis[u[w]]=1;
		if(d[w]!=-1 && !vis[d[w]]) q.emplace(x+1, y, d[w]), vis[d[w]]=1;
		if(l[w]!=-1 && !vis[l[w]]) q.emplace(x, y-1, l[w]), vis[l[w]]=1;
		if(r[w]!=-1 && !vis[r[w]]) q.emplace(x, y+1, r[w]), vis[r[w]]=1;
	}
	for(int i=xx;i<xx+n;i++){
		for(int j=yy;j<yy+m;j++) cout << a[i][j] << " ";
		cout << "\n";
	}

	return 0;
}

