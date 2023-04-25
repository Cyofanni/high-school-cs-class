//1- i global, i local
var i = 'abcde';

function f() {
    var i = 'qwerty';
    return i;
}

console.log(f(), '\n\n');

//2- j global
var j = 'foo';
function g() {
    j = 'bar';
    return j;
}

console.log(g());
console.log(j, '\n\n');

//3- hoisting
function h() {
    console.log(k); //variables are visible before their declaration
    for (var k = 0; k < 10; k++) {}
}

h();
