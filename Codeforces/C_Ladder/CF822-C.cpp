// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;
const int oo = 2e9 + 5;

struct item {
  int l, r, cost;
};

int n, x;
vector<item> v[N];

int solve(vector<item>& A, vector<item>& B) {
  sort(all(A), [](const item& a, const item& b) {
    return a.r > b.r;
  });
  sort(all(B), [](const item& a, const item& b) {
    return a.l > b.l;
  });
  int j = 0;
  int mn = oo;
  int best = oo;
  for(int i = 0 ; i < sz(A) ; i++) {
    while(j < sz(B) && B[j].l > A[i].r) {
      mn = min(mn, B[j].cost);
      j++;
    }
    if(j)
      best = min(best, A[i].cost + mn);
  }
  return best;
}

int main()
{
  cin >> n >> x;
  for(int i = 0 ; i < n ; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    v[r - l + 1].pb({l, r, c});
  }
  int best = oo;
  for(int a = 1 ; a < x ; a++) {
    best = min(best, solve(v[a], v[x - a]));
  }
  if(best >= oo) best = -1;
  cout << best << endl;
  return 0;
}
