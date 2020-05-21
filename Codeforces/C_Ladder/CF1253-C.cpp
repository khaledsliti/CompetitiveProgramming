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

int n, m;
int arr[N];
long long pref[N];
long long ans[N];

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", arr + i);
  }
  sort(arr, arr + n);
  for(int i = 0 ; i < n ; i++) {
    pref[i] = arr[i];
    if(i) pref[i] += pref[i - 1];
  }
  for(int i = 0 ; i < n ; i++) {
    ans[i] = pref[i] - (i - m >= 0 ? pref[i - m] : 0);
    if(i - m >= 0)
      ans[i] += ans[i - m] + pref[i - m];
  }
  for(int i = 0 ; i < n ; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
