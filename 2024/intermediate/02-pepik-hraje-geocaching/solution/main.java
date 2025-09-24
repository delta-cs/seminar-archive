class Main {
    public static void main(String[] args) {
        // read input
        java.util.Scanner sc = new java.util.Scanner(System.in);
        // read line
        String line = sc.nextLine();

        // for each character in the line
        for (int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);
            if (c >= 'a' && c <= 'z') {
                // this works that way we subtract 'a' from the character, add 13, and then take modulo 26, so we get it in range of the alphabet then add 'a' back to get the character
                c = (char)('a' + (c - 'a' + 13) % 26);
            } else if (c >= 'A' && c <= 'Z') {
                c = (char)('A' + (c - 'A' + 13) % 26);
            }
            System.out.print(c);
        }
    }
}
