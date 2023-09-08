#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n;
	ll t,h,idx;
	while(cin >> n){
		if(n==0) break;
		stack<pii> st;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin >> t;
			while(!st.empty() && t<st.top().first){
				h=st.top().first, idx=st.top().second;
				st.pop();
				ans=max(ans, h*(st.empty()?i-1: i-1-st.top().second));
//				int area = h*(st.empty()?i-1: i-1-st.top().second);
//				deb(area) << endl;
			}
			st.push({t, i});
		}
		while(!st.empty()){
			h=st.top().first;
			st.pop();
			ans=max(ans, h*(st.empty()?n: n-st.top().second));
//			int area = h*(st.empty()?n: n-st.top().second);
//			cout << "OUT "; deb(area) << endl;
		}
		cout << ans << "\n";
	}
	
	return 0;
}

/*
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0

6
2 4 1 3 3 2
6
3 5 1 7 5 9
7
6 2 5 4 5 1 6
0

ans: 6, 15, 12
*/
