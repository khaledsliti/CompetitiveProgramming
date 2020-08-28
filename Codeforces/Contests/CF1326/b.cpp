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
long long b[N], a[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n; i++)
    cin >> b[i];
  long long mx = 0;
  for(int i = 0 ; i < n ; i++) {
    a[i] = b[i] + mx;
    mx = max(a[i], mx);
  }
  for(int i = 0 ; i < n ; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
