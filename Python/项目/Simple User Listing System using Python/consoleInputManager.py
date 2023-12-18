import contactManager


class ConsoleInputManager:
    "This static class manages the input"
    contactManager = None

    def __init__(self):
        self.contactManager = contactManager.ContactManager()

    def __getContactInfoFromUser(self):
        print("Please give the name of this contact")
        name = input()
        print("Please give the address of this contact")
        address = input()
        print("Please give the email of this contact")
        email = input()
        print("Please give the phone number of this contact")
        phone = input()
        return (name, address, email, phone)

    def __addContactToContacts(self):
        name, address, email, phone = self.__getContactInfoFromUser()
        contact = self.contactManager.addContact(name, address, email, phone)

    def __deleteContactFromContacts(self):
        name, address, email, phone = self.__getContactInfoFromUser()
        if self.contactManager.deleteContact(
                name, address, email, phone):
            print("Sucessfully removed contact!")
        else:
            print("Failed to find contact, please try again")

    def __createSearch(self):
        done = False
        name = ""
        address = ""
        email = ""
        phone = ""

        while not done:
            print("""What info do you want to search on?
                name
                address
                email
                phone?""")
            respond = input()
            if respond.lower() == "name":
                print("Please give the name of this contact")
                name = input()
            else:
                if respond.lower() == "address":
                    print("Please give the address of this contact")
                    address = input()
                else:
                    if respond.lower() == "email":
                        print("Please give the email of this contact")
                        email = input()
                    else:
                        if respond.lower() == "phone":
                            print("Please give the phone number of this contact")
                            phone = input()
                        else:
                            print("Please enter a valid input")
            print("Do you want to enter more info? (y/n)")
            done = input() == "n"
        self.contactManager.searchContacts(name, address, email, phone)

    def __parse(self, respond):
        if respond.lower() == "list":
            self.contactManager.listContacts()
            return True
        if respond.lower() == "add":
            self.__addContactToContacts()
            return True
        if respond.lower() == "delete":
            self.__deleteContactFromContacts()
            return True
        if respond.lower() == "delete all":
            self.contactManager.deleteAllContacts()
            print("Sucessfully deleted all contacts")
            return True
        if respond.lower() == "search":
            self.__createSearch()
            return True
        if respond.lower() == "close":
            print("See you next time!")
            return False
        else:
            print("Incorrect respond please respond correctly next time!")
            return True

    def run(self):
        running = True
        welcome = "======== Simple User Listing System ========"
        mainMenu = """Please select an option
        | List       | Lists all users
        | Add        | Adds an user
        | Delete     | Deletes an user
        | Delete all | Removes all users
        | Search     | Search or a user
        | Close      | Closes the address book"""
        print(welcome)
        while running:
            print(mainMenu)
            respond = input()
            running = self.__parse(respond)
