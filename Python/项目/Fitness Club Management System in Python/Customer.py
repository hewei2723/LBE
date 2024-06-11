from IDGenerator import IDGenerator


class Customer:
    """
    Customer entity class.
    Private Attributes:
        customerID String
        name String
        phoneNo String
        joiningDate Date

    Public methods:
        Getters and setters
    """

    def __init__(self, name='', phoneNo='', joiningDate=''):
        self.__name = name
        self.__phoneNo = phoneNo
        self.__joiningDate = joiningDate
        self.__customerId = IDGenerator.generateCustomerID()

    def setName(self, name):
        self.__name = name

    def getName(self):
        return self.__name

    def setPhoneNo(self, phoneNo):
        self.__phoneNo = phoneNo

    def getPhoneNo(self):
        return self.__phoneNo

    def setJoiningDate(self, joiningDate):
        self.__joiningDate = joiningDate

    def getJoiningDate(self):
        return self.__joiningDate

    def getCustomerId(self):
        return self.__customerId

    def __str__(self):
        return self.getName()+" "+self.getPhoneNo()+" "+self.getJoiningDate()+" "+str(self.getCustomerId())