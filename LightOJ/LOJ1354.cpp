#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

bool solve()
{
  string s, p;
  cin >> s >> p;
  s += '.', p += '.';
  int i = 0, j = 0;
  for(int it = 0 ; it < 4 ; it++){
    int a = 0, b = 0;
    while(s[i] != '.'){
      a = (a * 10 + s[i] - '0');
      i++;
    }
    i++;
    while(p[j] != '.'){
      b = (b * 2 + p[j] - '0');
      j++;
    }
    j++;
    if(a != b)
      return false;
  }
  return true;
}

int main()
{
  int T, tc = 1;
  cin >> T;
  while(T--){
    printf("Case %d: %s\n", tc++, solve() ? "Yes" : "No");
  }
  return 0;
}
