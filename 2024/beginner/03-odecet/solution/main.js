const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];
readline.on('line', (line) => {
    inputs.push(parseInt(line));
    if (inputs.length === 2) {
        console.log(inputs[0] - inputs[1]);
        readline.close();
    }
});
