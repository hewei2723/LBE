import pickle
import os
import pathlib
class Account :
    accNo = 0
    name = ''
    deposit=0
    type = ''
    
    def createAccount(self):
        self.accNo= int(input("\n\tEnter the account no : "))
        self.name = input("\tEnter the account holder name : ")
        self.type = input("\tEnter the type of account [C/S] : ")
        self.deposit = int(input("\tEnter The Initial amount(>=500 for Saving and >=1000 for current : "))
        print("\n\n\n\tAccount Created")
    
    def showAccount(self):
        print("\tAccount Number : ",self.accNo)
        print("\tAccount Holder Name : ", self.name)
        print("\tType of Account",self.type)
        print("\tBalance : ",self.deposit)
    
    def modifyAccount(self):
        print("\tAccount Number : ",self.accNo)
        self.name = input("\tModify Account Holder Name :")
        self.type = input("\tModify type of Account :")
        self.deposit = int(input("\tModify Balance :"))
        
    def depositAmount(self,amount):
        self.deposit += amount
    
    def withdrawAmount(self,amount):
        self.deposit -= amount
    
    def report(self):
        print(self.accNo, " ",self.name ," ",self.type," ", self.deposit)
    
    def getAccountNo(self):
        return self.accNo
    def getAcccountHolderName(self):
        return self.name
    def getAccountType(self):
        return self.type
    def getDeposit(self):
        return self.deposit
    

def intro():
    print("\n\n")
    print("\t========================")
    print("\t BANK MANAGEMENT SYSTEM")
    print("\t========================")

    input()



def writeAccount():
    account = Account()
    account.createAccount()
    writeAccountsFile(account)

def displayAll():
    file = pathlib.Path("accounts.data")
    if file.exists ():
        infile = open('accounts.data','rb')
        mylist = pickle.load(infile)
        for item in mylist :
            print("\t",item.accNo," ", item.name, " ",item.type, " ",item.deposit )
        infile.close()
    else :
        print("\tNo records to display")
        

def displaySp(num): 
    file = pathlib.Path("accounts.data")
    if file.exists ():
        infile = open('accounts.data','rb')
        mylist = pickle.load(infile)
        infile.close()
        found = False
        for item in mylist :
            if item.accNo == num :
                print("\tYour account Balance is = ",item.deposit)
                found = True
    else :
        print("\tNo records to Search")
    if not found :
        print("\tNo existing record with this number")

def depositAndWithdraw(num1,num2): 
    file = pathlib.Path("accounts.data")
    if file.exists ():
        infile = open('accounts.data','rb')
        mylist = pickle.load(infile)
        infile.close()
        os.remove('accounts.data')
        for item in mylist :
            if item.accNo == num1 :
                if num2 == 1 :
                    amount = int(input("\tEnter the amount to deposit : "))
                    item.deposit += amount
                    print("\tYour account is updted")
                elif num2 == 2 :
                    amount = int(input("\tEnter the amount to withdraw : "))
                    if amount <= item.deposit :
                        item.deposit -=amount
                    else :
                        print("\tYou cannot withdraw larger amount")
                
    else :
        print("\tNo records to Search")
    outfile = open('newaccounts.data','wb')
    pickle.dump(mylist, outfile)
    outfile.close()
    os.rename('newaccounts.data', 'accounts.data')

    
def deleteAccount(num):
    file = pathlib.Path("accounts.data")
    if file.exists ():
        infile = open('accounts.data','rb')
        oldlist = pickle.load(infile)
        infile.close()
        newlist = []
        for item in oldlist :
            if item.accNo != num :
                newlist.append(item)
        os.remove('accounts.data')
        outfile = open('newaccounts.data','wb')
        pickle.dump(newlist, outfile)
        outfile.close()
        os.rename('newaccounts.data', 'accounts.data')
     
def modifyAccount(num):
    file = pathlib.Path("accounts.data")
    if file.exists ():
        infile = open('accounts.data','rb')
        oldlist = pickle.load(infile)
        infile.close()
        os.remove('accounts.data')
        for item in oldlist :
            if item.accNo == num :
                item.name = input("\tEnter the account holder name : ")
                item.type = input("\tEnter the account Type : ")
                item.deposit = int(input("\tEnter the Amount : "))
        
        outfile = open('newaccounts.data','wb')
        pickle.dump(oldlist, outfile)
        outfile.close()
        os.rename('newaccounts.data', 'accounts.data')
   

def writeAccountsFile(account) : 
    
    file = pathlib.Path("accounts.data")
    if file.exists ():
        infile = open('accounts.data','rb')
        oldlist = pickle.load(infile)
        oldlist.append(account)
        infile.close()
        os.remove('accounts.data')
    else :
        oldlist = [account]
    outfile = open('newaccounts.data','wb')
    pickle.dump(oldlist, outfile)
    outfile.close()
    os.rename('newaccounts.data', 'accounts.data')
    
        

ch=''
num=0
intro()

while ch != 8:
    print("\n")
    print("\tMAIN MENU")
    print("\t1. NEW ACCOUNT")
    print("\t2. DEPOSIT")
    print("\t3. WITHDRAW")
    print("\t4. BALANCE")
    print("\t5. DISPLAY ACCOUNT LIST")
    print("\t6. CLOSE ACCOUNT")
    print("\t7. MODIFY ACCOUNT")
    print("\t8. EXIT")
    print("\tSelect Your Option (1-8) ")
    ch = input("\tEnter your choice : ")

    
    if ch == '1':
        writeAccount()
    elif ch =='2':
        num = int(input("\tEnter The account No. : "))
        depositAndWithdraw(num, 1)
    elif ch == '3':
        num = int(input("\tEnter The account No. : "))
        depositAndWithdraw(num, 2)
    elif ch == '4':
        num = int(input("\tEnter The account No. : "))
        displaySp(num)
    elif ch == '5':
        displayAll();
    elif ch == '6':
        num =int(input("\tEnter The account No. : "))
        deleteAccount(num)
    elif ch == '7':
        num = int(input("\tEnter The account No. : "))
        modifyAccount(num)
    elif ch == '8':
        print("\tThanks for using bank managemnt system")
        break
    else :
        print("Invalid choice")
    
   
    


    
    
    
    
    
    
    
    
    
    
