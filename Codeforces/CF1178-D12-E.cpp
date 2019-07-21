#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 5;

int n;
string s;
bool taken[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  n = sz(s);
  int l = 0, r = n - 1;
  while(l <= r){
    if(s[l] == s[r]){
      taken[l] = taken[r] = 1;
      --r;
      ++l;
    }else if(l < r - 1 && s[l] == s[r - 1]){
      taken[l] = taken[r - 1] = 1;
      r -= 2;
      ++l;
    }else if(l + 1 < r && s[l + 1] == s[r]){
      taken[l + 1] = taken[r] = 1;
      r--;
      l += 2;
    }else if(l + 1 < r - 1 && s[l + 1] == s[r - 1]){
      taken[l + 1] = taken[r - 1] = 1;
      r -= 2;
      l += 2;
    }else{
      taken[l] = 1;
      break;
    }
  }
  string res = "";
  for(int i = 0 ; i < n ; i++)
    if(taken[i])
      res.push_back(s[i]);
  cout << res << endl;
  return 0;
}
