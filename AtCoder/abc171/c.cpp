// We only fail when we stop trying
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
  ll n;
  cin >> n;
  string s = "";
  while(n > 0) {
    n--;
    s += char('a' + n % 26);
    n /= 26;
  }
  reverse(all(s));
  cout << s << endl;
  return 0;
}
