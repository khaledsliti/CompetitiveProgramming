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

bool check(int a, int b) {
  int cnt[10];
  memset(cnt, 0, sizeof cnt);
  while(a > 0) {
    cnt[a % 10]++;
    a /= 10;
  }
  while(b > 0) {
    cnt[b % 10]--;
    b /= 10;
  }
  for(int i = 0; i < 10; i++)
    if(cnt[i])
      return false;
  return true;
}

int main()
{
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    bool good = true;
    for(int j = 2; j <= k; j++) {
      good &= check(i, i * j);
    }
    if(good) {
      for(int j = 1; j <= k; j++)
        cout << i * j << " \n"[j == k];
    }
  }
  return 0;
}
