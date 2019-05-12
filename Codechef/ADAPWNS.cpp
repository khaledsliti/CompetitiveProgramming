/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://www.codechef.com/COOK102B/problems/ADAPWNS

  Idea:
    https://discuss.codechef.com/problems/ADAPWNS

  Compexity:
    Time: O(N)
    Memory: O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;

int main()
{
  int T;
  cin >> T;
  while(T--){
    string s;
    cin >> s;
    vector<int> v;
    int cnt = 0;
    for(int i = 0 ; i < sz(s) ; i++)
      if(s[i] == 'P')
        v.push_back(cnt), cnt = 0;
      else
        cnt++;
    int ans = 0;
    for(int i = sz(v) - 1 ; i >= 0 ; i -= 2)
      ans ^= v[i] % 3;
    cout << (ans ? "Yes" : "No") << endl;
  }
  return 0;
}