#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;
string str[N];
string vv = "aeoiu";
vector<pair<int, int>> pos[10];

int index(char c)
{
  for(int i = 0 ; i < sz(vv) ; i++)
    if(vv[i] == c)
      return i;
  return sz(vv);
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for(int it = 0 ; it < n ; it++){
    string s;
    cin >> s;
    str[it] = s;
    int cnt = 0;
    int last = -1;
    for(int i = 0 ; i < sz(s) ; i++){
      int idx = index(s[i]);
      if(idx < sz(vv)){
        cnt++;
        last = idx;
      }
    }
    pos[last].push_back({cnt, it});
  }
  for(int c = 0 ; c < sz(vv) ; c++)
    sort(all(pos[c]));
  vector<pair<int, int>> A; // matching
  vector<pair<int, int>> rem; // remaining strings
  for(int i = 0 ; i < sz(vv) ; i++){
    for(int j = 0 ; j < sz(pos[i]) ; j++){
      if(j + 1 < sz(pos[i]) && pos[i][j].first == pos[i][j + 1].first){
        A.pb({pos[i][j].second, pos[i][j + 1].second});
        j++;
      }else{
        rem.pb(pos[i][j]);
      }
    }
  }
  // sort remaining by length
  sort(all(rem));
  vector<pair<int, int>> B;
  for(int i = 0 ; i < sz(rem) ; i++){
    if(i + 1 < sz(rem) && rem[i].first == rem[i + 1].first){
      B.pb({rem[i].second, rem[i + 1].second});
      i++;
    }
  }
  while(A.size() > B.size()){
    B.push_back(A.back());
    A.pop_back();
  }
  cout << min(A.size(), B.size()) << endl;
  for(int i = 0 ; i < min(A.size(), B.size()) ; i++)
    cout << str[B[i].first] << " " << str[A[i].first] << endl << str[B[i].second] << " " << str[A[i].second] << endl;
  return 0;
}
