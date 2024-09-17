if __name__ == "__main__":
    text = input()
    compressing = input() == "compress"
    
    if compressing:
        current_letter_count = 1
    
        for i in range(len(text)):
            if i < len(text) - 1 and text[i] == text[i + 1]:
                current_letter_count += 1
            else:
                print(text[i], end="")
                
                if current_letter_count > 1:
                    print(current_letter_count, end="")
                
                current_letter_count = 1
    else:
        i = 0
        while i < len(text):
            print(text[i], end="")
    
            count_buffer = ""
            j = i
            while j < len(text):
                if j < len(text) - 1 and text[j + 1].isdigit():
                    count_buffer += text[j + 1]
                else:
                    if count_buffer:
                        count = int(count_buffer)
                        print(text[i] * (count - 1), end="")
    
                    i = j
                    break
                j += 1
    
            i += 1
    
    print()
