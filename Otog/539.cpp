#include<bits/stdc++.h>

using namespace std;

const int N = 3e5+1;
int a[N], pos[N];

int main(){
	int t,x,n,l1,l2; scanf("%d", &t);
	while(t--){
		cin >> n >> l1 >> l2;
		for(int i=1;i<=l1;i++) scanf("%d", &a[i]), pos[a[i]]=i;
		vector<int> v;
		for(int i=1;i<=l2;i++){
			scanf("%d", &x);
			if(!pos[x]) continue;
			auto it = lower_bound(v.begin(), v.end(), pos[x]);
			if(it==v.end()) v.push_back(pos[x]);
			else *it = pos[x];
		}
		printf("%d\n",v.size());
		memset(pos,0,sizeof(pos));
	}
	
	return 0;
}
