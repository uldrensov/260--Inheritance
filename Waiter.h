#include "Employee.h"

#ifndef WAITER
#define WAITER

class Waiter : public Employee{
	public:
		//default constructor
		Waiter(string inName = "", long inID = 0, char inType = ' ', float inSalary = 0, float inTips = 0, int inServ = 0);

		//display function
		virtual void display(ostream& out) const;

		//salary calculator function
		float calcsal(float base, float extra);


	private:
		//data members
		float tips;
		int serv;
		float netSalary; //net monthly salary after accounting for tips
};


//inline constructor definition
inline Waiter::Waiter(string inName, long inID, char inType, float inSalary, float inTips, int inServ)
	:Employee(inName, inID, inType, inSalary), tips(inTips), serv(inServ), netSalary(calcsal(inSalary, inTips)){}

//inline display function definition
inline void Waiter::display(ostream& out) const{
	Employee::display(out);
	out  << "Net salary: $" << netSalary << endl
			<< "Years of service: " << serv << endl << endl;
}

//inline salary calculator definition
inline float Waiter::calcsal(float base, float extra){
	float netsal = base + extra;
	return netsal;
}

#endif
