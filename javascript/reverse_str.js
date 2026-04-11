function rev(str) {
  let l = str.length;
  if (l == 0) {
    return "";
  }
  if (l == 1) {
    return str;
  }
  return str[l - 1] + rev(str.slice(0, l - 1));
}

console.log("banana", rev("banana"));
console.log("b", rev("b"));
console.log("", rev(""));
console.log("giovanni", rev("giovanni"));
console.log("string", rev("string"));
