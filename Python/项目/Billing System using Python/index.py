#module mane: main
import read
import purchase
import write
again="Y"
while again.upper()=="Y":
    a=read.read_file()
    b=purchase.purchase(a)
    write.over_write(a,b)
    again=input("\nIs any new customer waiting to buy product? ")
print("\nThank you for shopping!")
print("Please check your invoice for your shopping details, \nWe created receipt in a text file format for you.")
