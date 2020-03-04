#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 203;

int main()
{
  int T;
  cin >> T;
  while(T--){
    string s;
    cin >> s;
    vector<int> used(26, 0);
    deque<char> dq;
    int pos = 0;
    dq.push_back(s[0]);
    used[s[0] - 'a'] = 1;
    bool possible = true;
    for(int i = 1 ; i < sz(s) && possible ; i++){
      char c = s[i];
      if(c == dq[pos]) continue;
      else if(pos > 0 && c == dq[pos - 1]){
        pos--;
      }else if(pos + 1 < sz(dq) && c == dq[pos + 1]){
        pos++;
      }else if(pos == 0 && !used[c - 'a']){
        dq.push_front(c);
        used[c - 'a'] = 1;
      }else if(pos == sz(dq) - 1 && !used[c -'a']){
        dq.push_back(c);
        used[c - 'a'] = 1;
        pos++;
      }else{
        possible = false;
      }
    }
    if(!possible){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
      for(int i = 0 ; i < 26 ; i++)
        if(!used[i])
          dq.push_back(char('a' + i));
      for(auto c : dq)
        cout << c;
      cout << endl;
    }
  }
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity