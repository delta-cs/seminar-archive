def jePalindrom(s):
    return s == s[::-1]
def najdiPalindrom(text):
    nejdelsi = ""
    for i in range(len(text)):
        for j in range(i + len(nejdelsi) + 1, len(text) + 1):
            if jePalindrom(text[i:j]) and len(text[i:j]) > len(nejdelsi):
                nejdelsi = text[i:j]

    return nejdelsi

print(najdiPalindrom(input()))