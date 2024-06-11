import sys


STUDENT_NAME = []
STUDENT_ROLL_NUMBER = []
STUDENT_ADDRESS = []
STUDENT_EMAIL = []
STUDENT_AGE = []
STUDENT_MOBILE_NUMBER = []
STUDENT_CLASS = []


class STUDENT_MANAGEMENT_SYSTEM:
    @staticmethod
   
    def ADD_STUDENT_INFORMATION():
        print("ADDING STUDENT INFORMATION : \n")
        print("ENTER STUDENT NAME :", end=" ")
        NAME = input().upper()
        STUDENT_NAME.append(NAME)

        print("ENTER STUDENT ROLL NUMBER :", end=" ")
        ROLL_NUMBER = int(input())
        STUDENT_ROLL_NUMBER.append(ROLL_NUMBER)

        print("ENTER STUDENT AGE :", end=" ")
        AGE = int(input())
        STUDENT_AGE.append(AGE)

        print("ENTER STUDENT CLASS :", end=" ")
        CLASS = input().upper()
        STUDENT_CLASS.append(CLASS)

        print("ENTER STUDENT E-MAIL ID :", end=" ")
        EMAIL_ID = input().upper()
        STUDENT_EMAIL.append(EMAIL_ID)

        print("ENTER STUDENT ADDRESS :", end=" ")
        ADDRESS = input().upper()
        STUDENT_ADDRESS.append(ADDRESS)

        print("ENTER STUDENT MOBILE NUMBER :", end=" ")
        MOBILE_NUMBER = input()
        MOBILE_NUMBER_LEN = len(MOBILE_NUMBER)

        if MOBILE_NUMBER_LEN < 10:
            print("\t PLEASE ENTER VALID TEN DIGIT MOBILE NUMBER.")
        else:
            STUDENT_MOBILE_NUMBER.append(MOBILE_NUMBER)
            print("\n")
            print("\t STUDENT INFORMATION ADDED SUCCESSFULLY.")
            print("\n")

    @staticmethod
    #   THIS FUNCTION HELP TO 'DELETE' DATA OF STUDENT
    def DELETE_STUDENT_INFORMATION():
        print("DELETING STUDENT INFORMATION : \n")

        if len(STUDENT_NAME) == 0 and len(STUDENT_ROLL_NUMBER) == 0 and len(STUDENT_AGE) == 0 and len(
                STUDENT_CLASS) == 0 and len(STUDENT_MOBILE_NUMBER) == 0 and len(STUDENT_ADDRESS) == 0 and len(
                STUDENT_EMAIL) == 0:
            print("\n")
            print("\t\t\t 'PLEASE FILL SOME INFORMATION DON'T KEEP IT EMPTY")
            print("\n")
        else:
            print("ENTER STUDENT'S ROLL NUMBER :", end=" ")
            ROLL_NUMBER = int(input())
            LOC = STUDENT_ROLL_NUMBER.index(ROLL_NUMBER)

            STUDENT_ROLL_NUMBER.remove(STUDENT_ROLL_NUMBER[LOC])
            STUDENT_NAME.remove(STUDENT_NAME[LOC])
            STUDENT_MOBILE_NUMBER.remove(STUDENT_MOBILE_NUMBER[LOC])
            STUDENT_AGE.remove(STUDENT_AGE[LOC])
            STUDENT_ADDRESS.remove(STUDENT_ADDRESS[LOC])
            STUDENT_EMAIL.remove(STUDENT_EMAIL[LOC])
            STUDENT_CLASS.remove(STUDENT_CLASS[LOC])

            print("\n")
            print("\t\t STUDENT INFORMATION DELETED SUCCESSFULLY.")
            print("\n")

    @staticmethod
    #    THIS FUNCTION HELP TO 'UPDATE' DATA OF STUDENT.
    def UPDATE_STUDENT_INFORMATION():
        print("UPDATE STUDENT INFORMATION : \n")

        if len(STUDENT_NAME) == 0 and len(STUDENT_ROLL_NUMBER) == 0 and len(STUDENT_AGE) == 0 and len(
                STUDENT_CLASS) == 0 and len(STUDENT_MOBILE_NUMBER) == 0 and len(STUDENT_ADDRESS) == 0 and len(
                STUDENT_EMAIL) == 0:
            print("\n")
            print("\t\t\t 'PLEASE FILL SOME INFORMATION DON'T KEEP IT EMPTY")
            print("\n")
        else:
            print("ENTER STUDENT ATTRIBUTE YOU WANT TO DELETE :", end="\n")
            print("LIKE 'NAME, ROLL NUMBER, AGE, MOBILE NUMBER, ADDRESS, EMAIL, CLASS.")
            print("ENTER HERE :", end=" ")
            ATTRIBUTE = input().upper()

            if ATTRIBUTE == 'NAME':
                print("ENTER 'OLD NAME' :", end=" ")
                OLD_NAME = input()
                LOC_NAME = STUDENT_NAME.index(OLD_NAME)

                print("ENTER 'NEW NAME' :", end=" ")
                NEW_NAME = input()
                STUDENT_NAME[LOC_NAME] = NEW_NAME
                print("\t 'NAME UPDATED SUCCESSFULLY.")
                print("\n")

            elif ATTRIBUTE == 'ROLL NUMBER':
                print("ENTER 'OLD ROLL NUMBER' :", end=" ")
                OLD_ROLL_NUMBER = int(input())
                LOC_ROLL = STUDENT_ROLL_NUMBER.index(OLD_ROLL_NUMBER)

                print("ENTER 'NEW ROLL NUMBER' :", end=" ")
                NEW_ROLL = int(input())
                STUDENT_ROLL_NUMBER[LOC_ROLL] = NEW_ROLL
                print("\t 'ROLL NUMBER UPDATED SUCCESSFULLY.")
                print("\n")

            elif ATTRIBUTE == 'AGE':
                print("ENTER 'OLD AGE' :", end=" ")
                OLD_AGE = int(input())
                LOC_ROLL = STUDENT_AGE.index(OLD_AGE)

                print("ENTER 'NEW AGE' :", end=" ")
                NEW_AGE = int(input())
                STUDENT_AGE[LOC_ROLL] = NEW_AGE
                print("\t 'AGE UPDATED SUCCESSFULLY.")
                print("\n")

            elif ATTRIBUTE == 'ADDRESS':
                print("ENTER 'OLD ADDRESS' :", end=" ")
                OLD_ADDRESS = input()
                LOC_ADDRESS = STUDENT_ADDRESS.index(OLD_ADDRESS)

                print("ENTER 'NEW ADDRESS' :", end=" ")
                NEW_ADDRESS = input()
                STUDENT_ADDRESS[LOC_ADDRESS] = NEW_ADDRESS
                print("\t 'ADDRESS UPDATED SUCCESSFULLY.")
                print("\n")

            elif ATTRIBUTE == 'EMAIL':
                print("ENTER 'OLD EMAIL' :", end=" ")
                OLD_EMAIL = input()
                LOC_EMAIL = STUDENT_EMAIL.index(OLD_EMAIL)

                print("ENTER 'NEW EMAIL' :", end=" ")
                NEW_EMAIL = input()
                STUDENT_EMAIL[LOC_EMAIL] = NEW_EMAIL
                print("\t 'EMAIL - ID UPDATED SUCCESSFULLY.")
                print("\n")

            elif ATTRIBUTE == 'CLASS':
                print("ENTER 'OLD CLASS' :", end=" ")
                OLD_CLASS = input()
                LOC_CLASS = STUDENT_CLASS.index(OLD_CLASS)

                print("ENTER 'NEW CLASS' :", end=" ")
                NEW_CLASS = input()
                STUDENT_CLASS[LOC_CLASS] = NEW_CLASS
                print("\t 'CLASS UPDATED SUCCESSFULLY.")
                print("\n")

            elif ATTRIBUTE == 'MOBILE NUMBER':
                print("ENTER 'OLD MOBILE NUMBER' :", end=" ")
                OLD_MOBILE = input()

                print("ENTER 'NEW MOBILE NUMBER' :", end=" ")
                NEW_MOBILE = input()
                MOBILE_NUMBER_LEN = len(OLD_MOBILE)
                M_N_LEN = len(NEW_MOBILE)

                if MOBILE_NUMBER_LEN < 10:
                    print(end="\n")
                    print("PLEASE ENTER TEN DIGIT MOBILE NUMBER.")
                    print("SYSTEM HAS STOP, PLEASE TRY AGAIN.")
                    sys.exit()
                elif M_N_LEN < 10:
                    print(end="\n")
                    print("\t PLEASE ENTER VALID TEN DIGIT MOBILE NUMBER.")
                    print("\t SYSTEM WORKING HAS STOP PLEASE TRY AGAIN.")
                    sys.exit()
                else:
                    LOC_MOBILE = STUDENT_MOBILE_NUMBER.index(OLD_MOBILE)
                    STUDENT_MOBILE_NUMBER[LOC_MOBILE] = NEW_MOBILE
                    print("\t 'MOBILE NUMBER UPDATED SUCCESSFULLY.")
                    print("\n")

    @staticmethod
    #    THIS FUNCTION HELP TO UPDATE 'DATA' OF STUDENT.
    def DISPLAY_STUDENT_INFORMATION():
        print("DISPLAYING STUDENTS INFORMATION : \n")

        if len(STUDENT_NAME) == 0 and len(STUDENT_ROLL_NUMBER) == 0 and len(STUDENT_AGE) == 0 and len(
                STUDENT_CLASS) == 0 and len(STUDENT_MOBILE_NUMBER) == 0 and len(STUDENT_ADDRESS) == 0 and len(
                STUDENT_EMAIL) == 0:
            print("\n")
            print("\t\t\t 'OOPS ! NOTHING TO DISPLAY, BECAUSE NO DATA IS THERE.")
            print("\n")
        else:
            print("STUDENT'S NAME : ", end="\n")

            for x in STUDENT_NAME:
                print(x)
            print()

            print(end="\n")

            print("STUDENT'S ROLL NUMBER :", end="\n")

            for y in STUDENT_ROLL_NUMBER:
                print(y)
            print()

            print(end="\n")

            print("STUDENT'S AGE :", end="\n")

            for z in STUDENT_AGE:
                print(z)
            print()

            print(end="\n")

            print("STUDENT'S MOBILE NUMBER :", end="\n")

            for x in STUDENT_MOBILE_NUMBER:
                print(x)
            print()

            print(end="\n")

            print("STUDENT'S EMAIL :", end="\n")

            for y in STUDENT_EMAIL:
                print(y)
            print()

            print(end="\n")

            print("STUDENT'S CLASS :", end="\n")

            for z in STUDENT_CLASS:
                print(z)
            print()

            print(end="\n")

            print("STUDENT'S ADDRESS :", end="\n")

            for x in STUDENT_ADDRESS:
                print(x)
            print()

            print(end="\n")


SMS = STUDENT_MANAGEMENT_SYSTEM()

if __name__ == '__main__':
    print("\n")

    print("' ********** WELCOME TO REORD INFORMATION SYSTEM ********** ' \n")
    run = True

    while run:
        print("PRESS FROM THE FOLLOWING OPTION : \n")

        print("PRESS 1 : TO ADD STUDENT INFORMATION.")
        print("PRESS 2 : TO DELETE STUDENT INFORMATION.")
        print("PRESS 3 : TO UPDATE STUDENT INFORMATION.")
        print("PRESS 4 : TO DISPLAY STUDENT INFORMATION.")
        print("PRESS 5 : TO EXIT SYSTEM.")

        OPTION = int(input("ENTER YOUR OPTION : "))
        print("\n")
        print(end="\n")

        if OPTION == 1:
            SMS.ADD_STUDENT_INFORMATION()
        elif OPTION == 2:
            SMS.DELETE_STUDENT_INFORMATION()
        elif OPTION == 3:
            SMS.UPDATE_STUDENT_INFORMATION()
        elif OPTION == 4:
            SMS.DISPLAY_STUDENT_INFORMATION()
        elif OPTION == 5:
            print("THANK YOU ! VISIT AGAIN.")
            run = False
        else:
            print("PLEASE CHOOSE CORRECT OPTION FROM THE FOLLOWING.")
            print("\n")
