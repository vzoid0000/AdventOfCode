#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int part1(std::vector<std::string> lines, unsigned int lines_size);
int part2(std::vector<std::string> lines, unsigned int lines_size);

int main(int argc, char* argv[]) {

	if(argc != 2) {
		std::cout << "error: no input file specified\n";
		return -1;
	}
		
	std::ifstream input_file(argv[1]); 


	if(!input_file.is_open()) {
		std::cout << "error: could not open input_file\n";
		return -2;
	}

	
	std::vector<std::string> lines;
	std::string line { "" };
	unsigned int lines_size { 0 };

	while(std::getline(input_file, line)) {
		lines.push_back(line);
	}	

	lines_size = lines.size();

	std::cout << part1(lines, lines_size) << '\n';
	std::cout << part2(lines, lines_size) << '\n';




	return 0;
}


int part1(std::vector<std::string> lines, unsigned int lines_size) {

	int sum { 0 };

	for(int i = 0; i < lines_size; i++) {

		int first { 0 };
		int last { 0 };
		
		for(char c : lines[i]) {
			
			if(std::isdigit(c)) {

				if(first == 0)
					first = c - '0';
				else
					last = c - '0';

			}

		}

		if(last == 0)
			sum += first * 11;
		else
			sum += first * 10 + last;	

	}

	
	return sum;
}


int part2(std::vector<std::string> lines, unsigned int lines_size) {

	return 0;

}




