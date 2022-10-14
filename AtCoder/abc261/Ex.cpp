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

template<typename T>
bool maxi(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
bool mini(T& a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}

const int N = 4e5 + 5;

int n, m, start;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> start;
  start--;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
  }
  return 0;
}
