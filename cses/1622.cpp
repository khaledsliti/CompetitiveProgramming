// We only fail when we stop trying
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



int main()
{
  string s;
  cin >> s;
  sort(all(s));
  vector<string> sol;
  do {
    sol.push_back(s);
  } while(next_permutation(all(s)));
  cout << sz(sol) << endl;
  for(auto s: sol)
    cout << s << endl;
  return 0;
}
