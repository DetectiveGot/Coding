#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T,null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<int> s;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc,n,t; cin >> tc;
	while(tc--){
	    cin >> n;
	    ll ans=0,add;
	    for(int i=1;i<=n;i++){
	        cin >> t;
	        s.insert(t);
	        if(i&1) add=*s.find_by_order(i-1>>1);
	        else add=(*s.find_by_order(i-1>>1)+*s.find_by_order(i>>1))>>1;
	        ans+=add;
	    }
	    cout << ans << "\n";
	    s.clear();
	}
	
	return 0;
}