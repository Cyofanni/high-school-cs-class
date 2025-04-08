//?
console.log(function(x) { return x; } (42));

//?
console.log(function(x, y) { return x * y; } (6, 7));

//?
var g = function(a, b) {
    return a + b;
}
console.log(g(5));

//?
function f(a, b, c) {
    function s() {
        return a + b;
    }
    return s() + c;
}

console.log(f(5, 8, 7));

//?
var nums = [1, 2, 6, 7, 8];
var s = nums.reduce((x, y) => { return x * y; });
console.log(s);

//?
var ls = [0, 1];
for (var i = 2; i < 10; i++) {
    ls.push(ls[i - 1] + ls[i - 2]);
}
console.log(ls);

//?
var ls1 = [1, 3, 5, 7];
var ls2 = [1, 3, 5, 7];
console.log(ls1 == ls2);

//?
function k() {
    return 1;
}
console.log(k.call());

//?
pt1 = {x: 5, y: 3, sum_comp: function(pt2) { return {x: this.x + pt2.x, y: this.y + pt2.y}; }};
console.log(pt1.sum_comp({x: 7, y: 12}));

//?
ns = [5, 6, 1, 7, 12, 100, 3, 4];
ns.every(x => { return x != 100; });
