#include<stdio.h>

char s[14];

int main(){
	int q,n,x=0; scanf("%d", &q);
	while(q--){
		scanf("%s", s);
		x=0;
		for(int i=0;i<12;i++) x+=(14-i-1)*(s[i]-'0');
		x%=11;
		x=11-x;
		x+=11;
		x%=11;
		x%=10;
		if(x==s[12]-'0') printf("Y\n");
		else printf("N\n");
	}
	
	return 0;
}