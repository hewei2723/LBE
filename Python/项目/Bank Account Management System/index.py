import csv
import datetime
import os

volatile_data =[]
recovery_image = []
def back():
    con = input("Back to Main Menu ? Y/n")
    if con == "Y":
        main_menu()
    else:
     w = input("Warning your recovery data may loss, Are you sure you want to exit? Y/n :")
     if w == "Y":
         exit(0)
     else:
         back()
def load_data():
    
    get_temp_data = []
    with open("User_data.csv", "r", newline='') as file:
        read = csv.DictReader(file)
        for row in read:
            get_temp_data.append(row)
    
    return get_temp_data


if os.path.exists('User_data.csv'):
    volatile_data = load_data()

def update_date():
    get = input("Enter the card Number : ")
    update_data,i = search_data(get)
    volatile_data.remove(update_data)
    print("Which Part do you want to update? ")
    print("\n1: Card Number \n2: Name\n3: Age\n4: NRIC\n5: Amount ($)")
    memory = {"1": "Card Number", "2": "Name","3": "Age ","4": "NRIC", "5" :"Amount ($)"}
    k = input()
    for mem,val in memory.items():
        if k == mem:
          update_data[val] = input("Enter the new "+val+" : ")
          break
    volatile_data.insert(i, update_data)
    with open("User_data.csv", "w",newline='') as file:
        csv_writer = csv.DictWriter(file,fieldnames=["Card Number","Name","Age","NRIC","Amount ($)","Registered Date"])
        file.seek(0, 2)
        if file.tell() == 0:
            csv_writer.writeheader()  
        csv_writer.writerows(volatile_data)
    back()

def delete_data():
    danger = input("1: Remove All \n2: Remove specific data")
    recovery_image = volatile_data
    if danger == "1":
        confirm = input("Danger, Are confirm to delete? Y/n")
        if confirm == "Y":
            os.remove("User_data.csv")
            print("Data successfully erased ! \n But you still can do back up")
            back()
    elif danger == "2":
        select = input("Please enter the card number")
        delete_data,i = search_data(select)
        confirm = input("Danger, Are confirm to delete? Y/n")
        if confirm == "Y":
            recovery_image = volatile_data
            volatile_data.remove(delete_data)
            with open("User_data.csv", "w", newline='') as file:
                csv_writer = csv.DictWriter(file, fieldnames=["Card Number", "Name", "Age", "NRIC", "Amount ($)",
                                                              "Registered Date"])
                file.seek(0, 2)
                if file.tell() == 0:
                    csv_writer.writeheader()  # Write only Once
                csv_writer.writerows(volatile_data)
                back()


def search_data(card_no):
    i =0
    for data in volatile_data:
        if data["Card Number"] == card_no:
            return data,i
        i += 1
    print("Card number : "+card_no+" data not exist !")
    back()

def recovery_data():
    print("Data in system memory")
    for data in recovery_image:
        print(recovery_image)
    rec = input("Do you want to recover? Y/n")
    if rec == "Y":
        with open("User_data.csv", "w", newline='') as file:
            csv_writer = csv.DictWriter(file, fieldnames=["Card Number", "Name", "Age", "NRIC", "Amount ($)",
                                                          "Registered Date"])
            file.seek(0, 2)
            if file.tell() == 0:
                csv_writer.writeheader()
            csv_writer.writerows(recovery_image)
        back()


def view_data():
    for data in volatile_data:
        print(data)
        back()


def create_data():
    temp_data = {}
    unique = input("Enter Card Number : ")
    name = input("Enter Name : ")
    age = input("Enter Age : ")
    id = input("Enter NRIC : ")
    cash = float(input("Enter Deposit Amount : "))
    temp_data["Card Number"] =unique
    temp_data["Name"] = name
    temp_data["Age"] = age
    temp_data["NRIC"] =id
    temp_data["Amount ($)"] = cash
    x = datetime.datetime.now()
    temp_data["Registered Date"] = x.strftime("%d-%m-%Y")
    print("Saving Data...")
    with open("User_data.csv", "a",newline='') as file:
        csv_writer = csv.DictWriter(file,fieldnames=["Card Number","Name","Age","NRIC","Amount ($)","Registered Date"])
        file.seek(0,2)
        if file.tell() == 0:
            csv_writer.writeheader() 
        csv_writer.writerow(temp_data)
    back()

def main_menu():

    print("Welcome to Bank Account Management System \n====Main menu====d\n 1: Enter Data \n 2: Update Data \n 3: Delete Data \n 4: View Data \n 5: Recover Data")

    opt = input("Please Choose the option : ");
    if opt == "1":
        create_data()
        volatile_data = load_data()
    elif opt == "2":
        update_date()
        volatile_data = load_data()
    elif opt == "3":
        delete_data()
    elif opt == "4":
        view_data()
    elif opt == "5":
        recovery_data()






main_menu()



