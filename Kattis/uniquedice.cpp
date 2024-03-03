#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

map<array<int, 6>, bool> mp;
enum dice {
	top, bot, fr, bk, lt, rt
};
int op[6];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,ans=0; cin >> n;
	op[top]=bot, op[bot]=top;
	op[fr]=bk, op[bk]=fr;
	op[lt]=rt, op[rt]=lt;
	for(int i=0;i<n;i++){
		array<int, 6> ar;
		for(int j=0;j<6;j++) cin >> ar[j];
		bool ok=true;
		if(mp.count(ar)){
			ok=false;
			continue;
		}
		for(int j=0;j<6;j++){
			array<int, 6> tmp = ar;
			int pv = -1;
			for(int k=0;k<6;k++){
				if(op[j]==k || k==j) continue;
				if(pv==-1) pv=k;
				swap(ar[pv], ar[k]);
				pv=k;
			}
			if(mp.count(tmp)){
				ok=false;
				break;
			}
		}
		if(ok) ++ans;
	}
	cout << ans;

	return 0;
}

