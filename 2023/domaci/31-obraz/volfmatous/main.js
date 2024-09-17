const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const LEFT = 0;
const RIGHT = 1;
const TOP = 2;
const BOTTOM = 3;
const NAIL_CHAR = "o";
const TOP_EDGE_NAIL_COUNT = 2;

let w;
let h;

const table = [];

let rowsLoaded = 0;
let colsLoaded = 0;

rl.on("line", (line) => {
    if (w === undefined) {
        w = parseInt(line);
        return;
    }

    if (h === undefined) {
        h = parseInt(line);
        for (let i = 0; i < h; i++) {
            table.push([]);
        }

        if (h < 1 || w < 1) {
            rl.close();
        }
        return;
    }

    if (line === "") {
        return;
    }

    table[rowsLoaded].push(line);

    colsLoaded++;
    if (colsLoaded >= w) {
        rowsLoaded++;
        colsLoaded = 0;
    }

    if (rowsLoaded < h) {
        return;
    }

    const topEdgeSide = getTopEdgeSide(table);
    printPictureFromSide(table, topEdgeSide);

    rl.close();
});

function getTopEdgeSide(picture) {
    let nailsCount = 0;

    for (let row = 0; row < picture.length; row++) {
        if (picture[row][0] === NAIL_CHAR) {
            nailsCount++;

            if (nailsCount >= TOP_EDGE_NAIL_COUNT) {
                return LEFT;
            }
        }
    }

    nailsCount = 0;

    for (let row = 0; row < picture.length; row++) {
        if (picture[row][picture[0].length - 1] === NAIL_CHAR) {
            nailsCount++;

            if (nailsCount >= TOP_EDGE_NAIL_COUNT) {
                return RIGHT;
            }
        }
    }

    nailsCount = 0;

    for (let col = 0; col < picture[0].length; col++) {
        if (picture[0][col] === NAIL_CHAR) {
            nailsCount++;

            if (nailsCount >= TOP_EDGE_NAIL_COUNT) {
                return TOP;
            }
        }
    }

    return BOTTOM;
}

function printPictureFromSide(picture, side) {
    switch (side) {
        case LEFT:
            for (let col = 0; col < picture[0].length; col++) {
                for (let row = picture.length - 1; row >= 0; row--) {
                    let output = picture[row][col];

                    if (col === 0 || col === picture[0].length - 1 || row === 0 || row === picture.length - 1) {
                        switch (output) {
                            case "|":
                                output = "-";
                                break;

                            case "-":
                                output = "|";
                                break;
                        }
                    }

                    process.stdout.write(output);
                }

                process.stdout.write("\n");
            }

            break;

        case RIGHT:
            for (let col = picture[0].length - 1; col >= 0; col--) {
                for (let row = 0; row < picture.length; row++) {
                    let output = picture[row][col];

                    if (col === 0 || col === picture[0].length - 1 || row === 0 || row === picture.length - 1) {
                        switch (output) {
                            case "|":
                                output = "-";
                                break;

                            case "-":
                                output = "|";
                                break;
                        }
                    }

                    process.stdout.write(output);
                }

                process.stdout.write("\n");
            }

            break;

        case TOP:
            for (const row of picture) {
                for (const col of row) {
                    process.stdout.write(col);
                }

                process.stdout.write("\n");
            }

            break;

        case BOTTOM:
            for (let row = picture.length - 1; row >= 0; row--) {
                for (let col = picture[0].length - 1; col >= 0; col--) {
                    process.stdout.write(picture[row][col]);
                }

                process.stdout.write("\n");
            }

            break;
    }
}
