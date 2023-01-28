#배열을 이용해서 2개씩 짝지은 후에 최소값을 더한 풀이
class Solution(object):
    def arrayPairSum(self, nums):
        nums.sort()
        pairarray = []
        sum = 0;

        for i in range(len(nums)):
            pairarray.append(nums[i])
            if len(pairarray) == 2:
                sum += min(pairarray)
                pairarray = []

        return sum
      
      
#배열을 정렬후 2n에 있는 요소를 더한 파이썬스러운 풀이
class Solution(object):
    def arrayPairSum(self, nums):
        return sum(sorted(nums)[::2])
