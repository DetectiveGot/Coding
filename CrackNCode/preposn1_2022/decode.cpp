#define __USE_MINGW_ANSI_STDIO 0
#include<stdio.h>
#include<string.h>
#define ll long long

ll dp[1000002][9], qs[1000002][9], mod = 1e9+7;
char s[15];

int main(){
	int q; scanf("%d", &q);
	scanf("%s", s);
	int hs=0,fr=1,n=strlen(s);
	for(int j=0;j<3;j++){
		hs=(hs<<1)+s[j]-'0';
		fr<<=1;
	}
	dp[0][hs]++;
	for(int j=3;j<n;j++){
		hs=(hs<<1)+s[j]-'0';
		hs-=fr*(s[j-3]-'0');
		dp[0][hs]++;
	}
	for(int i=0;i<8;i++) qs[0][i]=dp[0][i];
	for(int i=1;i<=1000000;i++){
		for(int j=0;j<8;j++){
			dp[i][j]=(qs[i-1][j]<<1)%mod;
		}
		if(i&1){
			int cal = (s[n-2]-'0')*4+(s[n-1]-'0')*2;
			dp[i][cal]++;
			cal = (s[n-1]-'0')*4+s[0]-'0';
			dp[i][cal]++;
			cal = (s[0]-'0')*2+s[1]-'0';
			dp[i][cal]++;
			
		} else {
			int cal = (s[n-2]-'0')*4+(s[n-1]-'0')*2+1;
			dp[i][cal]++;
			cal = (s[n-1]-'0')*4+2+s[0]-'0';
			dp[i][cal]++;
			cal = 4+(s[0]-'0')*2+s[1]-'0';
			dp[i][cal]++;
		}
		for(int j=0;j<8;j++){
			dp[i][j]%=mod;
			qs[i][j]=qs[i-1][j]+dp[i][j];
			qs[i][j]%=mod;
		}
		int cal = (s[n-2]-'0')*4+(s[n-1]-'0')*2+s[0]-'0';
		qs[i][cal]++;
		cal = (s[n-1]-'0')*4+(s[0]-'0')*2+s[1]-'0';
		qs[i][cal]++;
		for(int j=0;j<8;j++) qs[i][j]%=mod;
	}
	while(q--){
		int t; scanf("%d", &t);
		for(int i=0;i<8;i++) printf("%lld ", dp[t][i]);
		printf("\n");
	}
	
	return 0;
}
