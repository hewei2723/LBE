def Write_Members_DataBase (Members_DataBase) :
	myfile = open("Members_DataBase.csv","w")
	for i in Members_DataBase :
		myfile.write(str(i)+";"+Members_DataBase[i][0]+";"+Members_DataBase[i][1]+";"+Members_DataBase[i][2]+";"+Members_DataBase[i][3]+";"+Members_DataBase[i][4]+";"+Members_DataBase[i][5]+";"+Members_DataBase[i][6]+"\n")
	myfile.close()
	
	
	
def Write_Coaches_DataBase (Coaches_DataBase) :
	myfile = open("Coaches_DataBase.csv","w")	
	for i in Coaches_DataBase :
		myfile.write(str(i)+";")
		for j in Coaches_DataBase[i] :
			myfile.write(str(j[0])+";"+j[1]+";"+j[2]+";")
		myfile.write("\n")
	
	myfile.close()
