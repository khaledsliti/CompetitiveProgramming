#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main()
{
  int n;
  cin >> n;
  string s; cin >> s;
  int a = 0, b = 0;
  for(int i = 0 ; i < n ; i++){
    if(s[i] == 'L') a++;
    else b--;
  }
  cout << a - b + 1 << endl;
  return 0;
}
