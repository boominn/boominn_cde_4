#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Course{
	
	private:
		// exam notes
		int hmG;
		int mtG;
		int finG;
		// weights
		double mtW;
		double hmW;
		double finW;
		
		string name;
		string letterGrade;	
	public:
		
		Course();
		Course(double, double, double);
		//setters
		void set_name(string);
		void set_hmG(int);
		void set_finG(int);
		void set_mtG(int);
		//getters
		int get_hmG();
		int get_mtG();
		int get_finG();
		string get_name();
		string get_letterGrade();
		//methods
		void calculate();
		
};

// contructors
Course::Course():Course(0.3, 0.2 , 0.5){
	
}

Course::Course(double mtW, double hmW, double finW):mtW{mtW}, hmW{hmW}, finW{finW}{
	
}

// Setters

void Course::set_mtG(int mtG){ this->mtG = mtG; }

void Course::set_hmG(int hmG){ this->hmG = hmG; }

void Course::set_finG(int finG){ this->finG = finG; }

void Course::set_name(string name){ this->name = name; }

// getters

int Course::get_mtG(){ return this->mtG; }

int Course::get_hmG(){ return this->hmG; }

int Course::get_finG() { return this->finG; }

string Course::get_name() { return this->name; }

string Course::get_letterGrade(){
	return this->letterGrade;
}

//methods

void Course::calculate(){
	
	double sum = hmG * hmW + mtG * mtW + finG * finW;
	
	
	if(sum >= 90.0)
	{
		this->letterGrade = "AA";
	}
	else if(sum >= 85.0)
	{
		this->letterGrade = "BA";
	}
	else if(sum >= 80.0)
	{
		this->letterGrade = "BB";
	}
	else if(sum >= 70.0)
	{
		this->letterGrade = "CB";	
	}
	else if(sum >= 60.0)
	{
		this->letterGrade = "CC";
	}
	else if(sum >= 50.0)
	{
		this->letterGrade = "DC";
	}
	else if(sum >= 45.0)
	{
		this->letterGrade = "DD";
	}
	else if(sum >= 35.0)
	{
		this->letterGrade = "FD";
	}
	else
		this->letterGrade = "FF";
		
}

int main(){
	
	Course course1;
	
	double mtW, hmW, finW;
	string name;
	int hmG,mtG,finG;
	
	cout << "Enter weights for second course: ";
	cin >> mtW >> hmW >> finW;
	Course course2(mtW, hmW, finW);
	
	cout << "Enter first course name: ";
	cin >> name;
	course1.set_name(name);
	
	cout << "Enter first course grades: ";
	cin >> hmG >> mtG >> finG;
	course1.set_finG(finG);
	course1.set_hmG(hmG);
	course1.set_mtG(mtG);
	
	
	cout << "Enter second course name: ";
	cin >> name;
	course2.set_name(name);
	
	cout << "Enter second course grades: ";
	cin >> hmG >> mtG >> finG;
	course2.set_finG(finG);
	course2.set_hmG(hmG);
	course2.set_mtG(mtG);
	
	//calculate
	course1.calculate();
	course2.calculate();
	
	cout << setw(10) << left << "Course" 
		<< setw(10) << left << "Midterm" 
		<< setw(10) << left << "Homework" 
		<< setw(10) << left << "Final" 
		<< setw(10) << left << "Letter" << endl;
	//course1 info
	cout << setw(10) << left << course1.get_name()
		<< setw(10) << left << course1.get_mtG() 
		<< setw(10) << left << course1.get_hmG() 
		<< setw(10) << left << course1.get_finG() 
		<< setw(10) << left << course1.get_letterGrade() << endl;
	//course2 info
		cout << setw(10) << left << course2.get_name()
		<< setw(10) << left << course2.get_mtG() 
		<< setw(10) << left << course2.get_hmG() 
		<< setw(10) << left << course2.get_finG() 
		<< setw(10) << left << course2.get_letterGrade() << endl;
		
	return 0;
}