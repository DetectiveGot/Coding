#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+2, K = 101, mod = 1e9+7;
int a[N],k,n;
ll dp[N][K], ans=0;
bool vis[N];
vector<int> g[N];

void dfs(int u, int p){
    vis[u]=1;
    dp[u][a[u]]++;
    dp[u][0]++;
    for(auto&e:g[u]){
        if(!vis[e]) dfs(e, u);
        for(int i=0;i<=100;i++) (dp[u][i]+=dp[e][i])%=mod;
        for(int i=max(a[u]-k, 1);i<=min(a[u]+k, 100);i++){
            (dp[u][a[u]]+=dp[e][i])%=mod;
        }
        (dp[u][a[u]]+=dp[e][0])%=mod;
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
//    freopen("in_all.txt", "r", stdin);
//    freopen("out_all.txt", "w", stdout);
    int m,u,v; cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++) cin >> a[i];
    dfs(1, -1);
    for(int i=1;i<=100;i++) (ans+=dp[1][i])%=mod;
    cout << ans << endl;
//    for(int i=1;i<=n;i++){
//        for(int j=0;j<=15;j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    return 0;
}
/*
3 2 1
1 2
2 3
1 2 3
out: 10
*/
