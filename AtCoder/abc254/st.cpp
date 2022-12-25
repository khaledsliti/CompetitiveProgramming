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

template <typename T>
struct Node {
  T val;
  Node *left, *right;
  Node(): val(T()), left(nullptr), right(nullptr) {}
  Node(T val): val(val), left(nullptr), right(nullptr) {}
  Node(T val, Node* left, Node* right): val(val), left(left), right(right) {}
  bool operator<(const Node& rhs) const {
    return val < rhs.val;
  }
  static Node* identity_p() {
    return new Node(0);
  }
  static Node identity() {
    return Node(0);
  }
  friend void merge(Node* r, Node* a, Node* b) {
    r->val = max(a->val, b->val);
  }

  void update(int s, int e, int idx, T val) {
    if(s > idx || e < idx) return;
    if(s == e) {

    }
  }
};

typedef Node<int>* pnode;



void update(pnode& cur, int s, int e, int idx, T val) {
  if(cur == nullptr) cur = Node::identity_p();
  if(s > idx || e < idx) return;
  printf("cur update = [%d %d]\n", s, e);
  if(s == e) {
    merge(cur, cur, new Node(val));
    printf("vaaaaaal = %d\n", cur->val);
    return;
  }
  int mid = s + (e - s) / 2;
  update(cur->left, s, mid, idx, val);
  update(cur->right, mid + 1, e, idx, val);
  merge(cur, cur->left, cur->right);
  printf("vaaaaaal[%d %d] = %d\n", s, e, cur->val);
}

void print(pnode cur, int s, int e) {
  printf("[%d - %d] = %d\n", s, e, cur == nullptr ? 0 : cur->val);
  if(s == e || cur == nullptr) return;
  int mid = s + (e - s) / 2;
  print(cur->left, s, mid);
  print(cur->right, mid + 1, e);
}

Node query_max(pnode cur, int s, int e, int i, int j) {
  if(s > j || e < i || cur == nullptr) return Node::identity();
  if(s >= i && e <= j) return cur == nullptr ? Node::identity() : *cur;
  int mid = (s + e) >> 1;
  return merge(query_max(cur->left, s, mid, i, j), query_max(cur->right, mid + 1, e, i, j));
}

int main()
{
  int s = 0, e = 16;
  pnode tree = nullptr;
  int q; cin >> q;
  while(q--) {
    int idx, val;
    cin >> idx >> val;
    printf("update %d to %d\n", idx, val);
    update(tree, s, e, idx, val);
    print(tree, s, e);
  }
  cout << tree->val << endl;
  return 0;
}
