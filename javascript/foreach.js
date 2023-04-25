function print_times_2(x) {
    console.log(x * 2);
}

var ls = [5, 4, 3, 76, 54, 34, 23, 1];

//print double of each number in ls, using a named function
console.log("Example 1: ");
ls.forEach(print_times_2);
console.log('\n')

//print double of each number in ls, using a lambda function (syntax 1)
console.log("Example 2: ");
ls.forEach(function(x) { console.log(x * 2) });
console.log('\n')

//print double of each number in ls, using a lambda function (syntax 2)
console.log("Example 3: ");
ls.forEach(x => { console.log(x * 2) });
