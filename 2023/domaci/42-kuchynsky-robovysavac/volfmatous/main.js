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

const LEFT = 0;
const RIGHT = 1;
const FORWARD = 2;
const BACK = 3;

main().then();

async function main() {
    let inputSplit = (await readLine()).split(" ");
    const h = parseInt(inputSplit[0]);

    const floor = [];

    const tileColors = [];
    const program = new Map();
    for (let row = 0; row < h; row++) {
        floor.push((await readLine()).split(" "));

        for (const tile of floor[row]) {
            if (!program.has(tile)) {
                program.set(tile, LEFT);
                tileColors.push(tile);
            }
        }
    }

    inputSplit = (await readLine()).split(" ");
    let cleanerY = parseInt(inputSplit[0]) - 1;
    let cleanerX = parseInt(inputSplit[1]) - 1;

    inputSplit = (await readLine()).split(" ");
    let stationY = parseInt(inputSplit[0]) - 1;
    let stationX = parseInt(inputSplit[1]) - 1;

    let totalPossiblePrograms = 0;

    while (true) {
        if (tryProgram(floor, cleanerY, cleanerX, stationY, stationX, program)) {
            totalPossiblePrograms++;
        }

        let end = false;
        for (let i = 0; i < tileColors.length; i++) {
            program.set(tileColors[i], program.get(tileColors[i]) + 1);
            if (program.get(tileColors[i]) > 3) {
                if (i >= tileColors.length - 1) {
                    end = true;
                }

                program.set(tileColors[i], 0);
            } else {
                break;
            }
        }

        if (end) {
            break;
        }
    }

    console.log(totalPossiblePrograms);
}

function tryProgram(floor, cleanerY, cleanerX, stationY, stationX, program) {
    const floorVisited = [];
    for (let i = 0; i < floor.length; i++) {
        floorVisited.push([]);
        for (let j = 0; j < floor[0].length; j++) {
            floorVisited[i].push(false);
        }
    }

    while (true) {
        const tile = floor[cleanerY][cleanerX];
        const direction = program.get(tile);

        switch (direction) {
            case LEFT:
                cleanerX--;
                break;
            case RIGHT:
                cleanerX++;
                break;
            case FORWARD:
                cleanerY--;
                break;
            case BACK:
                cleanerY++;
                break;
        }

        if (cleanerY < 0 || cleanerY >= floor.length || cleanerX < 0 || cleanerX >= floor[0].length
            || floorVisited[cleanerY][cleanerX]) {
            return false;
        }

        if (cleanerY === stationY && cleanerX === stationX) {
            return true;
        }

        floorVisited[cleanerY][cleanerX] = true;
    }
}
