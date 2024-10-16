from pymongo import MongoClient
client=MongoClient("mongodb://localhost:27017/")
db=client["python2"]
collection=db["lulwa"]

def insert():
    rollno=input("enter student roll number")
    name=input("enter name of student")
    address=input("enter address of student")
    contact=input("enter contact number of student")
    department=input("enter department of student")
    student={
        "rollno":rollno,
        "name":name,
        "address":address,
        "contact number":contact,
        "department":department
    }
    collection.insert_one(student)
    print("successfully")

def update():
    name=input("enter name of student")
    new_address=input("enter new address of student")
    collection.updateOne({"name":name},{"$set":{"address":new_address}})
    print("update successfully")

def display():
    for student in collection.find():
        print(student)
def delete():
    rollno=input("enter roll no of student to delete")
    collection.deleteOne({"rollno":rollno})

while True:
    print("\nMenu:")
    print("1. Insert student details")
    print("2. Update student address")
    print("3. Display student information")
    print("4. Delete student record")
    print("5. Exit")
    choice=input("enter choice")
    if choice=="1":
        insert()
    elif choice=="2":
        update()
    elif choice=="3":
        display()
    elif choice=="4":
        delete()
    elif choice=="5":
        break
    
