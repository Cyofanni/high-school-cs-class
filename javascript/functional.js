//reduce
nums = [7, 4, 2, 5, 1, 9, 46];
s = nums.reduce((x, y) => { return x + y; });
console.log(s);
p = nums.reduce((x, y) => { return x * y; });
console.log(p);

//filter, then reduce
nums = [1, 2, 6, 5, 1, 87, 57, 1, 0, 1, 4, 6];
n = nums.filter((x) => { return x % 2 == 0; }).reduce((x, y) => { return x + y; });
console.log(n);

//reduce vs reduceRight
vowels = ['a', 'e', 'i', 'o', 'u'];
console.log(vowels.reduce((x, y) => x + y));
console.log(vowels.reduceRight((x, y) => { return x + y; }));

//map
ns = [5, 6, 2, 3, 1, 24, 1];
console.log(ns.map((x) => x * 2));
console.log(ns);

//flat
matr = [[4, 5, 3], [3, 4, 10], [53, 46, 4], [6, 3, 91]];
console.log(matr.flat());
