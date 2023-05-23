powerset = []
def gen_subsets(nums, k, subset):
  if k == len(nums):
    powerset.append(subset.copy())
    return
  subset.append(nums[k])
  gen_subsets(nums, k + 1, subset)
  subset.pop()
  gen_subsets(nums, k + 1, subset)

gen_subsets([4, 5, 3, 9], 0, [])
for item in powerset:
  print(item)
