// Guess Who's Back
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;
const int L = 4;
const int INF = 1e9;

int n[4];
vector<vector<int>> g[L];
vector<int> cost[L];

void build_layer(int idx) {
  int n1 = n[idx - 1], n2 = n[idx];
  multiset<int> values;
  for(int i = 0; i < n1; i++) {
    values.insert(cost[idx - 1][i]);
  }
  for(int i = 0; i < n2; i++) {
    for(int j: g[idx][i]) {
      values.erase(values.find(cost[idx - 1][j]));
    }
    if(values.empty() == false) {
      cost[idx][i] += *values.begin();
    } else {
      cost[idx][i] = INF;
    }
    for(int j: g[idx][i]) {
      values.insert(cost[idx - 1][j]);
    }
  }
}

int main()
{
  for(int i = 0; i < L; i++) {
    scanf("%d", &n[i]);
    g[i].resize(n[i]);
  }
  for(int i = 0; i < L; i++) {
    cost[i].resize(n[i]);
    for(int j = 0; j < n[i]; j++) {
      scanf("%d", &cost[i][j]);
    }
  }
  for(int i = 1; i < L; i++) {
    int m; scanf("%d", &m);
    while(m--) {
      int a, b;
      scanf("%d%d", &a, &b);
      g[i][--b].push_back(--a);
    }
  }
  for(int i = 1; i < L; i++) {
    build_layer(i);
  }
  int ans = *min_element(all(cost[L - 1]));
  if(ans >= INF) ans = -1;
  cout << ans << endl;
  return 0;
}
