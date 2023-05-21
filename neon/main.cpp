#include<iostream>
#include<fstream>
#include<string>
#include<list>
using namespace std;

void main()
{
	ofstream fout("wyniki4.txt");
	ifstream fin("instrukcje.txt");
	if (fin.is_open())
	{
		string result;
		string command;
		char letter;

		int counter = 0;

		//list<string> sequence;
		int max_length = 0, count_in_current_sequence = 1;
		string max_command, prev_command;
		while (!fin.eof())//eof - end of file
		{
			counter++;
			command.clear();
			fin >> command >> letter;
			/*sequence.push_front(command);
			if (sequence.size() > 1)
			{
				//list<string>::iterator it = sequence.begin();
				//it++;
				if (sequence.front() == sequence.back())
				{
					if (sequence.size()>=max_length)
					{
						max_length = sequence.size();
						max_command = command;
					}
				}
				else
				{
					sequence.clear();
					sequence.push_front(command);
				}
			}*/

			if (command == prev_command)
			{
				count_in_current_sequence++;
				if (count_in_current_sequence >= max_length)
				{
					max_length = count_in_current_sequence;
					max_command = command;
				}
			}
			else
			{
				count_in_current_sequence = 1;
				prev_command = command;
			}

			if (command == "DOPISZ")
			{
				result.push_back(letter);
			}
			else if (command == "ZMIEN")
			{
				result.back() = letter;
			}
			else if (command == "USUN")
			{
				result.pop_back();
			}
			else if (command == "PRZESUN")
			{
				size_t position = result.find(letter);

				if (position < result.size())result[position] = letter + 1;
			}
		}
		fin.close();
		cout << result << endl;
		cout << result.size() << endl;
		cout << max_command << "\t" << max_length << endl;
	}
	else
	{
		cout << "File not found" << endl;
	}

	fout.close();
}