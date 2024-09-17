const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let lines = 0;
let n, p;

rl.on("line", (line) => {
    lines++;
    switch (lines) {
        case 1:
            n = parseInt(line);
            return;

        case 2:
            p = parseInt(line);
            break;
    }

    printMultiplicationTable(n, p);
});

function printMultiplicationTable(n, count) {
    for (let multiplier = 1; multiplier <= count; multiplier++) {
        console.log(n * multiplier);
    }
}
