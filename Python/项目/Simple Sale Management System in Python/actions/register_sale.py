from utils import (
    safe_input,
    select_by_id_or_name,
    today,
    get_products,
    update_products,
    get_employees,
    get_sales,
    add_sale
)


def register_sale():
    sale = {
        "date": today()
    }

    print("--- Register sale ---\n")
    print("Who is selling the product?")

    employees = get_employees()
    for e in employees:
        print("- %s (%s)" % (e['name'], e['id']))
    print()

    employee = select_by_id_or_name(employees, 'employee')
    sale['employee_id'] = employee['id']

    print("Selected: %s (%s)\n" % (employee['name'], employee['id']))
    print("Which product is it?")
    products = get_products()

    for p in products:
        print("- %s (%s) (%s in stock)" %
              (p['name'], p['id'], p['quantity']))
    print()

    product = select_by_id_or_name(products, 'product')

    sale['product_id'] = product['id']

    print("Selected: %s (%s) (%s in stock)\n" %
          (product['name'], product['id'], (product['quantity'])))

    quantity = 0
    while True:
        quantity = safe_input("int_positive", "How many items? ")
        if quantity > 0 and quantity <= product['quantity']:
            print("The order is valid. Calculating total price...")
            break
        else:
            print(
                "The order is invalid. Please choose a number that is not greater than the quantity in stock")

    # we are updating the reference, so this dictionary is also modified
    # on the products list
    product['quantity'] -= quantity
    sale['num_products'] = quantity
    sale['total_price'] = quantity * product['price']

    print("\nTotal price: $%s (+ $%s tax)" %
          (sale['total_price'], sale['total_price'] * 0.16))

    sale['id'] = len(get_sales())

    print("\nThis order's id is", sale['id'])

    update_products(products)
    add_sale(sale)
