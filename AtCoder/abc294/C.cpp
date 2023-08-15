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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  vector<int> c;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c.push_back(a[i]);
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
    c.push_back(b[j]);
  }

  sort(all(c));
  for (int i = 0; i < n; i++) {
    cout << lower_bound(all(c), a[i]) - begin(c) + 1 << " ";
  }
  cout << endl;
  for (int i = 0; i < m; i++) {
    cout << lower_bound(all(c), b[i]) - begin(c) + 1 << " ";
  }
  cout << endl;
  return 0;

}
