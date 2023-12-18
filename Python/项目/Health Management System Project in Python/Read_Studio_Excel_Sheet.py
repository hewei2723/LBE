def Read_Members_DataBase() :

	myfile = open("Members_DataBase.csv","r")

	Members_Dict = dict()
	member_ID = ""
	Programme = ""
	Coach_Name = ""
	member_Name = ""
	member_Age = ""
	member_Gender = ""
	member_Originalweight=""
	member_Currentweight=""
	member_Address = ""
	Phone_Number = ""
	flag = 0
	text = myfile.read()
		
	for i in text :
		if flag == 0 :
						if i != ";" :
							member_ID = member_ID + i
						elif i == ";" :
							flag = 1
							
		elif flag == 1 :
						if i != ";" :
							Programme = Programme + i
						elif i == ";" :
							flag = 2
							
		elif flag == 2 :
						if i != ";" :
							Coach_Name = Coach_Name + i
						elif i == ";" :
							flag = 3
							
		elif flag == 3 :
						if i != ";" :
							member_Name = member_Name + i
						elif i == ";" :
							flag = 4
							
		elif flag == 4 :
						if i != ";" :
							member_Age = member_Age + i
						elif i == ";" :
							flag = 5
							
		elif flag == 5 :
						if i != ";" :
							member_Gender = member_Gender + i
						elif i == ";" :
							flag = 6
							
		elif flag == 6 :
						if i != ";" :
							member_Address = member_Address + i
						elif i == ";" :
							flag = 7
							
		elif flag == 7 :
						if i != ";" :
							member_Originalweight = member_Originalweight + i
						elif i == ";" :
							flag = 8
		elif flag == 8 :
						if i != ";" :
							member_Currentweight = member_Currentweight + i
						elif i == ";" :
							flag = 9
		elif flag == 9 :
						if i != "\n" :
							Phone_Number = Phone_Number + i
						elif i == "\n" :
							Members_Dict[int(member_ID)]=[Programme,Coach_Name,member_Name,member_Age,member_Gender,member_Address,member_Originalweight,member_Currentweight,Phone_Number]
							member_ID = ""
							Programme = ""
							Coach_Name = ""
							member_Name = ""
							member_Age = ""
							member_Gender = ""
							member_Address = ""
							member_Originalweight = ""
							member_Currentweight = ""
							Phone_Number = ""
							flag = 0
							
		
	myfile.close()
	return Members_Dict
			
			
			
def Read_Coaches_DataBase () :

	myfile = open ("Coaches_DataBase.csv","r")

	Coaches_Dict = dict()
	Coach_ID = ""
	Coach_Name = ""
	Coach_Address = ""
	Coach_PhoneNumber=""
	member_ID = ""
	Session_Start = ""
	Session_End = ""
	flag = 0

	
	text = myfile.read()

	while text.count(";;") :
		text=text.replace(";;",";")
	
	for i in text :
		if flag == 0 :
					if i != ";" :
						Coach_ID = Coach_ID + i
					elif i == ";" :
						flag = 1
				
		elif flag == 1 :
					if i != ";" :
						Coach_Name = Coach_Name + i
					elif i == ";" :
						flag = 2
				
		elif flag == 2 :
					if i != ";" :
						Coach_Address = Coach_Address + i
					elif i == ";" :
						flag = 3
				
		elif flag == 3 :
					if i != ";" :
						Coach_PhoneNumber = Coach_PhoneNumber + i
					elif i == ";" :
						flag = 4
						Coach_Data_List = [Coach_Name,Coach_Address,Coach_PhoneNumber]
						Coaches_Dict[int(Coach_ID)]=[Coach_Data_List]

						
		elif flag == 4 :
					if i != ";" and i != "\n" :
						member_ID = member_ID + i
					elif i == ";" :
						flag = 5
					elif i == "\n" :
						flag = 0
						Coach_ID = ""
						Coach_Name = ""
						Coach_Address = ""
						Coach_PhoneNumber = ""
						
		elif flag == 5 :
					if i != ";" :
						Session_Start = Session_Start + i
					elif i == ";" :
						flag = 6
		
		elif flag == 6 :
					if i != ";" and i != "\n" :
						Session_End = Session_End + i
					elif i == ";" :
						flag = 4
						Appointment_List = [int(member_ID),Session_Start,Session_End]	
						Coaches_Dict[int(Coach_ID)].append(Appointment_List)
						member_ID = ""
						Session_Start = ""
						Session_End = ""
					elif i == "\n" :
						flag = 0
						Coach_ID = ""
						Coach_Name = ""
						Coach_Address = ""
						Coach_PhoneNumber = ""

	myfile.close()
	return Coaches_Dict
