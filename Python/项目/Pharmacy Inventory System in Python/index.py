import menu_functions
import sys
menu_choice=0
while menu_choice != 6:
    print('##### Pharmacy Inventory System ####')
    print('-----------------------------')
    print("|Enter 1 for Pharmacy menu  |")
    print('----------------------------')
    print('|Enter 2 for Customer menu  |')
    print('----------------------------')
    print('|Enter 3 for Supplier menu  |')
    print('----------------------------') 
    print('|Enter 4 for Report menu    |')
    print('----------------------------')
    print('|Enter 5 for Invoicing      |')
    print('----------------------------')
    print('|Enter 6 to Exit program|')
    print('-----------------------------')
    menu_choice=int(input("Enter Your Choice\n"))
    if menu_choice==1:
        menu_functions.medicine_menu()
    elif menu_choice==2:
        menu_functions.customer_menu()
    elif menu_choice==3:
        menu_functions.supplier_menu()
    elif menu_choice==4:
        menu_functions.report_menu()
    elif menu_choice==5:
        menu_functions.invoicing_menu()
    elif menu_choice==6:
        break
    else:
        print("Invalid Input! Try Again! \n")    
sys.exit()
