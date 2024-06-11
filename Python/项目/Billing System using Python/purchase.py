
def purchase(List):
    L=List 
    a_name=input("Please enter your name: ")
    print("\nHello "+a_name+"! Welcome to Electronic Store.\nLook at above and select product as your choice.")
    q={}  
    flag="Y"
    while flag.upper()=="Y":  
        product=input("\nWhat product do you want to buy? ")  
        product_name=product.upper()    
        
        if product_name==L[0][0].upper() or product_name==L[1][0].upper() or product_name==L[2][0].upper(): 
            p=True
            while p==True:
                try:
                    p_quantity=int(input("How many "+product+" do you want to buy: "))
                    p=False
                except:                             
                    print("\t\tError!!!\nPlease enter integer value!! ") 
            if product_name==L[0][0].upper() and p_quantity<=int(L[0][2]):       
                q[product_name]=p_quantity    
            elif product_name==L[1][0].upper() and p_quantity<=int(L[1][2]):
                    q[product_name]=p_quantity
            elif product_name==L[2][0].upper() and p_quantity<=int(L[2][2]):
                    q[product_name]=p_quantity
            else:
                print("\nSorry!! "+a_name+"!, "+product+" is out of stock.\nWe will add stock of "+product+" later. \nLets hope, you will get this product after next shopping.\n")
                
            flag=(input(a_name+" do you want buy more products?(Y/N)"))
        else:
            print("sorry!! "+product+" is not available in our store.")
            print("\nChoose from following products please!")
            print("--------------------------------------------")
            print("PRODUCT\t\tPRICE\t\tQUANTITY")
            print("--------------------------------------------")
            for i in range(len(L)):
                print(L[i][0],"\t\t",L[i][1],"\t\t",L[i][2])
            print("--------------------------------------------")
                
    print ("\nYou Choosed Items and it's Quantity respectively:\n",q,"\n")
   
    f_amount=0 
    for keys in q.keys():
        if keys==L[0][0].upper(): 
            p_price=int(L[0][1])
            p_num=int(q[keys])
            p_amount=(p_price*p_num)
            f_amount+=(p_price*p_num)
            print("\nTotal cost for Phone: ",p_amount) 
        elif keys==L[1][0].upper():  
            l_price=int(L[1][1])
            l_num=int(q[keys])
            l_amount=(l_price*l_num)
            f_amount+=(l_price*l_num)
            print("Total cost for Laptop: ",l_amount)
        else:                        
            h_price=int(L[2][1])
            h_num=int(q[keys])
            h_amount=(h_price*h_num)
            f_amount+=(h_price*h_num)
            print("Total cost for TV: ",h_amount)
    print("\nYour discountable total amount is: ", f_amount)

   
    disc=float(input("Please enter your expected discount (%): "))
    dis=0.0
    if ((f_amount>=5000) and (f_amount<10000)):
        discount=disc
        if(discount<=5.0):
            dis=(discount*f_amount)/100
            total=float(f_amount-dis)
            print("You got your expected "+str(disc)+"% discount and amount is: ",dis)
        else:
            discount=5.0
            dis=(discount*f_amount)/100
            total=float(f_amount-dis)
            print("You did not got your expected "+str(disc)+"% discount\nBecause, your totel purchase is not meet the minimum criteria for "+str(disc)+"% discount.")
            print("You got basic 5% discount and discounted amount is:",dis)
    elif (f_amount>=10000):
        discount=disc
        if(discount<=10.0):
            dis=(discount*f_amount)/100
            total=float(f_amount-dis)
            print("You got your expected "+str(disc)+"% discount and amount is: ",dis)
        else:
            discount=10.0
            dis=(discount*f_amount)/100
            total=float(f_amount-dis)
            print("You did not got your expected "+str(disc)+"% discount\nBecause, your totel purchase is not meet the minimum criteria for "+str(disc)+"% discount.")
            print("You got basic 10% discount and discounted amount is:",dis)
    else:
        discount=0.0
        total=float(f_amount)
        print("You did not got your expected "+str(disc)+"% discount\nBecause, your totel purchase is not meet the minimum criteria for "+str(disc)+"% discount.")
    print("Your payable amount is: ", total)

  
    
    import datetime 
    dt=str(datetime.datetime.now().year)+"-"+str(datetime.datetime.now().month)+"-"+str(datetime.datetime.now().day)+"-"+str(datetime.datetime.now().hour)+"-"+str(datetime.datetime.now().minute)+"-"+str(datetime.datetime.now().second)
    invoice=str(dt)    
    t=str(datetime.datetime.now().year)+"-"+str(datetime.datetime.now().month)+"-"+str(datetime.datetime.now().day)
    d=str(t)    
    u=str(datetime.datetime.now().hour)+":"+str(datetime.datetime.now().minute)+":"+str(datetime.datetime.now().second) 
    e=str(u)    
    
    file=open(invoice+" ("+a_name+").txt","w")      
    file.write("=============================================================")
    file.write("\nELECTRONIC STORE\t\t\t\tINVOICE")
    file.write("\n\nInvoice: "+invoice+"\t\tDate: "+d+"\n\t\t\t\t\tTime: "+e+"")
    file.write("\nName of Customer: "+str(a_name)+"")
    file.write("\n=============================================================")
    file.write("\nPARTICULAR\tQUANTITY\tUNIT PRICE\tTOTAL")                     
    file.write("\n-------------------------------------------------------------")
          
    for keys in q.keys():           
        if keys=="Phone":
            file.write(str("\n"+str(keys)+" \t\t "+str(q['Phone'])+" \t\t "+str(L[0][1])+" \t\t "+str(p_amount)))
        elif keys=="Laptop":
            file.write(str("\n"+str(keys)+" \t\t "+str(q['Laptop'])+" \t\t "+str(L[1][1])+" \t\t "+str(l_amount)))
        else: 
            file.write(str("\n"+str(keys)+" \t\t "+str(q['TV'])+" \t\t "+str(L[2][1])+" \t\t "+str(h_amount)))
       
    file.write("\n\n-------------------------------------------------------------")
    file.write("\n\t\t\tYour discountable amount: "+str(f_amount))
    file.write("\n-------------------------------------------------------------")
    file.write("\n\t\t   Your "+str(discount)+"% discounted amount is: "+str(dis))
    file.write("\n-------------------------------------------------------------")
    file.write("\n\t\t\t Your payable amount is: "+str(total))
    file.write("\n-------------------------------------------------------------")
    file.write("\n\n\tThank You "+a_name+" for your shopping.\n\t\tSee you again!")
    file.write("\n=============================================================")
    file.close()
    return q
    
