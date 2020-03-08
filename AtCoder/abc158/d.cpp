// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

string s;
int q;
deque<char> dq;


int main()
{
  cin >> s;
  for(auto c : s)
    dq.push_back(c);
  int rev = 0;
  cin >> q;
  while(q--) {
    int t; 
    cin >> t;
    if(t == 1) {
      rev ^= 1;
    } else {
      int f;
      char c;
      cin >> f >> c;
      --f;
      if(rev) f ^= 1;
      if(f == 0)
        dq.push_front(c);
      else
        dq.push_back(c);
    }
  }
  string r = "";
  for(auto c : dq)
    r += c;
  if(rev)
    reverse(all(r));
  cout << r << endl;
  return 0;
}
