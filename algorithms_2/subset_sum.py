def subset_sum(nums, i, ss, k):
  if i == len(nums):
    print(ss, end = ' ')
    if (sum(ss) == k):
      print('OK', end = '')
    print()
    return
  subset_sum(nums, i + 1, ss, k)
  subset_sum(nums, i + 1, ss + [nums[i]], k)

nums = [1, 2, 3, 5, 1, -6, -3]
subset_sum(nums, 0, [], 10)
