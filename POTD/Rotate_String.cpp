
/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 */

#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal)
{

  if (s.size() != goal.size())
    return false; // cannot convert the string as op leads to invalid
  string str = "";
  str = s + s; // concatinate two times
  // As we have to make operation Left to right so concating will led to give all possible result of left to right
  // so we can easly check substring of goal wheter it is present or not
  return str.find(goal) != string::npos;
}
int main()
{
  string s;
  cin >> s;
  string goal;
  cin >> goal;
  if (rotateString(s, goal))
    cout << "Valid" << endl;
  else
    cout << "Invalid" << endl;
}