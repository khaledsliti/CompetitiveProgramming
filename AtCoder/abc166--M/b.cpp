// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n, k;
int cnt[100];

int main()
{
  cin >> n >> k;
  for(int i = 0 ; i < k ; i++) {
    int d;
    cin >> d;
    while(d--) {
      int a;
      cin >> a;
      cnt[--a]++;
    }
  }
  int ans = 0;
  for(int i = 0 ; i < n ; i++)
    ans += !cnt[i];
  cout << ans << endl;
  return 0;
}
