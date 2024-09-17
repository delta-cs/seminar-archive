const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let lines = 0;
let a, b, c;

rl.on("line", (line) => {
    lines++;
    switch (lines) {
        case 1:
            a = parseFloat(line);
            return;

        case 2:
            b = parseFloat(line);
            return;
    }

    c = parseFloat(line);

    rl.close();

    let output;

    if (b === 1) {
        output = "undefined";
    } else {
        output = (c - a) / (b + 1);
    }

    console.log(output);
});
