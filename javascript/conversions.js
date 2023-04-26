var str = '1, b, 3, 7, 4, a, 7, 9, foo, 3, bar';
var str_split = str.split(', ');
console.log(str_split);

var sum = 0;

str_split.forEach(x => { if (!isNaN(x)) { sum += Number(x); } })
console.log(sum);
