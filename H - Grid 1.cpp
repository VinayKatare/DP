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
int mat[1005][1005];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout<<setprecision(12);
	int n,m;
	cin>>n>>m;
	string s[n];
	for(int i=0;i<n;i++)cin>>s[i];

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1][j-1]=='#')mat[i][j]=0;
			else if(i==1 && j==1)mat[i][j]=1;
			else
			mat[i][j]=(mat[i-1][j]+mat[i][j-1])%int(1e9+7);
		}
	}

	cout<<mat[n][m];
	return 0;
}
