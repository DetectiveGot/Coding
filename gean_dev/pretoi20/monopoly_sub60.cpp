#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pii pair<ll,int>
#define tpi tuple<int,int,int>
#define siz(x) (int)(x.size())
#define deb(x) cerr << "[" << #x << ": " << x << "]"

using namespace std;
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+2;
const ll inf = 1e18;
ll a[N], b[N], dp[N<<1];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=2*n;i++) dp[i]=inf;
    vector<ll> vec{0};
    bool sub = true;
    bool sub6 = true;
    for(int i=1;i<=n;i++){
        sub&=a[i]<=b[i];
        sub6&=a[i]>=b[i];
        vec.push_back(a[i]);
        vec.push_back(b[i]);
    }
    if(sub){ //sub a[i]<=b[i]
        sort(vec.begin(), vec.end());
        partial_sum(vec.begin(), vec.end(), vec.begin());
        int q; cin >> q;
        while(q--){
            ll x; cin >> x;
            cout << upper_bound(vec.begin(), vec.end(), x)-vec.begin()-1 << "\n";
        }
        return 0;
    }
    if(sub6){ //sub a[i]>=b[i] q=1
        int q; cin >> q;
        while(q--){
            ll x; cin >> x;
            vector<pii> v{0};
            vector<ll> qs(n+1);
            for(int i=1;i<=n;i++) v.emplace_back(a[i]+b[i], i);
            sort(v.begin(), v.end());
            for(int i=1;i<=n;i++) qs[i]=qs[i-1]+v[i-1].first;
            int p = upper_bound(qs.begin(), qs.end(), x)-qs.begin()-1;
            x-=qs[p];
            int ans = p*2;
            for(int i=p;i<n;i++){
                if(a[v[i].second]<=x){
                    ans++;
                    break;
                }
            }
            cout << ans << "\n";
        }
        return 0;
    }

    { //need optimization here
        for(int i=1;i<=n;i++){
            for(int j=2*n;j>=1;--j){
                if(j-2>=0) dp[j]=min(dp[j], dp[j-2]+a[i]+b[i]);
                dp[j]=min(dp[j], dp[j-1]+a[i]);
            }
        }
    }
    for(int i=2*n-1;i>=0;--i) dp[i]=min(dp[i], dp[i+1]);
    int q; cin >> q;
    while(q--){
        ll x; cin >> x;
        cout << upper_bound(dp, dp+2*n+1, x)-dp-1 << "\n";
    }

    return 0;
}