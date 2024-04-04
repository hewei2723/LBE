def welcome():
    entry = int(input("""\n=== Phone Book App === \n>>>What would you like to do?<<< \n1. Display Your exiting contacts \n2. Create a New contact \n3. Check an entry \n4. Delete an entry \n5. Exit \nEnter your entry here:  """))
    
   
    return entry


def phonebook():
   
    contact = {}
    
    
    while True:
        
        entry = welcome()
        
        if entry == 1:
            
            if bool(contact) != False:
                for k, v in contact.items():
                    print(k, '-->', v)
             
            else:
                print('You have an empty phonebook! Go back to the menu to add a new contact')
      
        elif entry == 2:
           
            phone_number = input('Please Enter a number: ')
            contact_name = input('Enter name in format "FirstName,LastName".: ')
            
           
            if phone_number not in contact.items():
                contact.update({contact_name:phone_number})
               
                print('Contact successfully saved')
                print('Your updated phonebook is Shown below: ')
                for k, v in contact.items():
                    print(k, '-->', v)
            else:
                print('That contact already exits in your Phonebook')
                
       
        elif entry == 3:
           
            name = input('Enter the name of the contact details you wish to view: ')
            if name in contact:
                print('The contact is',name,':',contact[name])
                
            else:
                print('That contact does not exist! Return to the main menu to enter the contact')
                
             
        elif entry == 4:
           
            name = input('Enter the name of the contact you wish to delete: ')
          
            if name in contact:
                
                print('The contact is',name,':',contact[name])
                
                
            else:
                print('That contact does not exist! Return to the main menu to enter the contact')
            
            
           
            confirm = input('Are you sure you wish to delete this contact? Yes/No: ')
            
            if confirm.capitalize() == 'Yes':
                
                contact.pop(name,None)
                
                for k, v in contact.items():
                    print('Your Updated Phonebook is shown below:')
                    print(k, '-->', v)
           
            else:
                print('Return to Main1231 Menu')
            
        elif entry == 5:
            print('Thanks for using the Py Contact Book')
            break
            
        
        else:
            print('Incorrect Entry!')
            
            
       

    

phonebook()
