#include <bits/stdc++.h>
using namespace std;
vector<char> solve(vector<char> &chars)
{

  int n = chars.size();
  int count = 1;
  vector<char> str;
  for (int i = 0; i < n; i++)
  {
    if (i == n - 1)
    {
      if (str.back() == (chars[i]))
      {
        // cnt>1
        count++;
        string s = to_string(count);
        for (char ch : s)
          str.push_back(ch);
      }
      else if (str.back() != chars[i])
      {
        str.push_back(chars[i]);
      }
    }
    else if (i < n - 1 && chars[i] == chars[i + 1])
    {
      while (i < n - 1 && chars[i] == chars[i + 1])
      {
        count++;
        i += 1;
      }
      str.push_back(chars[i]);
      string s = to_string(count);
      for (char ch : s)
        str.push_back(ch);
      count = 1;
    }

    else if (chars[i] != chars[i + 1])
    {
      // single character always
      str.push_back(chars[i]);
    }
  }

  return str;
}
int main()
{
  int n;
  cin >> n;
  vector<char> chars(n);
  for (int i = 0; i < n; i++)
    cin >> chars[i];
  if (chars.size() == 1)
  {
    cout << 1 << endl;
  }
  else
  {
    vector<char> ans = solve(chars);
    for (char ch : ans)
      cout << ch << "";
    cout << endl;
    cout << ans.size();
  }
}