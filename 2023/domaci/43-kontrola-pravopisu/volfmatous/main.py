if __name__ == "__main__":
    dictionary_words = set()

    d = int(input())
    for _ in range(d):
        dictionary_words.add(input())

    input()

    sentence_starts = True
    previous_word_was_number = False

    l = int(input())
    for _ in range(l):
        line = input()

        print(line)

        if len(line) < 1:
            continue

        error_indexes = []
        error_lengths = []
        error_messages = []

        current_index = 0
        duplicate_space_flag = False

        words = line.split(" ")

        for w in words:
            word = w

            if len(word) < 1:
                if duplicate_space_flag:
                    error_lengths[-1] += 1
                else:
                    error_indexes.append(max(0, current_index - 1))
                    error_lengths.append(2)
                    error_messages.append("duplicate space")
                    duplicate_space_flag = True

                current_index += 1
                continue

            duplicate_space_flag = False

            ends_with_dot = False
            if word.endswith("."):
                word = word[:-1]
                ends_with_dot = True

            is_number = True
            for c in word:
                if not ("0" <= c <= "9"):
                    is_number = False
                    break

            word_capitalized = word.capitalize()
            word_lowercase = word.lower()

            if is_number:
                if len(word) > 3:
                    error_indexes.append(current_index)
                    error_lengths.append(len(word))
                    error_messages.append("incorrect number formatting")
            elif word_capitalized not in dictionary_words and word_lowercase not in dictionary_words:
                error_indexes.append(current_index)
                error_lengths.append(len(word))
                error_messages.append("unknown word")
            elif word[0].isupper() and not sentence_starts and not previous_word_was_number and word not in dictionary_words:
                error_indexes.append(current_index)
                error_lengths.append(len(word))
                error_messages.append("incorrect leading uppercase")
            elif word[0].islower() and (sentence_starts or word_lowercase not in dictionary_words):
                error_indexes.append(current_index)
                error_lengths.append(len(word))
                error_messages.append("incorrect leading lowercase")

            current_index += len(w) + 1
            sentence_starts = ends_with_dot and not is_number
            previous_word_was_number = is_number

        if not error_indexes:
            continue

        current_index = 0
        for j in range(len(error_indexes)):
            for _ in range(error_indexes[j] - current_index):
                print(" ", end="")
            for _ in range(error_lengths[j]):
                print("~", end="")
            current_index = error_indexes[j] + error_lengths[j]

        print()

        current_index = 0
        for j in range(len(error_indexes)):
            for _ in range(error_indexes[j] - current_index):
                print(" ", end="")
            print("^", end="")
            current_index = error_indexes[j] + 1

        print()

        for line_index in range(len(error_indexes) * 2):
            current_index = 0
            for j in range(len(error_indexes) - line_index // 2):
                for _ in range(error_indexes[j] - current_index):
                    print(" ", end="")
                if j == len(error_indexes) - (line_index + 1) // 2:
                    print("-----", error_messages[j], end="")
                else:
                    print("|", end="")
                current_index = error_indexes[j] + 1
            print()

        print()
