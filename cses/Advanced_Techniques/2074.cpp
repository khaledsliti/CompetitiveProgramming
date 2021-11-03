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
class implicit_treap {
  struct node {
    int prior, size;
    T val;
    T sum;
    bool lazy;
    node *l, *r;
  };
  typedef node* pnode;
  pnode root = nullptr;
  int get_sz(pnode t) {
    return t ? t->size : 0;
  }
  void upd_sz(pnode t) {
    if(t) t->size = get_sz(t->l) + 1 + get_sz(t->r);
  }
  void push_down(pnode t) {
    if(!t || !t->lazy) return;
    swap(t->l, t->r);
    if(t->l) t->l->lazy = !t->l->lazy;
    if(t->r) t->r->lazy = !t->r->lazy;
    t->lazy = 0;
  }
  void reset(pnode t) {
    if(t) {
      t->sum = t->val;
    }
  }
  void combine(pnode& t, pnode l, pnode r) {
    if(!l || !r) return void(t = l ? l : r);
    t->sum = l->sum + r->sum;
  }
  void operation(pnode& t) {
    if(!t) return;
    reset(t);
    push_down(t->l);
    push_down(t->r);
    combine(t, t->l, t);
    combine(t, t, t->r);
  }
  void split(pnode t, pnode &l, pnode &r, int pos, int add = 0) {
    if(!t) return void(l = r = NULL);
    push_down(t);
    int cur_pos = add + get_sz(t->l);
    if(cur_pos <= pos) split(t->r, t->r, r, pos, cur_pos + 1), l = t;
    else split(t->l, l, t->l, pos, add), r = t;
    upd_sz(t);
    operation(t);
  }
  void merge(pnode &t, pnode l, pnode r) {
    push_down(l);
    push_down(r);
    if(!l || !r) t = l ? l : r;
    else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upd_sz(t);
    operation(t);
  }
  pnode init(T val) {
    pnode ret = new node;
    ret->prior = rand();
    ret->size = 1;
    ret->val = ret->sum = val;
    ret->lazy = 0;
    ret->l = ret->r = nullptr;
    return ret;
  }
  void insert(pnode& t, T val, int pos) {
    pnode L, R, mid;
    split(t, L, R, pos - 1);
    merge(mid, L, init(val));
    merge(t, mid, R);
  }
  T range_query(pnode& t, int l, int r) {
    pnode L, mid, R;
    split(t, L, mid, l - 1);
    split(mid, t, R, r - l);
    T ans = t->sum;
    merge(mid, L, t);
    merge(t, mid, R);
    return ans;
  }
  void range_update(pnode& t, int l, int r) {
    pnode L, mid, R;
    split(t, L, mid, l - 1);
    split(mid, t, R, r - l);
    t->lazy = !t->lazy;
    merge(mid, L, t);
    merge(t, mid, R);
  }
  void print(pnode t, string sp = "") {
    if(!t) return;
    print(t->r, sp + ".");
    cout << sp << t->sum << endl;
    print(t->l, sp + ".");
  }
public:
  void insert(int pos, T val) {
    insert(root, val, pos);
  }
  T range_query(int l, int r) {
    return range_query(root, l, r);
  }
  void range_update(int l, int r) {
    range_update(root, l, r);
  }
  void print() {
    print(root);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;
  implicit_treap<long long> tr;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    tr.insert(i, a);
  }
  
  while(q--) {
    int t, l, r;
    cin >> t >> l >> r;
    l--, r--;
    if(t == 1) {
      tr.range_update(l, r);
    } else {
      cout << tr.range_query(l, r) << endl;
    }
  }
  return 0;
}
