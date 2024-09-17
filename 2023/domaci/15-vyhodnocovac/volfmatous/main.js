const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n;

let result = 0;

let operation = "+";

let temp1 = 0;
let temp1Operation = "+";
let temp1Used = false;

let temp2 = 0;
let temp2Operation = "+";
let temp2Used = false;

let operand;
let nextOperation;

let loadedOperands = 0;

rl.on("line", (line) => {
    if (n === undefined) {
        n = parseInt(line);
        return;
    }

    if (operand === undefined) {
        loadedOperands++;

        operand = parseFloat(line);

        return;
    }

    nextOperation = line;

    if (temp2Used) {
        temp2 = applyOperation(temp2, temp2Operation, operand);
        temp2Operation = nextOperation;
    }

    if (nextOperation === "+" || nextOperation === "-" || loadedOperands >= n) {
        if (temp1Used) {
            temp1 = applyOperation(temp1, temp1Operation, temp2Used ? temp2 : operand);
            result = applyOperation(result, operation, temp1);

            temp1Used = false;
            temp2Used = false;
        } else {
            result = applyOperation(result, operation, operand);
        }

        operation = nextOperation;
    } else if (nextOperation === "*" || nextOperation === "/") {
        if (temp1Used) {
            temp1 = applyOperation(temp1, temp1Operation, temp2Used ? temp2 : operand);
            temp2Used = false;
        } else {
            temp1Used = true;
            temp1 = operand;
        }

        temp1Operation = nextOperation;
    } else if (nextOperation === "^") {
        if (temp1Used) {
            if (!temp2Used) {
                if (temp1Operation === "^") {
                    temp1 = applyOperation(temp1, temp1Operation, operand);
                    temp1Operation = nextOperation;
                } else {
                    temp2Used = true;
                    temp2 = operand;
                    temp2Operation = nextOperation;
                }
            }
        } else {
            temp1Used = true;
            temp1 = operand;
            temp1Operation = nextOperation;
        }
    }

    operand = undefined;
    nextOperation = undefined;

    if (loadedOperands >= n) {
        rl.close();
    }
});

rl.on("close", () => {
    console.log(result);
});

function applyOperation(a, operation, b) {
    let result = 0;

    switch (operation) {
        case "+":
            result = a + b;
            break;

        case "-":
            result = a - b;
            break;

        case "*":
            result = a * b;
            break;

        case "/":
            result = a / b;
            break;

        case "^":
            result = Math.pow(a, b);
            break;
    }

    return result;
}
