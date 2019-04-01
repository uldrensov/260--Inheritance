#include <iostream>
using namespace std;

#include "Employee.h"
#include "Manager.h"
#include "Chef.h"
#include "Waiter.h"

int main(){
	int totalprofit, tip1, tip2, tip3;
	cout << "Input total monthly profit:" << endl;
	cin >> totalprofit;
	cout << "Input three tips for each waiter:" << endl;
	cin >> tip1;
	cin >> tip2;
	cin >> tip3;

	Employee* ptr[6];
	ptr[0] = new Manager("Hashirama Senju", 89787, 'O', 15000, totalprofit);
	ptr[1] = new Chef("Hiruzen Sarutobi", 78346, 'C', 10000, totalprofit, "Vietnamese");
	ptr[2] = new Chef("Minato Namikaze", 93464, 'C', 10000, totalprofit, "Mongolian");
	ptr[3] = new Waiter("Obito Uchiha", 39821, 'W', 3000, tip1, 5);
	ptr[4] = new Waiter("Rin Nohara", 63992, 'W', 3000, tip2, 2);
	ptr[5] = new Waiter("Kakashi Hatake", 48392, 'W', 3000, tip3, 4);

	cout << "Displaying all employee data:" << endl << endl << endl;

	for (int i=0; i<6; i++){
		cout << *ptr[i];
	}
	cout << endl << "End of simulation." << endl;
}
