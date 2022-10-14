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
  long long a[3];
  for(int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  sort(a, a + 3);
  if(a[2] - a[1] > a[0]) {
    cout << -1 << endl;
    return 0;
  }
  long long ans = a[2] - a[1];
  a[0] -= ans;
  a[2] -= ans;
  ans += a[2];
  cout << ans << endl;
  return 0;
}
