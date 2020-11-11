#include <iostream>
#include <vector>
#include <algorithm>
#include "Team.h"

bool isNumberValueValid(const std::string& n_str, std::string n_stat)
{
	bool is_digit = n_str.find_first_not_of("0123456789") == std::string::npos;
	bool is_inRange = false;
	int t_Integer = 0;

	if (is_digit) 
	{
		t_Integer = std::stoi(n_str);
	}

	if (t_Integer <= 101 && t_Integer >= 0) 
	{
		is_inRange = true;
	}
	else 
	{
		std::cout << n_stat <<" should be between 0 and 100.\n";
	}

	return (is_digit && is_inRange);
}

bool isStringValueValid(const std::string& n_str)
{
	for (int i = 0; i < n_str.length(); i++)
	{
		if (n_str[i] == ' ') 
		{
			std::cout << "A name should not be empty. \n";
			return false;
		}
	}
	if (n_str.compare("null") == 0 || n_str.compare("empty") == 0)
	{
		std::cout << "A name should not be empty. \n";
		return false;
	}

	return true;
}

std::string analyzeInput (std::string input, std::vector<Team>& n_teams)
{
	std::string result = "";
	std::string teamName = "";
	int i = 0;

	//retrieving the command from the string
	do {
		result += input[i];
		i += 1;
	} while (input[i] != ';' && i < input.length());

	i += 1;


	//Depending on the command calls the function for it 
	if (result.compare("Team") == 0)
		{
			//team;
			bool t_flag = true;
			do {
				teamName += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (i < input.length() && t_flag == true);
			if (t_flag == true)
			{
				n_teams.push_back(Team(teamName));
			}
			else
			{
				std::cout << "Invalid Team Name! \n";
			}
		}
	else if (result.compare("Add") == 0)
		{
			//add;
			//t_ for temporary
			bool t_flag = true;
			int t_durability = 0;
			int t_sprint = 0;
			int t_dribble = 0;
			int t_passes = 0;
			int t_shooting = 0;
			std::string t_playerName = "";
			std::string t_strDurability = "";
			std::string t_strSprint = "";
			std::string t_strDribble = "";
			std::string t_strPasses = "";
			std::string t_strShooting = "";

			do {
				teamName += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (input[i] != ';' && t_flag == true);

			if (isStringValueValid(teamName))
			{
				//ok
			}
			else
			{
				t_flag = false;
			}


			i += 1;

			//extracting player name
			do {
				t_playerName += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (input[i] != ';' && t_flag == true);

			if (isStringValueValid(t_playerName))
			{
				//ok
			}
			else
			{
				t_flag = false;
			}

			i += 1;

			//extracting durability rating 		
			do {
				t_strDurability += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (input[i] != ';' && t_flag == true);

			if (isNumberValueValid(t_strDurability, "Durability")) 
			{
				//ok
			}
			else 
			{
				t_flag = false;
			}
			
			i += 1;

			//extracting sprint rating 		
			do {
				t_strSprint += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (input[i] != ';' && t_flag == true);

			if (isNumberValueValid(t_strSprint, "Sprint"))
			{
				//ok
			}
			else
			{
				t_flag = false;
			}

			i += 1;

			//extracting dribble rating 		
			do {
				t_strDribble += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (input[i] != ';' && t_flag == true);

			if (isNumberValueValid(t_strDribble, "Dribble"))
			{
				//ok
			}
			else
			{
				t_flag = false;
			}


			i += 1;

			//extracting passes rating 		
			do {
				t_strPasses += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (input[i] != ';' && t_flag == true);

			if (isNumberValueValid(t_strPasses, "Passes"))
			{
				//ok
			}
			else
			{
				t_flag = false;
			}

			i += 1;

			//extracting shooting rating 		
			do {
				t_strShooting += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (i < input.length() && t_flag == true);

			if (isNumberValueValid(t_strShooting, "Shooting"))
			{
				//ok
			}
			else
			{
				t_flag = false;
			}

			//
			if (t_flag) {
				t_durability = std::stoi(t_strDurability);
				t_sprint = std::stoi(t_strSprint);
				t_dribble = std::stoi(t_strDribble);
				t_passes = std::stoi(t_strPasses);
				t_shooting = std::stoi(t_strShooting);
			}
			else
			{
				std::cout << "Incorrect data! " << "\n";
			}

			//t_teamFound => remembers if team is found
			if (t_flag)
			{
				bool t_teamFound = false;
				for (auto& it : n_teams) {
					if (it.getName().compare(teamName) == 0)
					{
						Player temp(t_playerName, t_durability, t_sprint, t_dribble, t_passes, t_shooting);
						it.addPlayer(temp);

						t_teamFound = true;
					}
				}
				if (t_teamFound != true)
				{
					std::cout << "Team "<< teamName << " does not exists.\n";
				}
			}
		}
	else if (result.compare("Remove") == 0)
		{
			//remove;
			bool t_flag = true;
			std::string t_playerName = "";

			do {
				teamName += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (input[i] != ';' && t_flag == true);

			i += 1;

			//extracting player name
			do {
				t_playerName += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (i < input.length() && t_flag == true);

			//reusing t_flag
			t_flag = false;
			for (auto& it : n_teams) {
				if (it.getName().compare(teamName) == 0)
				{
					it.removePlayer(t_playerName);

					t_flag = true;
				}
			}
			if (t_flag != true)
			{
				std::cout << "Invalid Team Name! \n";
			}

		}
	else if (result.compare("Rating") == 0)
		{
			//rating;
			bool t_flag = true;
			do {
				teamName += input[i];
				if (input[i] == ' ')
				{
					t_flag = false;
				}
				i += 1;
			} while (i < input.length() && t_flag == true);

			//reusing variable t_flag
			t_flag = true;
			for (auto& it : n_teams) {
				if (it.getName().compare(teamName) == 0)
				{
					uint8_t temp_rating = it.getRating();
					std::cout << teamName << " - " << (int)temp_rating << "\n";
					t_flag = false;
				}

			}
			if (t_flag)
			{
				std::cout << "Team " << teamName << " does not exists.\n";
			}
		}
	else
		{
			std::cout << "Unidentified command!\n";
		}
	
	return result;
}

int main()
{
	std::string input;

	std::vector<Team> teams;


	//input
	do {
		std::getline(std::cin, input);
			if (input.compare("END") == 0)
				break;
		analyzeInput(input, teams);
	} while (true);
}