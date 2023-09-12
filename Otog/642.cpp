#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define deb(x) cout << "[" << #x << ": " << x << "] "
#define N (int)2e4+2
#define mod (int)1e7
#define p 31
#define mxN (int)1e7+2

using namespace std;

char a[N];
bool hsh[mxN];

int main(){
	int n,sz;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s", a);
		sz=strlen(a);
		ll hs=0;
		for(int j=0;j<sz;j++){
			if(a[j]=='A') a[j]='T';
			else if(a[j]=='T') a[j]='A';
			else if(a[j]=='C') a[j]='G';
			else if(a[j]=='G') a[j]='C';
			hs=hs*p%mod+a[j]-'A';
			hs%=mod;
		}
		hsh[hs]=1;
	}
	while(scanf("%s", &a)==1){
		sz=strlen(a);
		ll hs=0;
		for(int j=0;j<sz;j++){
			hs=hs*p%mod+a[j]-'A';
			hs%=mod;
		}
		if(hsh[hs]) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
/*
DNA:
ATCGACTC
ACTCCGAT
ASK:
TGAGGCTA -> YES

*/
