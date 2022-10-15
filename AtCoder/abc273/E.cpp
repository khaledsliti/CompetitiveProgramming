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

struct Node {
  int val;
  Node *prv;
  Node() : val(0), prv(nullptr){}
  Node(int val) : val(val), prv(nullptr){}
};

Node *cur, *root;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  root = new Node(-1);
  root->prv = root;
  map<int, Node*> notebook;

  cur = root;
  int q;
  cin >> q;
  while(q--) {
    string t;
    cin >> t;
    if(t[0] == 'A') {
      int x; cin >> x;
      Node *nxt = new Node(x);
      nxt->prv = cur;
      cur = nxt;
    } else if (t[0] == 'D') {
      cur = cur->prv;
    } else if(t[0] == 'S') {
      int y;
      cin >> y;
      notebook[y] = cur;
    } else if(t[0] == 'L') {
      int y; cin >> y;
      if(notebook.count(y) > 0) {
        cur = notebook[y];
      } else {
        cur = root;
      }
    }
    cout << cur->val << " ";
  }
  return 0;
}
