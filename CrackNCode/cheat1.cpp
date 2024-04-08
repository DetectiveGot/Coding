#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << #x << ": " << x << " "

using namespace std;

const int N = 1e6+2;
ll qs[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q,l,r,s,ed; cin >> n >> q;
    ll ans=1e18;
    for(int i=2;i<=n;i++) cin >> qs[i], qs[i]+=qs[i-1];
    while(q--){
        cin >> l >> r;
        if(l==r){
            cout << "0\n";
            continue;
        }
        ++l;
        ans=1e18;
        s=l, ed=r;
        while(l<r){
            int mid = (l+r+1)/2;
            if(qs[mid-1]-qs[s-1]<=qs[ed]-qs[mid-1]) l=mid;
            else r=mid-1;
        }
        ans=max(qs[l-1]-qs[s-1], qs[ed]-qs[l-1]);
        ans=min(ans, max(qs[l]-qs[s-1], qs[ed]-qs[l]));
        cout << ans << "\n";
    }
    
    return 0;
}
