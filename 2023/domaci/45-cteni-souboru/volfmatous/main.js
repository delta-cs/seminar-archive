const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
});
const fs = require("fs");

let linesRead = 0;
const lines = [];

async function readLine() {
    if (lines.length < 1) {
        for await (const line of rl) {
            lines.push(line);
        }
    }

    linesRead++;
    return lines[linesRead - 1];
}

main().then();

async function main() {
    const filePath = await readLine();

    if (!fs.existsSync(filePath)) {
        console.log("not found");
        return;
    }

    const content = fs.readFileSync(filePath, "utf8");
    console.log(content);
}
