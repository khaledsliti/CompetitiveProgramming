// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n;
char op[10];
int seen[N];
stack<int> st;

void reorder() {
  while(!st.empty()) {
    seen[st.top()] = 1;
    st.pop();
  }
}

int main()
{
  scanf("%d", &n);
  int now = 1;
  int ans = 0;
  for(int it = 0 ; it < 2 * n ; it++) {
    scanf("%s", op);
    if(op[0] == 'a') {
      int a;
      scanf("%d", &a);
      st.push(a);
    }else{
      if(!st.empty()){
        if(st.top() == now)
          st.pop();
        else
          reorder(), ans++;
      }
      now++;
    }
  }
  cout << ans << endl;
  return 0;
}
