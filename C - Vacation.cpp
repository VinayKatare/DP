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

int a[100005][3], dp[100005][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(12);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)for (int j = 0; j < 3; j++)cin >> a[i][j];
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dp[i][0] = a[i][0];
			dp[i][1] = a[i][1];
			dp[i][2] = a[i][2];
			continue;
		}
		dp[i][0] = a[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = a[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = a[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << max({ dp[n - 1][0],dp[n - 1][1],dp[n - 1][2] });
	return 0;
}
