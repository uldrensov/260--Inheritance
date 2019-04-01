#include "Employee.h"

#ifndef MANAGER
#define MANAGER

class Manager : public Employee{
	public:
		//default constructor
		Manager(string inName = "", long inID = 0, char inType = ' ', float inSalary = 0, float inProfit = 0);

		//display function
		virtual void display(ostream& out) const;

		//salary calculator function
		float calcsal(float base, float prof);


	private:
		//data members
		float profit; //total restaurant profit
		float netSalary; //net monthly salary after accounting for profits
};


//inline constructor definition
inline Manager::Manager(string inName, long inID, char inType, float inSalary, float inProfit)
	:Employee(inName, inID, inType, inSalary), profit(inProfit), netSalary(calcsal(inSalary, inProfit)){}
		//Self note: Net salary is not an argument in the constructor call, but is calculated using other arguments

//inline display function definition
inline void Manager::display(ostream& out) const{
	Employee::display(out);
	out << "Net salary: $" << netSalary << endl << endl;
}

//inline salary calculator definition
inline float Manager::calcsal(float base, float prof){
	float netsal;
	//if total profit is negative, the owner alone takes the full loss

	if (prof > 0){
		netsal = base + prof*.6;
	}
	else{
		netsal = base + prof;
	}
	return netsal;
}

#endif
