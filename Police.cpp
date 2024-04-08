#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e5+2;
int bi[N], pa[N], ban[N];
vector<int> g[N];
queue<int> q;

int fp(int x){
    if(pa[x]==x) return x;
    return pa[x]=fp(pa[x]);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
//    freopen("all_in.txt", "r", stdin);
//    freopen("all_out.txt", "w", stdout);
    int n,m,k,u,v; cin >> n >> m >> k;
    for(int i=1;i<=n;i++) bi[i]=-1, pa[i]=i;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(bi[i]==-1){
            bi[i]=0;
            q.push(i);
            while(!q.empty()){
                u=q.front();
                q.pop();
                for(auto&e:g[u]){
                    int pu=fp(u), pv=fp(e);
                    if(bi[e]==-1){
                        bi[e]=bi[u]^1;
                        q.push(e);
                    } else if(bi[e]==bi[u]){
                        ban[pv]=1;
                    }
                    pa[pv]=pa[pu];
                    ban[pu]|=ban[pv];
                }
            }
        }
    }
    while(k--){
        cin >> u >> v;
        int pu=fp(u), pv=fp(v);
        if(pu==pv){
        	if(!ban[pu]){
        		if(bi[u]==bi[v]) cout << "Yes\n";
        		else cout << "No\n";
			} else cout << "Yes\n";
		} else cout << "No\n";
    }
    
    return 0;
}
