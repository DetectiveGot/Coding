#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) x.begin(), x.end()
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 27, mxN = 5e5+1;
string sr[mxN];
vector<int> dp;
struct DATA{
	int x,u;
	bool operator < (const DATA &dt) const{
		if(x==dt.x) return u<dt.u;
		return x>dt.x;
	}
};

struct Aho {
	int next[N];
	bool out = false;
	int val = 0, idx = 0;
	Aho(int val=0, int idx=0) : val(val), idx(idx){
		fill(begin(next), end(next), -1);
	};
};
vector<Aho> ah(1);

inline void insert(string &s, int va, int p){
	int u=0;
	for(auto &e:s){
		int c=e-'A';
		if(e==' ') c=26;
		if(ah[u].next[c]==-1){
			ah[u].next[c]=ah.size();
			ah.emplace_back(va, p);
		}
		u=ah[u].next[c];
	}
	ah[u].out=true;
}

inline void search(int uu){
	priority_queue<DATA> pq;
	queue<int> q;
	q.push(uu);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(ah[u].out){
			pq.push({ah[u].val, ah[u].idx});
			if(pq.size()>3) pq.pop();
		}
		for(int i=0;i<=26;i++){
			if(ah[u].next[i]!=-1){
				int v=ah[u].next[i];
				q.push(v);
			}
		}
	}
	stack<int> ss;
	if(pq.empty()) cout << "N/A\n";
	else {
		while(!pq.empty()) ss.push(pq.top().u), pq.pop();
		while(!ss.empty()){
			cout << sr[ss.top()] << "\n";
			ss.pop();
		}
	}
}

inline void dfs(int u){
	if(ah[u].out) dp[u]=1;
	for(int i=0;i<=26;i++){
		if(ah[u].next[i]!=-1){
			int v = ah[u].next[i];
			dfs(v);
			dp[u]+=dp[v];
		}
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n; cin >> n;
	cin.ignore();
	for(int i=0;i<n;i++){
		getline(cin, sr[i]);
		string t="";
		int j=0, va=0;
		while(j<sr[i].size() && sr[i][j]!=',') t+=sr[i][j], ++j;
		++j;
		for(j;j<sr[i].size();j++) va=va*10+sr[i][j]-'0';
		insert(t, va, i);
	}
	dp.resize(ah.size());
	dfs(0);
	string s;
	int q; cin >> q;
	cin.ignore();
	while(q--){
		getline(cin, s);
		cout << s << "\n";
		for(auto &e:s) if(e>='a' && e<='z') e-='z'-'Z';
		int st=0;
		bool ok=true;
		for(auto &e:s){
			int c=e-'A';
			if(e==' ') c=26;
			if(ah[st].next[c]!=-1) st=ah[st].next[c];
			else {
				ok=false;
				break;
			}
		}
		if(!ok){
			cout << "N/A\n";
			continue;
		}
		if(dp[st]>1000){
			cout << dp[st] << "\n";
			continue;
		}
		search(st);
	}

	return 0;
}
/*
7
BANGKOK,71
BEIJING,72
LOMBARDY,65
LONDON,78
LOS ANGELES,80
LOUVRE,65
ZURICH,70
4
Ban
London
Lo
y
*/
