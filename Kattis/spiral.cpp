#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 501, mxN = 10001, ofs=201, dx[]={0,-1,0,1}, dy[]={1,0,-1,0};
int a[N][N], dist[N][N];
pii pos[mxN];
bool p[mxN];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	p[1]=1;
	for(int i=2;i*i<mxN;i++){
		if(p[i]) continue;
		for(int j=i*i;j<mxN;j+=i) p[j]=1;
	}
	int ax=ofs,ay=ofs,mxx=ofs,mxy=ofs,mnx=ofs,mny=ofs,c=0,cnt=0;
	for(int tn=0;c<mxN;tn++){
		for(int k=0;k<2;k++){
			for(int j=0;j<=tn && c<mxN;j++){
				a[ax][ay]=++c;
				pos[c]={ax,ay};
				mxx=max(mxx, ax);
				mnx=min(mnx, ax);
				mxy=max(mxy, ay);
				mny=min(mny, ay);
				ax+=dx[cnt%4], ay+=dy[cnt%4];
			}
			++cnt;
		}
	}
	int cs=0;
	while(cin >> ax >> ay){
		queue<pii> q;
		for(int i=mnx;i<=mxx;i++) for(int j=mny;j<=mxy;j++) dist[i][j]=0;
		q.push(pos[ax]); dist[pos[ax].first][pos[ax].second]=1;
		bool ok=false;
		while(!q.empty()){
			int x=q.front().first, y=q.front().second;
			q.pop();
			if(x==pos[ay].first && y==pos[ay].second){
				ok=true;
				break;
			}
			for(int i=0;i<4;i++){
				int vx=x+dx[i], vy=y+dy[i];
				if(vx<mnx || vy<mny || vx>mxx || vy>mxy || dist[vx][vy] || !p[a[vx][vy]]) continue;
				q.push({vx,vy});
				dist[vx][vy]=dist[x][y]+1;
			}
		}
		cout << "Case " << ++cs << ": ";
		if(ok) cout << dist[pos[ay].first][pos[ay].second]-1 << "\n";
		else cout << "impossible\n";
	}

	return 0;
}

