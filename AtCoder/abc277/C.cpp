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

const int N = 2e5 + 5;

int n;
map<int, int> mx;

int find(int a) {
  if(mx.count(a) == 0) {
    mx[a] = a;
  }
  if(mx[a] == a) {
    return a;
  }
  return mx[a] = find(mx[a]);
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    a = find(a);
    b = find(b);
    if(a > b) {
      swap(a, b);
    }
    mx[a] = b;
  }
  cout << find(1) << endl;
  return 0;
}
