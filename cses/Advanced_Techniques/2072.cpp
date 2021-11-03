#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
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
    node *l, *r;
  };
  typedef node* pnode;
  pnode root = nullptr;
  int get_sz(pnode t) {
    return t ? t->size : 0;
  }
  void upd_sz(pnode t) {
    if(t) {
      t->size = get_sz(t->l) + 1 + get_sz(t->r);
    }
  }
  void split(pnode t, pnode &l, pnode &r, int pos, int add = 0) {
    if(!t) return void(l = r = NULL);
    int cur_pos = add + get_sz(t->l);
    if(cur_pos <= pos) split(t->r, t->r, r, pos, cur_pos + 1), l = t;
    else split(t->l, l, t->l, pos, add), r = t;
    upd_sz(t);
  }
  void merge(pnode &t, pnode l, pnode r) {
    if(!l || !r) t = l ? l : r;
    else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upd_sz(t);
  }
  pnode init(char val) {
    pnode ret = new node;
    ret->prior = rand();
    ret->size = 1;
    ret->val = val;
    ret->l = ret->r = nullptr;
    return ret;
  }
  void insert(pnode &t, char val, int pos) {
    pnode L, R, mid;
    split(t, L, R, pos - 1);
    merge(mid, L, init(val));
    merge(t, mid, R);
  }
  char get(pnode t, int pos) {
    if(!t) return '\0';
    int size_left = get_sz(t->l);
    if(pos == size_left) return t->val;
    if(pos < size_left) return get(t->l, pos);
    return get(t->r, pos - size_left - 1);
  }
public:
  void insert(int pos, char val) {
    insert(root, val, pos);
  }
  void operation(int l, int r) {
    pnode L, R, mid, tmp;
    split(root, tmp, R, r);
    split(tmp, L, mid, l - 1);
    swap(mid, R);
    merge(tmp, L, mid);
    merge(root, tmp, R);
  }
  char get(int pos) {
    return get(root, pos);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n, q;
  string s;

  cin >> n >> q;
  cin >> s;
  implicit_treap tr;

  for(int i = 0; i < n; i++) {
    tr.insert(i, s[i]);
  }

  while(q--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    tr.operation(a, b);
  }

  for(int i = 0; i < n; i++) {
    cout << tr.get(i);
  }
  cout << endl;
  return 0;
}
