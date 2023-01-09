/*
Amirali Malekghasemi
c++ Final Project : Library Managment
Computer Science Grade 12
*/
#include <iostream>
#include <string>
#include <exception>

using namespace std;

void introduction() //This function is for introduction and only print out information
{
    cout << "Project Name: Library Managment" << endl;
    cout << "Name: Amirali Malekghasemi" << endl;
    cout << "School Name: Earl Haig" << endl;
    cout << "" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Welcome To The Library Managment Program" << endl;
    cout << "----------------------------------------" << endl;
    cout << "" << endl;
}
int menu() //This function print the menu, validates user's input and returns the choice number
{          //So that the switch in int main() can run one of them

    bool inputValidation = true; // This variable stays true and runs the while oop until the user puts in a valid input
    string choice; //This stores user's input as a string to run the validation process
    int choiceInt; //If the user's input is correct it will turn into an int and stored in this variable
    while (inputValidation) //The while loop for validation
    {
        try //Try block
        {
            cout << "Select one of the following options:" << endl;
            cout << "1) Create an account" << endl;
            cout << "2) Add a book" << endl;
            cout << "3) Borrow a book" << endl;
            cout << "4) Return a book" << endl;
            cout << "5) List of borrowed books(For each account)" << endl;
            cout << "6) List of books" << endl;
            cout << "7) Exit Program" << endl;
            cout << "Option: ";
            cin >> choice;
            choiceInt = stoi(choice); //If user's input contains anything but numbers the compiler will throw an
                                      //invalid_arguement exception
            if (choiceInt > 7 || choiceInt < 1) //If the user's input is a number but not in the range this
            {                                   //If-statment throws a invalid-arguement error
                throw invalid_argument("");
            }
            inputValidation = false; //If the is no errors the while loop ends by this bool turning to false
        }

        catch(std::invalid_argument e) //This will catch any invalid-arguement errors thrown from the try block if
        {                              //User's input is wrong
            cout << "" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "Invalid input. Please enter a number from 1 to 7 to select one of the options" << endl;;
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "" << endl;
        }
        return choiceInt; //This will return user's choice if there is no errors and the program goes from there
    }
}

class Account //This is the superclass and holds mutal functions
{             //For classes NormalAcc, PremiumAcc and LuxuryAcc
    string firstName, lastName, id; //Stores the first name, lastname and id associated with the account
    int borrowedBooks = 0; //Holds the number of books borrowed by the person

    public:

    void setFirstName(string fName) //This function sets the first name of the account
    {
        firstName = fName;
    }
    void setLastName(string lName) //This function sets the last name of the account
    {
        lastName = lName;
    }
    void setID(string id) //This function sets the id of the account
    {
        this->id = id;
    }
    string getFirstName() //This function gets the first name so we can use it in int main()
    {
        return firstName;
    }
    string getLastName() //This function gets the last name so we can use it in int main()
    {
        return lastName;
    }
    string getID() //This function gets the id so we can use it in int main()
    {
        return id;
    }
    void incBorrowedBooks() //Everytime someone borrows a book this function will be activated
    {                       //and add to their count of borrowed books
        borrowedBooks++;
    }
    void decBorrowedBooks()//Everytime someone returns a book this function will be activated
    {                      //and decrease from their count of borrowed books
        borrowedBooks--;
    }
    int getBorrowedBooks() // This function will get how many books an account has borrowed so we can use it in int main()
    {
        return borrowedBooks;
    }
};

class NormalAcc: public Account // This is the class for normal accounts and it's a derived from super class Account
{
    static int booksAllowed; //This variable is the number of the books that people with normal account are allowed to borrow
                             //The amount is decided on line 253
    public:
    NormalAcc(string fName, string lName, int id) //This is the constructor for the class
    {
        setFirstName(fName); //This will set first name based on user's input
        setLastName(lName); //This will set last name based on user's input
        string x = to_string(id + 100); //This will turn id to an string so it can be stored(the +100 is soley for cosmetics)
        setID(x); // This will set the id for the account
    }
    int getBooksAllowed() //This will get the number of the books the account is allowed to borrow so it can be used in int main()
    {
        return booksAllowed;
    }
};

class PremiumAcc: public Account //This is the class for premium accounts and it's a derived from super class Account
{
    static int booksAllowed; //This variable is the number of the books that people with normal account are allowed to borrow
                             //The amount is decided on line 254
    public:
    PremiumAcc(string fName, string lName, int id) //This is the constructor for the class
    {
        setFirstName(fName); //This will set first name based on user's input
        setLastName(lName); //This will set last name based on user's input
        string x = to_string(id + 100); //This will turn id to an string so it can be stored(the +100 is soley for cosmetics)
        setID(x); // This will set the id for the account
    }
    int getBooksAllowed() //This will get the number of the books the account is allowed to borrow so it can be used in int main()
    {
        return booksAllowed;
    }
};

class LuxuryAcc: public Account //This is the class for luxury accounts and it's a derived from super class Account
{
    static int booksAllowed; //This variable is the number of the books that people with normal account are allowed to borrow
                             //The amount is decided on line 254
    public:
    LuxuryAcc(string fName, string lName, int id) //This is the constructor for the class
    {
        setFirstName(fName); //This will set first name based on user's input
        setLastName(lName); //This will set last name based on user's input
        string x = to_string(id + 100); //This will turn id to an string so it can be stored(the +100 is soley for cosmetics)
        setID(x); // This will set the id for the account
    }
    int getBooksAllowed() //This will get the number of the books the account is allowed to borrow so it can be used in int main()
    {
        return booksAllowed;
    }
};

class AccTypeException: public exception //This class is for validating user's input for the account type
{                                        //If the input is wrong this function will get activated
	public:
		const char* errorMessage() const throw() //This will throw an exception and a return a message value
		{
			return "\n-------------------------\nThe account type is wrong\n-------------------------\n\n";
		}
};

class IdException: public exception //This class is for validating user's input for the id number
{                                   //If the input is wrong this function will get activated
	public:
		const char* errorMessage() const throw() //This will throw an exception and a return a message value
		{
			return "\n-------------------------\nInvalid ID input\n-------------------------\n\n";
		}
};

class BookException: public exception //This class is for validating user's input for the account type
{                                     //If the input is wrong this function will get activated
	public:
		const char* errorMessage() const throw() //This will throw an exception and a return a message value
		{
			return "\n-------------------------\nThe book was not found\n-------------------------\n\n";
		}
};




class Book //This is he class for Book which stores everything related to each book
{
    string bookName; //This variable stores the name of the book
    int bookNumber; //This variable stores the number of the book
    int borrowedBy = -1; //This variable stores the id of the person who has borrowed the book and if it's not borrowed it is equal to -1 by defualt
    static int numOfBooks; //This variable stays the same through out all the objects and stores the number of the books in the program

    public:
    Book(string name, int bookNum) //This the constructor for the class Book
    {
        bookName = name; //Sets the book name
        bookNumber = bookNum; //Sets the book number
    }
    void setBookName(string name) //This function sets the book name(if we want to change it)
    {
        bookName = name;
    }
    void setBookNumber(int bookNum) //This function sets the book number(if we want to change it)
    {
        bookNumber = bookNum;
    }
    void setBorrowedBy(string borrowedBy) //This function sets the borrowedBy variable depending on who borrows the book
    {
        this->borrowedBy = stoi(borrowedBy);
    }
    static void setNumOfBooks() //This function increases the number of books in the library everytime one is created
    {
        numOfBooks++;
    }
    string getBookName() //This function will get the book name so we can use it in int main()
    {
        return bookName;
    }
    int getBookNumber() //This function will get the book number so we can use it in int main()(The plus 10 is soley cosmetic)
    {
        return bookNumber + 10;
    }
    string getBorrowedBy() //This function will get the id of the person who borrowed the book so we can use it in int main()
    {
        return to_string(borrowedBy);
    }
    static int getNumOfBooks() //This function will get the number of books in the library so we can use it in int main()
    {
        return numOfBooks;
    }
    void info() //This function is used to print out the infomation about all the books in the library
    {
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "Book Name: " << getBookName() << "         Book Number: " << getBookNumber() << endl;
        if (borrowedBy == -1)
        {
            cout << "is this book borrowed: No" << endl;
        }
        else
        {
            cout << "is this book borrowed: Yes by account number " << getBorrowedBy() << endl;
        }
        cout << "------------------------------------------------------------------------------------" << endl;
    }
};


int NormalAcc :: booksAllowed = 3;  //Normal accounts are allowed to borrow 3 books at a time
int PremiumAcc :: booksAllowed = 5; //Premium accounts are allowed to borrow 5 books at a time
int LuxuryAcc :: booksAllowed = 10; //Luxury accounts are allowed to borrow 10 books at a time
int Book :: numOfBooks = 0;

int main()
{
    int choice; //Variable to store the option user's choses in the menu
    bool runProgram = true; //This variable is set to true until the user wants to exit the program
    int maxNumOfAccounts = 10000; //This variable is the limit of the number of accounts
    int maxNumOfBooks = 10000; //This variable is the limit of the number of books
    int index; //This variable is used in many places and is a temporary holder for the index of pointers
    string fName, lName; //These two variable store first name and last name and pass them to the class of choice
    string accType; //This variable stores account type and passes it to the class of choice
    string bookName; //This variable stores book name and passes it to the class of choice
    int bookNumber; //This variable stores book number and passes it to the class of choice
    string id; //This variable stores id number and passes it to the class or function of choice
    bool accFound; //This variable depending on if we find the account or not
    bool bookFound; //This variable depending on if we find the book or not


    NormalAcc * nAccounts[maxNumOfAccounts] = {nullptr}; //Objects being initialized as array of pointers
    PremiumAcc * pAccounts[maxNumOfAccounts] = {nullptr}; //Objects being initialized as array of pointers
    LuxuryAcc * lAccounts[maxNumOfAccounts] = {nullptr}; //Objects being initialized as array of pointers
    Book * books[maxNumOfBooks] = {nullptr};


    introduction(); //Initializing introduction function

    while (runProgram) //Loop starting the main part of the program
    {
        choice = menu(); //Choice changes depending on the return value of menu() function and runs one of the switch cases
        switch (choice) //Switch case loop
        {
        case 1: //This case gets activated if the user choses opntion number 1
            cout << "----------------------" << endl;
            cout << "Creating an account..." << endl;
            cout << "----------------------" << endl;

            for (int i = 0; i < maxNumOfAccounts; i++) //Chceks for all possible account numbers
            {
                if (nAccounts[i] == nullptr & pAccounts[i] == nullptr & lAccounts[i] == nullptr) //If none of the accounts have occuipied the pointer with this index this will run
                {
                    index = i; //Set index to i for further use
                    break; //Stoping the for loop cause we found our answer
                }
            }

            //Getting user's input for first name and last name
            cout << "Enter your First Name: ";
            cin >> fName;
            cout <<"Enter your Last Name: ";
            cin >> lName;

            try
            {
                //asking for the account type
                cout << "What is the account type (Enter n for normal/ p for premium/ l for luxury): ";
                cin >> accType;
                if(!(accType == "n" || accType == "p" || accType == "l"))//IF the account type is not right we will throw and exception
                {
                    throw AccTypeException();
                }
            }
            catch(AccTypeException e) //Catching the possible exception thrown from AccTypeException function
            {
                cout << e.errorMessage();
                break;
            }

            if (accType == "n") //If the account type is normal this will run
            {
                nAccounts[index] = new NormalAcc(fName, lName, index); //Storing the account information on the first empty pointer
                cout << "" << endl; //Printing the account iformation for review by using get functions of superclass account
                cout << "-------------------------------------------------------" << endl;
                cout << "The account has been created: " << endl;
                cout << "First name: " << nAccounts[index]->getFirstName() << endl;
                cout << "Last name: " << nAccounts[index]->getLastName() << endl;
                cout << "Account id number: " << nAccounts[index]->getID() << endl;
                cout << "The account type: Normal" << endl;
                cout << "-------------------------------------------------------" << endl;
                cout << "" << endl;
            }
            else if (accType == "p") //If the account type is premium this will run
            {
                pAccounts[index] = new PremiumAcc(fName, lName, index); //Storing the account information on the first empty pointer
                cout << "" << endl; //Printing the account iformation for review by using get functions of superclass account
                cout << "-------------------------------------------------------" << endl;
                cout << "The account has been created: " << endl;
                cout << "First name: " << pAccounts[index]->getFirstName() << endl;
                cout << "Last name: " << pAccounts[index]->getLastName() << endl;
                cout << "Account id number: " << pAccounts[index]->getID() << endl;
                cout << "The account type: Premium" << endl;
                cout << "-------------------------------------------------------" << endl;
                cout << "" << endl;
            }
            else if (accType == "l") //If the account type is luxury this will run
            {
                lAccounts[index] = new LuxuryAcc(fName, lName, index); //Storing the account information on the first empty pointer
                cout << "" << endl; //Printing the account iformation for review by using get functions of superclass account
                cout << "-------------------------------------------------------" << endl;
                cout << "The account has been created: " << endl;
                cout << "First name: " << lAccounts[index]->getFirstName() << endl;
                cout << "Last name: " << lAccounts[index]->getLastName() << endl;
                cout << "Account id number: " << lAccounts[index]->getID() << endl;
                cout << "The account type: Luxury" << endl;
                cout << "-------------------------------------------------------" << endl;
                cout << "" << endl;
            }

            break; //Finishing the case 1 process


 //------------------------------------------------------------------------------------------------------------------------------------------------------------


        case 2: //This case gets activated if the user choses opntion number 2
            cout << "----------------" << endl;
            cout << "Adding a book..." << endl;
            cout << "----------------" << endl;
            for (int i = 0; i < maxNumOfBooks; i++) //Chceks for all possible book numbers
            {
                if (books[i] == nullptr) //If none of the accounts have occuipied the pointer with this index this will run
                {
                    index = i; //Sets index to i
                    break;
                }
            }
            cout << "Enter the name of the book: "; //Asking for book name and storing it in a variable
            cin >> bookName;

            books[index] = new Book(bookName, index); //Storing the book info using the inputs we got from the user
            cout << "" << endl; //Printing out information of the book using the get functions of the superclass Account
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "Book has been added: " << endl;
            cout << "The book " << books[index]->getBookName() << " with the book number " << books[index]->getBookNumber() << " has been added to the list" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "" << endl;
            Book::setNumOfBooks(); //Increasing total number of books in the library
            break;


 //------------------------------------------------------------------------------------------------------------------------------------------------------------


        case 3: //This case gets activated if the user choses opntion number 3
            cout << "-------------------" << endl;
            cout << "Borrowing a book..." << endl;
            cout << "-------------------" << endl;

            cout << "What's the id number: ";
            cin >> id;


            try
            {
                accFound = false; //Set to false by defualt cause no account has been found
                for (int i = 0; i < maxNumOfAccounts; i++) //Chceks for all possible account numbers
                {
                    if (nAccounts[i] != nullptr) //If a normal account pointer with the index i exsits this will run
                    {
                        if (nAccounts[i]->getID() == id) //If the account id stored in this object is the same with the user's input this will run
                        {
                            if (nAccounts[i]->getBorrowedBooks() < nAccounts[i]->getBooksAllowed()) //If the user hasn't exceeded the limit of the
                            {                                                                       // borrowed books allowed this will run
                                accFound = true; //Turns this variable to true so that the program knows the account has been found
                                index = i; //sets index to i
                                accType = "n"; //sets account type to normal
                                break;
                            }
                            else //Else it won't allow the account to borrow anymore books
                            {
                                cout << "" << endl;
                                cout << "--------------------------------" << endl;
                                cout << "You can not borrow anymore books" << endl;
                                cout << "--------------------------------" << endl;
                                cout << "" << endl;
                            }
                        }
                    }
                    if (pAccounts[i] != nullptr) //If a premium account pointer with the index i exsits this will run
                    {
                        if (pAccounts[i]->getID() == id) //If the account id stored in this object is the same with the user's input this will run
                        {
                            if (pAccounts[i]->getBorrowedBooks() < pAccounts[i]->getBooksAllowed())//If the user hasn't exceeded the limit of the
                            {                                                                      // borrowed books allowed this will run
                                accFound = true; //Turns this variable to true so that the program knows the account has been found
                                index = i; //sets index to i
                                accType = "p"; //sets account type to premium
                                break;
                            }
                            else //Else it won't allow the account to borrow anymore books
                            {
                                cout << "" << endl;
                                cout << "--------------------------------" << endl;
                                cout << "You can not borrow anymore books" << endl;
                                cout << "--------------------------------" << endl;
                                cout << "" << endl;
                            }
                        }
                    }
                    if (lAccounts[i] != nullptr) //If a luxury account pointer with the index i exsits this will run
                    {
                        if (lAccounts[i]->getID() == id) //If the account id stored in this object is the same with the user's input this will run
                        {
                            if (lAccounts[i]->getBorrowedBooks() < lAccounts[i]->getBooksAllowed()) //If the user hasn't exceeded the limit of the
                            {                                                                       // borrowed books allowed this will run
                                accFound = true; //Turns this variable to true so that the program knows the account has been found
                                index = i; //sets index to i
                                accType = "l"; //sets account type to luxury
                                break;
                            }
                            else //Else it won't allow the account to borrow anymore books
                            {
                                cout << "" << endl;
                                cout << "--------------------------------" << endl;
                                cout << "You can not borrow anymore books" << endl;
                                cout << "--------------------------------" << endl;
                                cout << "" << endl;
                            }
                        }
                    }
                }
                if (accFound == true) //If the acount has been found this will run
                {
                    cout << "What is the number of the book: "; //Getting the number of the book from the user
                    cin >> bookNumber;
                    bookFound = false; //Setting the bookFOund to false until we find the matching book
                    for (int i = 0; i < maxNumOfBooks; i++) //Checking for all possible book numbers
                    {
                        if (books[i] != nullptr) //If the pointer with index i is not empty this will run
                        {
                            if (books[i]->getBookNumber() == bookNumber) //If the booknumber stored in the pointer the same as user's input this will run
                            {
                                bookFound = true; //We tell the program we have found the book
                                if(books[i]->getBorrowedBy() != "-1") //If the book is borrowed this will run
                                {
                                    cout << "" << endl;
                                    cout << "--------------------------------------------------------------------------" << endl;
                                    cout << "The books is already borrowed by account with the id: " << books[i]->getBorrowedBy() << endl;
                                    cout << "--------------------------------------------------------------------------" << endl;
                                    cout << "" << endl;
                                }
                                else //else if the book is not borrowed this will run and the books will be assigned to the input id
                                {
                                    books[i]->setBorrowedBy(id); //setting up the borrowed by to the id
                                    cout << "" << endl;
                                    cout << "---------------------------------------------------" << endl;
                                    cout << "You have succefuly borrowed the book " << books[i]->getBookName() << endl;
                                    cout << "---------------------------------------------------" << endl;
                                    cout << "" << endl;

                                    if (accType == "n") //This statement will add to the count of borrowed books of the id that is borrowing the book
                                    {
                                        nAccounts[index]->incBorrowedBooks();
                                    }
                                    if (accType == "p") //This statement will add to the count of borrowed books of the id that is borrowing the book
                                    {
                                        pAccounts[index]->incBorrowedBooks();
                                    }
                                    if (accType == "l") //This statement will add to the count of borrowed books of the id that is borrowing the book
                                    {
                                        lAccounts[index]->incBorrowedBooks();
                                    }
                                }
                                break;
                            }
                        }
                    }
                    if (bookFound == false) //If the book was not found this will run and throw and exception with a message
                    {
                        throw BookException(); //Throwing an exception
                    }
                }

                else //If the id is invalid this will run
                {
                    throw IdException(); //Throwing an exception
                }
            }

            catch(IdException e) //Catching exception thrown for wrong id
            {
                cout << e.errorMessage(); //Printing the eexception error message
            }
            catch(BookException e) //Catching exception thrown for wrong book number
            {
                cout << e.errorMessage(); //Printing the eexception error message
            }
            break;


//------------------------------------------------------------------------------------------------------------------------------------------------------------



        case 4: //This case gets activated if the user choses opntion number 4
            cout << "-------------------" << endl;
            cout << "Returning a book..." << endl;
            cout << "-------------------" << endl;

            cout << "What's the id number: ";
            cin >> id;


            try
            {
                accFound = false; //Set to false by defualt cause no account has been found
                for (int i = 0; i < maxNumOfAccounts; i++) //Chceks for all possible account numbers
                {
                    if (nAccounts[i] != nullptr) //If a normal account pointer with the index i exsits this will run
                    {
                        if (nAccounts[i]->getID() == id) //If the account id stored in this object is the same with the user's input this will run
                        {
                            index = i; //sets index to i
                            accFound = true; //Turns this variable to true so that the program knows the account has been found
                            accType = "n"; //sets account type to normal
                            break;
                        }
                    }
                    if (pAccounts[i] != nullptr) //If a premium account pointer with the index i exsits this will run
                    {
                        if (pAccounts[i]->getID() == id) //If the account id stored in this object is the same with the user's input this will run
                        {
                            index = i; //sets index to i
                            accFound = true; //Turns this variable to true so that the program knows the account has been found
                            accType = "p"; //sets account type to premium
                            break;
                        }
                    }
                    if (lAccounts[i] != nullptr) //If a luxury account pointer with the index i exsits this will run
                    {
                        if (lAccounts[i]->getID() == id) //If the account id stored in this object is the same with the user's input this will run
                        {
                            index = i; //sets index to i
                            accFound = true; //Turns this variable to true so that the program knows the account has been found
                            accType = "n"; //sets account type to luxury
                            break;
                        }
                    }
                }
                if (accFound == true) //If the account has been found this will run
                {
                    cout << "What is the number of the book: "; //Asking for the book number from the user
                    cin >> bookNumber;
                    bookFound = false; //Set to false by defualt because no book has been found yet
                    for (int i = 0; i < maxNumOfBooks; i++) //Checks for all possible book numbers
                    {
                        if (books[i] != nullptr) //If the pointer with index i is not empty this will run
                        {
                            if (books[i]->getBookNumber() == bookNumber)//If the booknumber stored in the pointer the same as user's input this will run
                            {
                                bookFound = true; //We tell the program we have found the book
                                if(books[i]->getBorrowedBy() == id) //If the user's id is the same with the id stored in this books pointer this will run
                                {                                   //and the book will be returned succesfully
                                    books[i]->setBorrowedBy("-1"); //Telling the program that this book is not borrowed anymore
                                    cout << "-------------------------------------" << endl;
                                    cout << "The book has been returned succesfuly" << endl;
                                    cout << "-------------------------------------" << endl;
                                    if (accType == "n") //Decreasing from the accounts borrowed books count
                                    {
                                        nAccounts[index]->decBorrowedBooks();
                                    }
                                    else if (accType == "p") //Decreasing from the accounts borrowed books count
                                    {
                                        pAccounts[index]->decBorrowedBooks();
                                    }
                                    else if (accType == "l") //Decreasing from the accounts borrowed books count
                                    {
                                        lAccounts[index]->decBorrowedBooks();
                                    }
                                }
                                else //If the id associated with the book is not the same with user's input this will run
                                {
                                    cout << "----------------------------------------" << endl;
                                    cout << "This books has not been borrowed by you! " << endl;
                                    cout << "----------------------------------------" << endl;
                                }
                                break;
                            }
                        }
                    }
                    if (bookFound == false) //If the book was not found this will run and throw and exception with a message
                    {
                        throw BookException(); //Throwing an exception
                    }
                }

                else //If the id is invalid this will run
                {
                    throw IdException(); //Throwing an exception
                }
            }

            catch(IdException e) //Catching exception thrown for wrong id
            {
                cout << e.errorMessage(); //Printing the eexception error message
            }

            catch(BookException e) //Catching exception thrown for wrong book number
            {
                cout << e.errorMessage(); //Printing the eexception error message
            }

            break;





//------------------------------------------------------------------------------------------------------------------------------------------------------------



        case 5: //This case gets activated if the user choses opntion number 5
            cout << "--------------------" << endl;
            cout << "Listing the books borrowed..." << endl;
            cout << "--------------------" << endl;

            cout << "Whats the id number: ";
            cin >> id;

            try
            {
                accFound = false; //Set to false by defualt cause no account has been found
                for (int i = 0; i < maxNumOfAccounts; i++) //Chceks for all possible account numbers
                {
                    if (nAccounts[i] != nullptr) //If a normal account pointer with the index i exsits this will run
                    {
                        if (nAccounts[i]->getID() == id) //If the account id stored in this object is the same with the user's input this will run
                        {
                            accFound = true; //Turns this variable to true so that the program knows the account has been found
                            index = i; //sets index to i
                            accType = "n"; //sets account type to normal
                            break;
                        }
                    }
                    if (pAccounts[i] != nullptr) //If a premium account pointer with the index i exsits this will run
                    {
                        if (pAccounts[i]->getID() == id) //If the account id stored in this object is the same with the user's input this will run
                        {
                            accFound = true; //Turns this variable to true so that the program knows the account has been found
                            index = i; //sets index to i
                            accType = "p"; //sets account type to premium
                            break;
                        }
                    }
                    if (lAccounts[i] != nullptr) //If a luxury account pointer with the index i exsits this will run
                    {
                        if (lAccounts[i]->getID() == id) //If the account id stored in this object is the same with the user's input this will run
                        {
                            accFound = true; //Turns this variable to true so that the program knows the account has been found
                            index = i; //sets index to i
                            accType = "l"; //sets account type to luxury
                            break;
                        }
                    }
                }
                if (accFound == true) //If the account has been found this will run
                {
                    bookFound = false; //This will be false by defualt because it's assumed the account doesn't having any borrowed accounts
                    cout << "" <<endl;
                    cout << "---------------------------------------------------------------------------------------------------------------" <<endl;
                    for(int i = 0; i < Book::getNumOfBooks(); i++) //Checking all the books that have been made in the program
                    {
                        if (accType == "n") //If the id is assigned to a normal account this will run
                        {
                            if (books[i]->getBorrowedBy() == id) //if the book's borrowedby id is the same as the user's input id this will run
                            {
                                cout << "Book number " <<  books[i]->getBookNumber() << " named " << books[i]->getBookName() << " has been borrowed by this account" << endl;
                                bookFound = true; //Tells the program that this account has at least one book borrowed
                            }
                        }
                        if (accType == "p") //If the id is assigned to a premium account this will run
                        {
                            if (books[i]->getBorrowedBy() == id) //if the book's borrowedby id is the same as the user's input id this will run
                            {
                                cout << "Book number " <<  books[i]->getBookNumber() << " named " << books[i]->getBookName() << " has been borrowed by this account" << endl;
                                bookFound = true; //Tells the program that this account has at least one book borrowed
                            }

                        }
                        if (accType == "l") //If the id is assigned to a luxury account this will run
                        {
                            if (books[i]->getBorrowedBy() == id) //if the book's borrowedby id is the same as the user's input id this will run
                            {
                                cout << "Book number " <<  books[i]->getBookNumber() << " named " << books[i]->getBookName() << " has been borrowed by this account" << endl;
                                bookFound = true; //Tells the program that this account has at least one book borrowed
                            }
                        }
                    }
                    if (bookFound == false) //If the account doesn't have any borrowed books this will run
                    {
                        cout << "This account doesn't have any borrowed books" << endl;
                    }
                    cout << "---------------------------------------------------------------------------------------------------------------" <<endl;
                    cout << "" <<endl;
                }
                else //If the id is wrong this will run and throw and exception
                {
                    throw IdException(); //Throws an exception
                }
            }

            catch(IdException e) //Catches the exception thrown from the wrong id
            {
                cout << e.errorMessage(); //Prints the exception error message
            }

            break;


//------------------------------------------------------------------------------------------------------------------------------------------------------------



        case 6: //This case gets activated if the user choses opntion number 6
            cout << "--------------------" << endl;
            cout << "Listing the books..." << endl;
            cout << "--------------------" << endl;
            bookFound = false;
            for (int i = 0; i < maxNumOfBooks; i++) //Checks for all possible made books
            {
                if (books[i] == nullptr) //If the pointer with index i is null the loop will finish
                {
                    continue;
                    bookFound == true;
                }
                else //else it wil run info() function which prints the book's information
                {
                    books[i]->info();
                }
            }
            if (bookFound == false)//This will run if no books exist in the library
            {
                cout << "" << endl;
                cout << "-----------------------" << endl;
                cout << "No books in the library" << endl;
                cout << "-----------------------" << endl;
                cout << "" << endl;
            }
            break;


//------------------------------------------------------------------------------------------------------------------------------------------------------------


        case 7: //This case gets activated if the user choses opntion number 7
            runProgram = false; //Ends the program
            break;


        }
    }
    return 0;
}
