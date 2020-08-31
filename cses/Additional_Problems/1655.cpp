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
const int L = 31;

struct Node {
  int nxt[2];
  Node() {
    nxt[0] = nxt[1] = -1;
  }
};

int n;
int a[N];
vector<Node> tr;

void insert(int x) {
  int cur = 0;
  for(int i = L - 1; i >= 0; i--) {
    int b = (x >> i) & 1;
    if(tr[cur].nxt[b] == -1) {
      tr[cur].nxt[b] = sz(tr);
      tr.push_back(Node());
    }
    cur = tr[cur].nxt[b];
  }
}

int get(int x) {
  int r = 0, cur = 0;
  for(int i = L - 1; i >= 0; i--) {
    int b = ((x >> i) & 1) ^ 1;
    if(tr[cur].nxt[b] != -1) {
      r |= (1 << i);
      cur = tr[cur].nxt[b];
    } else {
      cur = tr[cur].nxt[b ^ 1];
    }
  }
  return r;
}

void print(int x) {
  for(int i = L - 1; i >= 0; i--)
    cout << ((x >> i) & 1);
  cout << endl;
}

void go(int i, int cur, int x) {
  if(i < 0) {
    print(x);
    return;
  }
  if(tr[cur].nxt[0] != -1) {
    go(i - 1, tr[cur].nxt[0], x);
  }
  if(tr[cur].nxt[1] != -1) {
    go(i - 1, tr[cur].nxt[1], x | (1 << i));
  }
}

int main()
{
  cin >> n;
  tr.push_back(Node());
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  insert(0);
  int s = 0;
  int best = 0;
  for(int i = 0; i < n; i++) {
    s ^= a[i];
    best = max(best, get(s));
    insert(s);
  }
  cout << best << endl;
  return 0;
}
