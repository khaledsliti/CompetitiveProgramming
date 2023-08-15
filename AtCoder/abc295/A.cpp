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

vector<string> a {
  "you",
  "and",
  "not",
  "the",
  "that",
};

bool ok(string b) {
  for(auto& x : a) {
    if(x == b) {
      return true;
    }
  }
  return false;
}

int main()
{
  int n;
  cin >> n;
  int ans = false;
  for(int i = 0; i <n ;i++) {
    string a;
    cin >> a;
    if(ok(a)) {
      ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
