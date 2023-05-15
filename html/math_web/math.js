function gcd_euclid() {
  var a = document.getElementById("a").value;
  var b = document.getElementById("b").value;

  while (b != 0) {
    let rem = a % b;
    a = b;
    b = rem;
  }

  var el = document.getElementById("numbers");
  res = document.getElementById("gcd");
  if (res) {
    el.removeChild(res);
  }
  var resEl = document.createElement("div");
  resEl.setAttribute("id", "gcd");
  var resText = document.createTextNode(a);
  resEl.appendChild(resText);
  el.appendChild(resEl);
}
