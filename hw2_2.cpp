#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Contact{
	
	private:
		
		string name;
		string number;
		
	public:
		Contact();
		Contact(string, string);
		void print(string);
		
		//setters
		void set_name(string);
		void set_number(string);
		
		//getter
		string get_name();
		string get_number();
		
};

//constructors

Contact::Contact():Contact("Unknown", "0"){
	
}

Contact::Contact(string name, string number): name{name},number{number}{

}

//setters

void Contact::set_name(string name){ this->name = name; }

void Contact::set_number(string number){ this->number = number; }

//getters

string Contact::get_name(){
	return this->name;
}

string Contact::get_number(){
	return this->number;
}

//methods

void Contact::print(string word){
	
	
	if(word == "light")
	{
	 cout << setw(20) << left << this->name
	 	<< setw(20) << left << this->number << endl;		
	}
	else
	{
		cout << "Name :" << this->name << endl;
		cout << "Number :" << this->number << endl;
	}
}


class AdressBook{
	
	private:
		
		vector <Contact> contacts;
		int nrofcontacts;
		//methods
		int search(string);
	public:
		
		AdressBook();
		bool add(Contact);
		bool remove(string);
		void print();
		
};

//private methods

int AdressBook::search(string name){
	
	for(int i{0}; i < this->nrofcontacts; i++){
		if(name == this->contacts[i].get_name())
			return i;
	}
	return -1;
}

// constructors

AdressBook::AdressBook(): nrofcontacts{0}{
	
}

// methods

bool AdressBook::add(Contact contact){
	
	if(search(contact.get_name()) == -1)
	{
		this->contacts.push_back(contact);
		this->nrofcontacts++;
					
		return true;
	}
		
	
	return false;
}

bool AdressBook::remove(string name){
	
	int k = search(name);
	if(k != -1)
	{
		this->contacts.erase( this->contacts.begin() + k);
		this->nrofcontacts--;	
		return true;
	}
		
	
	return false;
}

void AdressBook::print(){
	
	if(this->nrofcontacts > 0)
	{
		cout << setw(20) << left << "Name" 
			<< setw(20) << left << "Number" << endl;
		for(int i{0}; i < this->nrofcontacts; i++){
			
			this->contacts[i].print("light");
		}
	}
	else
	{
		cout << "There is no contacts in book." << endl;
	}
}

int main(){
	
	int choice;
	
	AdressBook adressBook;
	
	do{
		cout << "1. Display Adress Book" << endl;
		cout << "2. Add new contact" << endl;
		cout << "3. Remove a contact" << endl;
		cout << "4. Exit" << endl;
		
		cout << "Enter your choice: ";
		cin >> choice;
		
		if(choice == 1)
		{
			adressBook.print();
		}
		else if(choice == 2)
		{
			string name,number;
			Contact contact;
			cout << "Enter a name: ";
			cin >> name;
			cout << "Enter a number: ";
			cin >> number;
			
			contact.set_name(name);
			contact.set_number(number);
			if(adressBook.add(contact))
			{
				cout << "Successfully added!" << endl;
			}
			else
			{
				cout << "The person is already exist!" << endl;
			}	
		}
		else if( choice == 3)
		{
			string name,number;
			cout << "Enter a name: ";
			cin >> name;
			if(adressBook.remove(name))
			{
				cout << "Person is removed!" << endl;
			}
			else
			{
				cout << "There is no such person!" << endl;
			}
		}
		
		
	}while(choice != 4);
	cout << "Bye !!!" ;
		
	return 0;
}