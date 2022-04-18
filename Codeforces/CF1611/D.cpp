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
int anc[N];
int dist[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> anc[i];
    --anc[i];
  }
  for(int i = 0; i < n; i++) {
    dist[i] = -1;
  }
  int minDist = 1;
  bool first = true, imp = false;
  for(int i = 0; i < n; i++) {
    int a; cin >> a; --a;
    if(first) {
      first = false;
      if(anc[a] != a) {
        imp = true;
      }
      dist[a] = 0;
    } else {
      if(dist[anc[a]] == -1) {
        imp = true;
      }
      dist[a] = max(dist[anc[a]] + 1, minDist);
      minDist = dist[a] + 1;
    }
  }
  if(!imp) {
    for(int i = 0; i < n; i++) {
      cout << dist[i] - dist[anc[i]] << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
