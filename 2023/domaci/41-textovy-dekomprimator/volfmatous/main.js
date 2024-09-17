const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
});

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
    const text = await readLine();
    const compressing = await readLine() === "compress";

    if (compressing) {
        let currentLetterCount = 1;

        for (let i = 0; i < text.length; i++) {
            if (i < text.length - 1 && text[i] === text[i + 1]) {
                currentLetterCount++;
            } else {
                process.stdout.write(text[i]);
                if (currentLetterCount > 1) {
                    process.stdout.write(currentLetterCount.toString());
                }

                currentLetterCount = 1;
            }
        }
    } else {
        for (let i = 0; i < text.length; i++) {
            process.stdout.write(text[i]);

            let countBuffer = "";
            for (let j = i; j < text.length; j++) {
                if (j < text.length - 1 && text[j + 1].charCodeAt(0) >= 48 && text[j + 1].charCodeAt(0) <= 57) {
                    countBuffer += text[j + 1];
                } else {
                    if (countBuffer.length > 0) {
                        const count = parseInt(countBuffer, 10);
                        for (let k = 0; k < count - 1; k++) {
                            process.stdout.write(text[i]);
                        }
                    }

                    i = j;
                    break;
                }
            }
        }
    }

    process.stdout.write("\n");
}
