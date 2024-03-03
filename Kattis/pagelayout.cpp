#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 21;
struct DATA{
	int w,h,x,y;
	bool operator < (const DATA &dt) const{
		return x<dt.x;
	}
} a[N];
bool vis[N];
int n,ans=0;

inline void dfs(int i, int area){
	if(i==n){
		ans=max(ans, area);
		return;
	}
	bool ok=true;
	for(int j=0;j<i;j++){
		bool k1=(a[i].y>=a[j].y && a[i].y<a[j].y+a[j].h) || (a[i].y+a[i].h>a[j].y && a[i].y+a[i].h<=a[j].y+a[j].h);
		bool k2=a[i].y<=a[j].y && a[i].y+a[i].h>=a[j].y+a[j].h;
		if(vis[j] && a[i].x<a[j].x+a[j].w && (k1 || k2)){
			ok=false;
			break;
		}
	}
	if(ok){
		vis[i]=1;
		dfs(i+1, area+a[i].h*a[i].w);
		vis[i]=0;
	}
	dfs(i+1, area);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	while(cin >> n && n!=0){
		ans=0;
		for(int i=0;i<n;i++) cin >> a[i].w >> a[i].h >> a[i].x >> a[i].y;
		sort(a, a+n);
		dfs(0, 0);
		cout << ans << "\n";
	}
	return 0;
}

