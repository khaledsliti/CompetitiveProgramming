// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

template <typename T>
class implicit_treap {
  struct node {
    int prior, size;
    T val;
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
    if(t->l) t->l->lazy ^= t->lazy;
    if(t->r) t->r->lazy ^= t->lazy;
    swap(t->l, t->r);
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
  pnode init(T val) {
    pnode ret = (pnode)malloc(sizeof(node));
    ret->prior = rand();
    ret->size = 1;
    ret->val = val;
    ret->lazy = 0;
    ret->l = ret->r = nullptr;
    return ret;
  }
  void print(pnode t) {
    if(!t) return;
    print(t->l);
    cerr << t->val;
    print(t->r);
  }
public:
  void insert(T val, int pos) {
    pnode L, R, mid;
    split(root, L, R, pos - 1);
    merge(mid, L, init(val));
    merge(root, mid, R);
  }
  void update(int l, int r, int d) {
    pnode L, mid, R, tmp;
    split(root, mid, R, r);
    split(mid, L, tmp, l - 1);
    tmp->lazy ^= 1;
    merge(mid, L, R);
    if(d == 0) { // front
      merge(root, tmp, mid);
    } else { // back
      merge(root, mid, tmp);
    }
  }
  T get(int idx) {
    pnode L, mid, R, tmp;
    split(root, mid, R, idx);
    split(mid, L, tmp, idx - 1);
    T ans = tmp->val;
    merge(mid, L, tmp);
    merge(root, mid, R);
    return ans;
  }
  void print() {
    print(root);
    cerr << '\n';
  }
};


const int N = 100008;

char s[N];

int main()
{
  scanf("%s", s);
  implicit_treap<char> tr;
  for(int i = 0 ; s[i] ; i++)
    tr.insert(s[i], i);
  int q;
  scanf("%d", &q);
  while(q--) {
    int t, x, y;
    scanf("%d %d", &t, &x);
    if(t == 1) {
      scanf("%d", &y);
      tr.update(x, y, 0);
    } else if(t == 2) {
      scanf("%d", &y);
      tr.update(x, y, 1);
    } else {
      printf("%c\n", tr.get(x));
    }
  }
  return 0;
}
