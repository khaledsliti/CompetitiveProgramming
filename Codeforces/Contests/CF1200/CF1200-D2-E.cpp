#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 5;

const int P1 = 1400516101;
const int P2 = 1400518169;
const int B = 26 * 2 + 10;

int n;
vector<string> s;
string sol = "";

int len;
long long h1[N];
long long h2[N];
long long bp1[N];
long long bp2[N];

int get(char c)
{
  if(c >= 'a' && c <= 'z')
    return c - 'a';
  if(c >= 'A' && c <= 'Z')
    return c - 'A' + 26;
  return 26 * 2 + c - '0';
}

void add(char a)
{
  int c = get(a);
  h1[len] = ((len > 0 ? h1[len - 1] : 0) * B % P1 + c) % P1;
  h2[len] = ((len > 0 ? h2[len - 1] : 0) * B % P2 + c) % P2;
  len++;
  sol.push_back(a);
}

int main()
{
  ios::sync_with_stdio(false);
  bp1[0] = bp2[0] = 1;
  for(int i = 1 ; i < N ; i++){
    bp1[i] = (bp1[i - 1] * B) % P1;
    bp2[i] = (bp2[i - 1] * B) % P2;
  }
  cin >> n;
  s.resize(n);
  for(int i = 0 ; i < n ; i++){
    cin >> s[i];
  }
  for(int i = 0 ; i < sz(s[0]) ; i++){
    add(s[0][i]);
  }
  for(int i = 1 ; i < n ; i++){
    string& cur = s[i];
    long long cur_h1 = 0, cur_h2 = 0;
    int best = 0;
    for(int j = 0, st = len - 1 ; j < min(sz(cur), len) ; j++, st--){
      int c = get(cur[j]);
      cur_h1 = (cur_h1 * B % P1 + c) % P1;
      cur_h2 = (cur_h2 * B % P2 + c) % P2;
      if(j + 1 <= len){
        long long suff1 = ((h1[len - 1] - (st > 0 ? h1[st - 1] : 0) * bp1[j + 1] % P1) % P1 + P1) % P1;
        long long suff2 = ((h2[len - 1] - (st > 0 ? h2[st - 1] : 0) * bp2[j + 1] % P2) % P2 + P2) % P2;
        if(suff1 == cur_h1 && suff2 == cur_h2)
          best = j + 1;
      }
    }
    for(int j = best ; j < sz(cur) ; j++){
      add(cur[j]);
    }
  }
  cout << sol << endl;  
  return 0;
}
