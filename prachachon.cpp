#include<stdio.h>

char s[13];

int main(){
	int q,n,x=0; scanf("%d", &q);
	while(q--){
		scanf("%s", s);
		x=0;
		for(int i=1;i<13;i++) x+=(14-i)*(s[i-1]-'0'), x%=11;
		x=11-x;
		x%=10;
		if(x==s[12]-'0') printf("Y\n");
		else printf("N\n");
	}
	
	return 0;
}
