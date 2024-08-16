#define __USE_MINGW_ANSI_STDIO 0
#include<stdio.h>
#define N 15486000
#define ll long long

int p[N], a[N], c=0;

int main(){
  for(int i=2;i<=(int)15485863;i++){
    if(p[i]) continue;
    for(int j=2*i;j<=(int)15485863;j+=i){
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