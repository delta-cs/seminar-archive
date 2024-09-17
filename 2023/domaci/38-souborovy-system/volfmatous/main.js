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
    const path1 = await readLine();
    const path2 = await readLine();

    const path2IsAbsolute = path2.startsWith("/");

    const path1Segments = dividePath(path1);
    const path2Segments = dividePath(path2);

    let result = "";

    if (path2IsAbsolute) {
        const longerPathLength = Math.max(path1Segments.length, path2Segments.length);
        for (let i = 0; i < longerPathLength; i++) {
            if (i < path1Segments.length && i < path2Segments.length && path1Segments[i] === path2Segments[i]) {
                continue;
            }

            for (let j = i; j < path1Segments.length; j++) {
                result += "../";
            }

            for (let j = i; j < path2Segments.length; j++) {
                result += path2Segments[j] + "/";
            }

            break;
        }
    } else {
        for (const segment of path2Segments) {
            if (segment === "..") {
                if (path1Segments.length < 1) {
                    continue;
                }

                path1Segments.pop();
            } else {
                path1Segments.push(segment);
            }
        }

        result = "/";
        for (const segment of path1Segments) {
            result += segment + "/";
        }
    }

    console.log(result);
}

function dividePath(path) {
    const pathSplit = path.split("/");
    const pathIsAbsolute = path.startsWith("/");

    const pathSimplified = [];
    for (let i = pathIsAbsolute ? 1 : 0; i < pathSplit.length - 1; i++) {
        const segment = pathSplit[i];

        if (pathIsAbsolute && segment === "..") {
            if (pathSimplified.length < 1) {
                continue;
            }

            pathSimplified.pop();
        } else {
            pathSimplified.push(segment);
        }
    }

    return pathSimplified;
}
