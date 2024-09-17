const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let inputCount = 0;

rl.on("line", () => {
    inputCount++;
});

rl.on("close", () => {
    console.log(inputCount);
});
