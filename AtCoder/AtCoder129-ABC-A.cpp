#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int a[3];
  for(int i = 0 ; i < 3 ; i++)
    cin >> a[i];
  sort(a, a + 3);
  cout << a[0] + a[1] << endl;
  return 0;
}
