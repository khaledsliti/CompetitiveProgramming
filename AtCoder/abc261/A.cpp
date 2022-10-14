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



int main()
{
  pair<int, int> a, b;
  cin >> a.first >> a.second >> b.first >> b.second;
  if(a.first > b.first) {
    swap(a, b);
  }
  if(b.first <= a.second) {
    int r = min(a.second, b.second);
    cout << r - b.first << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
