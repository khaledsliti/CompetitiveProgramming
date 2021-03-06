// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, k;
string s;
int seen[N];
string a;

int main()
{
  cin >> n >> k >> s;
  for(int i = 0 ; i < sz(s) ; i++) {
    int cur = s[i] - 'a';
    if(seen[cur])
      continue;
    seen[cur] = 1;
    a += s[i];
  }
  sort(all(a));
  if(k > n){
    while(sz(s) < k)
      s += a[0];
    cout << s << endl;
    return 0;
  }
  while(sz(s) > k)
    s.pop_back();
  n = sz(s);
  for(int i = k - 1 ; i >= 0 ; i--) {
    if(s[i] != a.back()){
      int idx = lower_bound(begin(a), end(a), s[i]) - begin(a);
      s[i] = a[++idx];
      for(int j = i + 1 ; j < k ; j++)
        s[j] = a[0];
      cout << s << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
