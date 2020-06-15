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

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(all(a));
  vector<int> b(m);
  for(int i = 0; i < m; i++) 
    cin >> b[i];
  sort(all(b));
  int ans = 0, i = 0, j = 0;
  while(i < n && j < m) {
    if(b[j] >= a[i] - k && b[j] <= a[i] + k) {
      ans++;
      i++;
      j++;
    } else if(a[i] + k < b[j]) {
      i++;
    } else {
      j++;
    }
  }
  cout << ans << endl;
  return 0;
}
