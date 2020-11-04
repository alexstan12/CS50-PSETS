import csv

file_name = "CS50 2019 - Lecture 7 - Favorite TV Shows (Responses) - Form Responses 1.csv"

with open(file_name, "r") as file:
    reader = csv.DictReader(file)
    for row in reader :
        print(row["title"])