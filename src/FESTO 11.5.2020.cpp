#include "Car.h"

struct DriveData{
	std::string model = "";
	int distance = 0;

	void print(void) {
		std::cout << model << ", " << distance << "\n";
	}
};

DriveData extractData(std::string input)
{
	DriveData result;
	int i = 0;

	do {
		i += 1;
	} while (input[i] != ' ');
	i += 1;

	do {
		result.model += input[i];
		i += 1;
	} while (input[i] != ' ');

	i += 1;

	int zeros = 0; //how many zeros do we have
	int zerosTransformed = 1; //transformed to a number ready for multiplication

	do {
		zeros = (input.length() - i - 1);
		zerosTransformed = pow(10, zeros);

		result.distance += (input[i] - '0') * zerosTransformed;
		i += 1;
	} while (i < input.length());
	zeros = 0;
	zerosTransformed = 1;

	return result;
	
};

Car* findCar(Car* arr, int length, DriveData data) 
{

	Car* result = nullptr;

	for (int i = 0; i < length; i++) {
	
		if (arr[i].getModel().compare(data.model) == 0) {
			result = &arr[i];
			result->drive(data.distance);
		}
	
	}

	return result;
}

int main()
{
	int n;
	std::cin >> n;
	std::string model;
	double fuel, fuelConsuption;
	
	Car* arr = new Car[n];

	for (int i = 0; i < n; i++)
	{
		std::cout << "Input model\n";
		std::cin >> model;
		std::cout << "Input total fuel\n";
		std::cin >> fuel;
		std::cout << "Input fuelConsuption\n";
		std::cin >> fuelConsuption;

		Car temp(model, fuel, fuelConsuption);

		arr[i] = temp;

	}
	
	std::cin.ignore();
	std::string input;
	while (true)
	{
		std::getline(std::cin, input);
		if (input == "End") 
		{
			break;
		}
		
		DriveData data = extractData(input);

		findCar(arr, n ,data);
	}

	for (int i = 0; i < n; i++) {
		arr[i].printData();
	}

	delete[] arr;
}