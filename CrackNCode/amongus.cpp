#define __USE_MINGW_ANSI_STDIO 0
#include<stdio.h>

int main(){
	int q; scanf("%d", &q);
	while(q--){
		int n; scanf("%d", &n);
		int p=n>>1;
		if(n%4==1){
			for(int i=1;i<=n/4;i++){
				for(int r=0;r<2;r++){
					for(int j=1;j<=n/4-i+1;j++) printf(".");
					for(int j=1;j<=2*i-1;j++) printf("#");
					for(int j=1;j<=n/4-i+r;j++) printf(".");
				}
				printf("\n");
			}
			for(int i=0;i<=n/2;i++){
				for(int j=1;j<=n;j++){
					if(j>=i+1 && j<=n-i) printf("#");
					else printf(".");
				}
				printf("\n");
			}
		} else {
			for(int i=1;i<=n/4;i++){
				for(int r=0;r<2;r++){
					for(int j=1;j<=n/4-i+1;j++) printf(".");
					for(int j=1;j<=2*i;j++) printf("#");
					for(int j=1;j<=n/4-i+r;j++) printf(".");
				}
				printf("\n");
			}
			for(int i=0;i<=n/2;i++){
				for(int j=1;j<=n;j++){
					if(j>=i+1 && j<=n-i) printf("#");
					else printf(".");
				}
				printf("\n");
			}
		}
	}
	
	return 0;
}
