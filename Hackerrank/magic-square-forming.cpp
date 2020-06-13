// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int n = 3;
int mat[n][n];

int get(vector<int>& p, int i, int j) {
  return p[i * n + j];
}

bool isMagic(vector<int>& p) {
  int r[n], c[n];
  for(int i = 0; i < n; i++)
    r[i] = c[i] = 0;
  int d = 0, a = 0;
  for(int i = 0; i < n; i++) {
    d += get(p, i, i);
    a += get(p, i, 2 - i);
    for(int j = 0; j < n; j++) {
      r[i] += get(p, i, j);
      c[j] += get(p, i, j);
    }
  }
  if(d != a) return false;
  for(int i = 0; i < n; i++)
    if(r[i] != d || c[i] != d)
      return false;
  return true;
}

int main()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> mat[i][j];
  vector<int> p(n * n);
  iota(all(p), 1);
  int best = 1e9;
  do {
    if(!isMagic(p))
      continue;
    int cost = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cost += abs(mat[i][j] - p[i * n + j]);
      }
    }
    best = min(best, cost);
  } while(next_permutation(all(p)));
  cout << best << endl;
  return 0;
}
