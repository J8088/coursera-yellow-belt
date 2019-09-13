#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
	Human(const string& name, const string& profession)
		: Name(name)
		, Profession(profession)
	{
	}

	void DoAction(const string& action) const {
		cout << Profession << ": " << Name << " " << action << endl;
	}

	virtual void Walk(const string& destination) const {
		DoAction("walks to: " + destination);
	}

	void VisitPlaces(const vector<string>& places) const {
		for (const auto& p : places) {
			Walk(p);
		}
	}

	const string Name = "";
	const string Profession = "";
};

class Student : public Human {
public:
	Student(const string& name, const string& favouriteSong)
		: Human(name, "Student")
		, FavouriteSong(favouriteSong)
	{
	}

	void Walk(const string& destination) const override {
		Human::Walk(destination);
		SingSong();
	}

	void Learn() const {
		DoAction("learns");
	}

	void SingSong() const {
		DoAction("sings a song: " + FavouriteSong);
	}

	const string FavouriteSong = "";
};

class Teacher : public Human {
public:
	Teacher(const string& name, const string& subject)
		: Human(name, "Teacher")
		, Subject(subject)
	{
	}

	void Teach() const {
		DoAction("teaches: " + Subject);
	}

	const string Subject = "";
};

class Policeman : public Human {
public:
	Policeman(const string& name)
		: Human(name, "Policeman")
	{
	}

	void Check(const Human& other) const {
		DoAction("checks " + other.Profession + ". " + other.Profession + "'s name is: " + other.Name);
	}
};

int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	t.Teach();
	t.VisitPlaces({ "Moscow", "London" });
	p.Check(s);
	s.VisitPlaces({ "Moscow", "London" });
	s.Learn();
	return 0;
}
