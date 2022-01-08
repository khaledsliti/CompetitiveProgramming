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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n; cin >> n;
  if(n >= 42) n += 1;
  string s = to_string(n);
  while(sz(s) < 3) s = "0" + s;
  cout << "AGC" << s << endl;
  return 0;
}
