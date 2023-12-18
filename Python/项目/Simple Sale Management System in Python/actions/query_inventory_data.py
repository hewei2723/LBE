from utils import (
    get_products,
    select_by_id_or_name,
    safe_input
)


def query_inventory_data():

    print("---Query inventory data---")
    print("Which product is it?")

    list_products = get_products()

    for products in list_products:
        print(products['name'], products['id'])

    this_product = select_by_id_or_name(list_products, 'product')

    print("Description:", this_product["description"])
    print("id:", this_product["id"])
    print("Price per unit:", this_product["price"])
    print("Quantity in stock:", this_product["quantity"])
    print("Season:", this_product["season"])
    print("Categories:", this_product["type"], "-", this_product["sub_type"])
