/*Description=> You are given a 0-indexed binary string s having an even length.

A string is beautiful if it's possible to partition it into one or more substrings such that:

Each substring has an even length.
Each substring contains only 1's or only 0's.
You can change any character in s to 0 or 1.

Return the minimum number of changes required to make the string s beautiful.*/

// eg => 1001 => (11), (00) 2 beautiful substring
// eg => 0000 => Already  beautiful substring
#include <bits/stdc++.h>
using namespace std;
int Beautifulstring(string &s)
{
  int n = s.length();
  int i = 0;
  int reqBeautyChange = 0;
  while (i < n - 1)
  {
    if (s[i] == s[i + 1])
    {
      // An smallest length even substring is beautiful
      // no need for count change
      i += 2;
    }
    else if (s[i] != s[i + 1])
    {
      // count the change
      reqBeautyChange += 1;
      i += 2;
    }
  }
  return reqBeautyChange;
}
int main()
{
  string s;
  cin >> s;
  if (s.size() % 2 != 0)
    cout << "INVALID ODD STRING";
  else
  {
    cout << Beautifulstring(s);
  }
}
