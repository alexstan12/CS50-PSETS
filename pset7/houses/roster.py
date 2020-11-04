# TODO
from cs50 import SQL
import csv
import sys

if len(sys.argv)!=2:
    print("Usage: python roster.py [house_name]")
    sys.exit(1)
db = SQL("sqlite:///students.db")
house = sys.argv[1]
list_of_dicts = []
list_of_dicts = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last ASC, first ASC", house)
for student_dict in list_of_dicts :
    for key in student_dict:
        if key =='birth':
            print('born '+str(student_dict[key]), end = '')
        elif key == 'middle':
            if student_dict[key]!=None:
                print(''+str(student_dict[key]) + ' ', end='')
        elif key == 'last':
            print(str(student_dict[key])+', ', end ='')
        else:
            print(''+str(student_dict[key]) + ' ', end='')
    print()
