from GymManager import GymManager
from Customer import Customer
from Package import Package

gymManager = GymManager()



def menu():
    print ("\n")
    print ("##### Fitness Club Management System #####")
    print ("\n")
    print ("1. Create Customer")
    print ("2. Create Package")
    print ("3. Display all packages")
    print ("4. Display all customers")
    print ("5. Search customer by name")
    print ("6. Process Subscription")
    print ("7. Process Payment")
    print ("8. Back to Menu")
    print ("\nEnter You Choice: ")

menu()

while(True):
    inp = int(input())
    if inp == 1:
        name = str(input("Enter customer's name - "))
        phoneNo = str(input("Enter customer's phone no. - "))
        joinDate = str(input("Enter joining date - "))
        customer = Customer(name, phoneNo, joinDate)
        gymManager.addCustomer(customer)

    elif inp == 2:
        type = str(input("Enter package type - "))
        facilities = str(input("Enter facilities - "))
        cost = int(input("Enter package cost - "))
        package = Package(type, facilities, cost)
        gymManager.addPackage(package)

    elif inp == 3:
        print ("PackageID\tType\tFacilities\tCost")
        for pkgId in gymManager.packages.keys():
            package = gymManager.packages[pkgId]
            packageId = pkgId
            type = package.getType()
            facilities = package.getFacilities()
            cost = package.getCost()
            print (str(packageId) + "\t" + type + "\t" + facilities + "\t" + str(cost))

    elif inp == 4:
        print ("CustomerID\tName\tPhone\tJoining Date")
        for cusId in gymManager.customers.keys():
            customer = gymManager.customers[cusId]
            customerId = cusId
            name = customer.getName()
            phoneNo = customer.getPhoneNo()
            joinDate = customer.getJoiningDate()
            print (str(customerId) + "\t" + name + "\t" + phoneNo + "\t" + joinDate)

    elif inp == 5:
        name = str(input("Enter customer name - "))
        customerId = -1
        for cusId in gymManager.customers.keys():
            customer = gymManager.customers[cusId]
            if customer.getName() == name:
                print (customer)
                customerId = cusId
                break;
        if customerId == -1:
            print ("Customer with name - {0} not found".format(name))
        else:
            packageDict = gymManager.subscriptions.get(customerId)
            print ("Customer found", gymManager.customers[customerId])
            if packageDict != {}:
                print ("Subscribed to")
                for pkgId in packageDict.keys():
                    print (gymManager.packages[pkgId], "for {0} months".format(gymManager.subscriptions[customerId][packageId]))
            else:
                print ("No subscription found for this customer")

    elif inp == 6:
        name = str(input("Enter customer name - "))
        customerId = -1
        for cusId in gymManager.customers.keys():
            customer = gymManager.customers[cusId]
            if customer.getName() == name:
                print (customer)
                customerId = cusId
                break;
        if customerId == -1:
            print ("Customer with name - {0} not found.".format(name))
            print ("Try adding a new customer.")
        else:
            print ("Customer found", gymManager.customers[customerId])
            if gymManager.packages.keys():
                for pkgId in gymManager.packages.keys():
                    print (pkgId, gymManager.packages[pkgId])
                packageId = int(input("Select a package: "))
                if packageId > max(gymManager.packages.keys()):
                    print ("Please select a valid package.")
                else:
                    months = int(input("Enter no. of months"))
                    gymManager.addSubscription(gymManager.customers[customerId], gymManager.packages[packageId], months)
                    print ("Subscription added.")
            else:
                print ("No package exists. Try adding a package first.")

    elif inp == 7:
        name = str(input("Enter customer name - "))
        customerId = -1
        for cusId in gymManager.customers.keys():
            customer = gymManager.customers[cusId]
            if customer.getName() == name:
                print (customer)
                customerId = cusId
                break;
        if customerId == -1:
            print ("Customer with name - {0} not found.".format(name))
            print ("Try adding a new customer.")
        else:
            print ("Customer found", gymManager.customers[customerId])
            if gymManager.packages.keys():
                for pkgId in gymManager.packages.keys():
                    print (pkgId, gymManager.packages[pkgId])
                packageId = int(input("Select a package"))
                if packageId > max(gymManager.packages.keys()):
                    print ("Please select a valid package.")
                else:
                    if gymManager.subscriptions[customerId][packageId] > 0:
                        customer = gymManager.customers[customerId]
                        package = gymManager.packages[packageId]
                        gymManager.addPayment(customer, package, package.getCost())
                        print ("Payment added. Subscription expires in {0} months.".format(gymManager.subscriptions[customerId][packageId]))
    elif inp == 8:
        menu()
    elif inp == 9:
        gymManager.save()
        exit(0)
    else:
        print ("Please enter a valid number")
    menu()
