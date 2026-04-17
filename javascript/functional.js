//reduce
nums = [7, 4, 2, 5, 1, 9, 46];
s = nums.reduce((x, y) => x + y, 10);
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

//filter on objects
people = [{name:'giovanna',surname:'rossi'},{name:'mario',surname:'rossini'},
          {name:'mario',surname:'verdi'}];
console.log(people.filter((p) => p.surname[0] == 'r'));

//every
nums = [1, 5, 4, 3, -6];
console.log(nums.every(x => x >= 0));

//keep only people whose surname is longer than 5
people = [{name:'giovanna',surname:'rossi'},{name:'mario',surname:'rossini'},
          {name:'mario',surname:'verdi'}];
console.log(people.filter(p => p.surname.length > 5));

//keep only non-negative arrays of an array of arrays
matrix = [[3, 4, 2], [-1, -4, 3], [6, 4, 0]];
console.log(matrix.filter(arr => arr.every(x => x >= 0)));

//return sums of non-negative arrays of an array of arrays
sums = matrix.filter(a => a.every(b => b >= 0)).map(c => c.reduce((d, e) => d + e));
console.log(sums);

//convert array of numbers into array of strings
nums = [6, 5, 4];
console.log(nums.map(x => x + ''));

//convert array of numbers into array of arrays of prime factors
function factorize(n) {
  let factors = [];
  while (n != 1) {
    for (let d = 2; d <= n; d++) {
      if (n % d == 0) {
        n = n / d;
        factors.push(d);
        d = n + 1;
      }
    }
  }
  return factors;
}

nums = [13, 53, 2645, 300, 42, 6274, 11, 79, 97, 4651, 6200093];
console.log(nums.map(factorize));

//keep only prime numbers
