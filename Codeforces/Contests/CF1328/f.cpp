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

int n, k;
int arr[N];
long long pre[N];

long long get(int a, int b) {
  if(a > b) return 0;
  return pre[b] - (a > 0 ? pre[a - 1] : 0);
}

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", arr + i);
  }
  sort(arr, arr + n);
  for(int i = 0 ; i < n ; i++)
    pre[i] = arr[i] + (i > 0 ? pre[i - 1] : 0);
  long long best = 1e18;
  for(int i = 0 ; i < n ; i++) {
    int j = i;
    while(j < n && arr[i] == arr[j]) ++j;
    j--;
    int len = j - i + 1;
    if(len >= k)
      best = 0;
    else {
      int rem = k - len;
      int left = i;
      int right = n - j - 1;
      long long shift_left = 1LL * left * (arr[i] - 1) - get(0, i - 1);
      long long shift_right = get(j + 1, n - 1) - 1LL * right * (arr[i] + 1);
      // left first
      if(rem > left) {
        long long cost = shift_left + shift_right + rem;
        best = min(best, cost);
      } else {
        long long cost = shift_left + rem;
        best = min(best, cost);
      }
      if(rem > right) {
        long long cost = shift_right + shift_left + rem;
        best = min(best, cost);
      } else {
        long long cost = shift_right + rem;
        best = min(best, cost);
      }
    }
    i = j;
  }
  cout << best << endl;
  return 0;
}
