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
ll dp[100005], h[100005];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(12);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> h[i];

	dp[0] = INT_MAX;

	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	}
	cout << dp[n];
	return 0;
}
