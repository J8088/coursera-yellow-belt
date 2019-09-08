#include "phone_number.h"

#include <iostream>

using namespace std;

int main() {
	try {
		PhoneNumber num("+7-495-hey");
		cout << num.GetInternationalNumber() << endl;
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}
