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

int n;

int main()
{
  cin >> n;
  if(n % 4 != 0 && n % 4 != 3) {
    cout << "NO" << endl;
    return 0;
  }
  vector<int> a, b;
  int st = 1;
  if(n % 4 == 3) {
    a.push_back(1);
    a.push_back(2);
    b.push_back(3);
    st = 4;
  }
  for(int i = st; i + 3 <= n; i += 4) {
    a.push_back(i);
    a.push_back(i + 3);
    b.push_back(i + 1);
    b.push_back(i + 2);
  }
  cout << "YES" << endl;
  cout << sz(a) << endl;
  for(int i = 0; i < sz(a); i++)
    cout << a[i] << " ";
  cout << endl;
  cout << sz(b) << endl;
  for(int i = 0; i < sz(b); i++)
    cout << b[i] << " ";
  cout << endl;
  return 0;
}
