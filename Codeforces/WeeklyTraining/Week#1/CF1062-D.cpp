// We only fail when we stop trying
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

int n;
int par[N];
ll cost[N];

int fs(int x) {
  return x == par[x] ? x : par[x] = fs(par[x]);
}

void add_edge(int a, int b, int c) {
  a = fs(a), b = fs(b);
  if(a != b) {
    par[b] = a;
    cost[a] += cost[b];
  }
  cost[b] += c;
}

int main()
{
  cin >> n;
  for(int i = 2; i < n; i++) {
    for(int j = 2 * i; j <= n; j += i) {
      add_edge(2 * i, 2 * j, j / i);
      add_edge(2 * i, 2 * j + 1, j / i);
      add_edge(2 * i + 1, 2 * j, j / i);
      add_edge(2 * i + 1, 2 * j + 1, j / i);
    }
  }
  ll best = 0;
  for(int i = 2; i <= 2 * n; i++)
    best = max(best, cost[fs(i)]);
  cout << best << endl;
  return 0;
}
