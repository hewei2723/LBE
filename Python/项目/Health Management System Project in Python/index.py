import Read_Studio_Excel_Sheet
import Write_Studio_Excel_Sheet


def AppointmentIndexInCoachesDataBase (member_ID) :
  for i in Coaches_DataBase :
        for j in Coaches_DataBase[i] :							
                if str(member_ID) == str(j[0]) :
                        Appointment_index = Coaches_DataBase[i].index(j)
                        return Appointment_index,i

print("****************************************************************************")
print("*                                                                          *")
print("*                  Welcome to Health Management System                     *")
print("*                                                                          *")
print("*                    Your Daily Health Guide                               *")
print("*                                                                          *")
print("****************************************************************************")


tries = 0
tries_flag = ""
while tries_flag != "Close the program" :

        Members_DataBase = Read_Studio_Excel_Sheet.Read_Members_DataBase()
        Coaches_DataBase  = Read_Studio_Excel_Sheet.Read_Coaches_DataBase()
                        
        print("-----------------------------------------")
        print("|Enter 1 for Admin mode			|\n|Enter 2 for member mode			|")
        print("-----------------------------------------")
        Admin_user_mode = input("Enter your mode : ") 
        

        if Admin_user_mode == "1" :																			#Admin mode
                        print("*****************************************\n|         Welcome to Admin mode         |\n*****************************************")
                        Password = input("Please enter your password : ")
                        while True :
                                
                                if Password == "12345" :
                                        print("-----------------------------------------")
                                        print("|To manage members Enter 1 		|\n|To manage downline coaches Enter 2	 	|\n|To manage appointments Enter 3 	|\n|To be back Enter E			|")
                                        print("-----------------------------------------")
                                        AdminOptions = input ("Enter your choice : ")
                                        AdminOptions = AdminOptions.upper()
                                        
                                        if AdminOptions == "1" :															#Admin mode --> Members Management
                                                        print("-----------------------------------------")
                                                        print("|To add new member Enter 1	  	|")
                                                        print("|To display member Enter 2	  	|")
                                                        print("|To delete member data Enter 3		|")
                                                        print("|To edit member data Enter 4      	|")
                                                        print("|To Back enter E      			|")
                                                        print("-----------------------------------------")
                                                        Admin_choice = input ("Enter your choice : ")
                                                        Admin_choice = Admin_choice.upper()
                                                        
                                                        if Admin_choice == "1" : 										#Admin mode --> Members Management --> Enter new member data
                                                                                try :		
                                                                                        member_ID = int(input("Enter member ID : "))
                                                                                        while member_ID in Members_DataBase :		#if Admin entered used ID
                                                                                                member_ID = int(input("This ID is unavailable, please try another ID : "))					
                                                                                        Programme=input("Enter member programme                : ")
                                                                                        CoachName=input("Enter name of coach guiding the member : ")
                                                                                        Name      =input("Enter member name                      : ")
                                                                                        Age       =input("Enter member age                       : ")
                                                                                        Gender    =input("Enter member gender                   : ")
                                                                                        Address   =input("Enter member address                   : ")
                                                                                        OriginalWeight =input("Enter member original weight                  : ")
                                                                                        CurrentWeight =input("Enter member current weight                   : ")
                                                                                        PhoneNumber=input("Enter member phone number               : ")
                                                                                        Members_DataBase[member_ID]=[Programme,CoachName,Name,Age,Gender,Address,OriginalWeight,CurrentWeight,PhoneNumber]
                                                                                        print("----------------------Member added successfully----------------------")
                                                                                except :
                                                                                        print("Member ID should be an integer number")
                                                                        
                                                        elif Admin_choice == "2" :										#Admin mode -->  Members Management --> Display member data
                                                                                try :		
                                                                                        member_ID = int(input("Enter member ID : "))
                                                                                        while member_ID not in Members_DataBase :
                                                                                                member_ID = int(input("Incorrect ID, Please Enter member ID : "))
                                                                                        print("\nmember name        : ",Members_DataBase[member_ID][2])
                                                                                        print("member age         : ",Members_DataBase[member_ID][3])
                                                                                        print("member gender      : ",Members_DataBase[member_ID][4])
                                                                                        print("member address     : ",Members_DataBase[member_ID][5])
                                                                                        print("member original weight     : ",Members_DataBase[member_ID][6])
                                                                                        print("member current weight     : ",Members_DataBase[member_ID][7])
                                                                                        print("member phone number : ",Members_DataBase[member_ID][8])
                                                                                        print("member is in "+Members_DataBase[member_ID][0]+" programme")
                                                                                        print("member is followed by Coach : "+Members_DataBase[member_ID][1])
                                                                                except :
                                                                                        print("Member ID should be an integer number")
                                                        
                                                        elif Admin_choice == "3" :										#Admin mode --> Members Management --> Delete member data
                                                                                try :		
                                                                                        member_ID = int(input("Enter member ID : "))
                                                                                        while member_ID not in Members_DataBase :
                                                                                                member_ID = int(input("Incorrect ID, Please Enter member ID : "))
                                                                                        Members_DataBase.pop(member_ID)
                                                                                        print("----------------------Member data deleted successfully----------------------")
                                                                                except :
                                                                                        print("Member ID should be an integer number")
                                                        elif Admin_choice =="4":
                                                                                try:            
                                                                                        member_ID = int(input("Enter member ID: "))
                                                                                        while member_ID not in Members_DataBase:
                                                                                                member_ID = int(input("Incorrect ID, Please Enter member ID: "))
                                                                                        while True:
                                                                                                print("------------------------------------------")
                                                                                                print("|To edit member Programme Enter 1 :      |")
                                                                                                print("|To edit Coach for programme Enter 2 :   |")
                                                                                                print("|To edit member Name Enter 3 :           |")
                                                                                                print("|To edit member Age Enter 4 :            |")
                                                                                                print("|To edit member Gender Enter 5 :         |")
                                                                                                print("|To edit member Address Enter 6 :        |")
                                                                                                print("|To edit member Current Weight Enter 8:  |")
                                                                                                print("|To edit member Phone Number Enter 9 :   |")
                                                                                                print("|To be Back Enter E                      |")
                                                                                                print("------------------------------------------")
                                                                                                Admin_choice = input("Enter your choice : ")
                                                                                                Admin_choice = Admin_choice.upper()
                                                                                                if Admin_choice == "1" :
                                                                                                        Members_DataBase[member_ID][0]=input("\nEnter member programme : ")
                                                                                                        print("----------------------Member Programme edited successfully----------------------")
                                                                                                        
                                                                                                elif Admin_choice == "2" :
                                                                                                        Members_DataBase[member_ID][1]=input("\nEnter Coach following case : ")
                                                                                                        print("----------------------Coach following case edited successfully----------------------")
                                                                        
                                                                                                elif Admin_choice == "3" :
                                                                                                        Members_DataBase[member_ID][2]=input("\nEnter member name : ")
                                                                                                        print("----------------------Member name edited successfully----------------------")
                                                                                                
                                                                                                elif Admin_choice == "4" :
                                                                                                        Members_DataBase[member_ID][3]=input("\nEnter member Age : ")
                                                                                                        print("----------------------Member age edited successfully----------------------")
                                                                                        
                                                                                                elif Admin_choice == "5" :
                                                                                                        Members_DataBase[member_ID][4]=input("\nEnter member gender : ")
                                                                                                        print("----------------------Member address gender successfully----------------------")
                                                                                                        
                                                                                                elif Admin_choice == "6" :
                                                                                                        Members_DataBase[member_ID][5]=input("\nEnter member address : ")
                                                                                                        print("----------------------Member address edited successfully----------------------")
                                                                                                elif Admin_choice == "7" :
                                                                                                        Members_DataBase[member_ID][6]=input("\nEnter member original weight : ")
                                                                                                        print("----------------------Member original weight edited successfully----------------------")
                                                                                                elif Admin_choice == "8" :
                                                                                                        Members_DataBase[member_ID][7]=input("\nEnter member current weight : ")
                                                                                                        print("----------------------Member current weight edited successfully----------------------")
                                                                                                        
                                                                                                elif Admin_choice == "9" :
                                                                                                        Members_DataBase[member_ID][8]=input("\nEnter member Phone Number : ")
                                                                                                        print("----------------------Member Phone Number edited successfully----------------------")
                                                                                        
                                                                                                elif Admin_choice == "E" :
                                                                                                        break
                                                                                                        
                                                                                                else :
                                                                                                        print("Please Enter a correct choice")
                                                                                except :
                                                                                        print("Member ID should be an integer number")
                                                                                                                                                        
                                                        elif Admin_choice == "E" :										#Admin mode --> Members Management --> Back
                                                                                break
                                                        
                                                        else :
                                                                                print("Please enter a correct choice\n")
                                                                                
                                        elif AdminOptions == "2" :															#Admin mode --> Coaches Management
                                                print("-----------------------------------------")
                                                print("|To add new coach  Enter 1              |")
                                                print("|To display coach  Enter 2              |")
                                                print("|To delete coach  data Enter 3          |")
                                                print("|To edit coach  data Enter 4            |")
                                                print("|To be back enter E                     |")
                                                print("-----------------------------------------")
                                                Admin_choice = input ("Enter your choice : ")
                                                Admin_choice = Admin_choice.upper()
                                                
                                                if Admin_choice == "1" : 											#Admin mode --> Coaches Management --> Enter new coach data
                                                                try :		#To avoid non integer input
                                                                        Coach_ID = int(input("Enter coach ID : "))
                                                                        while Coach_ID in Coaches_DataBase :			#if Admin entered used ID
                                                                                Coach_ID = int(input("This ID is unavailable, please try another ID : "))
                                                                        
                                                                        Name      =input("Enter Coach name       : ")
                                                                        Address   =input("Enter Coach address    : ")
                                                                        PhoneNumber =input("Enter Coach phone number    : ")
                                                                        Coaches_DataBase[Coach_ID]=[[Name,Address,PhoneNumber]]
                                                                        print("----------------------Coach added successfully----------------------")
                                                                except :
                                                                        print("Coach ID should be an integer number")
                                                        
                                                elif Admin_choice == "2" : 											#Admin mode --> Coaches Management --> Display coach data
                                                                try :		#To avoid non integer input
                                                                        Coach_ID = int(input("Enter coach ID : "))
                                                                        while Coach_ID not in Coaches_DataBase :
                                                                                Coach_ID = int(input("Incorrect ID, Please Enter coach ID : "))
                                                                        print("Coach name    : ",Coaches_DataBase[Coach_ID][0][0])
                                                                        print("Coach address : ",Coaches_DataBase[Coach_ID][0][1])
                                                                        print("Coach phone number : ",Coaches_DataBase[Coach_ID][0][2])
                                                                except :
                                                                        print("Coach ID should be an integer number")
                                                
                                                elif Admin_choice == "3" :											#Admin mode --> Coaches Management --> Delete coach data
                                                                try :		#To avoid non integer input
                                                                        Coach_ID = int(input("Enter coach ID : "))
                                                                        while Coach_ID not in Coaches_DataBase :
                                                                                Coach_ID = int(input("Incorrect ID, Please Enter coach ID : "))
                                                                        Coaches_DataBase.pop(Coach_ID)
                                                                        print("/----------------------Coach data deleted successfully----------------------/")
                                                                except :
                                                                        print("Coach ID should be an integer number")

                                                elif Admin_choice == "4" :											#Admin mode --> Coaches Management --> Edit Coach data
                                                                try :		#To avoid non integer input	
                                                                        Coach_ID=input("Enter coach ID : ")
                                                                        while Coach_ID not in Coaches_DataBase :
                                                                                Coach_ID = int(input("Incorrect ID, Please Enter Coach ID : "))
                                                                        print("-----------------------------------------")
                                                                        print("|To Edit coach's name Enter 1    |")
                                                                        print("|To Edit coach's address Enter 2          |")
                                                                        print("|To Edit coach's phone number Enter 3       |")
                                                                        print("To be Back Enter E                      |")
                                                                        print("-----------------------------------------")
                                                                        Admin_choice=input("Enter your choice : ")
                                                                        Admin_choice = Admin_choice.upper()
                                                                        if Admin_choice == "1" :
                                                                                Coaches_DataBase[Coach_ID][0][0]=input("Enter Coach's Name : ")
                                                                                print("/----------------------Coach's department edited successfully----------------------/")
                                                                                
                                                                        elif Admin_choice == "2" :
                                                                                Coaches_DataBase[Coach_ID][0][1]=input("Enter Coach's Address : ")
                                                                                print("----------------------Coach's name edited successfully----------------------")
                                                                                
                                                                        elif Admin_choice == "3" :
                                                                                Coaches_DataBase[Coach_ID][0][2]=input("Enter Coach's Phone Number : ")
                                                                                print("----------------------Coach's address edited successfully----------------------")
                                                                        
                                                                        elif Admin_choice == "E" :
                                                                                break
                                                                        
                                                                        else :
                                                                                print("\nPlease enter a correct choice\n")
                                                                                
                                                                except :
                                                                        print("Coach ID should be an integer number")
                                                                                
                                                elif Admin_choice == "E" :											#Back
                                                                        break
                                                                
                                                else :
                                                        print("\nPlease enter a correct choice\n")
                                                                                
                                        elif AdminOptions == "3" :															#Admin mode --> Appointment Management
                                                print("-----------------------------------------")
                                                print("|To book an appointment Enter 1         |")
                                                print("|To edit an appointment Enter 2         |")
                                                print("|To cancel an appointment Enter 3       |")
                                                print("|To be back enter E                     |")
                                                print("-----------------------------------------")
                                                Admin_choice = input ("Enter your choice : ")
                                                Admin_choice = Admin_choice.upper()
                                                if Admin_choice == "1" :												#Admin mode --> Appointment Management --> Book an appointment							
                                                        try :		#To avoid non integer input
                                                                        Coach_ID = int(input("Enter the ID of coach : "))
                                                                        while Coach_ID not in Coaches_DataBase :
                                                                                Coach_ID = int(input("Doctor ID incorrect, Please enter a correct coach ID : "))
                                                                        print("---------------------------------------------------------")
                                                                        print("|For book an appointment for an exist member Enter 1   |\n|For book an appointment for a new member Enter 2      |\n|To be Back Enter E                                     |")
                                                                        print("---------------------------------------------------------")
                                                                        Admin_choice = input ("Enter your choice : ")
                                                                        Admin_choice = Admin_choice.upper()
                                                                        if Admin_choice == "1" :
                                                                                        member_ID = int(input("Enter member ID : "))
                                                                                        while member_ID not in Members_DataBase :		#if Admin entered incorrect ID
                                                                                                member_ID = int(input("Incorrect ID, please Enter a correct member ID : "))	
                                                                        
                                                                                
                                                                        elif Admin_choice == "2" :
                                                                                member_ID = int(input("Enter patient ID : "))
                                                                                while member_ID in Members_DataBase :		#if Admin entered used ID
                                                                                        member_ID = int(input("This ID is unavailable, please try another ID : "))					
                                                                                DoctorName=Coaches_DataBase[Coach_ID][0][0]
                                                                                Name      =input("Enter member name    : ")
                                                                                Age       =input("Enter member age     : ")
                                                                                Gender    =input("Enter member gender  : ")
                                                                                Address   =input("Enter member address : ")
                                                                                OriginalWeight= input("Enter member original weight : ")
                                                                                PhoneNumber=""
                                                                                Members_DataBase[member_ID]=[DoctorName,Name,Age,Gender,Address,OriginalWeight,PhoneNumber]
                                                                        
                                                                        elif Admin_choice == "E" :
                                                                                break
                                                                                
                                                                        Session_Start = input("Session starts at : ")
                                                                        while Session_Start[ :2] == "11" or Session_Start[ :2] == "12" :
                                                                                Session_Start = input("Appointments should be between 01:00PM to 10:00PM, Please enter a time between working hours : ")
                                                                                
                                                                        for i in Coaches_DataBase[Coach_ID] :
                                                                                if type(i[0])!=str :
                                                                                        while Session_Start >= i[1] and Session_Start < i[2] :
                                                                                                Session_Start = input("This appointment is already booked, Please Enter an other time for start of session : ")
                                                                        Session_End   = input("Session ends at : ")
                                                                        
                                                                        New_Appointment=list()
                                                                        New_Appointment.append(member_ID)
                                                                        New_Appointment.append(Session_Start)
                                                                        New_Appointment.append(Session_End)
                                                                        Coaches_DataBase[Coach_ID].append(New_Appointment)								
                                                                        print("/----------------------Appointment booked successfully----------------------/")
                                                        except :
                                                                        print("Doctor ID should be an integer number")
                                
                                                elif Admin_choice == "2" :												#Admin mode --> Appointment Management --> Edit an appointment
                                                                try :		#To avoid non integer input
                                                                        member_ID = int(input("Enter member ID : "))						
                                                                        while member_ID not in Members_DataBase :
                                                                                member_ID = int(input("Incorrect Id, Please Enter correct member ID : "))
                                                                        try :   #To avoid no return function
                                                                                        AppointmentIndex,PairKey = AppointmentIndexInCoachesDataBase(Coach_ID)
                                                                                        Session_Start = input ("Please enter the new start time : ")
                                                                                        while Session_Start[ :2] == "11" or Session_Start[ :2] == "12" :
                                                                                                Session_Start = input("Appointments should be between 01:00PM to 10:00PM, Please enter a time between working hours : ")
                                                                                                
                                                                                        for i in Coaches_DataBase[Coach_ID] :
                                                                                                if type(i[0])!=str :
                                                                                                        while Session_Start >= i[1] and Session_Start < i[2] :
                                                                                                                Session_Start = input("This appointment is already booked, Please Enter an other time for start of session : ")
                                                                                        Session_End = input ("Please enter the new end time : ")
                                                                                        Coaches_DataBase[PairKey][AppointmentIndex]=[member_ID,Session_Start,Session_End]							
                                                                                        print("/----------------------appointment edited successfully----------------------/")
                                                                        except :
                                                                                        print("No Appointment for this patient")
                                                                except :
                                                                        print("Coach ID should be an integer number")
                                        
                                                elif Admin_choice == "3" :												#Admin mode --> Appointment Management --> Cancel an appointment
                                                                try :		#To avoid non integer input
                                                                        member_ID = int(input("Enter member ID : "))
                                                                        while member_ID not in Members_DataBase :
                                                                                member_ID = int(input("Incorrect ID, Enter member ID : "))
                                                                        try :
                                                                                        AppointmentIndex,PairKey = AppointmentIndexInCoachesDataBase(member_ID)						
                                                                                        Coaches_DataBase[PairKey].pop(AppointmentIndex)
                                                                                        print("/----------------------appointment canceled successfully----------------------/")
                                                                        except :
                                                                                        print("No Appointment for this member")
                                                                except :	 #To avoid no return function
                                                                        print("Member ID should be an integer number")
                                                
                                                elif Admin_choice == "E" :												#Back
                                                                        break
                                                
                                                else :
                                                                        print("please enter a correct choice")
                                        
                                        elif AdminOptions == "E" :															#Back
                                                break
                                        
                                        else :
                                                print("Please enter a correct option")
                                
                        
                                elif Password != "130400" :
                                        if tries < 2 :
                                                Password = input("Password incorrect, please try again : ")
                                                tries += 1
                                        else :
                                                print("Incorrect password, no more tries")
                                                tries_flag = "Close the program"
                                                break
                        
                                Write_Studio_Excel_Sheet.Write_Members_DataBase(Members_DataBase)
                                Write_Studio_Excel_Sheet.Write_Coaches_DataBase(Coaches_DataBase)
                                
                                
        elif Admin_user_mode == "2" :																		#User mode
                print("****************************************\n|         Welcome to user mode         |\n****************************************")
                while True :
                        print("\n-----------------------------------------")
                        print("|To view studio's programmes Enter 1 |")
                        print("|To view studio's coaches Enter 2     |")
                        print("|To view studio s' residents Enter 3    |")
                        print("|To view member's details Enter 4      |")
                        print("|To view coach's appointments Enter 5  |")
                        print("|To be Back Enter E                     |")
                        print("-----------------------------------------")
                        UserOptions = input("Enter your choice : ")
                        UserOptions = UserOptions.upper()
                        
                        if   UserOptions == "1" :											#User mode --> view studio's departments
                                                print("Studio's programmes :")
                                                for i in Coaches_DataBase :
                                                        print("	"+Coaches_DataBase[i][0][0])
                                
                        elif UserOptions == "2" :											#User mode --> view studio's Coaches
                                                print("Studio's coaches :")
                                                for i in Coaches_DataBase :
                                                        print("	Name : "+Coaches_DataBase[i][0][0], "Address : "+Coaches_DataBase[i][0][1],"Phone Number :"+Coaches_DataBase[i][0][2])
                                                        
                        elif UserOptions == "3" :											#User mode --> view members residents
                                for i in Members_DataBase :
                                        print("	Member : "+Members_DataBase[i][2]+" in "+Members_DataBase[i][0]+" programme and followed by "+Members_DataBase[i][1]+", age : "+Members_DataBase[i][3]+", from : "+Members_DataBase[i][5]+", Phone Number :"+Members_DataBase[i][8])
                        
                        elif UserOptions == "4" :											#User mode --> view members details
                              try :		
                                      member_ID = int(input("Enter member ID : "))
                                      while member_ID not in Members_DataBase :
                                        member_ID = int(input("Incorrect ID, Please Enter member ID : "))
                                        print("\nmember name        : ",Members_DataBase[member_ID][2])
                                        print("member age         : ",Members_DataBase[member_ID][3])
                                        print("member gender      : ",Members_DataBase[member_ID][4])
                                        print("member address     : ",Members_DataBase[member_ID][5])
                                        print("member original weight     : ",Members_DataBase[member_ID][6])
                                        print("member current weight     : ",Members_DataBase[member_ID][7])
                                        print("member phone number : ",Members_DataBase[member_ID][8])
                                        print("member is in "+Members_DataBase[member_ID][0]+" programme")
                                        print("member is followed by Coach : "+Members_DataBase[member_ID][1])
                              except :
                                        print("Member ID should be an integer number")        
                                                
                        elif UserOptions == "5" :											#User mode --> view coach's appointments
                                try :				
                                        Coach_ID = int(input("Enter coach's ID : "))
                                        while Coach_ID not in Coaches_DataBase :
                                                Coach_ID = int(input("Incorrect Id, Please enter coach ID : "))
                                        print(Coaches_DataBase[Coach_ID][0][0]+" has appointments :")
                                        for i in Coaches_DataBase[Coach_ID] :
                                                if type(i[0])==str :
                                                        continue
                                                else :
                                                        print("	from : "+i[1]+"    to : "+i[2])
                                except :
                                        print("Coach ID should be an integer number")
                                
                        elif UserOptions == "E" :											#Back
                                break
                                
                        else :
                                print("Please Enter a correct choice")
                                
                                
        else :
                print("Please choice just 1 or 2")
