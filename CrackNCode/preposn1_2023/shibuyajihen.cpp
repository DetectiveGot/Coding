#include<stdio.h>

int main(){
	int n; scanf("%d", &n);
	int x=2*n-1;
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if(j==0 || j==x-1 || (j>=0 && j<x && i==j)) printf("#");
//			else if(j==x+1) printf("#");
//			else if(i==0 && ((j>x+3 && j<=2*x+2) || (j>2*x+4 && j<=3*x+3))) printf("#");
//			else if(i==x-1 && ((j>=x+3 && j<=2*x+1) || (j>=2*x+4 && j<=3*x+2))) printf("#");
//			else if(i==n-1 && ((j>x+3 && j<2*x+2) || (j>2*x+4 && j<3*x+3))) printf("#");
//			else if(i && i<n-1 && (j==x+3 || j==2*x+4)) printf("#");
//			else if(i<x-1 && i>x-n && (j==2*x+2 || j==3*x+3)) printf("#");
//			else if(i==0 && j>x*3+5 && j<=4*x+3) printf("#");
//			else if(i && (j==3*x+5 || j==4*x+4)) printf("#");
//			else if(i==n-1 && j>3*x+5 && j<4*x+4) printf("#");
//			else if(j==4*x+6 || j==5*x+5) printf("#");
//			else if(i==j-(4*x+6)) printf("#");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}