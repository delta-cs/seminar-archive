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
    const dictionaryWords = new Set();

    const d = parseInt(await readLine());
    for (let i = 0; i < d; i++) {
        const word = await readLine();
        dictionaryWords.add(word);
    }

    await readLine();

    let sentenceStarts = true;
    let previousWordWasNumber = false;

    const l = parseInt(await readLine());
    for (let i = 0; i < l; i++) {
        const line = await readLine();

        console.log(line);

        if (line.length < 1) {
            continue;
        }

        const errorIndexes = [];
        const errorLengths = [];
        const errorMessages = [];

        let currentIndex = 0;
        let duplicateSpaceFlag = false;

        let words = line.split(" ");

        for (let w of words) {
            let word = w;

            if (word.length < 1) {
                if (duplicateSpaceFlag) {
                    errorLengths[errorLengths.length - 1]++;
                } else {
                    errorIndexes.push(Math.max(0, currentIndex - 1));
                    errorLengths.push(2);
                    errorMessages.push("duplicate space");
                    duplicateSpaceFlag = true;
                }

                currentIndex++;
                continue;
            }

            duplicateSpaceFlag = false;

            let endsWithDot = false;
            if (word.endsWith(".")) {
                word = word.slice(0, -1);
                endsWithDot = true;
            }

            let isNumber = true;
            for (let c of word) {
                if (c.charCodeAt(0) < 48 || c.charCodeAt(0) > 57) {
                    isNumber = false;
                    break;
                }
            }

            let wordCapitalized = word.charAt(0).toUpperCase() + word.slice(1);
            let wordLowercase = word.toLowerCase();

            if (isNumber) {
                if (word.length > 3) {
                    errorIndexes.push(currentIndex);
                    errorLengths.push(word.length);
                    errorMessages.push("incorrect number formatting");
                }
            } else if (!dictionaryWords.has(wordCapitalized) && !dictionaryWords.has(wordLowercase)) {
                errorIndexes.push(currentIndex);
                errorLengths.push(word.length);
                errorMessages.push("unknown word");
            } else if (word.charAt(0).toUpperCase() === word.charAt(0) && !sentenceStarts && !previousWordWasNumber && !dictionaryWords.has(word)) {
                errorIndexes.push(currentIndex);
                errorLengths.push(word.length);
                errorMessages.push("incorrect leading uppercase");
            } else if (word.charAt(0).toLowerCase() === word.charAt(0) && (sentenceStarts || !dictionaryWords.has(wordLowercase))) {
                errorIndexes.push(currentIndex);
                errorLengths.push(word.length);
                errorMessages.push("incorrect leading lowercase");
            }

            currentIndex += w.length + 1;
            sentenceStarts = endsWithDot && !isNumber;
            previousWordWasNumber = isNumber;
        }

        if (errorIndexes.length < 1) {
            continue;
        }

        currentIndex = 0;
        for (let j = 0; j < errorIndexes.length; j++) {
            for (let k = 0; k < errorIndexes[j] - currentIndex; k++) {
                process.stdout.write(" ");
            }

            for (let k = 0; k < errorLengths[j]; k++) {
                process.stdout.write("~");
            }

            currentIndex = errorIndexes[j] + errorLengths[j];
        }

        console.log();

        currentIndex = 0;
        for (let j = 0; j < errorIndexes.length; j++) {
            for (let k = 0; k < errorIndexes[j] - currentIndex; k++) {
                process.stdout.write(" ");
            }

            process.stdout.write("^");

            currentIndex = errorIndexes[j] + 1;
        }

        console.log();

        for (let lineIndex = 0; lineIndex < errorIndexes.length * 2; lineIndex++) {
            currentIndex = 0;

            for (let j = 0; j < errorIndexes.length - Math.floor(lineIndex / 2); j++) {
                for (let k = 0; k < errorIndexes[j] - currentIndex; k++) {
                    process.stdout.write(" ");
                }

                if (j === errorIndexes.length - Math.floor((lineIndex + 1) / 2)) {
                    process.stdout.write("----- " + errorMessages[j]);
                } else {
                    process.stdout.write("|");
                }

                currentIndex = errorIndexes[j] + 1;
            }

            console.log();
        }

        console.log();
    }
}
