/*
   sqrt(2) - 1 = (sqrt(2) - 1) * (sqrt(2) + 1) / (sqrt(2) + 1)
   = 1 / (sqrt(2) + 1) -->
   --> sqrt(2) = 1 + (1 / (sqrt(2) + 1))
*/

function sqrt_2_cont_fract_r(approx, n_calls) {
    if (!n_calls) {
        return approx;
    }
    res = 1 + (1 / (sqrt_2_cont_fract_r(approx, n_calls - 1) + 1));
    return res;
}

function sqrt_2_cont_fract_i(approx, n_iters) {
    for (i = 1; i <= n_iters; i++) {
        approx = 1 + (1 / (approx + 1));
    }

    return approx;
}

function sqrt_2_cont_fract_rt(approx, n_calls) {
    if (!n_calls) {
        return approx;
    }
    return sqrt_2_cont_fract_rt(1 + (1 / (approx + 1)), n_calls - 1);
}

console.log('head recursive: ', sqrt_2_cont_fract_r(1, 16));
console.log('iterative: ', sqrt_2_cont_fract_i(1, 16));
console.log('tail recursive: ', sqrt_2_cont_fract_rt(1, 16));
