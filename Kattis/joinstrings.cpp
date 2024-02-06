#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e5+1;
vector<int> res;
string s[N];
int fw[N], bw[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,u,v;
	cin >> n;
	for(int i=0; i<n; i++) cin >> s[i], fw[i]=bw[i]=i;
	for(int i=1; i<n; i++) {
		cin >> u >> v,--u,--v;
		fw[v]=bw[u];
		bw[u]=bw[v];
	}
	int x=bw[v];
	while(x!=fw[x]) {
		res.push_back(x);
		x=fw[x];
	}
	res.push_back(x);
	reverse(res.begin(), res.end());
	for(auto &e:res) cout << s[e];

	return 0;
}
