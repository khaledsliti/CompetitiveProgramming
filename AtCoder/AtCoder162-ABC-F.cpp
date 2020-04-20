// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 200010;

int n;
long long p[N], s[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    cin >> p[i];
    s[i] = p[i];
  }
  for(int i = 2 ; i < n ; i++)
    p[i] += p[i - 2];
  for(int i = n - 3 ; i >= 0 ; i--)
    s[i] += s[i + 2];
  if(n & 1) {
    long long best = -1e18;
    for(int i = 0 ; i < n ; i += 2) {
      long long left = 0;
      if(i > 0) left = p[i - 1];
      if(i > 1) left = max(left, p[i - 2]);
      long long right = 0;
      if(i + 1 < n) right = s[i + 1];
      if(i + 2 < n) right = max(right, s[i + 2]);
      best = max(best, left + right);
    }
    cout << best << endl;
  } else {
    cout << max(s[0], s[1]) << endl;
  }
  return 0;
}
