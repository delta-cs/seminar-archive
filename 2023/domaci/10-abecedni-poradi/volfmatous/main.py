import sys

def are_words_in_order(word1, word2, descending):
    letter_case_in_order = True
    letter_case_in_order_decided = False

    shorter_length = min(len(word1), len(word2))
    for i in range(shorter_length):
        char1 = word1[i]
        char2 = word2[i]

        if char1.lower() != char2.lower():
            alphabet_ascending_order = char1.lower() < char2.lower()
            return not alphabet_ascending_order if descending else alphabet_ascending_order

        if letter_case_in_order_decided:
            continue

        if char1.islower() and char2.isupper():
            letter_case_in_order = True
            letter_case_in_order_decided = True
            continue

        if char1.isupper() and char2.islower():
            letter_case_in_order = False
            letter_case_in_order_decided = True
            continue

    if len(word1) != len(word2):
        return len(word1) < len(word2)

    return letter_case_in_order


if __name__ == "__main__":
    n = int(input())

    descending = False
    descending_decided = False
    previous_word = ""
    for _ in range(n):
        current_word = input()

        in_order_ascending = are_words_in_order(previous_word, current_word, False)
        in_order_descending = are_words_in_order(previous_word, current_word, True)

        previous_word = current_word

        if descending_decided:
            if (descending and not in_order_descending) or (not descending and not in_order_ascending):
                print("unordered")
                sys.exit()
        else:
            if in_order_ascending and in_order_descending:
                continue

            descending_decided = True

            if in_order_ascending:
                descending = False
                continue

            if in_order_descending:
                descending = True
                continue

            print("unordered")
            sys.exit()

    print("ordered")
