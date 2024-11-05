def solve(s):
  beauty=0
  for i in range(0,len(s)-1,2):
    if s[i]!=s[i+1]:
      beauty+=1
  return beauty
s=input()
if len(s)%2!=0:
  print("Invalid ODD String ")
else:
  print(solve(s))

