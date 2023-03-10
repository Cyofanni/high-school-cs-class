odd_numbers = [1, 3, 5, 7, 9, 11];
console.log(odd_numbers);
odd_numbers[8] = 17;
console.log(odd_numbers);

/*output
  [ 1, 3, 5, 7, 9, 11 ]
  [ 1, 3, 5, 7, 9, 11, <2 empty items>, 17 ]
*/

var song = {
    title: "let it be",
    author: "the beatles"
}

console.log(song["title"])
console.log(song["author"])
console.log(song.title)
console.log(song.author)


