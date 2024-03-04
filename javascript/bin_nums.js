nums = [];

function bin_nums(n) {
    if (n == 0) {
	return;
    }
    if (n == 1) {
	nums.push([0], [1]);
	return;
    }
    bin_nums(n - 1);
    let half_len = nums.length;
    for (let i = 0; i < half_len; i++) {
	nums.push(nums[i].slice(0, nums[i].length));
    }
    for (let i = 0; i < half_len; i++) {
	nums[i].splice(0, 0, 0);
    }
    for (let i = half_len; i < half_len * 2; i++) {
	nums[i].splice(0, 0, 1);
    }
}

bin_nums(4);
console.log(nums);
