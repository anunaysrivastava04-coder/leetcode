class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num_set = set(nums)
        long_streak = 0
        for num in num_set:
            if (num - 1) not in num_set:
                current_num = num
                current_streak = 1
                while (current_num + 1) in num_set:
                    current_num += 1
                    current_streak += 1
                long_streak = max(long_streak, current_streak)
        return long_streak