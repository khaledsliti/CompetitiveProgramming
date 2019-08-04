#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  int n;
  cin >> n;
  int a;
  cin >> a;
  a = max(1, a - 1);
  for(int i = 0 ; i < n - 1 ; i++){
    int b;
    cin >> b;
    if(b < a)
      return cout << "No" << endl, 0;
    b = max(a, b - 1);
    a = b;
  }
  cout << "Yes" << endl;
  return 0;
}
