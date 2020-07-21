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
  int T;
  cin >> T;
  while(T--) {
    string str;
    cin >> str;
    int p = 0, r = 0, s = 0;
    for(auto c: str) {
      if(c == 'R') r++;
      if(c == 'P') p++;
      if(c == 'S') s++;
    }
    char a;
    if(s >= max(p, r)) a = 'R';
    else if(p >= max(s, r)) a = 'S';
    else if(r >= max(p, s)) a = 'P';
    for(int i = 0; i < sz(str); i++)
      cout << a;
    cout << endl;
  }
  return 0;
}
