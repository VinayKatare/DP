#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define all(a)                      a.begin(), a.end()
#define pb                          push_back
#define ll							long long
#define index(a)            		order_of_key(a)
#define value(a)					find_by_order(a)
#define count_1 					__builtin_popcount
#define mod(x, m)					((((x) % (m)) + (m)) % (m))
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
vector<int> v[1000000];
bool visited[1000000];
int maxd[1000000];

int dfs(int u){
	visited[u]=true;
	if(v[u].size()==0)maxd[u]=0;
	for(int x:v[u]){
		if(!visited[x]){
			maxd[u]=max(maxd[u],dfs(x)+1);
		}
		else maxd[u]=max(maxd[u],1+maxd[x]);
	}
	return maxd[u];
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout<<setprecision(12);
	int n,m,x,y;
	cin>>n>>m;
	fill(maxd+1,maxd+n+1,INT_MIN);
	for(int i=0;i<m;i++){
		cin>>x>>y;
		v[x].pb(y);
	}

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	int ans=INT_MIN;
	for(int i=1;i<=n;i++)ans=max(ans,maxd[i]);
	cout<<ans;
	return 0;
}
