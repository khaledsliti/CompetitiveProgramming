// Guess Who's Back
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

const int N = 1e5 + 5;

int n;
int arr[N];

bool check(int k) {
  for(int i = 0; i < n; i++) {
    int last = i > 0 ? arr[i - 1] : 0;
    int need = arr[i] - last;
    if(need > k) {
      return false;
    }
    if(need == k) {
      k--;
    }
  }
  return true;
}

void solve(int tc) {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int lo = 1, hi = arr[n - 1], ans;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  printf("Case %d: %d\n", tc, ans);
}

int main()
{
  int T;
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    solve(tc);
  }
  return 0;
}
