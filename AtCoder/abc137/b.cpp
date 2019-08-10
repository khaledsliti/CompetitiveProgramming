#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5;

int main()
{
  int k, x;
  cin >> k >> x;
  for(int i = max(-N, x - k + 1); i <= min(N, x + k - 1) ; i++)
    cout << i << " ";
  cout << endl;
  return 0;
}
