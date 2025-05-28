nums = [];

function gen_bin_nums(n, curr) {
  if (!n) {
    nums.push(curr);
    return;
  }
  gen_bin_nums(n - 1, curr + '0');
  gen_bin_nums(n - 1, curr + '1');
}

gen_bin_nums(5, '');
console.log(nums);
