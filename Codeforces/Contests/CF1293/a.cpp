#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1005;

int n, k, s;
int f[N];

int solve()
{
  int ans = 1e9;
  for(int i = 0 ; i <= k ; i++){
    int st = f[i] + 1, en = f[i + 1] - 1;
    if(st <= en){
      // D(st); D(en);
      if(st <= s && s <= en)
        return 0;
      ans = min(ans, min(abs(s - st), abs(s - en)));
    }
  }
  return ans;
}

int main()
{
  int tc;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d%d%d", &n, &s, &k);
    f[0] = 0;
    for(int i = 1 ; i <= k ; i++)
      scanf("%d", f + i);
    f[k + 1] = n + 1;
    sort(f, f + k + 2);
    cout << solve() << endl;
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity