#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
using namespace std;

class RepeatedPatterns
{
  long long getInt(string &s)
  {
    long long r = 0;
    for (int i = 0; i < (int)s.size(); i++)
      r = r * 10 + s[i] - '0';
    return r;
  }
  bool containsOne(string &s, int &pref, int &suff, long long cnt, int &index)
  {
    pref = suff = 0;
    bool yes = false;
    index = -1;
    for (int i = 0; i < (int)s.size(); i++)
    {
      if (s[i] == '0')
      {
        int len = 0;
        while (i < (int)s.size() && s[i] == '0')
          i++, len++;
        if (i == len)
          pref = len;
        if (i == (int)s.size())
          suff = len;
        i--;
        if (len >= cnt && index == -1)
          index = i - len + 1;
      }
      else
      {
        yes = true;
      }
    }
    return yes;
  }

  long long solve(string p1, string p2, string zeroCount)
  {
    long long zeros = getInt(zeroCount);
    int pref1, pref2, suff1, suff2;
    int index1, index2;
    bool p1ContainsOne = containsOne(p1, pref1, suff1, zeros, index1);
    bool p2ContainsOne = containsOne(p2, pref2, suff2, zeros, index2);

    if (p1ContainsOne && p2ContainsOne)
    {
      if (index1 != -1)
        return index1;
      if (suff1 + pref1 >= zeros)
        return p1.size() - suff1;
      if (suff1 + pref2 >= zeros)
        return p1.size() * 1000000LL - suff1;
      if (index2 != -1)
        return 1000000LL * p1.size() + index2;
      if (suff2 + pref1 >= zeros)
        return p1.size() * 1000000LL + p2.size() - suff2;
      if (suff2 + pref2 >= zeros)
        return 2 * (p1.size() * 1000000LL + p2.size()) - suff2;
      return -1;
    }

    if (p1ContainsOne && !p2ContainsOne)
    {
      if (index1 != -1)
        return index1;
      if (suff1 + pref1 >= zeros)
        return p1.size() - suff1;
      if (suff1 + pref2 + pref1 >= zeros)
        return p1.size() * 1000000LL - suff1;
      long long rem = zeros - pref1 - suff1;
      long long l = ceil(1.0 * rem / pref2);
      if (!pref2 || l <= 1e9 / pref2)
      {
        long long idx = 1000000LL * p1.size() * l + l * (l - 1) / 2 * pref2 - suff1;
        if (idx + zeros <= 1e16)
          return idx;
      }
      return -1;
    }

    if (!p1ContainsOne && p2ContainsOne)
    {
      if (pref1 * 1000000LL + pref2 >= zeros)
        return 0;
      if (suff2 + pref1 * 1000000LL + pref2 >= zeros)
        return 1000000LL * pref1 + p2.size() - suff2;
      return -1;
    }

    return 0LL;
  }

public:
  long long findZeroSegment(string p1, string p2, string zeroCount)
  {
    long long res = solve(p1, p2, zeroCount);
    if (res + getInt(zeroCount) > 1e16)
      return -1;
    return res;
  }
};
