#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;
const int N = 1e5+2;
pii co[N], ans[N], ask[N];

ll cal(const int &i, const int &j){
    return abs(ask[i].first-co[j].first)+co[j].second;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("in_all.txt", "r", stdin);
    freopen("out_all.txt", "w", stdout);
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> co[i].first >> co[i].second;
    for(int i=1;i<=q;i++){
    	cin >> ask[i].first, ask[i].second=i;
    	ans[i]={1e18, -1e18};
	}
    sort(co+1, co+n+1);
    sort(ask+1, ask+q+1);
    int j=1,idx=1, id2=1;
    for(int i=1;i<=q;i++){
        while(j<=n && co[j].first<=ask[i].first){
            if(cal(i, idx)>cal(i,j)) idx=j;
            if(cal(i, id2)<cal(i,j)) id2=j;
            ++j;
        }
        ans[ask[i].second].first=min(ans[ask[i].second].first, cal(i, idx));
        ans[ask[i].second].second=max(ans[ask[i].second].second, cal(i, id2));
    }
	j=idx=id2=n;
    for(int i=q;i>=1;--i){
        while(j>=1 && co[j].first>=ask[i].first){
            if(cal(i,idx)>cal(i,j)) idx=j;
            if(cal(i, id2)<cal(i,j)) id2=j;
            --j;
        }
        ans[ask[i].second].first=min(ans[ask[i].second].first, cal(i, idx));
        ans[ask[i].second].second=max(ans[ask[i].second].second, cal(i, id2));
    }
    for(int i=1;i<=q;i++) cout << ans[i].first << " " << ans[i].second << "\n";
    
    return 0;
}
