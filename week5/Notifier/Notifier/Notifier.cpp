#include <algorithm>
#include <functional>
#include <cmath>
#include <limits>
#include <cfloat>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef int64_t I64;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

void SendSms(const string& number, const string& message) {
	cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
	cout << "Send '" << message << "' to e-mail " << email << endl;
}

class INotifier {
public:
	virtual void Notify(const string& message) const = 0;
};

class SmsNotifier : public INotifier {
public:
	SmsNotifier(const string& phone)
		: phone_(phone)
	{}

	void Notify(const string& message) const override {
		SendSms(phone_, message);
	}

private:
	string phone_;
};

class EmailNotifier : public INotifier {
public:
	EmailNotifier(const string& email)
		: email_(email)
	{}

	void Notify(const string& message) const override {
		SendEmail(email_, message);
	}

private:
	string email_;
};

void Notify(INotifier& notifier, const string& message) {
	notifier.Notify(message);
}


int main() {
	SmsNotifier sms{ "+7-495-777-77-77" };
	EmailNotifier email{ "na-derevnyu@dedushke.ru" };

	Notify(sms, "I have White belt in C++");
	Notify(email, "And want a Yellow one");
	return 0;
}
