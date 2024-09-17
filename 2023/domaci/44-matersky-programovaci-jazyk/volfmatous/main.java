import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<String, Double> variables = new HashMap<>();

        int c = scanner.nextInt();
        scanner.nextLine();

        List<String[]> linesSplit = new ArrayList<>();
        List<Integer> linesNestLevels = new ArrayList<>();

        for (int i = 0; i < c; i++) {
            String line = scanner.nextLine().split("//")[0].stripTrailing();

            if (line.isEmpty()) {
                continue;
            }

            int nestLevel = 0;
            while (line.length() > 2 && line.startsWith("  ")) {
                line = line.substring(2);
                nestLevel++;
            }

            linesSplit.add(line.split(" "));
            linesNestLevels.add(nestLevel);
        }

        List<Double> output = new ArrayList<>();

        boolean repeating = false;
        int repeatStartLineIndex = 0;
        int nestLevelCurrent = 0;

        for (int i = 0; i < linesSplit.size(); i++) {
            String[] lineSplit = linesSplit.get(i);
            int nestLevel = linesNestLevels.get(i);

            if (nestLevel > nestLevelCurrent) {
                continue;
            }

            boolean atLastLine = i >= linesSplit.size() - 1;

            if (repeating && (nestLevel < linesNestLevels.get(repeatStartLineIndex) + 1 || atLastLine)) {
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
                    if (lineSplit.length < 5 || !lineSplit[lineSplit.length - 1].equals("tak")) {
                        System.out.println("error");
                        return;
                    }

                    boolean[] conditionResult = conditionPass(Arrays.copyOfRange(lineSplit, 1, lineSplit.length - 1), variables);

                    if (!conditionResult[0]) {
                        System.out.println("error");
                        return;
                    }

                    if (conditionResult[1]) {
                        nestLevelCurrent++;
                    }

                    break;
                }

                case "dokud": {
                    if (lineSplit.length < 5 || !lineSplit[lineSplit.length - 1].equals("tak")) {
                        System.out.println("error");
                        return;
                    }

                    boolean[] conditionResult = conditionPass(Arrays.copyOfRange(lineSplit, 1, lineSplit.length - 1), variables);

                    if (!conditionResult[0]) {
                        System.out.println("error");
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
                    double expressionResult = expressionValue(Arrays.copyOfRange(lineSplit, 1, lineSplit.length), variables);

                    if (Double.isNaN(expressionResult)) {
                        System.out.println("error");
                        return;
                    }

                    output.add(expressionResult);
                    break;
                }

                default: {
                    String variableName = lineSplit[0];

                    if (Character.toLowerCase(variableName.charAt(0)) < 'a' || Character.toLowerCase(variableName.charAt(0)) > 'z'
                            || lineSplit.length < 2 || !lineSplit[1].equals("je")) {
                        System.out.println("error");
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
                            System.out.println("error");
                            return;
                    }

                    double expressionResult = expressionValue(Arrays.copyOfRange(lineSplit, 2, lineSplit.length), variables);

                    if (Double.isNaN(expressionResult)) {
                        System.out.println("error");
                        return;
                    }

                    variables.put(variableName, expressionResult);
                    break;
                }
            }
        }

        for (double line : output) {
            System.out.println(new DecimalFormat("#.################").format(line));
        }
    }

    static boolean[] conditionPass(String[] lineSplit, Map<String, Double> variables) {
        List<Integer> orIndexes = new ArrayList<>();
        orIndexes.add(-1);
        for (int i = 0; i < lineSplit.length; i++) {
            if (lineSplit[i].equals("nebo")) {
                orIndexes.add(i);
            }
        }

        orIndexes.add(lineSplit.length);

        boolean conditionPass = false;

        for (int i = 0; i < orIndexes.size() - 1; i++) {
            int startIndex = orIndexes.get(i) + 1;
            int endIndex = orIndexes.get(i + 1) - 1;

            int comparatorIndex = -1;
            for (int c = startIndex; c <= endIndex; c++) {
                if (lineSplit[c].equals("rovno") || lineSplit[c].equals("aspon") || lineSplit[c].equals("nejvic")) {
                    comparatorIndex = c;
                    break;
                }
            }

            if (comparatorIndex == -1) {
                return new boolean[]{false, false};
            }

            String comparator = lineSplit[comparatorIndex];
            double expression1Result = expressionValue(Arrays.copyOfRange(lineSplit, startIndex, comparatorIndex), variables);
            double expression2Result = expressionValue(Arrays.copyOfRange(lineSplit, comparatorIndex + 1, endIndex + 1), variables);

            if (Double.isNaN(expression1Result) || Double.isNaN(expression2Result)) {
                return new boolean[]{false, false};
            }

            if (!conditionPass) {
                double expression1 = expression1Result;
                double expression2 = expression2Result;

                switch (comparator) {
                    case "rovno":
                        conditionPass = expression1 == expression2;
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

        return new boolean[]{true, conditionPass};
    }

    static double expressionValue(String[] lineSplit, Map<String, Double> variables) {
        if (lineSplit.length % 2 != 1) {
            return Double.NaN;
        }

        boolean expressionAdd = true;
        double expressionValue = 0;

        for (int w = 0; w < lineSplit.length; w++) {
            if (w % 2 == 0) {
                double value;
                try {
                    value = Double.parseDouble(lineSplit[w]);
                } catch (NumberFormatException e) {
                    if (!variables.containsKey(lineSplit[w])) {
                        return Double.NaN;
                    }

                    value = variables.get(lineSplit[w]);
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
                        return Double.NaN;
                }
            }
        }

        return expressionValue;
    }
}
