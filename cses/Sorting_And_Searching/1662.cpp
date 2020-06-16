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

const int N = 2e5 + 5;

int main()
{
  ll ans = 0;
  int n;
  cin >> n;
  map<int, int> cnt;
  cnt[0]++;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int a; 
    cin >> a;
    sum = (sum + a) % n;
    if(sum < 0) sum += n;
    ans += cnt[sum];
    cnt[sum]++;
  }
  cout << ans << endl;
  return 0;
}
