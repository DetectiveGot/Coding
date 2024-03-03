#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 150, dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
char a[N][N];
int cnt[N][N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	n=2*n-1;
	memset(cnt, -1, sizeof(cnt));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	for(int i=2;i<=n;i+=2){
		for(int j=2;j<=n;j+=2){
			cnt[i][j]=0;
			for(int k=0;k<4;k++){
				int x=i+dx[k], y=j+dy[k];
				if(a[x][y]=='.') cnt[i][j]++;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout << cnt[i][j] << " ";
//		}
//		cout << "\n";
//	}
	int ans=0;
	for(int i=2;i<=n;i+=2){
		for(int j=2;j<=n;j+=2){
			if(cnt[i][j]<=1) continue;
			for(int k=0;k<4;k++){
				int x=i+dx[k], y=j+dy[k];
				int vx=i+dx[k]*2, vy=j+dy[k]*2;
				int vxx=i+dx[k]*3, vyy=j+dy[k]*3;
				if(vxx<1 || vxx>n || vyy<1 || vyy>n) continue;
				if(a[vxx][vyy]=='.' && cnt[vx][vy]>1 && cnt[i][j]>1){
					--cnt[vx][vy];
					--cnt[i][j];
					++ans;
					a[vx][vy]='#';
				}
			}
		}
	}
	for(int i=2;i<=n;i+=2){
		for(int j=2;j<=n;j+=2){
			if(cnt[i][j]<=1) continue;
			for(int k=0;k<4 && cnt[i][j]>1;k++){
				int x=i+dx[k], y=j+dy[k];
				int vx=i+dx[k]*2, vy=j+dy[k]*2;
				if(a[x][y]=='.' && cnt[i][j]>1 && (vx<1 || vy<1 || vx>n || vy>n || cnt[vx][vy]>1)){
					--cnt[i][j];
					--cnt[vx][vy];
					a[x][y]='#';
					++ans;
//					deb(i); deb(j); deb(x); deb(y); deb(vx); deb(vy) << endl;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout << cnt[i][j] << " ";
//		}
//		cout << endl;
//	}
	++ans;
	cout << ans;
//	cout << endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	return 0;
}
