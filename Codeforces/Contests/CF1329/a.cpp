// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, m;
int l[N], ans[N];

int main()
{
  cin >> n >> m;
  long long sum = 0;
  bool good = true;
  for(int i = 0 ; i < m ; i++) {
    cin >> l[i];
    sum += l[i];
    if(i + l[i] > n)
      good = false;
  }
  if(sum < n || !good)
    return cout << -1 << endl, 0;
  int j = n - 1;
  for(int i = m - 1 ; i >= 0 ; i--) {
    int lf = j - l[i] + 1;
    lf = max(lf, i);
    ans[i] = lf + 1;
    j = lf - 1;
  }
  for(int i = 0 ; i < m ; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
