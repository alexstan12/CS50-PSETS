# TODO
from cs50 import SQL
import csv
import sys

if len(sys.argv)!=2:
    print("Usage: python [script].py [csv_name].csv")
    sys.exit(1)

db = SQL("sqlite:///students.db")

with open(sys.argv[1], 'r') as file:
    reader = csv.DictReader(file, delimiter = ',')
    for row in reader:
        names = list(row['name'].split(' '))
        firstName = names[0] if len(names) == 2 else names[0]
        middleName = None if len(names) == 2 else names[1]
        lastName = names[2] if len(names) == 3 else names[1]
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?,?,?,?,?)",firstName, middleName, lastName, row['house'], row['birth'])

