#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 1e6+1;
int qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	qs[1]=1;
	for(int i=2;i<N;i++){
		int s=i;
		while(s!=1 && s!=4){
			int t = s;
			s=0;
			while(t) s+=(t%10)*(t%10), t/=10;
		}
		if(s==1) ++qs[i];
		qs[i]+=qs[i-1];
	}
	while(tc--){
		int a,b; cin >> a >> b;
		cout << qs[b]-qs[a-1] << "\n";
	}

	return 0;
}

