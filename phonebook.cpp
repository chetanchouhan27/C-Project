// Phonebook project made by Yash Karil & Chetan Chouhan

#include <iostream>
#include <conio.h>
#include <string>
using namespace std; 

//prototypes
void printline(char, int);
bool name_valid(string);
bool mob_valid(string);

class contact
{
    string name;
    string mob;     
     public:
    	//Initialize the contact by a default value
        contact(): name(""), mob("")
        {}
        
        // Shows all contacts
        bool show()
        {
            if(name != "")
            {
            	cout<<"\t";
                cout << name << "\t" << mob << endl;
                return 1; //Indicates success
            }
            else
                return 0; //Indicates failure
        }
        
        //Search
        bool show(string search_term)
        {
            if(search_term == name)
            {
            	cout<<"\t";
                cout << name << "\t" << mob << endl;
                return 1;
            }
            else
                return 0;
        }
        
        //Checks whether the name exists or not
        bool name_exists(string tname)
        {
            if(tname == name)
                return 1;
            else
                return 0;
        }
        
        //The contact object is initialized by valid values
        bool add(string new_name, string new_mob)
        {
            if(name=="")
            {
                name = new_name;
                mob = new_mob;
                return 1; // Success
            }
            else
                return 0; // Failure
    
        }
        
        //Edits the contact details
        bool edit(string);
        
        //Sets the contact details to default values
        //That is, the contact details are thus erased
        bool erase(string new_name)
        {
            if(new_name==name)
            {       
                name = "";
                mob = "";
                return 1;
            }
            else
                return 0;
        }
};


//Edits the contact
bool contact :: edit(string new_name)
{
    string new_mob;
    if(new_name==name)
    {
        cout << "\tEnter new name: "; cin >> new_name;
        cout << "\tEnter new mobile no: "; cin >> new_mob;
        
        name = new_name;
        mob = new_mob;
        return 1;
    }
    else
        return 0;
}



int main()
{
    contact person[100];
            
    string temp_name, temp_mob;
    int choice, i, counter;
    bool flag;
    bool cancel_flag;
        //cout<<"\t\t";
        printline('-', 50);
        //cout<<"\t\t";
        printline('-', 50);
        //cout<<"\t\t";
    cout <<"\n\n\t*** PHONEBOOK MANAGAMENT SYSTEM ***" << endl;
    
    do
    {   
        cout << "\n\n\n";
        //cout<<"\t\t";
        printline('-', 50);
       // cout<<"\t\t";
        printline('-', 50);
        //cout<<"\t\t";
        cout << "\n\t0. Show contacts" << endl
        << "\t1. Add Contact" << endl
        << "\t2. Edit Contact" << endl
        << "\t3. Delete Contact" << endl
        << "\t4. Search" << endl
        << "\t5. Quit" << endl << endl
        << "\tYour choice... ";
        cin >> choice;
        
        system("cls");
       //cout<<"\t\t";
       printline('-', 50);
       //cout<<"\t\t";
        cancel_flag = 0;
        flag = 0;
        counter = 0;
        
        switch(choice)
        {
            case 0: 
                cout << "\tShowing Contacts" << endl;
                //cout<<"\t\t";
                printline('-', 50);
                //cout<<"\t\t";
                cout<<"\tNAME\tCONTACT";
                for(i=0; i<100; i++)
                    if(person[i].show())
                        flag = 1;
                
                if(!flag)
                    cout << "\tNo contacts found!" << endl;
                break;
                
            case 1:
                cout << "\tAdd New Contact\t\tpress $ to cancel" << endl;
                //cout<<"\t\t";
                printline('-', 50);
                //cout<<"\t\t";
                counter = 0;
                
                //Loop until correct name and mobile number are entered
                do
                {
                    flag = 0;
                    if(counter)
                        cout << "\t\tTry again\t\t\t\tpress $ to cancel" 
						<< endl;
						
                    //counts how many times the do-while loop executes
					counter++; 
                        
                    cout << "\tEnter Name: "; cin >> temp_name;
                    
                    //Cancel operation
                    if(temp_name=="$")
                    {
                        cancel_flag = 1;
                        break;
                    }
                    cout << "\tEnter Mobile No.: "; cin >> temp_mob;
                    
                    //Cancel operation
                    if(temp_mob=="$")
                    {
                        cancel_flag = 1;
                        break;
                    }
                    
                    //Check whether name exists
                    for(i=0; i<100; i++)
                        if(person[i].name_exists(temp_name))
                        {
                            cout << "\tThe name you entered is already there" 
							"in the phonebook, enter a different name." 
							<< endl;
                            flag = 1;
                            break;
                        }
                    
                }while(!name_valid(temp_name) || 
								flag ||
						!mob_valid(temp_mob));
                
                if(cancel_flag)
                {
                    system("cls");
                    break;
                }
            
                
                //This code adds the contact to phonebook    
                for(i=0; i<100; i++)
                    if(person[i].add(temp_name, temp_mob))
                    {
                        cout << "\tContact added successfully!" << endl;
                        flag = 1;
                        break;
                    }
                
                if(!flag)
                    cout << "\tMemory full! Delete some contacts first." 
					<< endl;
                break;
                
            case 2:
                cout << "\tEnter a contact name to edit or press $ to cancel\n";
                cout<<"\tName=";
				cin >> temp_name;
                
                //Cancel Operation
                if(temp_name=="$")
                {
                    system("cls");
                    break;
                }
                
                for(i=0; i<100; i++)
                    if(person[i].edit(temp_name))
                    {
                        cout << "\tEdited Successfully!" << endl;
                        flag = 1;
                        break;
                    }
                
                if(!flag)
                    cout << "\tContact name not found!" << endl;
                break;
                
            case 3:
                do
                {
                    if(counter)
                        cout << "\tTry again" << endl;
                    counter++;
                    cout << "\tEnter a contact name to delete or press $ to cancel\n";
					cout<<"\tName = ";
					cin >> temp_name;
                
                    //Cancel Operation
                    if(temp_name=="$")
                    {
                        system("cls");
                        break;
                    }
                
                
                    //Final Confirmation
                    for(i=0; i<100; i++)
                    if(person[i].name_exists(temp_name))
                    {
                        flag = 1;
                        cout << "\tAre you sure you want to delete? (1/0)" 
						<< endl;
                        int yes;
                        cin >> yes;
                        if(!yes)
                        {
                            system("cls");
                            cancel_flag = 1;
                        }
                        break;
                    }
                
                    if(!flag)
                        cout << "\tContact name not found!" << endl;
                    
                    if(cancel_flag)
                        break;
                
                    // This code deletes the contact
                    if(flag)
                    {
                        for(i=0; i<100; i++)
                            if(person[i].erase(temp_name))
                            {
                                cout << "\tDeleted successfully!" << endl;
                                break;
                            }
                    }
                    
                }while(!flag);
                break;
                
            case 4:
                do
                {
                    if(counter)
                        cout << "\tTry again" << endl;
                    counter++;
                    cout << "\tSearch a name or press $ to cancel\n";
                    cout<<"\tName = ";
					 cin >> temp_name;
                
                    //Cancel Operation
                    if(temp_name=="$")
                    {
                        system("cls");
                        break;
                    }
                
                    for(i=0; i<100; i++)
                        if(person[i].show(temp_name))
                        {
                            flag = 1;
                            break;
                        }
    
                    if(!flag)
                        cout << "\tContact name not found" << endl;
                }while(!flag);
                    
                break;
                
            case 5:
                return 0;
                break;
            
        }
    } while(1);
    
    getch();
    return 0;
}

//prints a line
void printline(char ch, int size)
{
    for(int i=0; i<size; i++)
        cout << ch;
    cout << "\n";
}


//Contact name validation
bool name_valid(string tname)
{
    
    if(tname.size()>20)
    {
        cout << "\tInvalid Name!\n\tEnter a name within 20 characters!" 
		<< endl;
        return 0;
    }
    else if(tname == "")
    {
        cout << "\tInvalid Name!\nName cannot be blank!" << endl;
        return 0;
    }
    else
        return 1;
}

//mobile number validation
bool mob_valid(string tmob)
{
    if(tmob.size()>13 || tmob.size()<10)
    {
        cout << "\tInvalid mobile no.\n\tEnter a no." 
		"between 10 and 13 digits" << endl;
        return 0;
    }
    else if(tmob == "")
    {
        cout << "\tInvalid mobile no.\n\tMobile" 
		"no cannot be blank" << endl;
        return 0;
    }
    else
        return 1;
}
