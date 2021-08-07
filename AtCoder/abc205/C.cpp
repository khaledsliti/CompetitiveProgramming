// Guess Who's Back
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
  int a, b, c;
  cin >> a >> b >> c;
  if(c % 2 == 0) a = abs(a), b = abs(b);
  if(a == b) {
    cout << "=" << endl;
    return 0;
  }
  if(a < b) cout << "<" << endl;
  else cout << ">" << endl;
  return 0;
}
