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
 
const int N = 1e6 + 5;
 
int n, s;
int sol[N];
 
int main()
{
  cin >> n >> s;
  if(s <= 2 * n - 1) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for(int i = 0; i < n - 1;i ++)
    cout << "1 ";
  cout << s - n + 1 << endl;
  cout << n << endl;
  return 0;
}