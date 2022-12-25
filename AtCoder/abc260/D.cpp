// RedStone
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

int n, k;
int p[N];
int par[N], siz[N];
vector<int> st[N];
int ans[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }

  memset(ans, -1, sizeof ans);

  set<int> cards;
  for(int i = 0; i < n; i++) {
    auto it = cards.lower_bound(p[i]);
    int idx;
    if(it == cards.end()) {
      cards.insert(p[i]);
      st[p[i]].push_back(p[i]);
      par[p[i]] = p[i];
      idx = p[i];
    } else {
      int parent = par[*it];
      st[parent].push_back(p[i]);
      par[p[i]] = parent;
      idx = parent;
      cards.erase(*it);
      cards.insert(p[i]);
    }
    if(sz(st[idx]) == k) {
      cards.erase(p[i]);
      for(int x: st[idx]) {
        ans[x] = i + 1;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
