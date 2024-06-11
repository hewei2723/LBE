import getpass
import sqlite3
connection=sqlite3.connect('database.db')
cursor=connection.cursor()
error=1
from os import system, name
def screen_clear():
   if name == 'nt':
      _ = system('cls')
   else:
      _ = system('clear')
cursor.execute("""select count(name) from sqlite_master where type='table' and name='doctor'""")
if cursor.fetchone()[0]==0:
    cursor.execute("""CREATE TABLE doctor ( 
    d_id number primary key, 
    dnamedfirst VARCHAR2(20), 
    dnamedlast VARCHAR2(30), 
    password varchar2(20) not null,
    speciality varchar2(40) not null,
    shift varchar2(10) not null,
    phone number(10) not null);""")
cursor.execute("""select count(name) from sqlite_master where type='table' and name='patient'""")
if cursor.fetchone()[0]==0:
    cursor.execute("""CREATE TABLE patient ( 
    p_id number primary key, 
    pfirst VARCHAR2(20), 
    pdlast VARCHAR2(30), 
    City varchar2(20) not null,
    DOB date not null,
    age number not null,
    DOA date not null,
    number number(10) not null);""")
    cursor.execute("""CREATE TABLE virus ( 
    p_id number not null, 
    dname VARCHAR2(20) primary key,
    vname VARCHAR2(20), 
    treatment VARCHAR2(50), 
    symptoms varchar2(50) not null);""")
    cursor.execute("""CREATE TABLE bacteria ( 
    p_id number not null, 
    dname VARCHAR2(20) primary key,
    bname VARCHAR2(20), 
    treatment VARCHAR2(50), 
    symptoms varchar2(50) not null);""")
    cursor.execute("""CREATE TABLE injury ( 
    p_id number not null, 
    iname VARCHAR2(20) primary key,
    idiagnosis VARCHAR2(50), 
    type varchar2(50) not null);""")
    print("Databse created successfully")
    
else:
    e=1
    while e!=0:
        e=int(input("1. Sign In\n2. Create a New Doctor Account\n"))
        if e==2:
            did=int(input('\nEnter id - '))
            dnf=input('Enter first name - ')
            dnl=input('Enter last name - ')
            pas=getpass.getpass('Enter password - ')
            spec=input('Enter speciality - ')
            shf=input('Enter working shift(ex. 6:00am to 6:00pm) - ')
            ph=int(input('Enter phone number - '))
            cursor.execute("""insert into doctor values(?,?,?,?,?,?,?)""",(did,dnf,dnl,pas,spec,shf,ph))
            screen_clear()
            e=1
        elif e==1:
            while error==1:
                i=input("\nEnter your ID - ")
                p=getpass.getpass("Enter your Password - ")
                cursor.execute("""select count(d_id) from doctor where d_id=(?)""",(i,))
                if cursor.fetchone()[0]==1:
                    cursor.execute("""select count(password) from doctor where password=?""",(p,))
                    if cursor.fetchone()[0]==1:
                        print("\nSign in successful!")
                        screen_clear()
                        error=0
                        e=0
                        r=1
                        cursor.execute("""select d_id,dnamedfirst,dnamedlast,speciality,shift,phone from doctor where d_id=(?)""",(i,))
                        for row in cursor.fetchall():
                           print("ID -",row[0],"  Name -",row[1], row[2],"  Speciality -",row[3],"\nShift -",row[4],"  Phone Number -",row[5])
                        while r!=0:
                           print("\n1. View Patient details\n2. Add a New Patient\n3. Delete Patient Details\n0. Exit")
                           r=int(input())
                           if r==1:
                              access=input("\nEnter Patient ID:- ")
                              cursor.execute("""select count(*) from patient where p_id=(?)""",(access,))
                              if cursor.fetchone()[0]!=0:
                                 cursor.execute("""select * from patient where p_id=(?)""",(access,))
                                 print("\nPatient Details - ")
                                 for row in cursor.fetchall():
                                    print("Id: ", row[0])
                                    print("First Name: ", row[1])
                                    print("Last Name: ", row[2])
                                    print("City: ", row[3])
                                    print("Date of Birth: ", row[4])
                                    print("Age: ", row[5])
                                    print("Date of Admission: ", row[6])
                                 print("\nDiagnosis Report - ")
                                 cursor.execute("""select count(*) from virus where p_id=(?)""",(access,))
                                 if cursor.fetchone()[0]!=0:
                                    cursor.execute("""select * from virus where p_id=(?)""",(access,))
                                    for row in cursor.fetchall():
                                       print("Id: ", row[0])
                                       print("Disease Name: ", row[1])
                                       print("Virus Name: ", row[2])
                                       print("Treatment: ", row[3])
                                       print("Symptoms: ", row[4])
                                    print("\n")
                                 cursor.execute("""select count(*) from bacteria where p_id=(?)""",(access,))
                                 if cursor.fetchone()[0]!=0:
                                    cursor.execute("""select * from bacteria where p_id=(?)""",(access,))
                                    for row in cursor.fetchall():
                                       print("Id: ", row[0])
                                       print("Disease Name: ", row[1])
                                       print("Bacteria Name: ", row[2])
                                       print("Treatment: ", row[3])
                                       print("Symptoms: ", row[4])
                                    print("\n")
                                 cursor.execute("""select count(*) from injury where p_id=(?)""",(access,))
                                 if cursor.fetchone()[0]!=0:
                                    cursor.execute("""select * from injury where p_id=(?)""",(access,))
                                    for row in cursor.fetchall():
                                       print("Id: ", row[0])
                                       print("Injury Name: ", row[1])
                                       print("Diagnosis Name: ", row[2])
                                       print("Type: ", row[3])
                                    print("\n")
                              else:
                                 print("Incorrect Patient id")
                           elif r==2:
                              pid=int(input('\nEnter id - '))
                              pnf=input('Enter first name - ')
                              pnl=input('Enter last name - ')
                              pcity=input('Enter city - ')
                              pdob=input('Enter date of birth(M-D-Y) - ')
                              page=int(input('Enter age - '))
                              pdoa=input('Enter date of admission - ')
                              pnum=int(input('Enter phone number - '))
                              cursor.execute("""insert into patient values(?,?,?,?,?,?,?,?)""",(pid,pnf,pnl,pcity,pdob,page,pdoa,pnum))
                              print("\n1. Virus\n2. Bacteria\n3. Injury")
                              m=int(input())
                              if m==1:
                                 dname=input("\nEnter disease name - ")
                                 bname=input("Enter virus name - ")
                                 treatment=input("Enter treatment - ")
                                 symptoms=input("Enter symptoms - ")
                                 cursor.execute("""insert into virus values(?,?,?,?,?)""",(pid,dname,bname,treatment,symptoms))
                              elif m==2:
                                 dname=input("\nEnter disease name - ")
                                 bname=input("Enter bacteria name - ")
                                 treatment=input("Enter treatment - ")
                                 symptoms=input("Enter symptoms - ")
                                 cursor.execute("""insert into bacteria values(?,?,?,?,?)""",(pid,dname,bname,treatment,symptoms))
                              elif m==3:
                                 iname=input("\nEnter injury name - ")
                                 idiag=input("Enter diagnosis - ")
                                 itype=input("Enter injury type - ")
                                 cursor.execute("""insert into injury values(?,?,?,?)""",(pid,iname,idiag,itype))
                              print("\nPatient Added")
                              connection.commit()
                           elif r==3:
                              access=input("\nEnter Patient ID:- ")
                              cursor.execute("""select count(*) from patient where p_id=(?)""",(access,))
                              if cursor.fetchone()[0]!=0:
                                 cursor.execute("""delete from patient where p_id=(?)""",(access,))
                                 cursor.execute("""select count(*) from virus where p_id=(?)""",(access,))
                                 if cursor.fetchone()[0]!=0:
                                    cursor.execute("""delete from virus where p_id=(?)""",(access,))
                                 cursor.execute("""select count(*) from bacteria where p_id=(?)""",(access,))
                                 if cursor.fetchone()[0]!=0:
                                    cursor.execute("""delete from bacteria where p_id=(?)""",(access,))
                                 cursor.execute("""select count(*) from injury where p_id=(?)""",(access,))
                                 if cursor.fetchone()[0]!=0:
                                    cursor.execute("""delete from injury where p_id=(?)""",(access,))
                              else:
                                 print("Incorrect Patient id Patient does not exist")
                              print("\nPatient Deleted")
                              connection.commit()
                           elif r==0:
                              break
                    else:
                        print("Incorrect passoword. Please retry ")
                else:
                    print("Incorrect User ID. Please retry ")
            break
        elif e==2212:
            cursor.execute("""select * from doctor""")
            print(cursor.fetchall())
            cursor.execute("""select * from virus""")
            print(cursor.fetchall())
            cursor.execute("""select * from bacteria""")
            print(cursor.fetchall())
            cursor.execute("""select * from injury""")
            print(cursor.fetchall())
            break
connection.commit()
connection.close()
print("")
def progress(status, remaining, total):
    print(f'Copied {total-remaining} of {total} pages...')

try:
    sqliteCon = sqlite3.connect('database.db')
    backupCon = sqlite3.connect('bp_database.db')
    with backupCon:
        sqliteCon.backup(backupCon, pages=1, progress=progress)
    print("backup successful")
except sqlite3.Error as error:
    print("Error while taking backup: ", error)
finally:
    if(backupCon):
        backupCon.close()
        sqliteCon.close()
