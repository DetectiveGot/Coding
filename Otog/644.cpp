#include<stdio.h>
#define ll long long
#define N (int)35
#define mod 10000019
#define p 4
#define mxN 10000021

char a[N];
ll hsh[mxN], ch[1000001],mp[257];;

int main(){
	int n,q,len,sz; scanf("%d%d%d",&n,&q,&len);
	ll hs=0,x=0;
    mp['A']=0;
    mp['T']=1;
    mp['C']=2;
    mp['G']=3;
	for(int i=1;i<=n;i++){
		scanf("%s", a);
		hs=0, x=0;
		for(int j=0;j<len;j++){
			if(a[j]=='A') a[j]='T';
			else if(a[j]=='T') a[j]='A';
			else if(a[j]=='C') a[j]='G';
			else if(a[j]=='G') a[j]='C';
			hs=hs*p+mp[a[j]];
		}
		x=hs;
		hs%=mod;
		int fnd=1;
		while(hsh[hs]){
			if(ch[hsh[hs]]==x){
				fnd=0;
				break;
			}
			++hs;
			hs%=mod;
		}
		if(fnd) hsh[hs]=i,ch[i]=x;
	}
	while(q--){
		scanf("%s", a);
		hs=0,x=0;
		int fnd=0;
		for(int i=0;i<len;i++) hs=hs*p+mp[a[i]];
		x=hs;
		hs%=mod;
		while(hsh[hs]){
    		if(ch[hsh[hs]]==x){
				printf("YES\n");
    			fnd=1;
				break;
			}
			++hs;
			hs%=mod;
		}
		if(!fnd) printf("NO\n");
	}
	
	return 0;
}


// https://cp-algorithms.com/string/string-hashing.html

