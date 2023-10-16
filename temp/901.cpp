#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define deb(x) cout << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 5e6+1;
ll a[N], ans[N];
stack<pii> st;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	ll res=0,s1=0;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		while(!st.empty() && a[i]<=st.top().first){
			pii tmp = st.top();
			st.pop();
			if(!st.empty()) s1-=tmp.first*(tmp.second-st.top().second);
		}
		if(!st.empty()) s1+=a[i]*(i-st.top().second);
		else s1=a[i]*i;
		st.push({a[i], i});
		ans[i]=s1;
	}
	while(!st.empty()) st.pop();
	s1=0;
	for(ll i=n;i>=1;--i){
		while(!st.empty() && a[i]<=st.top().first){
			pii tmp = st.top();
			st.pop();
			if(!st.empty()) s1-=tmp.first*(st.top().second-tmp.second);
		}
		if(!st.empty()) s1+=a[i]*(st.top().second-i);
		else s1=a[i]*(n-i+1);
		st.push({a[i], i});
		res=max(res, s1-a[i]+ans[i]);
	}
	cout << res;
	
	return 0;
}
