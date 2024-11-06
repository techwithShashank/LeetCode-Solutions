#include <bits/stdc++.h>
using namespace std;
bool canSortArray(vector<int> &nums)
{
  int n = nums.size(); // size of input array
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < (n - i - 1); j++)
    {
      if (nums[j] <= nums[j + 1])
      {
        // no swap required Already sorted element
        continue;
      }
      else
      {
        if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1]))
        {
          // set bits are same and required swapping
          swap(nums[j], nums[j + 1]);
        }
        else
        {
          // set bits are not same
          return false;
        }
      }
    }
  }
  return true;
}
int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  cout << canSortArray(nums);
}