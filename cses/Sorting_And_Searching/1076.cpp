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

void maintain() {
  if(sz(a) < sz(b)) {
    a.insert(*b.begin());
    b.erase(b.begin());
  } else if(sz(a) > sz(b) + 1) {
    b.insert(*a.rbegin());
    a.erase(a.find(*a.rbegin()));
  }
}

void add(int i) {
  if(sz(a) && x[i] <= *a.rbegin()) {
    a.insert(x[i]);
  } else {
    b.insert(x[i]);
  }
  maintain();
}

void del(int i) {
  auto it = a.find(x[i]);
  if(it != a.end()) {
    a.erase(it);
  } else {
    b.erase(b.find(x[i]));
  }
  maintain();
}

void print() {
  cout << *a.rbegin() << " ";
}

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> x[i];
  for(int i = 0; i < k; i++) {
    add(i);
  }
  print();
  for(int i = k; i < n; i++) {
    del(i - k);
    add(i);
    print();
  }
  cout << endl;
  return 0;
}
