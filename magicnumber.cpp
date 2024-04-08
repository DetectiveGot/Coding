#define __USE_MINGW_ANSI_STDIO 0
#include<stdio.h>
#define mxN 15486000
#define N 1000001
#define ll long long

int p[mxN], a[N], c=0;

int main(){
  for(int i=2;i<=(int)1000000;i++){
    if(p[i]) continue;
    for(int j=2*i;j<=(int)16000000;j+=i){
      p[j]++;
    }
    a[c++]=i;
  }
  int q,t; scanf("%d", &q);
  while(q--){
    scanf("%d", &t);
    --t;
    printf("%lld\n", 1LL*a[t]*a[t]);
  }
  return 0;
}
