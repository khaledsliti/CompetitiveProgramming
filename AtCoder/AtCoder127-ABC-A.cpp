#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;

int main()
{
  int a, b;
  cin >> a >> b;
  if(a >= 13)
    cout << b << endl;
  else if(a >= 6)
    cout << b / 2 << endl;
  else 
    cout << 0 << endl;
  return 0;
}