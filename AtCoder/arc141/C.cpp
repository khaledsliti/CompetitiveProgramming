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

const int N = 4e5 + 5;

int n;
int p[N], q[N];
char sol_p[N], sol_q[N];
char sol[N];
const char EMPTY = '#';

struct Sol {
  char op, cl;
  char *sol;
  int *p;
  Sol(char *sol, char op, char cl, int* p) : op(op), cl(cl), sol(sol), p(p) {
    memset(sol, EMPTY, sizeof sol);
  }
  bool solve() {
    set<int> unassigned, assigned_op, assigned_cl, seen;
    for(int i = n - 1; i >= 0; i--) {
      int cur = p[i];
      if(sz(seen) && *seen.begin() < cur) {
        // cur should be open
        sol[cur] = op;
        assigned_op.insert(cur);
        // assigned all less than cur
        while(sz(unassigned) && *unassigned.begin() < cur) {
          auto x = *unassigned.begin();
          sol[x] = cl;
          unassigned.erase(x);
          assigned_cl.insert(x);
        }
        // check for errors
        if(sz(assigned_op) && *assigned_op.begin() < cur) {
          return false;
        }
      } else {
        unassigned.insert(cur);
      }
      seen.insert(cur);
    }
    return true;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  n <<= 1;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for(int i = 0; i < n; i++) {
    cin >> q[i];
    q[i]--;
  }
  reverse(q, q + n);

  auto first = Sol(sol_p, ')', '(', p);
  auto second = Sol(sol_q, '(', ')', q);

  if(!first.solve() || !second.solve()) {
    cout << -1 << endl;
    return 0;
  }

  // for(int i = 0; i < n; i++) {
  //   cout << sol_p[i] << " ";
  // }
  // cout << endl;
  // for(int i = 0; i < n; i++) {
  //   cout << sol_q[i] << " ";
  // }
  // cout << endl;

  for(int i = 0; i < n; i++) {
    if(sol_p[i] != EMPTY && sol_q[i] != EMPTY && sol_p[i] != sol_q[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  int open = n >> 1;
  for(int i = 0; i < n; i++) {
    sol[i] = sol_p[i];
    if(sol[i] == EMPTY) {
      sol[i] = sol_q[i];
    }
    if(sol[i] == '(') open--;
  }

  
  for(int i = 0; i < n; i++) {
    if(sol[p[i]] == EMPTY) {
      if(open > 0) {
        sol[p[i]] = '(';
        open--;
      } else {
        sol[p[i]] = ')';
      }
    }
  }

  // for(int i = 0; i < n; i++) {
  //   cout << sol[p[i]];
  // }
  // cout << endl;

  // for(int i = 0; i < n; i++) {
  //   cout << sol[q[i]];
  // }
  // cout << endl;

  auto check = [&](int *p) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      if(sol[p[i]] == '(') cnt++;
      else cnt--;
      if(cnt < 0) return false;
    }
    return cnt == 0;
  };

  if(!check(p) || !check(q)) {
    cout << -1 << endl;
  }

  for(int i = 0; i < n; i++) {
    cout << sol[i];
  }
  cout << endl;

  return 0;
}
