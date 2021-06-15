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

const int N = 19;

int n;
string s;
int tree[1 << N], state[1 << N];
unordered_map<int, int> nodeId, nodeIdx;

void updateState(int cur) {
  int idx = nodeIdx[cur];
  if(s[idx] == '?') {
    state[cur] = -1;
    tree[cur] = tree[2 * cur + 1] + tree[2 * cur + 2];
  } else if(s[idx] == '0') {
    state[cur] = 0;
    tree[cur] = tree[2 * cur + 1];
  } else {
    state[cur] = 1;
    tree[cur] = tree[2 * cur + 2];
  }
}

void build(int cur, int range) {
  if(range == 1) {
    tree[cur] = 1;
    return;
  }
  build(cur * 2 + 1, range >> 1);
  build(cur * 2 + 2, range >> 1);
  updateState(cur);
}

void build() {
  int idx = (1 << n) - 2;
  queue<int> q;
  q.push(0);
  while(idx >= 0) {
    int u = q.front();
    q.pop();
    nodeIdx[u] = idx;
    nodeId[idx--] = u;
    q.push(u * 2 + 2);
    q.push(u * 2 + 1);
  }
  build(0, (1 << n));
}

void update(int cur) {
  updateState(cur);
  if(cur == 0) return;
  update(cur - 1 >> 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> s;
  build();

  int q; cin >> q;
  while(q--) {
    int idx; char new_val;
    cin >> idx >> new_val;
    idx--;
    s[idx] = new_val;
    update(nodeId[idx]);
    cout << tree[0] << endl;
  }

  return 0;
}
