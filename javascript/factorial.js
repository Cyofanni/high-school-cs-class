function factorial(num) {
    if (!num) {
        return 1;
    }
    return num * factorial(num - 1);
}

for (let num = 0; num < 30; num++) {
    console.log("factorial of ", num, " is: ", factorial(num))
}
