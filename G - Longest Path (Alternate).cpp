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

int in_degree[100005], dist[100005];
vector<int> v[100005];
bool visited[100005];

void dfs(int u) {
	visited[u] = true;

	for (auto x : v[u]) {
		dist[x] = max(dist[x], 1 + dist[u]);
		in_degree[x]--;
		if (in_degree[x] == 0) {
			dfs(x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(12);
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].pb(y);
		in_degree[y]++;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i] && in_degree[i] == 0) {
			dfs(i);
		}
	}
	int ans = -1;
	for (int i = 1; i <= n; i++)ans = max(ans, dist[i]);
	cout << ans;
	return 0;
}
