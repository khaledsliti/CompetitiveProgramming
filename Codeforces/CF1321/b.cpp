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

int main()
{
  scanf("%d", &n);
  map<int, long long> cnt;
  long long ans = 0;
  for(int i = 0 ; i < n ; i++){
    scanf("%d", arr + i);
    int cur = i + 1 - arr[i];
    cnt[cur] += arr[i];
    ans = max(ans, cnt[cur]);
  }
  cout << ans << endl;
  return 0;
}
