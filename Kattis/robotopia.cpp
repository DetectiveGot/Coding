#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int tc; cin >> tc;
	while(tc--){
		ll a1,b1,a2,b2,k,m,x=0,y=0; cin >> a1 >> b1 >> a2 >> b2 >> k >> m;
		int cnt=0;
		for(int i=1;i<=10000;i++){
			if(k-a1*i<=0 || m-b1*i<=0) break;
			if(cnt>1) break;
			if((k-a1*i)%a2==0 && (m-b1*i)%b2==0)
				if((k-a1*i)/a2 == (m-b1*i)/b2) x=i,y=(k-a1*i)/a2,++cnt;
		}
		if(cnt==1) cout << x << " " << y << "\n";
		else cout << "?\n";
	}

	return 0;
}

