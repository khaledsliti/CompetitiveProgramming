#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

string s, t;
vector<int> pos[26];

void init()
{
  for(int i = 0 ; i < 26 ; i++)
    pos[i].clear();
  for(int i = 0 ; i < sz(s) ; i++){
    pos[s[i] - 'a'].pb(i);
  }
}

int get_from(int cursor, int d)
{
  int idx = lower_bound(begin(pos[d]), end(pos[d]), cursor) - begin(pos[d]);
  if(idx < sz(pos[d]))
    return pos[d][idx];
  return sz(s);
}

int solve()
{
  int res = 1;
  int cursor = 0;
  for(int i = 0 ; i < sz(t) ; i++){
    int cur = t[i] - 'a';
    cursor = get_from(cursor, cur);
    if(cursor < sz(s)){
      cursor++;
    }else{
      res++;
      cursor = 0;
      cursor = get_from(cursor, cur);
      if(cursor >= sz(s))
        return -1;
      cursor++;
    }
  }
  return res;
}

int main()
{
  int ts;
  cin >> ts;
  while(ts--){
    cin >> s >> t;
    init();
    cout << solve() << endl;
  }
  return 0;
}
