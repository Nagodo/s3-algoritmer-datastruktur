#include <iostream>
#include <map>

bool is_split(char c);

std::string get_most_word(std::string input) {
	std::map<std::string, int> map;

	std::string currentMaxWord;
	int amount;

	std::string newWord = "";

	for (int i = 0; i < input.length(); i++) {
		char* c = &input[i];
		if (is_split(*c)) {
			if (newWord != "") {
				map[newWord]++;

				if (map[newWord] > amount) {
					amount = map[newWord];
					currentMaxWord = newWord;
				}
			}
			newWord = "";
            
			continue;
		}

		newWord += *c;		
	}

	return currentMaxWord;
}

std::string to_lower(std::string input) {
	std::string out = "";
	for (int i = 0; i < input.length(); i++) {
		if (input[i] < 61) { // Is not lower
			out += input[i] - 32;
		}
	}

	return out;
}

bool is_split(char c) {
  return c == ',' || c == ' ' || c == '.';
}


int main() {

  std::string input = "The cattle were running back and forth, but there was no wolf to be seen, heard or smelled, so the shepherd decided to take a little nap in a bed of grass and early summer flowers. Soon he was awakened by a sound he had never heard before.";

  std::cout << "Most: " << get_most_word(input) << std::endl;
  return 0;
}
