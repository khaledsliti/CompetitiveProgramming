#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2005;

int n, k;
string s, wanted;
vector<pair<int, int>> sol;

int main()
{
  int T;
  cin >> T;
  while(T--){
    cin >> n >> k;
    cin >> s;
    wanted = "";
    int pref = n - (k - 1) * 2;
    for(char c : { '(', ')' })
      for(int i = 0 ; i < pref / 2 ; i++)
        wanted += c;
    while(sz(wanted) < n)
      wanted += "()";
    sol.clear();
    for(int i = 0 ; i < n ; i++){
      char need = wanted[i];
      if(need == s[i])
        continue;
      int j = i + 1;
      while(s[j] != need)
        j++;
      sol.pb({ i + 1, j + 1 });
      reverse(s.begin() + i, s.begin() + j + 1);
    }
    cout << sz(sol) << endl;
    for(auto i : sol)
      cout << i.first << " " << i.second << endl;
  }
  return 0;
}
