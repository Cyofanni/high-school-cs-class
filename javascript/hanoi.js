function hanoi(n, init, temp, final) {
    if (n == 1) {
        console.log("move disk from peg", init, "to peg", final);
        return;
    }
    hanoi(n - 1, init, final, temp);
    console.log("move disk from peg", init, "to peg", final);
    hanoi(n - 1, temp, init, final);
}

hanoi(3, 'A', 'B', 'C');
