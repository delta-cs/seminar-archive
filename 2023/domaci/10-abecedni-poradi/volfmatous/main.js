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
    const n = parseInt(await readLine());

    let descending = false;
    let descendingDecided = false;
    let previousWord = "";
    for (let i = 0; i < n; i++) {
        const currentWord = await readLine();

        const inOrderAscending = areWordsInOrder(previousWord, currentWord, false);
        const inOrderDescending = areWordsInOrder(previousWord, currentWord, true);

        previousWord = currentWord;

        if (descendingDecided) {
            if (descending ? !inOrderDescending : !inOrderAscending) {
                console.log("unordered");
                return;
            }
        } else {
            if (inOrderAscending && inOrderDescending) {
                continue;
            }

            descendingDecided = true;

            if (inOrderAscending) {
                descending = false;
                continue;
            }

            if (inOrderDescending) {
                descending = true;
                continue;
            }

            console.log("unordered");
            return;
        }
    }

    console.log("ordered");
}

function areWordsInOrder(word1, word2, descending) {
    let letterCaseInOrder = true;
    let letterCaseInOrderDecided = false;

    const shorterLength = Math.min(word1.length, word2.length);
    for (let i = 0; i < shorterLength; i++) {
        const char1 = word1[i];
        const char2 = word2[i];

        if (char1.toLowerCase() !== char2.toLowerCase()) {
            const alphabetAscendingOrder = char1.toLowerCase() < char2.toLowerCase();
            return descending ? !alphabetAscendingOrder : alphabetAscendingOrder;
        }

        if (letterCaseInOrderDecided) {
            continue;
        }

        if (char1.toLowerCase() === char1 && char2.toUpperCase() === char2) {
            letterCaseInOrder = true;
            letterCaseInOrderDecided = true;
            continue;
        }

        if (char1.toUpperCase() === char1 && char2.toLowerCase() === char2) {
            letterCaseInOrder = false;
            letterCaseInOrderDecided = true;
            continue;
        }
    }

    if (word1.length !== word2.length) {
        return word1.length < word2.length;
    }

    return letterCaseInOrder;
}
