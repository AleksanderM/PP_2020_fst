#include <string>
#include "Rectangle.h"

struct Data
{
	std::string id1;
	std::string id2;

	Data() 
	{
		id1 = "";
		id2 = "";
	}

	void print(void)
	{
		std::cout << "id1: " << id1 << "\t id2: " << id2 << "\n";
	}

};

Data extractData(std::string input) {
	Data result;
	int i = 0;


	do {
		result.id1 += input[i];

		i += 1;
	} while (input[i] != ' ');

	i += 1;

	do {
		result.id2 += input[i];

		i += 1;
	} while (i < input.length());

	return result;
}

int findRectangle(Data data, Rectangle* arr, int length) 
{
	Rectangle id1;
			  
	Rectangle id2;

	int result;

	for (int i = 0; i < length; i++) {

		if (arr[i].getId().compare(data.id1) == 0) {
			id1 = arr[i];
		}
		if (arr[i].getId().compare(data.id2) == 0) {
			id2 = arr[i];
		}

	}

	result = id1.overlap(id2);

	return result;
}

int main()
{
	int n, m;

	std::cin >> n >> m;

	Rectangle* arr = new Rectangle[n];

	std::string id;
	int x, y;
	int heigth, width;


	for (int i = 0; i < n; i++) {

		std::cin >> id >> heigth >> width >> x >> y;
		arr[i] = Rectangle(id, x, y, heigth, width);

	}

	std::cout << " Input ids: " << "\n";

	std::string input;
	
	for (int i = 0; i < m; i++) 
	{
		std::cin.ignore();
		std::getline(std::cin, input);

		Data data = extractData(input);

		if (findRectangle(data, arr, n) == 1) 
		{
			std::cout << "true \n";
		}
		else
		{
			std::cout << "false\n";
		}
	}

}
