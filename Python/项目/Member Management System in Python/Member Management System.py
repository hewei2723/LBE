import os
import platform

global listMem 
listMem = ["John Smith"] 

def manageMember(): 

	x = "#" * 30
	y = "=" * 28
	
	print(""" 

 |======================================================| 
 |======== Welcome To Member Management System	========|
 |======================================================|

Enter 1 : View Member List 
Enter 2 : Add New Member 
Enter 3 : Search Member 
Enter 4 : Remove Member 
		
		""")

	try: 
		userInput = int(input("Please select an option: ")) 
	except ValueError:
		exit("\nHy! That's Not A Number")
	else:
		print("\n")

		
	if(userInput == 1): 
		print("List Member\n")  
		for members in listMem:
			print("=> {}".format(members))

	elif(userInput == 2): 
		newMem = input("Enter New Member: ")
		if(newMem in listMem):  
			print("\nThis Member {} Already In The Database".format(newMem))
		else:	
			listMem.append(newMem)
			print("\n=> New Member {} Successfully Add \n".format(newMem))
			for members in listMem:
				print("=> {}".format(members))	

	elif(userInput == 3): 
		srcMem = input("Enter Member Name To Search: ")
		if(srcMem in listMem): 
			print("\n=> Record Found Of Member {}".format(srcMem))
		else:
			print("\n=> No Record Found Of Member {}".format(srcMem))

	elif(userInput == 4): 
		rmMem = input("Enter Member Name To Remove: ")
		if(rmMem in listMem):  
			listMem.remove(rmMem)
			print("\n=> Member {} Successfully Deleted \n".format(rmMem))
			for members in listMem:
				print("=> {}".format(members))
		else:
			print("\n=> No Record Found of This Member {}".format(rmMem)) 
	 
	elif(userInput < 1 or userInput > 4): 
		print("Please Enter Valid Option")		
						

manageMember()

def startApp(): 
	runAgn = input("\nWant to continue y/n?: ")
	if(runAgn.lower() == 'y'):
		if(platform.system() == "Windows"): 
			print(os.system('cls')) 
		else:
			print(os.system('clear'))
		manageMember()
		startApp()
	else:
		quit() 

startApp()		
