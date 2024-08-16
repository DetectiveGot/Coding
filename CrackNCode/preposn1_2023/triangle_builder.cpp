#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	ll ans=0;
	for(int x1=0;x1<=n;x1++){
		for(int x2=0;x2<=n;x2++){
			for(int x3=0;x3<=n;x3++){
				for(int y1=0;y1<=m;y1++){
					for(int y2=0;y2<=m;y2++){
						for(int y3=0;y3<=m;y3++){
							if((x1==x2 && y1==y2) || (x1==x3 && y1==y3) || (x2==x3 && y2==y3)) continue;
							if((x1==x2 && x2==x3 && y1==y2 && y2==y3)) continue;
							ll tmp = abs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1);
							ans+=tmp;
						}
					}
				}
			}
		}
	}
	cout << ans/6;
	
	return 0;
}