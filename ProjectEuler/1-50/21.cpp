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

const int N = 1000000;

int d[N];

int main()
{
  for(int i = 1; i < N; i++)
    for(int j = 2 * i; j < N; j += i)
      d[j] += i;
  int ans = 0;
  for(int i = 1 ; i < 10000 ; i++)
    if(d[d[i]] == i && d[i] != i)
      ans += i;
  cout << ans << endl;
  return 0;
}
