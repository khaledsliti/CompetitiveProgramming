#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 101;

int n, m;
string s[N];
bool taken[N];

bool isPal(string s)
{
  for(int i = 0 ; i < sz(s) / 2 ; i++){
    if(s[i] != s[sz(s) - 1 - i])
      return false;
  }
  return true;
}

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
    cin >> s[i];
  vector<pair<int, int>> v;
  string a = "", b = "";
  for(int i = 0 ; i < n ; i++){
    for(int j = i + 1 ; j < n ; j++)
      if(isPal(s[i] + s[j])){
        v.pb({i, j});
        a += s[i];
        string tmp = s[j]; reverse(all(tmp));
        b += tmp;
        taken[i] = taken[j] = 1;
      }
  }
  reverse(all(b));
  string c = "";
  for(int i = 0 ; i < n ; i++)
    if(isPal(s[i]) && !taken[i]){
      c = s[i];
      break;
    }
  cout << sz(a) + sz(b) + sz(c) << endl;
  cout << a << c << b << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity