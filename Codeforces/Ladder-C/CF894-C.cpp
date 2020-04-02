// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1001;

int n;
int a[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> a[i];
  int g = 0;
  for(int i = 1 ; i < n ; i++)
    g = __gcd(g, a[i]);
  if(g % a[0])
    return cout << -1 << endl, 0;
  cout << 2 * n - 1 << endl;
  cout << a[0] << " ";
  for(int i = 1 ; i < n ; i++)
    cout << a[i] << " " << a[0] << " ";
  cout << endl;
  return 0;
}
