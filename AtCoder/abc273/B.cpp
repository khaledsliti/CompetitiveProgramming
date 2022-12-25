// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;



int main()
{
  long long x, k;
  cin >> x >> k;
  for(int i = 0; i < k; i++) {
    x = round(x / 10.0);
  }
  for(int i = 0; i < k; i++) {
    x *= 10;
  }
  cout << x << endl;
  return 0;
}
