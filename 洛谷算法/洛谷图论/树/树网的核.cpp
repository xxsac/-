#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct edge {
  int v, w;
};
const int N = 3e5 + 9;
vector<edge> e[N];
int dep[N], f[N], c;
int dia[N], cnt, pres[N], posts[N];
bool vis[N];
int n, s;

void dfs(int u, int fa) {
  f[u] = fa;
  for (auto ed : e[u]) {
    if (ed.v == fa || vis[ed.v]) continue;
    dep[ed.v] = dep[u] + ed.w;
    if (dep[ed.v] > dep[c]) c = ed.v;
    dfs(ed.v, u);
  }
}

void get_diameter() {
  dfs(1, 0);
  dep[c] = 0;
  dfs(c, 0);
  for (int u = c; u; u = f[u]) {
    dia[++cnt] = u;
    pres[cnt] = dep[u];
  }
  reverse(dia + 1, dia + cnt + 1);
  reverse(pres + 1, pres + cnt + 1);
  for (int i = cnt; i > 0; i--) posts[i] = pres[cnt] - pres[i];
}

void solve() {
  for (int i = 1; i <= cnt; i++) vis[dia[i]] = true;
  int maxd = 0;
  for (int i = 1; i <= cnt; i++) {
    dep[dia[i]] = 0, c = 0;
    dfs(dia[i], 0);
    maxd = max(dep[c], maxd);
  }
  int l = 1, r = 1;
  int minecc = 1 << 30;
  for (; l <= cnt; l++) {
    while (r <= cnt && pres[r + 1] - pres[l] <= s) r++;
    minecc = min(max(maxd, max(pres[l], posts[r])), minecc);
  }
  cout << minecc << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  get_diameter();
  solve();
  return 0;
}
