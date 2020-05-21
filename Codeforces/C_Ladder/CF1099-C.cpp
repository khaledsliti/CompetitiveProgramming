#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


int main()
{
  string s;
  int k;
  cin >> s >> k;
  vector<pair<pair<int, int>, char>> q;
  string p = "";
  for(int i = 0 ; i < sz(s) ; i++){
    if(s[i] == '?'){
      q.pb({{sz(p) - 1, 1}, p.back()});
      p.pop_back();
    }else if(s[i] == '*'){
      q.pb({{sz(p) - 1, 2}, p.back()});
      p.pop_back();
    }else{
      p.push_back(s[i]);
    }
  }
  int need = k - sz(p);
  if(need < 0){
    cout << "Impossible" << endl;
    return 0;
  }
  reverse(all(q));
  string sol = "";
  for(int i = 0 ; i <= sz(p) ; i++){
    while(need > 0 && sz(q) && q.back().first.first == i){
      need--;
      sol += q.back().second;
      if(q.back().first.second == 1)
        q.pop_back();
    }
    if(i < sz(p))
      sol += p[i];
  }
  if(need > 0)
    cout << "Impossible" << endl;
  else
    cout << sol << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity