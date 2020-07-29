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

const int N = 1e6 + 5;

int n, m, k;
int a[N];

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  int cur_sum = 0;
  int ans = 0;
  for(int i = 1; i < N; i++) {
    cur_sum += a[i];
    if(i - m > 0) cur_sum -= a[i - m];
    while(cur_sum >= k) {
      a[i]--;
      ans++;
      cur_sum--;
    }
  }
  cout << ans << endl;
  return 0;
}
