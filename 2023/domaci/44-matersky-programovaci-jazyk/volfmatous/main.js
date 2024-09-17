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
    const variables = {};

    const c = parseInt(await readLine());

    const linesSplit = [];
    const linesNestLevels = [];

    for (let i = 0; i < c; i++) {
        let line = (await readLine()).split("//")[0].trimEnd();

        if (line === '') {
            continue;
        }

        let nestLevel = 0;
        while (line.length > 2 && line.startsWith("  ")) {
            line = line.substring(2);
            nestLevel++;
        }

        linesSplit.push(line.split(' '));
        linesNestLevels.push(nestLevel);
    }

    const output = [];

    let repeating = false;
    let repeatStartLineIndex = 0;
    let nestLevelCurrent = 0;

    for (let i = 0; i < linesSplit.length; i++) {
        const lineSplit = linesSplit[i];
        const nestLevel = linesNestLevels[i];

        if (nestLevel > nestLevelCurrent) {
            continue;
        }

        const atLastLine = i >= linesSplit.length - 1;

        if (repeating && (nestLevel < linesNestLevels[repeatStartLineIndex] + 1 || atLastLine)) {
            repeating = false;
            i = repeatStartLineIndex - 1;
            if (!atLastLine) {
                continue;
            }
        } else if (nestLevel < nestLevelCurrent) {
            nestLevelCurrent = nestLevel;
        }

        switch (lineSplit[0]) {
            case "kdyz": {
                if (lineSplit.length < 5 || lineSplit[lineSplit.length - 1] !== "tak") {
                    console.log("error");
                    return;
                }

                const conditionResult = conditionPass(lineSplit.slice(1, -1), variables);

                if (!conditionResult[0]) {
                    console.log("error");
                    return;
                }

                if (conditionResult[1]) {
                    nestLevelCurrent++;
                }

                break;
            }

            case "dokud": {
                if (lineSplit.length < 5 || lineSplit[lineSplit.length - 1] !== "tak") {
                    console.log("error");
                    return;
                }

                const conditionResult = conditionPass(lineSplit.slice(1, -1), variables);

                if (!conditionResult[0]) {
                    console.log("error");
                    return;
                }

                if (conditionResult[1]) {
                    nestLevelCurrent++;
                    repeating = true;
                    repeatStartLineIndex = i;
                }

                break;
            }

            case "vypsat": {
                const expressionResult = expressionValue(lineSplit.slice(1), variables);

                if (!expressionResult[0]) {
                    console.log("error");
                    return;
                }

                output.push(expressionResult[1]);
                break;
            }

            default: {
                const variableName = lineSplit[0];

                if (variableName.toLowerCase().charCodeAt(0) < 'a'.charCodeAt(0) || variableName.toLowerCase().charCodeAt(0) > 'z'.charCodeAt(0)
                    || lineSplit.length < 2 || lineSplit[1] !== "je") {
                    console.log("error");
                    return;
                }

                switch (variableName) {
                    case "je":
                    case "a":
                    case "bez":
                    case "kdyz":
                    case "tak":
                    case "rovno":
                    case "aspon":
                    case "nejvic":
                    case "nebo":
                    case "dokud":
                    case "vypsat":
                        console.log("error");
                        return;
                }

                const expressionResult = expressionValue(lineSplit.slice(2), variables);

                if (!expressionResult[0]) {
                    console.log("error");
                    return;
                }

                variables[variableName] = expressionResult[1];
                break;
            }
        }
    }

    for (const line of output) {
        console.log(line);
    }
}

function expressionValue(lineSplit, variables) {
    if (lineSplit.length % 2 !== 1) {
        return [false, 0];
    }

    let expressionAdd = true;
    let expressionValue = 0;

    for (let w = 0; w < lineSplit.length; w++) {
        if (w % 2 === 0) {
            let value = parseFloat(lineSplit[w]);
            value = isNaN(value) ? variables[lineSplit[w]] : value;
            if (value === undefined) {
                return [false, 0];
            }

            expressionValue += expressionAdd ? value : -value;
        } else {
            switch (lineSplit[w]) {
                case "a":
                    expressionAdd = true;
                    break;
                case "bez":
                    expressionAdd = false;
                    break;
                default:
                    return [false, 0];
            }
        }
    }

    return [true, expressionValue];
}

function conditionPass(lineSplit, variables) {
    const orIndexes = [-1];
    for (let i = 0; i < lineSplit.length; i++) {
        if (lineSplit[i] === "nebo") {
            orIndexes.push(i);
        }
    }

    orIndexes.push(lineSplit.length);

    let conditionPass = false;

    for (let i = 0; i < orIndexes.length - 1; i++) {
        const startIndex = orIndexes[i] + 1;
        const endIndex = orIndexes[i + 1] - 1;

        let comparatorIndex = -1;
        for (let c = startIndex; c <= endIndex; c++) {
            if (lineSplit[c] === "rovno" || lineSplit[c] === "aspon" || lineSplit[c] === "nejvic") {
                comparatorIndex = c;
                break;
            }
        }

        if (comparatorIndex === -1) {
            return [false, false];
        }

        const comparator = lineSplit[comparatorIndex];
        const expression1Result = expressionValue(lineSplit.slice(startIndex, comparatorIndex), variables);
        const expression2Result = expressionValue(lineSplit.slice(comparatorIndex + 1, endIndex + 1), variables);

        if (!expression1Result[0] || !expression2Result[0]) {
            return [false, false];
        }

        if (!conditionPass) {
            const expression1 = expression1Result[1];
            const expression2 = expression2Result[1];

            switch (comparator) {
                case "rovno":
                    conditionPass = expression1 === expression2;
                    break;
                case "aspon":
                    conditionPass = expression1 >= expression2;
                    break;
                case "nejvic":
                    conditionPass = expression1 <= expression2;
                    break;
            }
        }
    }

    return [true, conditionPass];
}
