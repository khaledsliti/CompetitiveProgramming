#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
public:
  string breakPalindrome(string& palindrome) {
    int n = palindrome.size();
    if(n == 1)
      return "";
    int half = n >> 1;
    for(int i = 0 ; i < half ; i++)
      if(palindrome[i] != 'a'){
        palindrome[i] = 'a';
        return palindrome;
      }
    palindrome[n - 1] = 'b';
    return palindrome;
  }
};

int main()
{
  Solution sol;
  cout << sol.breakPalindrome("abccba") << endl;
  cout << sol.breakPalindrome("a") << endl;
  cout << sol.breakPalindrome("aaaaaa") << endl;
  cout << sol.breakPalindrome("aaa") << endl;
  return 0;
}

//Check array sizes
//Check limits: N = 1 ? N = Max ? .. etc
//Check time complexity