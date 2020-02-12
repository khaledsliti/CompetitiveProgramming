#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, k;
string s;
int a[N];

int main()
{
  cin >> n >> k >> s;
  stack<int> st;
  for(int i = 0 ; i < n && k > 0; i++){
    if(s[i] == '(') st.push(i);
    else{
      a[i] = a[st.top()] = 1;
      k -= 2;
      st.pop();
    }
  }
  for(int i = 0 ; i < n ; i++)
    if(a[i])
      cout << s[i];
  cout << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity