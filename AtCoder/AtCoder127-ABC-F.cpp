#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int MAX = 1e9 + 5;

struct node{
  int cnt;
  long long sum;
  node *L,*R;
  node() : cnt(0), sum(0LL), L(NULL), R(NULL){}
};

node* tree;

// add
void add(node* cur, int At, int s = -MAX, int e = MAX)
{
  if(s > At || e < At)
    return;
  if(s == e){
    cur->cnt++;
    cur->sum += At;
    return;
  }
  if(!cur->L) cur->L = new node();
  if(!cur->R) cur->R = new node();
  int mid = s + (e - s) / 2;
  add(cur->L, At, s, mid);
  add(cur->R, At, mid + 1, e);
  cur->cnt = cur->L->cnt + cur->R->cnt;
  cur->sum = cur->L->sum + cur->R->sum;
}

// get Kth
int get(node* cur, int idx, int s = -MAX, int e = MAX)
{
  if(s == e)
    return s;
  if(!cur->L) cur->L = new node();
  if(!cur->R) cur->R = new node();
  int mid = s + (e - s) / 2;
  if(cur->L->cnt - 1 >= idx) return get(cur->L, idx, s, mid);
  return get(cur->R, idx - cur->L->cnt, mid + 1, e);
}

// query
pair<int, long long> query(node* cur, int i, int j, int s = -MAX, int e = MAX)
{
  if(s > j || e < i)
    return {0, 0};
  if(s >= i && e <= j)
    return { cur->cnt, cur->sum };
  if(!cur->L) cur->L = new node();
  if(!cur->R) cur->R = new node();
  int mid = s + (e - s) / 2;
  auto a = query(cur->L, i, j, s, mid);
  auto b = query(cur->R, i, j, mid + 1, e);
  return { a.first + b.first, a.second + b.second };
}

int main()
{
  node* tree = new node();
  int q, nbr = 0;
  long long sb = 0;
  scanf("%d", &q);
  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 1){
      int a, b;
      scanf("%d%d", &a, &b);
      sb += b;
      add(tree, a);
      nbr++;
    }else{
      int At = get(tree, (nbr - 1) / 2);
      pair<int, long long> l = query(tree, -MAX, At);
      pair<int, long long> r = query(tree, At + 1, MAX);
      cout << At << " " << sb + 1LL * l.first * At - l.second + r.second - 1LL * r.first * At << endl;
    }
  }
  return 0;
}
