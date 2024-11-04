#include <bits/stdc++.h>
using namespace std;
string compressedString(string &word)
{
  int cnt = 1;
  string ans = "";
  if (word.size() == 1)
  {
    ans += to_string(cnt);
    ans += word[0];
  }
  else
  {
    for (int i = 0; i < word.size(); i++)
    {
      if (i == word.size() - 1)
      {
        if (ans.back() == word[i])
        {
          cnt += 1;
          ans += to_string(cnt);
          ans += word[i];
        }
        else
        {
          cnt = 1;
          ans += to_string(cnt);
          ans += word[i];
        }
      }
      else if (word[i] != word[i + 1])
      {
        cnt = 1;
        ans += to_string(cnt);
        ans += word[i];
      }
      else if (word[i] == word[i + 1])
      {
        while (i < word.size() - 1 && word[i] == word[i + 1])
        {
          cnt += 1;
          i++;
        }
        if (cnt > 9)
        {
          while (cnt > 9)
          {
            ans += to_string(9);
            ans += word[i];
            cnt = cnt - 9;
          }
        }
        ans += to_string(cnt);
        ans += word[i];
        cnt = 1; // reset count
      }
    }
  }
  return ans;
}
int main()
{
  string input;
  cin >> input;
  cout << compressedString(input);
}