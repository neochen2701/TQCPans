name = input()
id = input()
age = int(input())

student = {
    "name": name,
    "id": id,
    "age": age
}

print(f"The student name is {student['name']}")
print(f"The student ID is {student['id']}")
print(f"The student age is {student['age']}")