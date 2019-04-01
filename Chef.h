#include "Employee.h"

#ifndef CHEF
#define CHEF

class Chef : public Employee{
	public:
		//default constructor
		Chef(string inName = "", long inID = 0, char inType = ' ', float inSalary = 0, float inProfit = 0, string inSpec = "");

		//display function
		virtual void display(ostream& out) const;

		//salary calculator function
		float calcsal(float base, float prof);


	private:
		//data members
		float profit; //total restaurant profit
		string spec;
		float netSalary; //net monthly salary after accounting for profits
};


//inline constructor definition
inline Chef::Chef(string inName, long inID, char inType, float inSalary, float inProfit, string inSpec)
	:Employee(inName, inID, inType, inSalary), profit(inProfit), spec(inSpec), netSalary(calcsal(inSalary, inProfit)){}

//inline display function definition
inline void Chef::display(ostream& out) const{
	Employee::display(out);
	out << "Net salary: $" << netSalary << endl
			<< "Culinary specialty: " << spec << endl << endl;
}

//inline salary calculator definition
inline float Chef::calcsal(float base, float prof){
	float netsal;
	//if total profit is negative, a chef is paid his base salary only

	if (prof > 0){
		netsal = base + prof*.2;
	}
	else{
		netsal = base;
	}
	return netsal;
}

#endif
