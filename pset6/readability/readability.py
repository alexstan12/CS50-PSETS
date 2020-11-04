from cs50 import get_string

def main() :
    text = get_string("Text: ")
    count = 0
    words = 0
    sentences = 0
    for char in text :
        if char.isalpha() :
            count+=1
        if char == ' ' :
            words+=1
        if char == '!' or char == '.'or char == '?' :
            sentences+=1
    words+=1
    if sentences == 0 :
        sentences+=1 
    result = index(words, sentences, count)
    if result > 16 :
        print("Grade 16+")
    elif result<1 :
        print("Before Grade 1")
    else :
        print(f"Grade {result}")
    
    
def index(words, sentences, letters) :
    L = float(letters*100 / words)
    S = float(sentences *100 / words)
    index  = round((0.0588 * L - 0.296 * S) - 15.8)
    return index
    
    
if __name__ == "__main__":
    main()
    