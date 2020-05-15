// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main()
{
  vector<int> p {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for(int it = 1; it < 1000000; it++) {
    next_permutation(all(p));
  }
  for(int i = 0; i < sz(p); i++)
    cout << p[i];
  cout << endl;
  return 0;
}
