#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1001;
pii dir[4][N][N];
char a[N][N];
int vis[N][N];
vector<pii> g[N][N];
queue<pii> q;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m; cin >> m >> n;
    pii inv={-1,-1};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            for(int k=0;k<4;k++) dir[k][i][j]=inv;
            if(a[i][j]=='M') q.push({i,j}), vis[i][j]=1;
        }
    }
    for(int i=2;i<n;i++){
        for(int j=2;j<m;j++){
            //up
            if(a[i-1][j]=='_') dir[0][i][j]=dir[0][i-1][j];
            else if(a[i-1][j]=='#') dir[0][i][j]={i,j};
            else dir[0][i][j]={i-1,j};
            //left
            if(a[i][j-1]=='_') dir[3][i][j]=dir[3][i][j-1];
            else if(a[i][j-1]=='#') dir[3][i][j]={i,j};
            else dir[3][i][j]={i,j-1};
        }
    }
    //down
    for(int i=n-1;i>1;--i){
        for(int j=2;j<m;j++){
            if(a[i+1][j]=='_') dir[2][i][j]=dir[2][i+1][j];
            else if(a[i+1][j]=='#') dir[2][i][j]={i,j};
            else dir[2][i][j]={i+1,j};
        }
    }
    //right
    for(int i=2;i<n;i++){
        for(int j=m-1;j>1;--j){
            if(a[i][j+1]=='_') dir[1][i][j]=dir[1][i][j+1];
            else if(a[i][j+1]=='#') dir[1][i][j]={i,j};
            else dir[1][i][j]={i,j+1};
        }
    }
    for(int i=2;i<n;i++){
        for(int j=2;j<m;j++){
            if(a[i][j]=='#') continue;
            for(int k=0;k<4;k++){
                int vx=dir[k][i][j].first, vy=dir[k][i][j].second;
                if(dir[k][i][j]==inv || dir[k][i][j]==make_pair(i,j)) continue;
                g[vx][vy].push_back({i,j});
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        for(auto &e:g[x][y]){
            if(vis[e.first][e.second]) continue;
            vis[e.first][e.second]=vis[x][y]+1;
            q.push(e);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout << vis[i][j]-1 << " ";
        cout << "\n";
    }
    
    return 0;
}
