#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 10;

int n;
string s[N];
unordered_set<string> ex;
map<string, vector<int>> pos;

void getNotUsed(int idx)
{
  string& cur = s[idx];
  for(int d = 0 ; d < 4 ; d++){
    for(int c = 0 ; c < 10 ; c++){
      string newOne = cur;
      newOne[d] = char('0' + c);
      if(ex.find(newOne) == ex.end()){
        ex.insert(newOne);
        cur = newOne;
        return;
      }
    }
  }
}

int main()
{
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    pos.clear();
    ex.clear();
    for(int i = 0 ; i < n ;i ++){
      cin >> s[i];
      ex.insert(s[i]);
      pos[s[i]].push_back(i);
    }
    int ans = 0;
    for(auto& str : pos){
      vector<int>& v = str.second;
      ans += sz(v) - 1;
      for(int i = 1 ; i < sz(v) ; i++){
        getNotUsed(v[i]);
      }
    }
    cout << ans << endl;
    for(int i = 0 ; i < n ; i++)
      cout << s[i] << endl;
  }
  return 0;
}
 