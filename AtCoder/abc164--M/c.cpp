// We only fail when we stop trying
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
  int T;
  cin >> T;
  set<string> st;
  while(T--) {
    string s; cin >> s;
    st.insert(s);
  }
  cout << st.size() << endl;
  return 0;
}
