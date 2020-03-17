// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 11;

int n;
int s[N];
vector<string> sol;

void solve(int cur, int last) {
  if(cur >= n) {
    string t = "";
    for(int i = 0 ; i < n ; i++) 
      t += char(s[i] + 'a');
    sol.push_back(t);
    return;
  }
  for(int i = 0 ; i <= last + 1 ; i++) {
    s[cur] = i;
    solve(cur + 1, max(last, i));
  }
}

int main()
{
  cin >> n;
  solve(0, -1);
  for(int i = 0 ; i < sz(sol) ; i++)
    cout << sol[i] <<  endl;
  return 0;
}
