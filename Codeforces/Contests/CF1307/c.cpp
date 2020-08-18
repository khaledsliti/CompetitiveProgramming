#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5, A = 26;

int n;
string s;
int fr[A];
long long occ[A][A];

long long solve(int a, int b)
{
  int cnt = 0;
  long long ans = 0;
  for(int i = 0 ; i < sz(s) ; i++){
    if(s[i] - 'a' == b){
      ans += cnt;
    }
    if(s[i] - 'a' == a){
      cnt++;
    }
  }
  return ans;
}

int main()
{
  cin >> s;
  n = sz(s);
  long long best = 1;
  for(int i = 0 ; i < sz(s) ; i++){
    best = max((int)best, ++fr[s[i] - 'a']);
  }
  for(int i = 0 ; i < A ; i++){
    for(int j = 0 ; j < A ; j++){
      best = max(best, solve(i, j));
    }
  }
  cout << best << endl;
  return 0;
}
