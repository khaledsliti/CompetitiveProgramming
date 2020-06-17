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

const int N = 2e5 + 5;

int n, k;
int x[N];
multiset<int> a, b;
ll sum_a, sum_b;

void maintain() {
  if(sz(a) < sz(b)) {
    sum_a += *b.begin();
    sum_b -= *b.begin();
    a.insert(*b.begin());
    b.erase(b.begin());
  } else if(sz(a) > sz(b) + 1) {
    sum_a -= *a.rbegin();
    sum_b += *a.rbegin();
    b.insert(*a.rbegin());
    a.erase(a.find(*a.rbegin()));
  }
}

void add(int i) {
  if(sz(a) && x[i] <= *a.rbegin()) {
    a.insert(x[i]);
    sum_a += x[i];
  } else {
    b.insert(x[i]);
    sum_b += x[i];
  }
  maintain();
}

void del(int i) {
  auto it = a.find(x[i]);
  if(it != a.end()) {
    a.erase(it);
    sum_a -= x[i];
  } else {
    b.erase(b.find(x[i]));
    sum_b -= x[i];
  }
  maintain();
}

void print() {
  ll mid = *a.rbegin();
  ll ans = mid * sz(a) - sum_a + sum_b - mid * sz(b);
  cout << ans << " ";
}

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sum_a = sum_b = 0;
  for(int i = 0; i < k; i++) {
    add(i);
  }
  print();
  for(int i = k; i < n; i++) {
    del(i - k);
    add(i);
    print();
  }
  return 0;
}
