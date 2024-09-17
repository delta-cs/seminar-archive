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
const UP = 1;
const RIGHT = 2;
const DOWN = 3;

const NONE = 0;
const ROBOT = 1;
const PILLAR = 2;
const BOX = 3;

main().then();

async function main() {
    const w = await readInt();
    const h = await readInt();
    await readLine();

    let robotX = await readInt() - 1;
    let robotY = await readInt() - 1;
    await readLine();
    let robotOrientation = LEFT;

    const warehouse = [];
    for (let col = 0; col < w; col++) {
        warehouse.push([]);
        for (let row = 0; row < h; row++) {
            warehouse[col].push(NONE);
        }
    }

    warehouse[robotX][robotY] = ROBOT;

    const p = await readInt();
    await readLine();
    for (let i = 0; i < p; i++) {
        const x = await readInt() - 1;
        const y = await readInt() - 1;

        warehouse[x][y] = PILLAR;
        await readLine();
    }

    const b = await readInt();
    await readLine();
    for (let i = 0; i < b; i++) {
        warehouse[await readInt() - 1][await readInt() - 1] = BOX;
        await readLine();
    }

    const c = await readInt();
    await readLine();
    for (let i = 0; i < c; i++) {
        const command = await readLine();

        switch (command) {
            case "L":
            case "R":
                robotOrientation = rotate(robotOrientation, command === "R");
                break;

            case "F":
                const newPosition = moveForward(warehouse, robotX, robotY, robotOrientation);
                robotX = newPosition[0];
                robotY = newPosition[1];
                break;
        }
    }

    printWarehouse(warehouse);
}

function rotate(currentOrientation, clockwise) {
    if (clockwise) {
        return (currentOrientation + 1) % 4;
    } else {
        return (currentOrientation - 1 + 4) % 4;
    }
}

function moveForward(warehouse, robotX, robotY, orientation) {
    switch (orientation) {
        case LEFT:
            for (let col = robotX - 1; col >= 0; col--) {
                if (warehouse[col][robotY] === PILLAR) {
                    break;
                }

                if (warehouse[col][robotY] === BOX) {
                    continue;
                }

                for (let col2 = col + 1; col2 <= robotX; col2++) {
                    warehouse[col2 - 1][robotY] = warehouse[col2][robotY];
                }

                warehouse[robotX][robotY] = NONE;
                return [robotX - 1, robotY];
            }

            break;

        case RIGHT:
            for (let col = robotX + 1; col < warehouse.length; col++) {
                if (warehouse[col][robotY] === PILLAR) {
                    break;
                }

                if (warehouse[col][robotY] === BOX) {
                    continue;
                }

                for (let col2 = col - 1; col2 >= robotX; col2--) {
                    warehouse[col2 + 1][robotY] = warehouse[col2][robotY];
                }

                warehouse[robotX][robotY] = NONE;
                return [robotX + 1, robotY];
            }

            break;

        case UP:
            for (let row = robotY - 1; row >= 0; row--) {
                if (warehouse[robotX][row] === PILLAR) {
                    break;
                }

                if (warehouse[robotX][row] === BOX) {
                    continue;
                }

                for (let row2 = row + 1; row2 <= robotY; row2++) {
                    warehouse[robotX][row2 - 1] = warehouse[robotX][row2];
                }

                warehouse[robotX][robotY] = NONE;
                return [robotX, robotY - 1];
            }

            break;

        case DOWN:
            for (let row = robotY + 1; row < warehouse[0].length; row++) {
                if (warehouse[robotX][row] === PILLAR) {
                    break;
                }

                if (warehouse[robotX][row] === BOX) {
                    continue;
                }

                for (let row2 = row - 1; row2 >= robotY; row2--) {
                    warehouse[robotX][row2 + 1] = warehouse[robotX][row2];
                }

                warehouse[robotX][robotY] = NONE;
                return [robotX, robotY + 1];
            }

            break;
    }

    return [robotX, robotY];
}

function printWarehouse(warehouse) {
    for (let i = 0; i < warehouse.length + 2; i++) {
        process.stdout.write(".");
    }

    process.stdout.write("\n");

    for (let row = 0; row < warehouse[0].length; row++) {
        process.stdout.write(".");

        for (let col = 0; col < warehouse.length; col++) {
            let output = " ";

            switch (warehouse[col][row]) {
                case ROBOT:
                    output = "r";
                    break;

                case PILLAR:
                    output = "o";
                    break;

                case BOX:
                    output = "#";
                    break;
            }

            process.stdout.write(output);
        }

        process.stdout.write(".\n");
    }

    for (let i = 0; i < warehouse.length + 2; i++) {
        process.stdout.write(".");
    }

    process.stdout.write("\n");
}

async function readInt() {
    return parseInt(await readLine());
}
