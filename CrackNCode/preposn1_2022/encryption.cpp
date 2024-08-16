#include<stdio.h>
#define ll long long

int a[20];

int main(){
	int q=5,sz=0;
	ll ans=0,tmp=0,t;
	while(q--){
		ans=sz=0;
		tmp=0;
		scanf("%lld", &t);
		while(t){
			a[sz++]=t%2;
			t>>=1;
		}
		a[sz]=0;
		for(int i=0;i<sz;i++){
			if(a[i]==1){
				if(tmp==0) tmp=1;
				else tmp=(tmp<<1)|1;
			}
			if(a[i+1]==0) ans+=tmp, tmp=0;
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}