def over_write(List,Dictionary):
    L=List 
    d=Dictionary 
   
    for keys in d.keys():
        if keys=="Phone":
            L[0][2]=str(int(L[0][2])-d['Phone']) 
        elif keys=="Laptop":
            L[1][2]=str(int(L[1][2])-d['Laptop'])
        else:
            L[2][2]=str(int(L[2][2])-d['TV']) 
    print("\nRemaining Stock Products:\n",L)
        
    files=open("products.txt","w")  
    for each in L:
        files.write(str(",".join(each)))
        files.write("\n")         
    files.close()
    return
