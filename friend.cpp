#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Chai {

private:
	string Teaname;
	int servings;

public:
	Chai(string name, int serve) {
Teaname:
		name;
servings:
		serve;
	}

	friend bool compair(const Chai &chai1, const Chai &chai2);


	void display() const {
		cout << "tea name: "<< Teaname<<endl;
	}
};


bool compair(const Chai &chai1, const Chai &chai2) {
	return chai1.servings > chai2.servings;
}



int main()
{
	Chai masalaChai("masala Chai", 44);
	Chai gingerChai("ginger Chai", 9);

	masalaChai.display();
	gingerChai.display();

	if(compair(masalaChai, gingerChai)) {
		cout << "masala chai have more servings" << endl;
	}
	else {
		cout << "masalaChai have less' servings" << endl;
	}



	// return 0;
}