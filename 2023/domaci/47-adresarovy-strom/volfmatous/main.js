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
    const folderPath = await readLine();

    if (!fs.existsSync(folderPath)) {
        console.log("not found");
        return;
    }

    printDirectoryContents(folderPath);
}

function printDirectoryContents(folderPath, nestLevel = 0) {
    const files = fs.readdirSync(folderPath).sort();
    const directories = files.filter(item => fs.statSync(`${folderPath}/${item}`).isDirectory());

    console.log(" ".repeat(Math.max(nestLevel - 1, 0) * 2));
    if (nestLevel > 0) {
        process.stdout.write("- ");
    }
    console.log(folderPath.split("/").pop());

    files.forEach(file => {
        if (!fs.statSync(`${folderPath}/${file}`).isDirectory()) {
            console.log(" ".repeat(nestLevel * 2) + `- ${file}`);
        }
    });

    directories.forEach(directory => {
        printDirectoryContents(`${folderPath}/${directory}`, nestLevel + 1);
    });
}
