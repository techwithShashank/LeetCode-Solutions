from typing import List

class Solution:
    def countSetBits(self, n: int) -> int:
        count = 0
        while n:
            count += n & 1
            n >>= 1
        return count

    def canSortArray(self, nums: List[int]) -> bool:
        for i in range(len(nums)):
            for j in range(len(nums) - 1 - i):
                if nums[j] <= nums[j + 1]:
                    continue
                else:
                    if self.countSetBits(nums[j]) == self.countSetBits(nums[j + 1]):
                        nums[j], nums[j + 1] = nums[j + 1], nums[j]
                    else:
                        return False
        return True

if __name__ == "__main__":
    # Taking input from the user
    n = int(input("Enter the number of elements in the array: "))
    
    # Taking multiple elements on one line and converting them to integers
    nums = list(map(int, input("Enter the elements separated by spaces: ").split()))

    # Creating an instance of Solution
    solution = Solution()
    
    # Checking if the array can be sorted
    result = solution.canSortArray(nums)
    
    # Outputting the result
    print("Can the array be sorted?", "Yes" if result else "No")
