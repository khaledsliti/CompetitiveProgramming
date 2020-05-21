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

int n;
int a[N], b[N];

int main()
{
  cin >> n;
  ll sum = 0;
  for(int i = 0; i < n; i++) {
    double d;
    cin >> d;
    a[i] = floor(d);
    sum += a[i];
    b[i] = ((ll)(d * 100000)) % 100000;
  }
  for(int i = 0; i < n && sum; i++) {
    if(b[i]) {
      sum -= a[i];
      a[i] += 1;
      sum += a[i];
    }
  }
  for(int i = 0; i < n; i++)
    cout << a[i] << endl;
  return 0;
}