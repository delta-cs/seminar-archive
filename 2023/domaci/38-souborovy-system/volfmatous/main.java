import java.util.Scanner;
import java.util.ArrayList;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String path1 = scanner.nextLine();
        String path2 = scanner.nextLine();

        boolean path2IsAbsolute = path2.startsWith("/");

        ArrayList<String> path1Segments = dividePath(path1);
        ArrayList<String> path2Segments = dividePath(path2);

        String result = "";

        if (path2IsAbsolute) {
            int longerPathLength = Math.max(path1Segments.size(), path2Segments.size());
            for (int i = 0; i < longerPathLength; i++) {
                if (i < path1Segments.size() && i < path2Segments.size() && path1Segments.get(i).equals(path2Segments.get(i))) {
                    continue;
                }

                for (int j = i; j < path1Segments.size(); j++) {
                    result += "../";
                }

                for (int j = i; j < path2Segments.size(); j++) {
                    result += path2Segments.get(j) + "/";
                }

                break;
            }
        } else {
            for (String segment : path2Segments) {
                if (segment.equals("..")) {
                    if (path1Segments.size() < 1) {
                        continue;
                    }

                    path1Segments.remove(path1Segments.size() - 1);
                } else {
                    path1Segments.add(segment);
                }
            }

            result = "/";
            for (String segment : path1Segments) {
                result += segment + "/";
            }
        }

        System.out.println(result);
    }

    static ArrayList<String> dividePath(String path) {
        String[] pathSplit = path.split("/", -1);
        boolean pathIsAbsolute = path.startsWith("/");

        ArrayList<String> pathSimplified = new ArrayList<>();
        for (int i = pathIsAbsolute ? 1 : 0; i < pathSplit.length - 1; i++) {
            String segment = pathSplit[i];

            if (pathIsAbsolute && segment.equals("..")) {
                if (pathSimplified.size() < 1) {
                    continue;
                }

                pathSimplified.remove(pathSimplified.size() - 1);
            } else {
                pathSimplified.add(segment);
            }
        }

        return pathSimplified;
    }
}
