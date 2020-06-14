// We only fail when we stop trying
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

struct node {
  int ch, rating;
  bool operator<(const node& other) const {
    return rating > other.rating;
  }
};

int n, q;
int ch[N], rating[N];
set<node> gar[N];
multiset<int> global;

int get_max_rating(int g) {
  if(gar[g].empty()) return -1;
  return gar[g].begin()->rating;
}

void add(int index) {
  int m = get_max_rating(ch[index]);
  if(m != -1) {
    global.erase(global.find(m));
  }
  gar[ch[index]].insert({index, rating[index]});
  global.insert(get_max_rating(ch[index]));
}

void del(int index) {
  int m = get_max_rating(ch[index]);
  assert(m != -1);
  global.erase(global.find(m));
  gar[ch[index]].erase({index, rating[index]});
  m = get_max_rating(ch[index]);
  if(m != -1) {
    global.insert(m);
  }
}

int main()
{
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> rating[i] >> ch[i];
    add(i);
  }
  while(q--) {
    int c, d;
    cin >> c >> d;
    --c;
    del(c);
    ch[c] = d;
    add(c);
    cout << *global.begin() << endl;
  }
  return 0;
}
