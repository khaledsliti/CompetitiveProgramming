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

const int N = 105;

int n;
int a[N], b[N];

bool check() {
  for (int i = 0; i < n - 1; i++) {
    if (a[i] <= a[n - 1] && b[i] <= b[n - 1]) {
      continue;
    }
    swap(a[i], b[i]);
    if (a[i] <= a[n - 1] && b[i] <= b[n - 1]) {
      continue;
    }
    return false;
  }
  return true;
}

void Solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (check()) {
    cout << "Yes" << endl;
    return;
  }
  swap(a[n - 1], b[n - 1]);
  if (check()) {
    cout << "Yes" << endl;
    return;
  }
  cout << "No" << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    Solve();
  }
  return 0;
}
