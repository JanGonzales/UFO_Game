#include <iostream>
#include "ufo_functions.hpp"
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

int main() {
  greet();
  std::string codeword;
  std::string answer;
  int misses = 0;
  std::vector <char> incorrect;
  bool guess = false;
  char letter;
  // --------------------------------------
  std::vector <std::string> dictionary;
  std::ifstream file("Dictionary.txt");
  std::string store_dictionary;
  while(getline(file, store_dictionary)) dictionary.push_back(store_dictionary);
  srand(time(NULL));
  codeword = dictionary[rand() % dictionary.size() + 1];
  //---------------------------------------

  for(int answer_len = 0; answer_len < codeword.size(); answer_len++){
      answer += "_";
  }

  while(answer != codeword && misses < 7){
    display_misses(misses);
    display_status(incorrect, answer);
    std::cout << "\n" << "Please enter your guess: ";
    std::cin >> letter;

    for(int a = 0; a < codeword.size(); a++){
      if(letter == codeword[a]){
        std::cout << "you guess a right word" << std::endl;
        answer[a] = letter;
        guess = true;
      }
    }
    if (guess == true){
      std::cout << "Correct!" << std::endl;
      guess = false;
    }
    else{
      incorrect.push_back(letter);
      misses++;
    }

    
  }
  
  std::cout << end_game(answer, codeword) << std::endl;
  std::cout << "---------------------------------------------------" << std::endl;
  std::cout << "the codeword was: " << codeword << std::endl;
  std::cout << "The letters you guessed " << answer << std::endl;
  std::cout << "---------------------------------------------------" << std::endl;

}
