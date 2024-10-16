from pymongo import MongoClient

# Connect to MongoDB
client = MongoClient("mongodb://localhost:27017/")
db = client["Python"]  # Replace "your_database_name" with your actual database name
collection = db["Student"]

def insert_student():
    rollno = input("Enter Roll No: ")
    name = input("Enter Name: ")
    address = input("Enter Address: ")
    contact_no = input("Enter Contact No: ")
    department = input("Enter Department: ")
    student = {
        "rollno": rollno,
        "name": name,
        "address": address,
        "contact_no": contact_no,
        "department": department
    }
    collection.insert_one(student)
    print("Student details inserted successfully.")

def update_address():
    name = input("Enter Name of the student: ")
    new_address = input("Enter New Address: ")
    collection.update_one({"name": name}, {"$set": {"address": new_address}})
    print("Address updated successfully.")

def display_students():
    print("Student Information:")
    for student in collection.find():
        print(student)

def delete_student():
    rollno = input("Enter Roll No of the student to delete: ")
    collection.delete_one({"rollno": rollno})
    print("Student record deleted successfully.")

while True:
    print("\nMenu:")
    print("1. Insert student details")
    print("2. Update student address")
    print("3. Display student information")
    print("4. Delete student record")
    print("5. Exit")
    
    choice = input("Enter your choice: ")
    
    if choice == "1":
        insert_student()
    elif choice == "2":
        update_address()
    elif choice == "3":
        display_students()
    elif choice == "4":
        delete_student()
    elif choice == "5":
        print("Exiting program.")
        break
    else:
        print("Invalid choice. Please enter a valid option.")
