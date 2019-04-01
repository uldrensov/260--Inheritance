#include <iostream>

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee{
	public:
		//default constructor
		Employee(string inName = "", long inID = 0, char inType = ' ', float inSalary = 0);

		//display function
		virtual void display(ostream& out) const;


	private:
		//data members
		string name;
		long ID;
		char type;
		float salary; //base monthly wage
};


//inline constructor definition
inline Employee::Employee(string inName, long inID, char inType, float inSalary)
	:name(inName), ID(inID), type(inType), salary(inSalary){}

//inline display function definition
inline void Employee::display(ostream& out) const{
	out << "Name: " << name << endl
			<< "ID: " << ID << endl
			<< "Class: " << type << endl
			<< "Base salary: $" << salary << endl;
}

//inline output operator definition
inline ostream& operator<<(ostream& out, const Employee& in){
	in.display(out);
	return out;
}

#endif
