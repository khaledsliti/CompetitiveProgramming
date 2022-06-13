#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 2e5 + 5;

int n;
int a[N], b[N];
vector<int> pos_a[N], pos_b[N];

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  multiset<int> s;
  int j = n - 1, i = n - 1;
  while(i >= 0 && j >= 0) {
    if(a[i] == b[j]) {
      i--, j--;
    } else if(j + 1 < n && b[j + 1] == b[j]) {
      s.insert(b[j]);
      j--;
    } else if(s.find(a[i]) != s.end()) {
      s.erase(s.find(a[i]));
      i--;
    } else {
      break;
    }
  } 
  while(i >= 0 && s.find(a[i]) != s.end()) {
    s.erase(s.find(a[i]));
    i--;
  }
  if(i >= 0 || j >= 0 || sz(s) > 0) cout << "NO" << endl;
  else cout << "YES" << endl;
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
