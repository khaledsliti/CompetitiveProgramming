#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n;
string s;

bool check(string s)
{
  int sum = 0;
  for(int i = 0 ; i < sz(s) ; i++){
    sum += (s[i] == '(') - (s[i] == ')');
    if(sum < 0)
      return false;
  }
  return sum == 0;
}

int main()
{
  cin >> n >> s;
  if(check(s))
    return cout << "Yes" << endl, 0;
  for(int i = 0 ; i < n ; i++){
    if(s[i] == ')'){
      string p = s.substr(0, i) + s.substr(i + 1, sz(s) - i - 1) + s[i];
      if(check(p))
        return cout << "Yes" << endl, 0;
      break;
    }
  }
  for(int i = n - 1 ; i >= 0 ; i--){
    if(s[i] == '('){
      string p = s[i] + s.substr(0, i) + s.substr(i + 1, sz(s) - i - 1);
      if(check(p))
        return cout << "Yes" << endl, 0;
      break;
    }
  }
  cout << "No" << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity