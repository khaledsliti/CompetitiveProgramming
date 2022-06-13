#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1007;

int n;
char sol[N];

char ask1(int i) {
  cout << "? 1 " << i + 1 << endl;
  char c; cin >> c;
  if(c == '0') {
    exit(0);
  }
  return c;
}

int ask2(int l, int r) {
  cout << "? 2 " << l + 1 << " " << r + 1 << endl;
  int c; cin >> c;
  if(c == 0) {
    exit(0);
  }
  return c;
}

void solve() {
  cin >> n;
  vector<int> last(26, -1);
  for(int i = 0; i < n; i++) {
    vector<int> pos;
    for(int c = 0; c < 26; c++) {
      if(last[c] != -1) {
        pos.push_back(last[c]);
      }
    }
    sort(all(pos));
    // for(int x: pos) cout << x << ", "; cout << endl;
    int low = 0, high = sz(pos) - 1, idx = -1;
    while(low <= high) {
      int mid = (low + high) >> 1;
      if(ask2(pos[mid], i) == sz(pos) - mid) {
        low = mid + 1;
        idx = mid;
      } else {
        high = mid - 1;
      }
    }
    if (idx == -1) {
      sol[i] = ask1(i);
    } else {
      sol[i] = sol[pos[idx]];
    }
    last[sol[i] - 'a'] = i;
  }
  cout << "! ";
  for(int i = 0; i < n; i++) {
    cout << sol[i];
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
