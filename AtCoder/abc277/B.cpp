// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 100;

int main()
{
  int n; cin >> n;
  int ok = 1;
  set<string> st;
  string a = "HDCS";
  string b = "A23456789TJQK";
  auto in = [](string s, char c) -> bool {
    for(char a : s) {
      if(a == c) {
        return true;
      }
    }
    return false;
  };
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    if(st.find(s) != st.end()) {
      ok = 0;
    }
    st.insert(s);
    if(!in(a, s[0]) || !in(b, s[1])) {
      ok = 0;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
