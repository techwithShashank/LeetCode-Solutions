
n=int(input())
candidates=list(map(int,input().split()))


def largestCombination(candidates):
  maxi=0
  for i in range(0,32):
    res=0
    for num in candidates:
      if (num & (1<<i))!=0:
        res+=1
    maxi=max(maxi,res)
  return maxi
print(largestCombination(candidates))
