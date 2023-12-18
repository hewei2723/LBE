check1=0 
check2=0 
check3=0 
check4=0 
opp='a'  
while opp!='c': 
    opp=input("===== ANIMAL MANAGEMENT SYSTEM ===== \nAdd Animal Record[a]\
    \nUpdate Record[e] \nDisplay Record[v] \nSearch a Record[s] \nExit Application[c]\n :") 
    if opp=='a' or opp=='e' or opp=='v' or opp=='s' or opp=='c':
        if opp=='a':
            num=eval(input("How many records do you want to enter (max entries= 4)"))
            if num>=1 and num<=4:
                i=1
                while num!=i-1:
                    if i==1:
                        animal_name1=input("Enter 1st Animal name :")
                        cage_no1=input("Enter 1st Cage number :")
                        feed_no1=input("Enter 1st Feed Number :")
                        breed_no1=input("Enter 1st breed :")
                        record1=("The 1st record of animal is "+str(animal_name1)+" - "+str(cage_no1)+" - "+str(feed_no1)+\
                                 " - "+str(breed_no1))
                        check1=1
                        i+=1
                    elif i==2:
                        animal_name2=input("Enter 2nd Animal name :")
                        cage_no2=input("Enter 2nd Cage number :")
                        feed_no2=input("Enter 2nd Feed Number :")
                        breed_no2=input("Enter 2nd breed :")
                        record2="The 2nd record of animal is "+str(animal_name2)+" - "+str(cage_no2)+" - "+str(feed_no2)+\
                                 " - "+str(breed_no2)
                        check2=1
                        i+=1
                    elif i==3:
                        animal_name3=input("Enter 3rd Animal name :")
                        cage_no3=input("Enter 3rd Cage number :")
                        feed_no3=input("Enter 3rd Feed Number :")
                        breed_no3=input("Enter 3rd breed :")
                        record3=("The 1st record of animal is "+str(animal_name3)+" - "+str(cage_no3)+" - "+str(feed_no3)+\
                                 " - "+str(breed_no3))
                        check3=1
                        i+=1
                    else:
                        animal_name4=input("Enter 4th Animal name :")
                        cage_no4=input("Enter 4th Cage number :")
                        feed_no4=input("Enter 4th Feed Number :")
                        breed_no4=input("Enter 4th breed :")
                        record4=("The 1st record of animal is "+str(animal_name4)+" - "+str(cage_no4)+" - "+str(feed_no4)+\
                                 " - "+str(breed_no4))
                        check4=1
                        i+=1
            else:
               print ("wrong number")
                        
        elif opp=='e':
                Record_no=eval(input("Enter the record number to be edited"))
                if Record_no<=4 and Record_no>=1:
                    if Record_no==1:
                        animal_name1=input("Enter  1st Animal name :")
                        cage_no1=input("Enter 1st Cage number :")
                        feed_no1=input("Enter 1st Feed Number :")
                        breed_no1=input("Enter 1st breed :")
                        record1="The 1st record of animal is "+str(animal_name1)+" - "+str(cage_no1)+" - "+str(feed_no1)+\
                                 " - "+str(breed_no1)
                    elif Record_no==2:
                          
                          animal_name2=input("Enter 2nd Animal name :")
                          cage_no2=input("Enter 2nd Cage number :")
                          feed_no2=input("Enter 2nd Feed Number :")
                          breed_no2=input("Enter 2nd breed :")
                          record2="The 2nd record of animal is "+str(animal_name2)+" - "+str(cage_no2)+" - "+str(feed_no2)+\
                                 " - "+str(breed_no2)
                    elif Record_no==3:
                          animal_name3=input("Enter 3rd Animal name :")
                          cage_no3=input("Enter 3rd Cage number :")
                          feed_no3=input("Enter 3rd Feed Number :")
                          breed_no3=input("Enter 3rd breed :")
                          record3="The 1st record of animal is "+str(animal_name3)+" - "+str(cage_no3)+" - "+str(feed_no3)+\
                                     " - "+str(breed_no3)
                    else:
                        
                        animal_name4=input("Enter 4th Animal name :")
                        cage_no4=input("Enter 4th Cage number :")
                        feed_no4=input("Enter 4th Feed Number :")
                        breed_no4=input("Enter 4th breed :")
                        record4="The 1st record of animal is "+str(animal_name4)+" - "+str(cage_no4)+" - "+str(feed_no4)+\
                                 " - "+str(breed_no4)
                            
                                                     
                else:
                    print("Not Found")
        
        elif opp=='v':
            Record_no=eval(input("Enter Record No. :"))
            if Record_no>=1 and Record_no<=4:
                if Record_no==1:
                    if check1==1:
                        print (record1)
                    else:
                        print ("Not Found")
                elif Record_no==2:
                    if check2==1:
                        print (record2)
                    else:
                        print ("Not Found")
                elif  Record_no==3:
                    if check3==1:
                        print (record3)
                    else:
                        print ("Not Found")
                elif Record_no==4:
                    
                    if check4==1:
                        print (record4)
                    else:
                        print ("Not Found")
                else:
                    print ("Record Not Found")
        elif opp=='s':
            Record_=input("Search Animal name[a] \nSearch Feed number[f] \nSearch Breed number[b] \n Search Cage no[c]\n: ")
            if Record_=='a':
                animal_search=input("enter animal name :")
                if check1==1:                   
                    if animal_search==animal_name1:
                        chck1=0
                        print ("Record Find \n",record1)
                    else:
                        chck1=1
                else:
                    chck1=1
                    
                if check2==1:
                    if animal_search==animal_name2:
                        chck2=0
                        print ("Record Find \n",record2)
                    else:
                        chck2=2
                else:
                    chck2=2
                if check3==1:
                    if animal_search==animal_name3:
                        chck3=0
                        print ("Record Find \n",record3)
                    else:
                        chck3=3
                else:
                    chck3=3
                if check4==1:
                    if animal_search==animal_name4:
                        chck4=0
                        print ("Record Find \n",record4)
                    else:
                        chck4=4
                else:
                    chck4=4
                if chck1==1 and chck2==2 and chck3==3 and chck4==4:
                    print ("record not Found")
            if Record_=='b':
                breed_search=input("enter breed no :")
                if check1==1:               
                    if breed_search==breed_no1:
                        chck1=0
                        print ("Record Find \n",record1)
                    else:
                        chck1=1
                else:
                    chck1=1
                if check2==1:
                    if breed_search==breed_no2:
                        chck2=0
                        print ("Record Find \n",record2)
                    else:
                        chck2=1
                else:
                    chck2=1
                if check3==1:
                    if breed_search==breed_no3:
                        chck3=0
                        print ("Record Find \n",record3)
                    else:
                        chck3=1
                else:
                    chck3=1
                if check4==1:
                    if breed_search==breed_no4:
                        chck4=0
                        print ("Record Find \n",record4)
                    else:
                        chck4=1
                else:
                    chck4=1
                if chck1==1 and chck2==1 and chck3==1 and chck4==1:
                    print ("record not Found")
            if Record_=='f':
                feed_search=input("enter feed no :")
                if check1==1:                   
                    if feed_search==feed_no1:
                        chck1=0
                        print ("Record Find \n",record1)
                    else:
                        chck1=1
                else:
                    chck1=1
                if check2==1:
                    if feed_search==feed_no2:
                        chck2=0
                        print ("Record Find \n",record2)
                    else:
                        chck2=1
                else:
                    chck2=1
                if check3==1:
                    if feed_search==feed_no3:
                        chck3=0
                        print ("Record Find \n",record3)
                    else:
                        chck3=1
                else:
                    chck3=1
                if check4==1:
                    if feed_search==feed_no4:
                        chck4=0
                        print ("Record Find \n",record4)
                    else:
                        chck4=1
                else:
                    chck4=1
                if chck1==1 and chck2==1 and chck3==1 and chck4==1:
                    print ("record not Found")
                
            if Record_=='c':
                cage_search=input("enter cage number :")
                if check1==1:                   
                    if cage_search==cage_no1:
                        chck1=0
                        print ("Record Find \n",record1)
                    else:
                        chck1=1
                else:
                    chck1=1
                if check2==1:
                    if cage_search==cage_no2:
                        chck2=0
                        print ("Record Find \n",record2)
                    else:
                        chck2=1
                else:
                    chck2=1
                if check3==1:
                    if cage_search==cage_no3:
                        chck3=0
                        print ("Record Find \n",record3)
                    else:
                        chck3=1
                else:
                    chck3=1
                if check4==1:
                    if cage_search==cage_no4:
                        chck4=0
                        print ("Record Find \n",record4)
                    else:
                        chck4=1
                else:
                    chck4=1
                if chck1==1 and chck2==1 and chck3==1 and chck4==1:
                    print ("record not Found")
                
                    
    else:
        print ("you enter envalid key. TrY Again")
                
