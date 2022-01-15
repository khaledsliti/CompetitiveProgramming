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

int add(int a, int b, int c) {
  return a * 100 + b * 10 + c;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  char a, b, c;
  cin >> a >> b >> c;
  a -= '0', b -= '0', c -= '0';
  cout << add(a, b, c) + add(b, c, a) + add(c, a, b) << endl;

  return 0;
}
