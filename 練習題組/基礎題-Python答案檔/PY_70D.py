name = input()
id = input()
age = int(input())
school1 = input()
school2 = input()
school3 = input()
a = int(input())

student = {
    "name": name,
    "id": id,
    "age": age,
    "school": [school1, school2, school3]
}

print(f"The student name is {student['name']}")
print(f"The student ID is {student['id']}")
print(f"The student age is {student['age']}")
print(f"The specific school is {student['school'][a]}")

# 在這裡建立一個字典 student，使用 name 來當作 key 儲存人名, 使用 id 來當作 key 儲存學號，使用 age 來當作 key 儲存年齡，使用 school 來當作 key 儲存含有三間學校的串列

# 輸出 The student name is {student_name}，使用索引鍵來取得 student 字典儲存的人名
# 輸出 The student ID is {student_id}，使用索引鍵來取得 student 字典儲存的學號
# 輸出 The student age is {student_age}，使用索引鍵來取得 student 字典儲存的年齡
# 輸出 The specific school is {student_specific_school}，使用索引鍵來取得 student 字典儲存的學校，並輸出索引值為 a 的學校