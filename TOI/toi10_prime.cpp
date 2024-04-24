#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cerr << "[" << #x << ": " << x << "] "

using namespace std;

const int N = 8e6+1;
bool p[N];

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	int n,c=1; cin >> n;
	for(int i=2;i*i<N;i++){
		if(p[i]) continue;
		for(int j=i*i;j<N;j+=i) p[j]=1;
	}
	if(n==1) cout << 2;
	else {
		for(int i=3;i<N;i+=2){
			if(p[i]) continue;
			if(++c==n){
				cout << i;
				return 0;
			}
		}
	}

	return 0;
}

