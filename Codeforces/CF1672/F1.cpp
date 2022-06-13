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
int arr[N];
int deg[N];

void solve() {
  cin >> n;
  memset(deg, 0, (n + 1) * sizeof(deg[0]));
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    deg[arr[i]]++;
  }
  vector<int> a;
  for(int i = 1; i <= n; i++) {
    if(deg[i]) {
      a.push_back(i);
    }
  }
  vector<vector<int>> nxt(n + 1);
  while(sz(a)) {
    for(int i = 0; i < sz(a); i++) {
      int x = a[i], y = a[(i + 1) % sz(a)];
      nxt[x].push_back(y);
      deg[x]--;
    }
    vector<int> tmp;
    for(int x: a) {
      if(deg[x]) {
        tmp.push_back(x);
      }
    }
    swap(a, tmp);
  }
  for(int i = 0; i < n; i++) {
    cout << nxt[arr[i]].back() << " ";
    nxt[arr[i]].pop_back();
  }
  cout << endl;
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
