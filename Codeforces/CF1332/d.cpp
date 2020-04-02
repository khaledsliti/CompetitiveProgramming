// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()



int main()
{
  int k;
  cin >> k;
  int n = 0;
  while((1 << n) <= k) n++;
  n = (1 << n);
  cout << "2 3\n";
  cout << (n | k) << " " << k << " " << n << endl;
  cout << n << " " << (n | k) << " " << k << endl;
  return 0;
}
