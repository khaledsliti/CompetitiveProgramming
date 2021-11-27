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
long long k;
string s;
vector<int> v;

struct Bag {
  int items = 0, total = 0;
  long long cost = 0;
  deque<int> dq;
  void addRight(int size) {
    cost += 1LL * size * (items + 1);
    dq.push_back(size);
    items++;
    total += size;
  }
  void addLeft(int size) {
    cost += total + size;
    dq.push_front(size);
    items++;
    total += size;
  }
  void removeLeft() {
    int size = dq.front();
    dq.pop_front();
    total -= size;
    items--;
    cost -= total + size;
  }
  void removeRight() {
    int size = dq.back();
    dq.pop_back();
    cost -= 1LL * size * items;
    items--;
    total -= size;
  }
};

bool check(int length) {
  if(length == 1) {
    for(int i = 0; i < sz(v); i++) {
      if(v[i] <= length) {
        return true;
      }
    }
    return false;
  }
  Bag left, right;
  for(int i = 0; i < length / 2; i++) {
    left.addRight(v[i]);
  }
  for(int i = length - 1; i >= length / 2; i--) {
    right.addRight(v[i]);
  }
  if(left.cost + right.cost <= k) {
    return true;
  }
  int j = length / 2;
  for(int i = length; i < sz(v); i++) {
    left.removeLeft();
    left.addRight(v[j++]);
    right.removeRight();
    right.addLeft(v[i]);
    if(left.cost + right.cost <= k) {
      return true;
    }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s >> k;
  n = sz(s);
  int i = 0;
  while(i < n && s[i] == '.') {
    i++;
  }
  if(i >= n) {
    cout << 0 << endl;
    return 0;
  }
  while(i < n) {
    int j = i + 1;
    while(j < n && s[j] == '.') {
      j++;
    }
    if(j < n) {
      v.push_back(j - i - 1);
    }
    i = j;
  }
  int low = 1, high = sz(v), ans = 1;
  while(low <= high) {
    int mid = (low + high) >> 1;
    if(check(mid)) {
      ans = mid + 1;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
