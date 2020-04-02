// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 100003;

int n, k;
int arr[N];
map<long long, int> cnt;

int main()
{
  scanf("%d%d", &n, &k);
  for(int i = 0 ; i < n ; i++)
    scanf("%d", arr + i);
  vector<long long> values;
  if(k == 1) values.pb(1);
  else if(k == -1) values.pb(1), values.pb(-1);
  else {
    long long cur = 1;
    while(llabs(cur) <= 1e15) {
      values.pb(cur);
      cur *= k;
    }
  }
  long long ans = 0;
  long long sum = 0;
  cnt[0] = 1;
  for(int i = 0 ; i < n ; i++) {
    sum += arr[i];
    for(auto& v : values)
      if(cnt.count(sum - v))
        ans += cnt[sum - v];
    cnt[sum]++;
  }
  cout << ans << endl;
  return 0;
}
