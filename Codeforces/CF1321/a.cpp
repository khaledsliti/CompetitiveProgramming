// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;

int n;
int a[N], b[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> a[i];
  for(int i = 0 ; i < n ; i++)
    cin >> b[i];
  int A = 0, B = 0;
  for(int i = 0 ; i < n ; i++) {
    if(a[i] && !b[i])
      A++;
    else if(!a[i] && b[i])
      B++;
  }
  if(!A)
    return cout << -1 << endl, 0;
  cout << B / A + 1 << endl;
  return 0;
}
