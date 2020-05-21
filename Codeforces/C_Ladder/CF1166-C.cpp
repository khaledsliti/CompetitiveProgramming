// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
int arr[N];

int calc(int a, int b) {
  return lower_bound(arr, arr + n, b + 1) - lower_bound(arr, arr + n, a);
}

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  sort(arr, arr + n);
  long long ans = 0;
  for(int i = 0 ; i < n ; i++) {
    if(arr[i]) {
      int c = (abs(arr[i]) + 1) / 2;
      ans += calc(-2 * abs(arr[i]), -c) + calc(c, 2 * abs(arr[i])) - 1;
    } else {
      ans += calc(0, 0) - 1;
    }
  }
  cout << ans / 2 << endl;
  return 0;
}
