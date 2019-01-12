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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	ll h[n+1],dp[n+1];
	for(int i=1;i<=n;i++){cin>>h[i];dp[i]=INT_MAX;}
	dp[1]=0;
	dp[0]=INT_MAX;
	
	for(int i=2;i<=n;i++){
		ll m=INT_MAX;
		for(int j=1;j<=k;j++){
			if(i-j>=0)
			m=min(m,dp[i-j]+abs(h[i]-h[i-j]));
		}
		dp[i]=m;
	}
//	for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
	cout<<dp[n];
	return 0;
}
