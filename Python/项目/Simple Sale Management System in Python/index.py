from utils import (
    safe_input,
    get_products,
    get_employees,
    get_sales
)

from actions import (
    register_sale,
    register_product_arrival,
    query_inventory_data,
    employees_with_most_sales,
    most_sold_items
)


def main():
    print("\n======== Sale Management System ========")
    print("""
Select an action

1. Register sale
2. Register product arrival
3. Inventory Record
4. Employees with most sales
""")

    while True:
        
        action = safe_input('int_positive', 'Choose your option: ')

        if action > 0 and action < 9:
            break

        print("Oops! Try again with an action from 1 to 8")

    
    if action == 1:
        register_sale()
    elif action == 2:
        register_product_arrival()
    elif action == 3:
        query_inventory_data()
    elif action == 4:
        employees_with_most_sales()

    print("Thanks for using the system. Have a great day\n")


while True:
    main()

    again = input("Do you want to start again? (y/n) ").strip()[0].lower()

    if (again == 'y'):
        continue
    else:
        print("See you later!\n")
        break
