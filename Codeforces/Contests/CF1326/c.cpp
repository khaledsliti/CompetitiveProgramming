// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int Mod = 998244353;
const int N = 2e5 + 5;

int n, k;
int p[N], v[N];

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", p + i);
  long long ans1 = 0;
  for(int i = 0 ; i < n ; i++) {
    if(p[i] > n - k)
      v[i] = 1, ans1 += p[i];
  }
  long long ans2 = 1;
  int l = 0, r = n - 1;
  while(v[l] == 0) l++;
  while(v[r] == 0) r--;
  for(int i = l ; i < r ; i++) {
    if(v[i] == 0) {
      int j = i;
      while(j < n && v[j] == 0)
        j++;
      int cnt = j - i + 1;
      ans2 = (ans2 * cnt) % Mod;
      i = j;
    }
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
