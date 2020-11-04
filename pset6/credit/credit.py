from cs50 import get_int

def main() :
    ccNumber = get_int("Number: ")
    firstDigit = 0
    secondDigit = 0
    simpleSum = 0
    doubleSum = 0
    numDigits = 0
    while ccNumber > 0 :
        secondDigit = firstDigit
        firstDigit = ccNumber %10
        if numDigits % 2 == 0 :
            simpleSum += firstDigit
        else :
            multiple = firstDigit *2
            doubleSum += multiple//10 + multiple%10
        numDigits+=1
        ccNumber//=10

    checkSum = (simpleSum + doubleSum)%10 == 0
    firstTwoDigits = firstDigit*10 + secondDigit

    if firstDigit==4 and numDigits >=13 and numDigits <=16 and checkSum :
        print("VISA")
    elif firstTwoDigits>=51 and firstTwoDigits<=55 and numDigits == 16 and checkSum :
        print("MASTERCARD")
    elif (firstTwoDigits == 34 or firstTwoDigits ==37) and numDigits == 15 and checkSum :
        print("AMEX")
    else :
        print("INVALID")


if __name__ == '__main__' :
    main()