def main():
    while True:
        try:
            height = int(input("Height: "))
        except ValueError:
            continue
        else :
            if height >=1 and height<=8 :
                    break
        
    for i in range(height) :
        for j in range(height) :
            if j < height - i -1 :
                print(" ", end="")
            else:
                print("#", end="")
        print("  ", end="")
        for j in my_range(height-1, 0, 1):
            if j< height-i-1 :
                continue
            else:
                print("#", end="")
        
        print()
    
    
def my_range(start, end, step):
    while start >=end:
        yield start
        start -= step


main()
