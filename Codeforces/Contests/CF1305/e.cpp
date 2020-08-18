// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 5010;

int n, m;
int ans[N];

int main()
{
  cin >> n >> m;
  int rem = m;
  for(int i = 0 ; i < n ; i++) {
    int now = i >> 1;
    if(rem > now) {
      ans[i] = i + 1;
      rem -= now;
    } else {
      int cur = 2 * i + 1 - 2 * rem;
      ans[i] = cur;
      cur = 2 * cur + 1;
      for(int j = i + 1; j < n; j++, cur += 5002)
        ans[j] = cur;
      rem = 0;
      break;
    }
  }
  if(rem > 0)
    return cout << -1 << endl, 0;
  for(int i = 0 ; i < n ; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
