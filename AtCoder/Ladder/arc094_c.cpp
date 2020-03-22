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
int a[N], b[N];

int main()
{
  cin >> n;
  bool same = true;
  int mnb = 1e9 + 5;
  long long sum = 0;
  for(int i = 0 ; i < n ; i++) {
    cin >> a[i] >> b[i];
    same &= a[i] == b[i];
    if(a[i] > b[i]) mnb = min(mnb, b[i]);
    sum += a[i];
  }
  if(same) return cout << 0 << endl, 0;
  cout << sum - mnb << endl;
  return 0;
}
