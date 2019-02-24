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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

ll dp[101][100005], w[100005], c[100005];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(12);

	ll n, C;
	cin >> n >> C;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> c[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= C; j++) {
			if (j < w[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
		}
	}
	cout << dp[n][C];
	return 0;
}
