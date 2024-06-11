import os
import fileinput

def menuDisplay():
    print('\n')
    print('|=======================================|')
    print('|=== Stock Inventory Management Menu ===|')
    print('|=======================================|')
    print('\n')
    print('(1) Add New Item to Inventory')
    print('(2) Remove Item from Inventory')
    print('(3) Update Inventory')
    print('(4) Search Item in Inventory')
    print('(5) Print Inventory Report')
    print('(6) Exit Application')
    CHOICE = int(input("Enter choice: "))
    menuSelection(CHOICE)

def menuSelection(CHOICE):
    if CHOICE == 1:
        addInventory()
    elif CHOICE == 2:
        removeInventory()
    elif CHOICE == 3:
        updateInventory()
    elif CHOICE == 4:
        searchInventory()
    elif CHOICE == 5:
        printInventory()
    elif CHOICE == 6:
        exit()

def addInventory():
    InventoryFile = open('Inventory.txt', 'a')
    print("Adding Inventory")
    print("================")
    item_description = input("Enter the name of the item: ")
    item_quantity = input("Enter the quantity of the item: ")
    InventoryFile.write(item_description + '\n')
    InventoryFile.write(item_quantity + '\n')
    InventoryFile.close()
    CHOICE = int(input('Enter 1 to continue or 0 to exit: '))
    if CHOICE == 1:
            menuDisplay()
    else:
        exit()
    
def removeInventory():
    print("Removing Inventory")
    print("==================")
    item_description = input("Enter the item name to remove from inventory: ")

    file = fileinput.input('Inventory.txt', inplace=True)

    for line in file:
         if item_description in line:
             for i in range(1):
                 next(file, None)
         else:
             print(line.strip('\n'), end='\n')
    item_description
    CHOICE = int(input('Enter 1 to continue or 0 to exit: '))
    if CHOICE == 1:
            menuDisplay()
    else:
        exit()

def updateInventory():
    print("Updating Inventory")
    print("==================")
    item_description = input('Enter the item to update: ')
    item_quantity = int(input("Enter the updated quantity. Enter - for less: "))

    with open('Inventory.txt', 'r') as f:
        filedata = f.readlines()

    replace = ""
    line_number = 0
    count = 0
    f = open('Inventory.txt','r')
    file = f.read().split('\n')
    for i, line in enumerate(file):
        if item_description in line:
            for b in file[i+1:i+2]:
                value = int(b)
                change = value + (item_quantity)
                replace = b.replace(b, str(change))
                line_number = count
            count = i + 1      
    f.close()
    
    filedata[count] = replace + '\n'

    with open('Inventory.txt', 'w') as f:
        for line in filedata:
            f.write(line)
                                            
                
    CHOICE = int(input('Enter 1 to continue or 0 to exit: '))
    if CHOICE == 1:
            menuDisplay()
    else:
        exit()

def searchInventory():
    print('Searching Inventory')
    print('===================')
    item_description = input('Enter the name of the item: ')
    
    f = open('Inventory.txt', 'r')
    search = f.readlines()
    f.close
    for i, line in enumerate(search):
        if item_description in line:
            for b in search[i:i+1]:
                print('Item:     ', b, end='')
            for c in search[i+1:i+2]:
                print('Quantity: ', c, end='')
                print('----------')
        
    CHOICE = int(input('Enter 1 to continue or 0 to exit: '))
    if CHOICE == 1:
            menuDisplay()
    else:
        exit()
        
def printInventory():
    InventoryFile = open('Inventory.txt', 'r')
    item_description = InventoryFile.readline()
    print('Current Inventory')
    print('-----------------')
    while item_description != '':
        item_quantity = InventoryFile.readline()
        item_description = item_description.rstrip('\n')
        item_quantity = item_quantity.rstrip('\n')
        print('Item:     ', item_description)
        print('Quantity: ', item_quantity)
        print('----------')
        item_description = InventoryFile.readline()
    InventoryFile.close()

    CHOICE = int(input('Enter 1 to continue or 0 to exit: '))
    if CHOICE == 1:
            menuDisplay()
    else:
        exit()

menuDisplay()
