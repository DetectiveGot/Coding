#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+2;
bool a[N];
int ans[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,c=1; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==0) continue;
		if(a[i]==1){
			ans[i]=c++;
			if(i+1<=n) a[i+1]=!a[i+1];
			int x=i-1;
			while(x>=1 && !ans[x]){
				ans[x]=c++;
				x--;
			}
		}
	}
	int x=n;
	while(x>=1 && !ans[x]) ans[x]=c++, --x;
	for(int i=1;i<=n;i++) cout << ans[i] << " ";
	
	return 0;
}