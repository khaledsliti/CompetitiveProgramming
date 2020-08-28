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

const int N = 1001;

int n, k;
int arr[N][N];
int calls = 0;
int ans[N];

int askPos(vector<int> v) {
  assert(++calls <= 12);
  cout << "? " << sz(v);
  for(int i = 0; i < sz(v); i++)
    cout << " " << v[i] + 1;
  cout << endl;
  cout.flush();
  int r; cin >> r;
  return r;
}

int askRange(int st, int en) {
  vector<int> v(en - st + 1);
  iota(begin(v), end(v), st);
  return askPos(v);
}

void solve() {
  calls = 0;
  cin >> n >> k;
  for(int i = 0; i < k; i++) {
    int c; cin >> c;
    for(int j = 0; j < n; j++)
      arr[i][j] = 1;
    while(c--) {
      int a;
      cin >> a;
      arr[i][--a] = 0;
    }
  }
  int mx = askRange(0, n - 1);
  int l = 0, r = n - 1;
  while(l < r) {
    int mid = (l + r) / 2;
    if(askRange(l, mid) == mx) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  assert(l == r);
  int mx_idx = l;
  for(int i = 0; i < k; i++) {
    if(arr[i][mx_idx]) ans[i] = mx;
    else {
      vector<int> pos;
      for(int j = 0; j < n; j++)
        if(arr[i][j])
          pos.push_back(j);
      ans[i] = askPos(pos);
    }
  }
  cout << "!";
  for(int i = 0; i < k; i++)
    cout << " " << ans[i];
  cout << endl;
  cout.flush();
  string correct;
  cin >> correct;
  assert(correct == "Correct");
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
