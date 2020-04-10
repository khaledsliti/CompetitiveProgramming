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
  for(int i = 1 ; i <= n ; i++)
    scanf("%d", arr + i);
  long long sum = 0;
  map<long long, int> last;
  last[0] = 0;
  int st = 1;
  long long ans = 0;
  for(int i = 1 ; i <= n ; i++) {
    sum += arr[i];
    if(last.count(sum)) {
      int l = last[sum] + 1;
      if(l >= st) {
        ans += 1LL * (l - st + 1) * (n - i + 1);
        st = l + 1;
      }
    }
    last[sum] = i;
  }
  cout << 1LL * n * (n + 1) / 2 - ans << endl;
  return 0;
}
