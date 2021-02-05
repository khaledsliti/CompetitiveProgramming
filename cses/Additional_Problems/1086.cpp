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

const int N = 20;

vector<int> d;
vector<long long> tp;

long long count(long long n) {
  d.clear(); tp.clear();
  while(n > 0) {
    d.push_back(n % 10);
    n /= 10;
  }
  long long t = 1;
  for(int i = 0; i < sz(d); i++) {
    tp.push_back(t);
    t *= 10;
  }
  long long ans = 0;
  for(int i : d) {
    ans += i == 1;
  }
  int sum = 0;
  for(int i = sz(d) - 1; i >= 0; i--) {
    for(int cur = 0; cur < d[i]; cur++) {
      ans += (sum + (cur == 1)) * tp[i] + tp[i - 1] * i;
    }
    if(d[i] == 1) {
      sum++;
    }
  }
  return ans;
}

int main()
{
  long long n;
  cin >> n;
  long long lo = 1, hi = 1e18, best = -1;
  while(lo <= hi) {
    ll mid = (lo + hi) / 2;
    if(count(mid) <= n) {
      best = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << best << endl;
  return 0;
}
