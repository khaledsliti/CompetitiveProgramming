// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, x;
int arr[N];

void solve() {
  scanf("%d%d", &n, &x);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", arr + i);
  }
  sort(arr, arr + n);
  reverse(arr, arr + n);
  long long sum = 0;
  int best = 0;
  for(int i = 0 ; i < n ; i++) {
    sum += arr[i];
    if(sum >= 1LL * (i + 1) * x)
      best = i + 1;
  }
  printf("%d\n", best);
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
  return 0;
}
