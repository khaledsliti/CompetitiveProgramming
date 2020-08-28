#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
int par[N];
vector<int> contains[26];

int fs(int x)
{
  return x == par[x] ? x : par[x] = fs(par[x]);
}

void us(int a, int b)
{
  a = fs(a);
  b = fs(b);
  if(a != b)
    par[b] = a;
}

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    string s;
    cin >> s;
    sort(all(s));
    for(int j = 0 ; j < sz(s) ; j++)
      if(j == 0 || s[j] != s[j - 1])
        contains[s[j] - 'a'].push_back(i);
  }
  for(int i = 0 ; i < n ; i++)
    par[i] = i;
  for(int i = 0 ; i < 26 ; i++){
    for(int j = 0 ; j < sz(contains[i]) - 1 ; j++){
      us(contains[i][j], contains[i][j + 1]);
    }
  }
  int ans = 0;
  for(int i = 0 ; i < n ; i++)
    if(fs(i) == i)
      ++ans;
  cout << ans << endl;
  return 0;
}
