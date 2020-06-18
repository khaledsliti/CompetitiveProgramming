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

int fr[26];

int main()
{
  string s;
  cin >> s;
  for(auto c : s)
    fr[c - 'A']++;
  string mid = "";
  for(int i = 0; i < 26; i++) {
    if(fr[i] & 1) {
      if(sz(mid)) {
        cout << "NO SOLUTION" << endl;
        return 0;
      } else {
        mid.push_back(char('A' + i));
        fr[i]--;
      }
    }
  }
  string a, b;
  for(int i = 0; i < 26; i++) {
    int need = fr[i] / 2;
    while(need > 0){
      a.push_back(char('A' + i));
      b.push_back(char('A' + i));
      need--;
    }
  }
  reverse(all(b));
  cout << a << mid << b << endl;
  return 0;
}
