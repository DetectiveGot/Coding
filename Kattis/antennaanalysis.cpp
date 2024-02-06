#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 4e5+1;
ll a[N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    ll mx1=LLONG_MIN,mx2=LLONG_MIN,c;
    int n; cin >> n >> c;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ll x=-a[i]+c*i,y=a[i]+c*i;
        mx1=max(mx1, x);
        mx2=max(mx2, y);
        cout << max(a[i]-c*i+mx1,-a[i]-c*i+mx2)
    }

    return 0;
}
