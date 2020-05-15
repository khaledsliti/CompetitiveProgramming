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

const int N = 30000;

int d[N];
int good[N];

int main()
{
  for(int i = 1; i < N; i++)
    for(int j = 2 * i; j < N; j += i)
      d[j] += i;
  vector<int> nums;
  for(int i = 1; i < N; i++) {
    if(d[i] > i)
      nums.push_back(i);
  }

  for(int i = 0; i < sz(nums); i++)
    for(int j = i; j < sz(nums); j++) {
      int cur = nums[i] + nums[j];
      if(cur < N)
        good[cur] = true;
    }
  int ans = 0;
  for(int i = 1; i < N; i++) {
    if(!good[i]) {
      cout << i << endl;
      ans += i;
    }
  }
  cout << ans << endl;

  return 0;
}
