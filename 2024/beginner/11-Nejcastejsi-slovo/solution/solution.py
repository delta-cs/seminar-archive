

if __name__ == "__main__":
    words = input().split(" ")

    word_dict = {}

    for w in words:
        try:
            word_dict[w] += 1
        except:
            word_dict.update({w : 1})
        
    
    print(max(word_dict, key=word_dict.get))