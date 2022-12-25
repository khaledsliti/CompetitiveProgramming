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

struct E{
  int a, b, idx;
};

int main()
{
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<E> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i].a;
    arr[i].idx = i;
  }
  for(int i = 0; i < n; i++) {
    cin >> arr[i].b;
  }

  vector<int> sol;
  
  sort(all(arr), [&](E a, E b) {
    if(a.a != b.a) {
      return a.a > b.a;
    }
    return a.idx < b.idx;
  });
  vector<E> tmp;
  for(int i = 0; i < sz(arr); i++) {
    if(i < x) {
      sol.push_back(arr[i].idx);
    } else {
      tmp.push_back(arr[i]);
    }
  }
  arr = tmp;
  tmp.clear();

  sort(all(arr), [&](E a, E b) {
    if(a.b != b.b) {
      return a.b > b.b;
    }
    return a.idx < b.idx;
  });
  for(int i = 0; i < sz(arr); i++) {
    if(i < y) {
      sol.push_back(arr[i].idx);
    } else {
      tmp.push_back(arr[i]);
    }
  }
  arr = tmp;
  tmp.clear();

  sort(all(arr), [&](E a, E b) {
    if(a.a + a.b != b.a + b.b) {
      return a.a + a.b > b.a + b.b;
    }
    return a.idx < b.idx;
  });
  
  for(int i = 0; i < sz(arr); i++) {
    if(i < z) {
      sol.push_back(arr[i].idx);
    } else {
      tmp.push_back(arr[i]);
    }
  }

  sort(all(sol));
  for(int x: sol) {
    cout << x + 1 << endl;
  }
  return 0;
}
