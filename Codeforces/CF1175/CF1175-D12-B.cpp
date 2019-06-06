#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  bool good = true;
  stack<pair<long long, int>> st;
  st.push({0, 1});
  for(int i = 0 ; i < n ; i++){
    string s;
    cin >> s;
    if(s == "add"){
      st.top().first++;
    }else if(s == "end"){
      long long cur = st.top().first;
      int t = st.top().second;
      st.pop();
      st.top().first += t * cur;
    }else{
      int x;
      cin >> x;
      st.push({0, x});
    }
    if(st.top().first >= (1LL << 32)){
      good = false;
      break;
    }
  }
  if(good)
    cout << st.top().first << endl;
  else
    cout << "OVERFLOW!!!" << endl;
  return 0;
}
