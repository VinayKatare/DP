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
int dp[3003][3003];
string a,b,ans="";

void pr(int i,int j){
	if(i<=0 || j<=0)return ;
	
	if(a[i-1]==b[j-1]){
		ans=a[i-1]+ans;
		pr(i-1,j-1);
	}
	else if(dp[i-1][j] > dp[i][j-1]){
		pr(i-1,j);
	}
	else pr(i,j-1);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>a>>b;
	
	for(int i=0;i<=a.size();i++){
		for(int j=0;j<=b.size();j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}
			else if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	pr(a.size(),b.size());
	
	cout<<ans;
	return 0;
}
