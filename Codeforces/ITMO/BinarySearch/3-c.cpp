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

const int N = 1e5 + 5;

int n, k;
int a[N];

bool check(int minLen) {
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt++;
    int j = i + 1;
    while(j < n && a[j] - a[i] < minLen)
      j++;
    i = j - 1;
  }
  return cnt >= k;
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int lo = 0, hi = 1e9, best = 0;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) {
      best = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << best << endl;
  return 0;
}
