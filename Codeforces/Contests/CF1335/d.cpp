// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 10;

string s[N];

int main()
{
  int T;
  cin >> T;
  while(T--) {
    for(int i = 0 ; i < 9 ; i++)
      cin >> s[i];

    vector<int> c = {0, 3, 6, 1, 4, 7, 2, 5, 8};
    for(int i = 0 ; i < 9 ; i++)
        s[i][c[i]] = s[i][c[i]] == '9' ? '1' : (s[i][c[i]] + 1);

    for(int i = 0 ; i < 9 ;i++)
      cout << s[i] << endl;
  }  
  return 0;
}
