import csv
import sys
import re

if len(sys.argv) != 3:
    print("Usage: dna.py [database] sequence")
    sys.exit(1)

database = sys.argv[1]
# file = open(database, "r")
# if not file :
#     print(f"Could not open{}", format(database))
sequence = sys.argv[2]  # the DNA sequence
s = open(sequence, "r")
if not s:
    print("Could not open{}", format(sequence))
seq = s.read()

with open(database, "r") as file:
    reader = csv.DictReader(file)
    strHeader = reader.fieldnames
    temp = dict()  # counter for all STR's in the provided sequence of DNA
    for header in strHeader:
        temp[header] = temp.get(header, 0)
    for header in strHeader[1:]:
        pattern = "(?:" + header + ")+"
        groups = re.findall(pattern, seq)  # finds all consecutive substrings in seq and returns a list? of them
        largest = max(groups, key=len, default='')
        temp[header] = len(largest)//len(header)

    for row in reader:
        for key in row:  # checking every header
            checker = True
            if not row[key].isalpha():  # if it's not the 'name' column
                if row[key] == str(temp[key]):  # str functions turns the integer to a string
                    continue
                else:
                    checker = False
                    break
        if checker == True:
            print(row['name'])
            exit(0)

    print("No match")

