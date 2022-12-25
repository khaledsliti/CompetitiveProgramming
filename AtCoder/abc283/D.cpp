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

const int N = 3e5 + 5;
const int A = 26;

string s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s;
  stack<int> st, a;
  set<char> box;

  for(int i = 0; i < sz(s); i++) {
    if(s[i] == '(') {
      st.push(i);
      continue;
    }
    if(s[i] == ')') {
      int left = st.top();
      st.pop();
      while(sz(a) && a.top() >= left) {
        box.erase(s[a.top()]);
        a.pop();
      }
      continue;
    }
    if(box.find(s[i]) != box.end()) {
      cout << "No" << endl;
      return 0;
    }
    box.insert(s[i]);
    a.push(i);
  }
  cout << "Yes" << endl;
  return 0;
}
