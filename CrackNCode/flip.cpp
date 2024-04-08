#define __USE_MINGW_ANSI_STDIO 0
#include<stdio.h>

int qs[100002],a[6],mp[10];

int cmp(int &x, int &y){
	if((x==8 && y==8) || (x==1 && y==1) || (x==0 && y==0) || (x==6 && y==9) || (x==9 && y==6)) return 1;
	return 0;
}

int main(){
	int q,l,r; scanf("%d", &q);
	mp[1]=mp[0]=mp[8]=1;
	for(int i=1;i<=100000;i++){
		int sz=0,t=i;
		while(t){
			a[sz++]=t%10;
			t/=10;
		}
		int ok=1;
		for(int j=0;j<sz/2;j++){
			if(!cmp(a[j], a[sz-j-1])){
				ok=0;
				break;
			}
		}
		if(sz&1 && !mp[a[sz/2]]) ok=0;
		if(ok) qs[i]++;
		qs[i]+=qs[i-1];
	}
	while(q--){
		scanf("%d%d",&l, &r);
		printf("%d\n",qs[r]-qs[l-1]);
	}
}
