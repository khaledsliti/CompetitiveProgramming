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



void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  auto print = [&]() {
    for(int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  };
  cout << n << endl;
  print();
  swap(a[0], a[1]);
  print();
  for(int i = 2; i < n; i++) {
    swap(a[i - 1], a[i]);
    print();
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
/*
1 2 3 -> 3
2 1 3 -> 1
3 1 2 -> 0

*/