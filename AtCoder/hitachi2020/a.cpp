// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

string hi = "hi";

int main()
{
  string s;
  cin >> s;
  string t = "hi";
  for(int it = 0 ; it < 10 ; it++) {
    if(s == t){
      cout << "Yes" << endl;
      return 0;
    }
    t += hi;
  }
  cout << "No" << endl;
  return 0;
}
