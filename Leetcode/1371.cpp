// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << endl;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void deb() {
  cerr << endl;
}

template<typename Head, typename... Tail>
void deb(Head h, Tail... t) {
  cerr << " " << h;
  deb(t...);
}

class Solution {
  int N = 5;
  int get_index(char c) {
    vector<char> v = {'a', 'e', 'i', 'u', 'o'};
    for(int i = 0 ; i < (int)v.size() ; i++)
      if(v[i] == c)
        return i;
    return -1;
  }
public:
  int findTheLongestSubstring(string s) {
    int n = (int)s.size();
    int mem[1 << N];
    for(int i = 0 ; i < (1 << N) ; i++)
      mem[i] = -1;
    mem[0] = 0;
    int cur_mask = 0, ans = 0;
    for(int i = 1 ; i <= n ; i++) {
      int idx = get_index(s[i - 1]);
      if(idx > -1) {
        cur_mask ^= (1 << idx);
      }
      if(mem[cur_mask] != -1) {
        int left = mem[cur_mask] + 1;
        if(left <= i)
          ans = max(ans, i - left + 1);
      } else {
        mem[cur_mask] = i;
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol = Solution();
  cout << sol.findTheLongestSubstring("eleetminicoworoep") << endl;
  return 0;
}
