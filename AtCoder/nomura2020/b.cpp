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

string s;

int main()
{
  cin >> s;
  for(int i = 0; i < sz(s); i++)
    if(s[i] == '?')
      s[i] = 'D';
  cout << s << endl;
  return 0;
}
