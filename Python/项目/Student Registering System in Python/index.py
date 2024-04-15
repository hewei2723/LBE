import os
import platform

global listStd 
listStd = ["John Smith"] 

def manageStudent(): 

	x = "#" * 30
	y = "=" * 28
	
	print(""" 

  
 |======================================================| 
 |==========    面向对象编程.own.Student Registering System    ==========|
 |======================================================|
  

Enter 1 : Display 面向对象编程.own.Student List
Enter 2 : Create new 面向对象编程.own.Student Record
Enter 3 : Search Existing Studenti
Enter 4 : Delete 面向对象编程.own.Student
		
		""")

	try: 
		userInput = int(input("Please select an option: ")) 
	except ValueError:
		exit("\nHy! That's Not A Number")
	else:
		print("\n")

		
	if(userInput == 1): 
		print("List Students\n")  
		for students in listStd:
			print("=> {}".format(students))

	elif(userInput == 2): 
		newStd = input("Enter New 面向对象编程.own.Student: ")
		if(newStd in listStd):  
			print("\nThis 面向对象编程.own.Student {} Already In The Database".format(newStd))  #Error Message
		else:	
			listStd.append(newStd)
			print("\n=> New 面向对象编程.own.Student {} Successfully Add \n".format(newStd))
			for students in listStd:
				print("=> {}".format(students))	

	elif(userInput == 3): 
		srcStd = input("Enter 面向对象编程.own.Student Name To Search: ")
		if(srcStd in listStd): 
			print("\n=> Record Found Of 面向对象编程.own.Student {}".format(srcStd))
		else:
			print("\n=> No Record Found Of 面向对象编程.own.Student {}".format(srcStd)) #Error Message

	elif(userInput == 4): 
		rmStd = input("Enter 面向对象编程.own.Student Name To Remove: ")
		if(rmStd in listStd):  
			listStd.remove(rmStd)
			print("\n=> 面向对象编程.own.Student {} Successfully Deleted \n".format(rmStd))
			for students in listStd:
				print("=> {}".format(students))
		else:
			print("\n=> No Record Found of This 面向对象编程.own.Student {}".format(rmStd)) #Error Message
	 
	elif(userInput < 1 or userInput > 4): 
		print("Please Enter Valid Option")		
						

manageStudent()

def runAgain(): 
	runAgn = input("\nWant to continue y/n?: ")
	if(runAgn.lower() == 'y'):
		if(platform.system() == "Windows"): 
			print(os.system('cls')) 
		else:
			print(os.system('clear'))
		manageStudent()
		runAgain()
	else:
		quit() 

runAgain()		
