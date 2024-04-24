#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 3011;
int qs[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int w,h,n,x,a; cin >> w >> h >> n;
	for(int i=1;i<=n;i++){
		cin >> x >> a;
		qs[x]++;
		qs[x+a]--;
	}
	int f=0,hf=0;
	for(int i=0;i<w;i++){
		qs[i+1]+=qs[i];
		if(qs[i]==0) f+=h;
		else if(qs[i]==1) hf+=h;
	}
	cout << f << " " << hf;

	return 0;
}

