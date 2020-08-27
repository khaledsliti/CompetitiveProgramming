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

const int N = 1e5 + 5;

int n, len;
int a[N];
double pr[N];
int min_pr[N];
int ansL, ansR;

bool check(double d) {
  for(int i = 0; i <= n; i++) {
    pr[i] = a[i] - d;
    if(i > 0) pr[i] += pr[i - 1];
    min_pr[i] = i;
    if(i > 0 && pr[min_pr[i - 1]] < pr[i]) {
      min_pr[i] = min_pr[i - 1];
    }
    if(i - len + 1 >= 0 && pr[i] >= 0) {
      ansL = 0;
      ansR = i;
      return true;
    }
    if(i - len >= 0 && pr[min_pr[i - len]] <= pr[i]) {
      ansL = min_pr[i - len] + 1;
      ansR = i;
      return true;
    }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> len;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  double l = 0, r = 100.0;
  for(int it = 0; it < 100; it++) {
    double mid = (l + r) / 2.0;
    if(check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  check((l + r) / 2.0);
  cout << ansL + 1 << " " << ansR + 1 << endl;
  return 0;
}
