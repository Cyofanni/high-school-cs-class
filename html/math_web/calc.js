function appendResult(result) {
  var resText = result;
  resEl.appendChild(resText);
  calcEl.appendChild(resEl);
}

function sum() {
  var a = document.getElementById("a").value;
  var b = document.getElementById("b").value;
  calcEl = document.getElementById("calc");
  oldResEl = document.getElementById("res");
  resEl = document.createElement("div");
  resEl.setAttribute("id", "res");

  if (oldResEl) {
    calcEl.removeChild(oldResEl);
  }
  appendResult(document.createTextNode(Number(a) + Number(b)));
}

function diff() {
  var a = document.getElementById("a").value;
  var b = document.getElementById("b").value;
  calcEl = document.getElementById("calc");
  oldResEl = document.getElementById("res");
  resEl = document.createElement("div");
  resEl.setAttribute("id", "res");

  if (oldResEl) {
    calcEl.removeChild(oldResEl);
  }
  appendResult(document.createTextNode(Number(a) - Number(b)));
}

function prod() {
  var a = document.getElementById("a").value;
  var b = document.getElementById("b").value;
  calcEl = document.getElementById("calc");
  oldResEl = document.getElementById("res");
  resEl = document.createElement("div");
  resEl.setAttribute("id", "res");

  if (oldResEl) {
    calcEl.removeChild(oldResEl);
  }
  appendResult(document.createTextNode(Number(a) * Number(b)));
}

function div() {
  var a = document.getElementById("a").value;
  var b = document.getElementById("b").value;
  calcEl = document.getElementById("calc");
  oldResEl = document.getElementById("res");
  resEl = document.createElement("div");
  resEl.setAttribute("id", "res");

  if (oldResEl) {
    calcEl.removeChild(oldResEl);
  }
  appendResult(document.createTextNode(Number(a) / Number(b)));
}

function gcd_euclid() {
  var a = document.getElementById("a").value;
  var b = document.getElementById("b").value;
  calcEl = document.getElementById("calc");
  oldResEl = document.getElementById("res");
  resEl = document.createElement("div");
  resEl.setAttribute("id", "res");

  if (oldResEl) {
    calcEl.removeChild(oldResEl);
  }

  while (b != 0) {
    let rem = a % b;
    a = b;
    b = rem;
  }

  appendResult(document.createTextNode(a));
}
