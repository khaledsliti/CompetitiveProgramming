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
  int x;
  cin >> x;
  long long a = x / 500;
  long long b = (x % 500)  / 5;
  cout << a * 1000 + b * 5 << endl;
  return 0;
}
