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

const SYMBOL_WIN_COUNT = 5;

main().then();

async function main() {
    const w = await readInt();
    const h = await readInt();
    const t = await readInt();
    let currentPlayerIsA = await readLine() === "A";
    await readLine();

    const board = [];
    for (let col = 0; col < w; col++) {
        board.push([]);
        for (let row = 0; row < h; row++) {
            board[col].push(0);
        }
    }

    for (let i = 0; i < t; i++) {
        const turnX = await readInt() - 1;
        const turnY = await readInt() - 1;
        await readLine();

        if (board[turnX][turnY] !== 0) {
            console.log("invalid");
            console.log(i + 1);
            return;
        }

        board[turnX][turnY] = currentPlayerIsA ? 1 : 2;

        if (isWin(board, turnX, turnY)) {
            console.log(currentPlayerIsA ? "A" : "B");
            console.log(i + 1);
            return;
        }

        currentPlayerIsA = !currentPlayerIsA;
    }

    console.log("?");
}

function isWin(board, turnX, turnY) {
    let symbolCountHorizontal = 0;
    let symbolCountVertical = 0;
    let symbolCountDiagonal1 = 0;
    let symbolCountDiagonal2 = 0;

    for (let i = -SYMBOL_WIN_COUNT + 1; i <= SYMBOL_WIN_COUNT - 1; i++) {
        let x = turnX + i;
        let y = turnY;

        if (hasCoordinates(board, x, y) && board[x][y] === board[turnX][turnY]) {
            symbolCountHorizontal++;
        } else {
            symbolCountHorizontal = 0;
        }

        x = turnX;
        y = turnY + i;

        if (hasCoordinates(board, x, y) && board[x][y] === board[turnX][turnY]) {
            symbolCountVertical++;
        } else {
            symbolCountVertical = 0;
        }

        x = turnX + i;
        y = turnY + i;

        if (hasCoordinates(board, x, y) && board[x][y] === board[turnX][turnY]) {
            symbolCountDiagonal1++;
        } else {
            symbolCountDiagonal1 = 0;
        }

        x = turnX + i;
        y = turnY - i;

        if (hasCoordinates(board, x, y) && board[x][y] === board[turnX][turnY]) {
            symbolCountDiagonal2++;
        } else {
            symbolCountDiagonal2 = 0;
        }

        if (symbolCountHorizontal >= SYMBOL_WIN_COUNT ||
            symbolCountVertical >= SYMBOL_WIN_COUNT ||
            symbolCountDiagonal1 >= SYMBOL_WIN_COUNT ||
            symbolCountDiagonal2 >= SYMBOL_WIN_COUNT) {
            return true;
        }
    }

    return false;
}

function hasCoordinates(board, x, y) {
    return x >= 0 && x < board.length && y >= 0 && y < board[0].length;
}

async function readInt() {
    return parseInt(await readLine());
}
