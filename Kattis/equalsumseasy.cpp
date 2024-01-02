#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 21;
int a[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc,cs=0,n,s; cin >> tc;
	while(tc--){
		cout << "Case #" << ++cs << ":\n";
		map<int, vector<int>> mp;
		bool ok=false;
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		sort(a, a+n);
		for(int i=1;i<1<<n;i++){
			vector<int> v;
			s=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					v.push_back(a[j]);
					s+=a[j];
				}
			}
			if(mp.count(s) && mp[s]!=v){
				for(auto &e:mp[s]) cout << e << " "; cout << "\n";
				for(auto &e:v) cout << e << " "; cout << "\n";
				ok=true;
				break;
			} else mp[s]=v;
		}
		if(!ok) cout << "impossible\n";
	}
	
	return 0;
}
