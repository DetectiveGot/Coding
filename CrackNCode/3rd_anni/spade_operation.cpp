#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pii pair<int,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "]"

using namespace std;
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+1, mxN = 3001, mod = 1e9+7;
ll dp[2][mxN];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    ll ans = 0;
    int r = n-1;
    for(int i=1;i<=n;i++){
        auto it = find(a.begin(), a.end(), i);
        int p = it-a.begin();
        ans+=min(p, r-p);
        a.erase(it);
        --r;
    }
    cout << ans << "\n";
    auto add = [&](ll &x, ll y) -> void {
        x+=y;
        if(x>=mod) x-=mod;
    };
    auto sub = [&](ll &x, ll y) -> void {
        x-=y;
        if(x<0) x+=mod;
    };
    dp[1][0]=1;
    for(int i=2;i<=n;i++){
        int mid = (i-1)/2;
        vector<ll> qs(ans+1);
        memset(dp[i&1], 0, sizeof(ll)*(ans+1));
        for(int j=0;j<=ans;j++){
            add(qs[j], dp[i&1^1][j]*2%mod);
            if(j+mid<=ans) sub(qs[j+mid], dp[i&1^1][j]*2%mod);
            if(j) add(qs[j], qs[j-1]);
            if(i&1){
                if(j-mid>=0) add(dp[i&1][j], dp[i&1^1][j-mid]);
            } else {
                if(j-mid>=0) add(dp[i&1][j], dp[i&1^1][j-mid]*2%mod);
            }
            add(dp[i&1][j], qs[j]);
        }
        // for(int j=0;j<=ans;j++){
        //     if(i&1) {
        //         if(j-mid>=0) dp[i&1][j]+=dp[i&1^1][j-mid], dp[i&1][j]%=mod;
        //     } else {
        //         if(j-mid>=0) dp[i&1][j]+=dp[i&1^1][j-mid]*2%mod, dp[i&1][j]%=mod;
        //     }
        //     for(int k=0;k<mid;k++){
        //         if(j-k>=0) dp[i&1][j]+=dp[i&1^1][j-k]*2%mod;
        //         dp[i&1][j]%=mod;
        //     }
        // }
    }
    cout << dp[n&1][ans];

    return 0;
}