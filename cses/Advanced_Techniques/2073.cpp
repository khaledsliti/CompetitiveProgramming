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

class implicit_treap {
  struct node {
    int prior, size;
    char val;
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
  void split(pnode t, pnode &l, pnode &r, int pos, int add = 0) {
    if(!t) return void(l = r = NULL);
    push_down(t);
    int cur_pos = add + get_sz(t->l);
    if(cur_pos <= pos) split(t->r, t->r, r, pos, cur_pos + 1), l = t;
    else split(t->l, l, t->l, pos, add), r = t;
    upd_sz(t);
  }
  void merge(pnode &t, pnode l, pnode r) {
    push_down(l);
    push_down(r);
    if(!l || !r) t = l ? l : r;
    else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upd_sz(t);
  }
  pnode init(char val) {
    pnode ret = (pnode)malloc(sizeof(node));
    ret->prior = rand();
    ret->size = 1;
    ret->val = val;
    ret->lazy = 0;
    ret->l = ret->r = nullptr;
    return ret;
  }
  void insert(pnode& t, char val, int pos) {
    pnode L, R, mid;
    split(t, L, R, pos - 1);
    merge(mid, L, init(val));
    merge(t, mid, R);
  }
  char get(pnode t, int pos) {
    if(!t) return '\0';
    push_down(t);
    int size_left = get_sz(t->l);
    if(pos == size_left) return t->val;
    if(pos < size_left) return get(t->l, pos);
    return get(t->r, pos - size_left - 1);
  }
  void print(pnode t) {
    if(!t) return;
    push_down(t);
    print(t->l);
    cout << t->val;
    print(t->r);
  }
public:
  void insert(int pos, char val) {
    insert(root, val, pos);
  }
  void reverse(int l, int r) {
    pnode L, mid, R, tmp;
    split(root, tmp, R, r);
    split(tmp, L, mid, l - 1);
    mid->lazy = 1;
    merge(tmp, L, mid);
    merge(root, tmp, R);
  }
  char get(int pos) {
    return get(root, pos);
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
  string s;
  cin >> n >> q >> s;
  implicit_treap tr;

  for(int i = 0; i < n; i++) {
    tr.insert(i, s[i]);
  }

  while(q--) {
    int l, r;
    cin >> l >> r;
    tr.reverse(--l, --r);
  }
  
  tr.print();
  cout << endl;
  return 0;
}
