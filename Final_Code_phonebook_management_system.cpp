#include<iostream>              // Includes basic input/output funtcions
#include<conio.h>               // For console input/output function eg. getch()
#include<windows.h>             // for all of the functions in the Windows API eg. system("cls"), 
#include<iomanip>               // Used to set field width eg. setw()
#include<fstream>               // To perform output and input of characters to/from files eg. ifstream , ofstream
#include<dos.h>                 // For sleep() function
using namespace std;

string first_name, last_name, phone_num;
int count_start = 0;

void start();                       // Yuvi                 
void addContact();                  // Harman              
void searchContact();               // Derek            
void show_all();                    // Yuvi                     
void help();                        // Harman           
void self_exit();                   // Derek                                     
void update();                      // Yuvi                                       
void del();                         // Harman                                        
void recycleBin();                  // Derek                                        
void binDel(string);                // Derek            
void cancel(string);                // Yuvi             
void recents();                     // Harman              
bool check_digits(string);          // All
bool check_numbers(string);         // All  
bool chDup(string);                 // All     

//Global File declaration
fstream phone("number.txt",ios::app);

int main()
{
    short int choice;
    system("cls");
    /*
	0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White*/
    system("color B0");

    while(count_start==0)
    {
        start(); //
        count_start=1;
    }
    
    ofstream obj2("number.txt",ios::app);
    obj2.close();
    
	system("cls");
    cout << "\n\n\n\n\n\n";
    cout << "\n\t\t\t\t\t--------------------------------------------";
    cout << "\n\t\t\t\t\t|           Choose your service            |";
    cout << "\n\t\t\t\t\t--------------------------------------------";
    cout << "\n\t\t\t\t\t--------------------------------------------";
    cout << "\n\t\t\t\t\t|           [1] Contacts List              |";
    cout << "\n\t\t\t\t\t|           [2] New Contact                |";
	cout << "\n\t\t\t\t\t|           [3] Search Contact             |";
    cout << "\n\t\t\t\t\t|           [4] Recents                    |";
    cout << "\n\t\t\t\t\t|           [5] Update Contact             |";
    cout << "\n\t\t\t\t\t|           [6] Delete Contact             |";
    cout << "\n\t\t\t\t\t|           [7] Reycle Bin                 |";
    cout << "\n\t\t\t\t\t|           [8] Help                       |";
    cout << "\n\t\t\t\t\t|           [9] Exit                       |";
    cout << "\n\t\t\t\t\t--------------------------------------------";
    cout << "\n\n\n\t\t\t\t\tEnter your Choice: "; 
    
    cin >> choice;

    switch(choice)
    {
        case 1:
            show_all();
            break;
        case 2:
            addContact();
            break;
        case 3:
            searchContact();
            break;
        case 4:
            recents();
            break;
        case 5:
            update();
            break;
		case 6:
            del();
            break;
        case 7:
        	recycleBin();
        	break;
        case 8:
            help();
            break;
        case 9:
            self_exit();
            break;
        
        default:
            cout << "\n\n\t\t\t\t\tInvalid Input !";
            cout << "\n\t\tPress Any Key To Continue...";
            getch();
    }
	
	main();
    return 0;
}


/*********************************/
/*********************************/
/*                                   START LOADING FUNCTION                                        */
/*********************************/
/*********************************/

void start()
{
    cout << "\n\n\n\n\n\n";
    cout << "\n\t\t\t\t\t--------------------------------------------";
    cout << "\n\t\t\t\t\t|       PHONE BOOK MANAGEMENT SYSTEM       |";
    cout << "\n\t\t\t\t\t--------------------------------------------";
    cout << "\n\t\t\t\t\t|               By: Group-4                |";
    cout << "\n\t\t\t\t\t|   Harmanpreet Singh     - 20BCS6501      |";
    cout << "\n\t\t\t\t\t|   Yuvpartap Singh Klair - 20BCS6448      |";
    cout << "\n\t\t\t\t\t|   Derek Samuel Austin   - 20BCS6489      |";
    cout << "\n\t\t\t\t\t--------------------------------------------";
    cout << "\n\n\n\n";
    char x=46; // "."
    for(int i=0; i<3; i++)
    {
    	cout<<"\r";  //\r is a carriage return character; it moves the cursor at the start of that line. 
        cout<<"\t\t\t\t\t\t\tLoading";
        for(int j=0; j<3; j++ )
        {
            cout<<x;
            Sleep(200); //Loading    
        }
        cout << "\r";
        cout << "\t\t\t\t\t\t\tLoading     ";
       	
    }
    system("cls");
}
/*********************************/
/*********************************/
/*                                   SELF Exit FUNCTION                                            */
/*********************************/
/*********************************/
void self_exit()
{
    system("cls");
    cout << "\n\n\n\n\n\n";
    cout << "\n\t\t\t\t\t----------------------------------";
    cout << "\n\t\t\t\t\t|      Thank you for using!      |";
    cout << "\n\t\t\t\t\t----------------------------------";
    cout << "\n\n\n\n\n\n";
    exit(1);
}

/*********************************/
/*********************************/
/*                                          HELP FUNCTION                                          */
/*********************************/
/*********************************/

void help()																	                                                   	//***HELP ()
{
	system("cls");
    cout << "\n\n\n\n\n\n";
    cout << "\n\t\t----------------------------------------------------------------------------------------";
    cout << "\n\t\t|                                    Help                                              |";
    cout << "\n\t\t----------------------------------------------------------------------------------------";
    cout << "\n\t\t|   Choose the Service you want from the list                                          |";
    cout << "\n\t\t|     a) Contact List   : Displays the All saved record of contacts                    |";
    cout << "\n\t\t|     b) New Contact    : Adds a new contact to database                               |";
    cout << "\n\t\t|     c) Search Contact : Find the desired contact by entering name or phone number    |";
    cout << "\n\t\t|     d) Recent         : It shows the recent search history of the user               |";
    cout << "\n\t\t|     e) Update Contact : Modify the Name or Phone Number of desired contact           |";
    cout << "\n\t\t|     f) Delete Contact : Delete the contacts from database                            |";
    cout << "\n\t\t|     g) Recycle Bin    : Search deleted contacts and permanently delete them          |";
    cout << "\n\t\t|     h) Exit           : Let you exit the program                                     |";
    cout << "\n\t\t----------------------------------------------------------------------------------------";    
    cout<<"\n\t\tPress ENTER to return HOME...";
    getch();
}

/*********************************/
/*********************************/
/*                                       SHOW ALL FUNCTION                                         */
/*********************************/
/*********************************/

void show_all()
{   
    ifstream f("number.txt",ios::ate);
        if(f.is_open())
        {
            if(f.tellg() == 0)
            {
                system("cls");
                cout << "\n\n\n\n\n\t\t\t\t\t-------------------------------------------";
			    cout << "\n\t\t\t\t\t|             File is empty!!             |";
                cout << "\n\t\t\t\t\t-------------------------------------------";
            }
            else
            {
                system("cls");
                f.seekg(ios::beg);
                cout << "\n\n";
                cout << "\n\t\t\t\t\t-------------------------------------";
                cout << "\n\t\t\t\t\t|              RECORD               |";
                cout << "\n\t\t\t\t\t-------------------------------------";
                while (!f.eof())
                    {
                        string first_name,last_name,phone_num;
                        f >> first_name >> last_name >> phone_num ;
                        cout << "\n\t\t\t\t\t  " << first_name << " " << last_name << " \t " << phone_num << endl;
                    }
            }
        }
        else
            {
                cout << "\n\t\t\t\t\tError opening File!";
            }
        f.close();
        cout << "\n\n\n\n\n\t\t\tPress any KEY to return HOME...\n";
        getch();            
}

/*********************************/
/*********************************/
/*                                      UPDATE FUNCTION                                            */
/*********************************/
/*********************************/

void update()
{
    string u_choice;
    system("cls");
    cout << "\n\tCANCEL (C)";
    cout << "\n\n\n\n\n";
    cout << "\n\t\t\t\t\t----------------------------------------------";
    cout << "\n\t\t\t\t\t|             Enter Your Choice              |";
    cout << "\n\t\t\t\t\t----------------------------------------------";
    cout << "\n\t\t\t\t\t|        [1] Update First Name               |";
    cout << "\n\t\t\t\t\t|        [2] Update Last Name                |";
    cout << "\n\t\t\t\t\t|        [3] Update Phone Number             |";
    cout << "\n\t\t\t\t\t----------------------------------------------";
    cout << "\n\n\t\t\t\t\tYour choice: ";
    cin >> u_choice;
    cancel(u_choice);

    if(u_choice == "1")
    {
        repeat_update_fname:
        string old_first_name;
        char u_confirm='0';
        
        ifstream fname_obj("number.txt",ios::ate);
        ofstream update_fname_obj("update.txt");
        if(fname_obj.tellg() == 0)
            {
                system("cls");
                cout << "\n\n\n\n\n\t\t\t\t\t-------------------------------------------";
			    cout << "\n\t\t\t\t\t|             File is empty !!             |";
                cout << "\n\t\t\t\t\t-------------------------------------------";
            }
        else
        {
            system("cls");
            cout << "\n\tCANCEL (C)";
            cout << "\n\n\n\n\n";
            cout << "\n\t\t\t\t\t------------------------------------";
            cout << "\n\t\t\t\t\t     Enter First Name to UPDATE ";
            cout << "\n\t\t\t\t\t------------------------------------";
            cout << "\n\t\t\t\t\t";
			cin >> old_first_name; 
            cancel(old_first_name);

            fname_obj.seekg(ios::beg);
			while(fname_obj >> first_name >> last_name >> phone_num)
            {
                if(old_first_name == first_name)
                {
                    repeat_fname_choice:
                    system("cls");
                    cout << "\n\n\n\n\n";
                    cout << "\n\t\t\t\t\t-------------------------------------------";
					cout << "\n\t\t\t\t\t|                Confirm                  |";
					cout << "\n\t\t\t\t\t+-----------------------------------------+";
                    cout << "\n\t\t\t\t\t\tDo you want to update this contact?";
                    cout << "\n\t\t\t\t\t\tFirst Name: " << first_name;
                    cout << "\n\t\t\t\t\t\tLast Name: " << last_name;
                    cout << "\n\t\t\t\t\t\tPhone Num: " << phone_num;
                    cout << "\n\t\t\t\t\t-------------------------------------------";
                    cout << "\n\t\t\t\t\t\t   Yes(Y) | No(N)  ";
                    cout << "\n\t\t\t\t\t-------------------------------------------";
                    cout << "\n\t\t\t\t\t";
					cin >> u_confirm;
                    if(u_confirm == 'Y' or u_confirm == 'y')
                    {
                        system("cls");
                        cout << "\n\t\t\t\t\t+------------------------------------+";
                        cout << "\n\t\t\t\t\t   Enter the new first name ";
                        cout << "\n\t\t\t\t\t+------------------------------------+";
						cout << "\n\t\t\t\t\t";
						cin >> first_name;
                        update_fname_obj << first_name << "\t" << last_name << "\t" << phone_num <<endl;
                    }
                }
                else
                {
                    update_fname_obj << first_name << "\t" << last_name << "\t" << phone_num <<endl;
                }
            }

            if(u_confirm == 'Y' or u_confirm == 'y')
            {
                fname_obj.close();
                update_fname_obj.close();
                phone.close();
                int res_rem = remove("number.txt");
                int res_ren = rename("update.txt","number.txt");
                if(res_rem == 0)
                {
                    if(res_ren == 0)
                    {
                        cout << "\n\t\t\t\t\tFirst Name updated successfully";
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\tError while renaming..!!";
                    }
                }
                else
                {
                    cout << "\n\t\t\t\t\tError while removing..!!";
                }
            }
            else if(u_confirm == 'N' or u_confirm == 'n')
            {
                goto repeat_update_fname;
            }
            else if(u_confirm == '0')
            {
                cout << "\n\t\t\t\t\tNo contacts match your search";
            }
            else
            {
                cout << "\n\t\t\t\t\tInvalid choice..!!";
                goto repeat_fname_choice;
            }
        }

    }
    else if(u_choice == "2")
    {
        repeat_update_lname:
        string old_last_name;
        char u_confirm='0';
        
        ifstream lname_obj("number.txt",ios::ate);
        ofstream update_lname_obj("update.txt");
        if(lname_obj.tellg() == 0)
            {
                system("cls");
                cout << "\n\n\n\n\n\t\t\t\t\t-------------------------------------------";
			    cout << "\n\t\t\t\t\t|             File is empty!!             |";
                cout << "\n\t\t\t\t\t-------------------------------------------";
            }
        else
        {
            system("cls");
            cout << "\n\tCANCEL (C)";
			cout << "\n\n\n\n\n";
            cout << "\n\t\t\t\t\t------------------------------------";
            cout << "\n\t\t\t\t\t      Enter Last Name to UPDATE   ";
            cout << "\n\t\t\t\t\t------------------------------------\n";
            cout << "\n\t\t\t\t\t";
			cin >> old_last_name;
            cancel(old_last_name);

            lname_obj.seekg(ios::beg);
            
            while(lname_obj >> first_name >> last_name >> phone_num)
            {
                if(old_last_name == last_name)
                {
                    repeat_lname_choice:
                    system("cls");
                    cout << "\n\n\n\n\n";
                    cout << "\n\t\t\t\t\t-------------------------------------------";
					cout << "\n\t\t\t\t\t|                Confirm                  |";
					cout << "\n\t\t\t\t\t+-----------------------------------------+";
                    cout << "\n\t\t\t\t\t\tDo you want to update this contact?";
                    cout << "\n\t\t\t\t\t\tFirst Name: "<< first_name;
                    cout << "\n\t\t\t\t\t\tLast Name: "<< last_name;
                    cout << "\n\t\t\t\t\t\tPhone Num: "<< phone_num;
                    cout << "\n\t\t\t\t\t-------------------------------------------";
                    cout << "\n\t\t\t\t\t\t   Yes(Y) | No(N)  ";
                    cout << "\n\t\t\t\t\t-------------------------------------------\n";
                    cout << "\n\t\t\t\t\t";
					cin >> u_confirm;
                    if(u_confirm == 'Y' or u_confirm == 'y')
                    {
                        system("cls");
                        cout << "\n\t\t\t\t\t+------------------------------------+";
                        cout << "\n\t\t\t\t\t   Enter the new Last name ";
                        cout << "\n\t\t\t\t\t+------------------------------------+\n";
						cout << "\n\t\t\t\t\t";
						cin >> last_name;
                        update_lname_obj << first_name << "\t" << last_name << "\t" << phone_num <<endl;
                    }
                }
                else
                {
                    update_lname_obj << first_name << "\t" << last_name << "\t" << phone_num << endl;
                }
            }
            if(u_confirm == 'Y' or u_confirm == 'y')
            {
                lname_obj.close();
                update_lname_obj.close();
                phone.close();
                int res_rem = remove("number.txt");
                int res_ren = rename("update.txt","number.txt");
                if(res_rem == 0)
                {
                    if(res_ren == 0)
                    {
                        cout << "\n\t\t\t\t\tContact updated successfully!";
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\tError while renaming..!!";
                    }
                }
                else
                {
                    cout << "\n\t\t\t\t\tError while removing..!!";
                }
            }
            else if(u_confirm == 'N' or u_confirm == 'n')
            {
				goto repeat_update_lname;
            }
            else if(u_confirm == '0')
            {
                cout << "\n\t\t\t\tNo contacs match your search.";
            }
            else
            {
                cout << "\n\t\t\t\t\tInvalid choice..!!";
                goto repeat_lname_choice;
            }
        }

    }
    
    else if(u_choice == "3")
    {
        repeat_update_pnum:
        string old_phone_num;
        char u_confirm='0';
        
        ifstream pnum_obj("number.txt",ios::ate);
        ofstream update_pnum_obj("update.txt");
        if(pnum_obj.tellg() == 0)
            {
                system("cls");
                cout << "\n\n\n\n\n\t\t\t\t\t-------------------------------------------";
			    cout << "\n\t\t\t\t\t|             File is empty!!             |";
                cout << "\n\t\t\t\t\t-------------------------------------------";
            }
        else
        {
            system("cls");
            
            cout << "\n\tCANCEL (C)";
			cout << "\n\n\n\n\n";
            cout << "\n\t\t\t\t\t------------------------------------";
            cout << "\n\t\t\t\t\t     Enter Phone number to UPDATE   ";
            cout << "\n\t\t\t\t\t------------------------------------";
            cout << "\n\t\t\t\t\t";
			cin >> old_phone_num; 
            cancel(old_phone_num);
            
            pnum_obj.seekg(ios::beg);
            
            while(pnum_obj >> first_name >> last_name >> phone_num )
            {
                if(old_phone_num == phone_num)
                {
                    repeat_pnum_choice:
                    system("cls");
                    cout << "\n\n\n\n\n";
                    cout << "\n\t\t\t\t\t-------------------------------------------";
					cout << "\n\t\t\t\t\t|                Confirm                  |";
					cout << "\n\t\t\t\t\t+-----------------------------------------+";
                    cout << "\n\t\t\t\t\t\tDo you want to update this contact?";
                    cout << "\n\t\t\t\t\t\tFirst Name: " << first_name;
                    cout << "\n\t\t\t\t\t\tLast Name: " << last_name;
                    cout << "\n\t\t\t\t\t\tPhone Num: " << phone_num;
                    cout << "\n\t\t\t\t\t-------------------------------------------";
                    cout << "\n\t\t\t\t\t\t   Yes(Y) | No(N)  ";
                    cout << "\n\t\t\t\t\t-------------------------------------------";
                    cin >> u_confirm;
                    if(u_confirm == 'Y' or u_confirm == 'y')
                    {
                        system("cls");
                        cout << "\n\t\t\t\t\t+------------------------------------+";
                        cout << "\n\t\t\t\t\t   Enter the new Phone Number ";
                        cout << "\n\t\t\t\t\t+------------------------------------+";
						cout << "\n\t\t\t\t\t";
						cin >> phone_num;
                        update_pnum_obj << first_name << "\t" << last_name << "\t" << phone_num << endl;
                    }
                }
                else
                {
                    update_pnum_obj << first_name << "\t" << last_name << "\t" << phone_num << endl;
                }
            }
            if(u_confirm == 'Y' or u_confirm == 'y')
            {
                pnum_obj.close();
                update_pnum_obj.close();
                phone.close();
                int res_rem = remove("number.txt");
                int res_ren = rename("update.txt","number.txt");
                if(res_rem == 0)
                {
                    if(res_ren == 0)
                    {
                        cout << "\n\t\t\t\t\tContact updated successfully!";
                    }
                    else
                    {
                        cout << "\n\t\t\t\t\tError while renaming..!!";
                    }
                }
                else
                {
                    cout << "\n\t\t\t\t\tError while removing..!!";
                }
            }
            else if(u_confirm == 'N' or u_confirm == 'n')
            {
                goto repeat_update_pnum;
            }
            else if(u_confirm == '0')
            {
                cout << "\n\t\t\t\t\tNo contacts match your search.";
            }
            else
            {
                cout << "Invalid choice..!!";
                goto repeat_pnum_choice;
            }
        }

    }
    else
    {
        cout << "\n\n\t\t\t\t\tInvalid Choice..!!";
    }

    getch();
}


/*********************************/
/*********************************/
/*                                   Add Contact FUNCTION                                          */
/*********************************/
/*********************************/

void addContact()																
{
    string first_name,last_name,phone_num;
    system("cls");
    cout<<"\n\tCANCEL (C)";
    cout << "\n\n\n\n\n\n";
    cout << "\n\t\t\t\t\t-------------------------------------------";
    cout << "\n\t\t\t\t\t          Enter the Contact Details        ";
    cout << "\n\t\t\t\t\t-------------------------------------------";
	cout << "\n\n\t\t\t\t\t     Enter First Name : ";
    cin >> first_name;
    cancel(first_name);

	cout << "\n\t\t\t\t\t     Enter Last Name  : ";
    cin >> last_name;
    cancel(last_name);

	cout << "\n\t\t\t\t\t     Enter Phone Number : ";
    cin >> phone_num;
    cancel(phone_num);
    
	string keyword = phone_num;
	
	fstream phone("number.txt",ios::app);
	
    if(chDup(keyword) == true)
	{
    	if(check_digits(phone_num) == true)
		{
		    if(check_numbers(phone_num) == true)
		    {
		        if(phone.is_open())
		        {
					phone << first_name << " " << last_name << "  " << phone_num << endl;
					cout << "\n\n\n\n\t\t\t\t\tContact successfully saved in Contacts."<<endl;
		        }
		        else
		        {
		            cout << "\n\tError Opening File !";
		        }
		    }
		    else
		    {
		        cout << "\n\t\t\t\t\tPhone Number Must Contain Numbers Only !\n\t\t\t\t\tTry again. (Y/N)";
		        char choice;
			    cin>>choice;
			    if(choice=='Y' or choice=='y')
			    	addContact();
			    else{
			    	main();
				}
		    }
		}
	    else
	    {
	        cout << "\n\t\t\t\t\tPhone Number Must Contain 10 Digits Only !\n\t\t\t\t\tTry again. (Y/N)";
	        char choice;
			cin>>choice;
		    if(choice=='Y' or choice=='y')
		    	addContact();
		    else{
		    	main();
			}
	    }    
	}
	else //chDup
    {
		system("cls");
	    cout<<"\n\n\n\n\n\n\t\t\t\t\tContact Already Exist !!";
	}
    phone.close();
    char choice;
    cout<<"\n\n\n\t\t\t\t\tNew Contact (Y/N) : ";
    cin>>choice;
    if(choice=='Y' or choice=='y'){
    	system("cls");
		addContact();
	}
    else{
    	main();
	}
}

/*********************************/
/*********************************/
/*                                   SEARCH CONTACT FUNCTION                                       */
/*********************************/
/*********************************/

void searchContact()														
{
	string first_name,last_name,phone_num;
    string c;
    search_choice:
    system("cls");
    
    cout << "\n\tCANCEL (C)";
	cout << "\n\n\n\n\n";
    cout << "\n\t\t\t\t---------------------------------------------------";
	cout << "\n\t\t\t\t         Search via Name(N) / Phone Number(P)      ";
	cout << "\n\t\t\t\t---------------------------------------------------";
	cout << "\n\t\t\t\t\t    Enter your Choice: ";
	cin>>c;
    cancel(c);

    system("cls");
    bool found = false;
    ifstream myfile("number.txt");
	string keyword;
	if(c == "n" or c == "N")
    {
        cout << "\n\tCANCEL (C)";
        cout << "\n\n\n\n\n\n";
	    cout << "\n\t\t\t\t\t---------------------------------------------------";
	    cout << "\n\t\t\t\t\t                  Search By Name                   ";
	    cout << "\n\t\t\t\t\t---------------------------------------------------";
	    cout << "\n\t\t\t\t\t   Enter First/Last Name To Search : "; 
	    cin >> keyword; 
        cancel(keyword);
	    system("cls");
	    cout << "\n\n\n\n\n\n";
	    cout << "\n\t\t\t\t\t-----------------------------------------";
	    cout << "\n\t\t\t\t\t|            Contact details            |";
	    cout << "\n\t\t\t\t\t-----------------------------------------";
	    while(myfile >> first_name >> last_name >> phone_num)  //read all lines
	    {
	        if(keyword == first_name or keyword == last_name)
	        {
                cout << "\n\t\t\t\t\t|      \tName   :   "<< first_name<<" "<<last_name<<"\t\t|";
	            cout << "\n\t\t\t\t\t|      \tPhone Number : "<< phone_num << "\t|";
				cout << "\n\t\t\t\t\t---------------------------------------";
	            found = true;
	            ofstream recents("recents.txt", ios :: app);
	            if(recents.is_open())
                {
	            	recents << first_name<< " " << last_name << "\t" << phone_num <<endl;
				}
				else
					cout<<"ERROR opening recents.txt";
				recents.close();
	        }
	    }
	}
	else if(c == "p" or c == "P") //same as 'name'
	{
        cout << "\n\tCANCEL (C)";
		cout << "\n\n\n\n\n";
	    cout << "\n\t\t\t\t--------------------------------------------------------------";
	    cout << "\n\t\t\t\t|\t            Search By Phone Number\t             |";
	    cout << "\n\t\t\t\t--------------------------------------------------------------";
	    cout << "\n\t\t\t\t\t   Enter Phone Number To Search : "; 
	    cin >> keyword;
        cancel(keyword);

	    while(myfile >> first_name >> last_name >> phone_num)
	    {
	        if(keyword == phone_num)
	        {
	            system("cls");
	            cout << "\n\n\n\n\n\n";
	            cout << "\n\t\t\t\t\t-----------------------------------------";
	            cout << "\n\t\t\t\t\t|            Contact details            |";
	            cout << "\n\t\t\t\t\t-----------------------------------------";
	            cout << "\n\t\t\t\t\t|      \tName   :   "<< first_name<<" "<<last_name<<"\t\t|";
	            cout << "\n\t\t\t\t\t|      \tPhone Number : "<< phone_num << "\t|";
				cout << "\n\t\t\t\t\t---------------------------------------";
	            found = true;
	            ofstream recents("recents.txt", ios :: app); //wrting the data 
	            if(recents.is_open())
                {
	            	recents << first_name<< " " << last_name << "\t" << phone_num << endl;
				}
				else
					cout<<"ERROR opening recents.txt";
				recents.close();
	            break;
	        }
	    }
	}
    else
    {
        cout << "\n\n\n\n\n\n\t\t\t\t\tInvalid Choice...!!"<<endl;
        cout << "\t\t\t\t\tPress ENTER to CONTINUE...";
        getch();
        goto search_choice;
    }
	myfile.close();
    if(found == false)
	    {
			cout << "\n\n\t\t\t\t\tNo Contacts Match Your Search !";		
		}
	
	char ch;	
	cout << "\n\n\n\t\t\t\t\tSearch another contact (Y/N) : ";
	cin >> ch;
	if(ch == 'y' or ch == 'Y')
	{
		system("cls");
		searchContact();
	}
    else{
		getch();
    	main();
	} 		
}
/*********************************/
/*********************************/
/*                                        DELETE FUNCTION                                          */
/*********************************/
/*********************************/
void del()
{
	ifstream f("number.txt",ios::ate);
	if(f.is_open())
        {
            if(f.tellg() == 0)
            {
                system("cls");
                cout << "\n\n\n\n\n\t\t\t\t\t---------------------------------------------------";
			    cout << "\n\t\t\t\t\t|          File is empty, no contact to delete !          |";
                cout << "\n\t\t\t\t\t-----------------------------------------------------------";
                Sleep(1000);
            	main();
            }
            else
            {
            	string choice;
                repeat_del_choice:
			    system("cls");
                cout << "\n\tCANCEL (C)";
                cout << "\n\n\n\n\n";
                cout << "\n\t\t\t\t\t---------------------------------------------------";
                cout << "\n\t\t\t\t\t                 Enter Your Choice                 ";
			    cout << "\n\t\t\t\t\t---------------------------------------------------";
			    cout << "\n\t\t\t\t\t\t      [1] Delete all Contacts               ";
			    cout << "\n\t\t\t\t\t\t      [2] Delete Specific Contacts          ";
			    cout << "\n\t\t\t\t\t---------------------------------------------------";
			    cout << "\n\t\t\t\t\tEnter your choice: ";
			    cin >> choice;
                cancel(choice);
			
			    if(choice == "1")																					//DELETE ALL CONTACTS
			    {	
					char conf;
					int count_contacts=0;
                    ifstream file1("number.txt");
                    while (file1 >> first_name >> last_name >> phone_num)
                    {
					   	count_contacts++;
					};
                    file1.close();
                    
                    cout << "\n\t\t\t\t\t-------------------------------------------";
					cout << "\n\t\t\t\t\t|                Confirm                  |";
					cout << "\n\t\t\t\t\t+-----------------------------------------+";
					cout << "\n\t\t\t\t\t|            Delete "<<setw(2)<<count_contacts<<" contacts?          |";                            
					cout << "\n\t\t\t\t\t|   Yes, Delete it(Y)   |    No(N)        |";
					cout << "\n\t\t\t\t\t-------------------------------------------"<<endl;
					cin >> conf;
						
					if(conf == 'y' or conf == 'Y')
                    {
                        ifstream file("number.txt");
				    	ofstream bin("Recycle bin.txt",ios::app);
					    while (file >> first_name >> last_name >> phone_num)
                        {
					    	bin << first_name << " " << last_name << "\t" << phone_num <<endl;
						}
                        file.close();
                        bin.close();
						f.close();
						phone.close();
						
						int res_rem = remove("number.txt"); 
                        ofstream obj("number.txt");
                        obj.close();
						if (res_rem==0)
                        {
							cout << "\n\n\t\t\t\t\tAll Contacts Deleted !";
                        }
                        else
                        {
                            cout << "\n\n\t\t\t\t\tError while removing number.txt";
                        }
					}
					else if(conf == 'n' or conf == 'N')
                    {
                        goto repeat_del_choice;	
                    }
                    else
                    {
                    	cout << "\n\t\t\t\t\tInvalid Choice..!!";
                        cout << "\n\t\t\t\t\tPress any key to CONTINUE..!!";
                        getch();
                        main();   
                    }		
				}
				else if(choice == "2")		//delete specific contact																		//DELETE SPECIFIC CONTACT
				{
					repeat_delete_specific:
					string d_keyword,d_first_name,d_last_name,d_phone_num;
                    char d_choose='0'; 
                    
                    system("cls");
                    cout<<"\n\tCANCEL (C)";
                    cout << "\n\n\n\n\n";
                    cout << "\n\t\t\t\t\t+-------------------------------------------------+";
                    cout << "\n\t\t\t\t\t|       Enter First Name/Last Name/Phone No.       |";
                    cout << "\n\t\t\t\t\t+-------------------------------------------------+";
                    cout << "\n\t\t\t\t\t		  ";
                    cin >> d_keyword;
                    cancel(d_keyword);
                    					
					ifstream out("number.txt");
					ofstream in("temper.txt");
					ofstream bin("Recycle bin.txt",ios::app);
				
					while(out >> first_name >> last_name >> phone_num)
					{
						if(d_keyword==first_name or d_keyword==last_name or d_keyword==phone_num)
						{
							repeat_choice:
							system("cls");
							cout << "\n\n\n\n\n";
							cout << "\n\t\t\t\t\t-------------------------------------------";
							cout << "\n\t\t\t\t\t|                Confirm                  |";
							cout << "\n\t\t\t\t\t+-----------------------------------------+";
							cout << "\n\t\t\t\t\t\tDo you want to delete this?";
							cout << "\n\t\t\t\t\t\tName: " << first_name;
							cout << "\n\t\t\t\t\t\tLast name: " << last_name;
							cout << "\n\t\t\t\t\t\tPhone Number: " << phone_num;
							cout << "\n\t\t\t\t\t+-----------------------------------------+"; 
							cout << "\n\t\t\t\t\t\t    Yes(Y) | No(N) : ";
							cout << "\n\t\t\t\t\t-------------------------------------------";
							cout << "\n\t\t\t\t\t";
							d_first_name = first_name;
                            d_last_name = last_name;
                            d_phone_num = phone_num;
                            cin >> d_choose;
						}
						else
						{
							in << first_name << "\t" << last_name << "\t" << phone_num <<endl;
						}
					}
					if(d_choose=='Y' or d_choose=='y')
					{
                        bin << d_first_name <<"\t"<< d_last_name << "\t" << d_phone_num <<endl;
						
						bin.close();
						f.close();
						out.close();
						in.close();
						phone.close();
						
						int res_rem = remove("number.txt");
						int res_ren = rename("temper.txt","number.txt");

						if(res_rem == 0)
						{
							if(res_ren == 0)
							{
								cout << "\n\t\t\t\t\tContact removed successfully!";
							}
							else
							{
								cout << "\n\t\t\t\t\tError while renaming";
							}
						}
						else
						{
							cout << "\n\t\t\t\t\tError while removing number.txt";
						}
					}
					else if(d_choose=='N' or d_choose=='n')
					{
						goto repeat_delete_specific;
					}
					else if(d_choose=='0')
					{
						cout << "No contacts match your search !";
					}
					else
					{
						cout << "Invalid choice!!";
						goto repeat_choice;
					}						
				}
            else
            {
                cout << "\n\t\t\t\t\tInvalid Choice..!";
				cout<<"\n\tPress ENTER to CONTINUE..\n";
				getch();
				goto repeat_del_choice;   
            }		
        }
	}
    else
    {
        cout << "\n\n\t\t\t\t\tError while opening file!";
    }
}

/*********************************/
/*********************************/
/*                                         OTHER FUNCTIONS                                         */
/*********************************/
/*********************************/

bool check_digits(string x)
{
    if(x.length() == 10)
    return true;
    else
    return false;
}

//------------------------------------------------------------------------------------------

bool check_numbers(string x)
{
    bool check = true;

    for(int i=0; i < x.length(); i++)
    {
        if(!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }

    if(check == true)
    return true;
    if(check == false)
    return false;
}

//------------------------------------------------------------------------------------------

void recycleBin()
{
    string r_first_name , r_last_name , r_phone_num , r_choice;

	ifstream bin("Recycle bin.txt",ios::ate);
	if(bin.is_open())
    {
        if(bin.tellg() == 0)
        {
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\n\t\t\t\t\t-------------------------------------------";
			cout << "\n\t\t\t\t\t|             File is empty!!             |";
            cout << "\n\t\t\t\t\t-------------------------------------------";
        	Sleep(1000);
           	main();
        }
        else
        {
			system("cls");
            bin.seekg(ios::beg);
            cout << "\n\n";
            cout << "\n\t\t\t\t\t-------------------------------------";
            cout << "\n\t\t\t\t\t|          DELETED  RECORD          |";
            cout << "\n\t\t\t\t\t-------------------------------------";

            while(bin >> r_first_name >> r_last_name >> r_phone_num)
            {
                cout << "\n\t\t\t\t\t" << r_first_name << " " << r_last_name << "\t" << r_phone_num;
            }
    		bin.close();
        	cout << "\n\n\n\n\n";
            cout << "\n\tCANCEL (C)";
            cout << "\n\t\t\t\t\t--------------------------------------";
        	cout << "\n\t\t\t\t\t|   Delete all record permanently    |";
			cout << "\n\t\t\t\t\t--------------------------------------";
        	cout << "\n\t\t\t\t\t|  [1] Yes,Delete it for sure (Y)    |";
        	cout << "\n\t\t\t\t\t|  [2] No,Continue to HOME. (N)      |";
        	cout << "\n\t\t\t\t\t--------------------------------------";
            cout << "\n\t\t\t\t\tEnter Your Choice: ";
			string choice;
			cin >> choice;
    		cancel(choice);	
			binDel(choice);
		}
	getch();
	main();
	}
	else
	{
		cout << "Error opening File!";
	}
}

//------------------------------------------------------------------------------------------

void binDel(string choice)
{
    if (choice == "Y" or choice == "y")
	{
		int res_rem = remove("Recycle bin.txt");
		
		if(res_rem == 0)
		{
				cout << "\n\t\t\t\t\tAll Contacts removed permanently..!!";
		}
		else
		{
			cout << "\n\t\t\t\t\tError while removing contacts";
		}
	}
	else if(choice == "N" or choice == "n") 
	{
		main();
	}
	else 
	{
		cout << "\n\t\t\t\t\tInvalid choice.. Select a Valid option..!!";
		cout << "\n\t\t\t\t\tPress any key to CONTINUE..!!";
        getch();
        main();
	}
}

//------------------------------------------------------------------------------------------

bool chDup(string k)
{
	ifstream myfile("number.txt");
	while(myfile >> first_name >> last_name >> phone_num)
	    {
	        if(k == phone_num)
	            return false;
	   	}
}

//------------------------------------------------------------------------------------------

void cancel(string cncl)
{
    if(cncl=="c" or cncl=="C")
    {
        main();
    }
}

//------------------------------------------------------------------------------------------



void recents()
{
	ifstream rec("recents.txt", ios :: ate);
	if(rec.tellg() == 0)
    {
        system("cls");
        cout << "\n\n\n\n\n\t\t\t\t\t-------------------------------------------";
		cout << "\n\t\t\t\t\t|             File is empty!!             |";
        cout << "\n\t\t\t\t\t-------------------------------------------";
    }
	else{
		system("cls");
		cout << "\n\n\n\n\n\n";
		cout << "\n\t\t\t\t\t-----------------------------------------";
		cout << "\n\t\t\t\t\t|      Recents Contact Details          |";
		cout << "\n\t\t\t\t\t-----------------------------------------";
		if(rec.is_open()){
            rec.seekg(ios::beg);
			while(rec >> first_name >> last_name >> phone_num )
            {
				cout << "\n\t\t\t\t\t      \tName   :   "<< first_name<<" "<<last_name<<"\t\t";
			    cout << "\n\t\t\t\t\t      \tPhone Number : "<< phone_num << "\t";
				cout << "\n\t\t\t\t\t---------------------------------------";
			}
		}
		else
	    {
	        cout << "Error opening File!";
	    }
	    rec.close();
	    cout << "\n\n\n\n\n\t\t\tPress any KEY to return HOME...\n";
	    getch();
	}  
}
