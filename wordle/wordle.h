#ifndef WORDLE_H
#define WORDLE_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
// #include <bits/stdc++.h>
#include <string>


//MACROS for colors and bolding
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define GRAY "\033[90m"


//Changing variables
int gameAttempts = 0;
int wins = 0;
bool won = false;


//Constant variables (need to persist in file)
int timesPlayed = 0;
int attempts = 0;
int averageAttempts = 0;
float winPercentage = 0.0;
int currStreak = 0;
int longestStreak = 0;


#include "statistics.h"


/*--------------------------------------------------------------------------------------------------------------------------------*/


//Checks if the input exists in allowed.txt
bool isAllowed(std::string wordInputted, std::string allowedWordsFile, std::string wordsFile) {
   std::ifstream file;
   std::ifstream fileTwo;


   file.open(allowedWordsFile, std::ios::in);
   fileTwo.open(wordsFile, std::ios::in);


   std::vector<std::string> allowedWords;
  
   //Iterates through allowed.txt
   if(file.is_open()) {
       std::string word;
       while(getline(file, word)) {
           allowedWords.push_back(word);
       }
   }
   file.close();


   //Iterates through words.txt
   if(fileTwo.is_open()) {
       std::string word;
       while(getline(fileTwo, word)) {
           allowedWords.push_back(word);
       }
   }
   fileTwo.close();


   for(int i = 0; i < allowedWords.size(); i++) {
       if(wordInputted == allowedWords[i]) {
           return true;
       }
   }


   return false;
}


//Finds random word to used for the wordle game
std::string findWordForWordle(std::string wordsFile) {
   std::string wordForWordle;
   std::string word;
   std::vector<std::string> words;
   srand(time(0));


   std::ifstream file;


   file.open(wordsFile, std::ios::in);
  
   int total;
   while(getline(file, word)) {
       total++;
       words.push_back(word);
   }


   int random = rand() % total;


   wordForWordle = words[random];
   file.close();


   return wordForWordle;
}


//For keyboard
void colorCodeKeyboard(std::vector<std::string> guessLetters, std::vector<std::string> correctWordLetters) {
   std::ofstream file;
   file.open("../keyboard/colors.txt", std::ios::app);


   for(int k = 0; k < guessLetters.size()-1; k++) {
       for(int l = 0; l < correctWordLetters.size()-1; l++) {
           if(guessLetters[k] == correctWordLetters[l] && k == l) {
               file << 'g' << std::endl;
               k++;


           } else if(std::count(correctWordLetters.begin(), correctWordLetters.end(), guessLetters[k])) {
               file << 'y' << std::endl;
               k++;


           } else {
               file << 'b' << std::endl;
               k++;
           }
       }
   }


   file.close();
}          


//Prints out the wordle word with the color code
void printingForWordle(std::vector<std::string> guessLetters, std::vector<std::string> correctWordLetters) {
   colorCodeKeyboard(guessLetters, correctWordLetters);
   //Top border
   for(int k = 0; k < guessLetters.size()-1; k++) {
       for(int l = 0; l < correctWordLetters.size()-1; l++) {
           if(guessLetters[k] == correctWordLetters[l] && k == l) {
               std::cout << BOLD << GREEN << " --- " << RESET;
               k++;
           } else if(std::count(correctWordLetters.begin(), correctWordLetters.end(), guessLetters[k])) {
               std::cout << BOLD << YELLOW << " --- " << RESET;
               k++;
           } else {
               std::cout << BOLD << GRAY << " --- " << RESET;
               k++;
           }
       }
   }          
   std::cout << std::endl;


   //Letters
   for(int k = 0; k < guessLetters.size()-1; k++) {
       for(int l = 0; l < correctWordLetters.size()-1; l++) {
           if(guessLetters[k] == correctWordLetters[l] && k == l) {
               std::cout << BOLD << GREEN << "| " << guessLetters[k] << " |"<< RESET;
               k++;
           } else if(std::count(correctWordLetters.begin(), correctWordLetters.end(), guessLetters[k])) {
               std::cout << BOLD << YELLOW << "| " << guessLetters[k] << " |" << RESET;
               k++;
           } else if(guessLetters[k] != correctWordLetters[l]) {
               std::cout << BOLD << GRAY << "| " << guessLetters[k] << " |" << RESET;
               k++;
           }
       }
   }
   std::cout << std::endl;


   //Bottom border
   for(int k = 0; k < guessLetters.size()-1; k++) {
       for(int l = 0; l < correctWordLetters.size()-1; l++) {
           if(guessLetters[k] == correctWordLetters[l] && k == l) {
               std::cout << BOLD << GREEN << " --- " << RESET;
               k++;
           } else if (std::count(correctWordLetters.begin(), correctWordLetters.end(), guessLetters[k])) {
               std::cout << BOLD << YELLOW << " --- " << RESET;
               k++;
           } else {
               std::cout << BOLD << GRAY << " --- " << RESET;
               k++;
           }
       }
   }
   std::cout << std::endl;
}


//A winning attempt
void victory() {
   won = true;
   attempts++;
   gameAttempts++;
   wins++;
   currStreak++;


   std::cout << std::endl;
   std::cout << std::endl;


   std::cout << "Splendid!" << std::endl;


   std::cout << std::endl;
   std::cout << std::endl;


   std::cout << "Press [enter] to continue";
   std::cin.ignore();
}


//A failing attempt
void defeat(std::string correct) {
   won = false;
   attempts++;
   gameAttempts++;
              
   if(longestStreak < currStreak) {
       longestStreak = currStreak;
   }
              
   currStreak = 0;


   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "The word was: " << correct << std::endl;


   std::cout << std::endl;
   std::cout << std::endl;


   std::cout << "Better luck next time!" << std::endl;


   std::cout << std::endl;
   std::cout << std::endl;


   std::cout << "Press [enter] to continue";
   std::cin.ignore();
}


//Stores bottom half of statistics
void answerStoring(std::string correct) {
   std::string win = "";
   if(won) {
       win = "Yes";
   } else {
       win = "No";
   }


   //Stores the guesses in the text file
   std::ofstream file;
   file.open("guesses.txt", std::ios::app);
   file << correct << std::setw(17-correct.length()) << std::right << gameAttempts << std::setw(9) << std::right << win << std::endl;
   file.close();
}


//Stores the answer in the keyboard answers.txt file
void keyboardAnswerStoring(std::string correct) {
   //Stores guesses in the keyboard folder
   std::ofstream keyFile;
   keyFile.open("../keyboard/answers.txt", std::ios::out);
   keyFile << correct << std::endl;
   keyFile.close();
}


//Stores each guess to the keyboard guesses.txt file
void guessStoring(std::vector<std::string> guessLetters) {
   std::ofstream file;
   file.open("../keyboard/guesses.txt", std::ios::app);


   for(int i = 0; i < guessLetters.size()-1; i++) {
       file << guessLetters[i] << std::endl;
   }
  
   file.close();
}


//Detects if the game is playing for keyboard
void gameStarted() {
   std::ofstream keys;
   keys.open("../keyboard/status.txt", std::ios::out);
      
   if(keys.is_open()){
       keys << "2" << std::endl;
   }
   keys.close();
}


//Option 1: Play Wordle
void wordleGame(std::string allowedWords, std::string words) {
   gameStarted();
   std::cin.ignore();
   system("clear");
   timesPlayed++;
   gameAttempts = 0;


   std::string correctWord = findWordForWordle(words);
   std::string upperCorrectWord = "";


   //Makes the selected word uppercased
   for(int i = 0; i < correctWord.length(); i++) {
       upperCorrectWord += toupper(correctWord[i]);
   }


   //Breaks apart the target word for comparisons
   std::vector<std::string> correctWordLetters;
   for(int i = 0; i < upperCorrectWord.size() + 1; i++) {
       correctWordLetters.push_back(upperCorrectWord.substr(i, 1));
   }


   //Variables for when game is going on
   int numGuesses = 0;
   std::string guess;


   //Ensures the game only lasts for up to 6 allowed guesses
   while(numGuesses < 6) {
       std::cout << "Enter guess: ";
       std::cin >> guess;
       std::cout<< "\033[1A";
       std::cout<< "\033[2K";
       std::cout<< "\033[0G";
       std::string upperGuess = "";


       //Makes the guess word upper cased
       for(int i = 0; i < guess.length(); i++) {
           upperGuess += toupper(guess[i]);
       }


       keyboardAnswerStoring(upperCorrectWord);


       if(isAllowed(guess, allowedWords, words)) {
           std::vector<std::string> guessLetters;


           for(int j = 0; j < upperGuess.size() + 1; j++) {
               guessLetters.push_back(upperGuess.substr(j, 1));
           }


           guessStoring(guessLetters);


           //If word was guessed correctly
           if(guess == correctWord) {      
               numGuesses = 6;
               printingForWordle(std::vector<std::string> (guessLetters), std::vector<std::string> (correctWordLetters));
               victory();


               std::ofstream fileOne;
               fileOne.open("../keyboard/colors.txt", std::ios::out);
               fileOne.close();


               std::ofstream fileTwo;
               fileTwo.open("../keyboard/guesses.txt", std::ios::out);
               fileTwo.close();


           //A failure attempt
           } else if(numGuesses == 5){
               numGuesses = 6;
               printingForWordle(std::vector<std::string> (guessLetters), std::vector<std::string> (correctWordLetters));
               defeat(upperCorrectWord);


               std::ofstream fileOne;
               fileOne.open("../keyboard/colors.txt", std::ios::out);
               fileOne.close();


               std::ofstream fileTwo;
               fileTwo.open("../keyboard/guesses.txt", std::ios::out);
               fileTwo.close();


           //Still have guesses left
           } else {
               attempts++;
               gameAttempts++;
               printingForWordle(std::vector<std::string> (guessLetters), std::vector<std::string> (correctWordLetters));
               numGuesses++;
           }
       }
   }
  
   answerStoring(upperCorrectWord);


   winPercentage = ((float) wins / timesPlayed) * 100;
   averageAttempts = attempts / timesPlayed; 
   statsStoring();
   std::cin.ignore();
}


/*--------------------------------------------------------------------------------------------------------------------------------*/


//Option 2: How to Play
void howToPlay() {
   std::cin.ignore();
   system("clear");


   std::cout << "=============================================" << std::endl;
   std::cout << "                HOW TO PLAY                  " << std::endl;
   std::cout << "=============================================" << std::endl;
   std::cout << "Guess the Wordle in 6 tries." << std::endl;


   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "HOW TO PLAY:" << std::endl;
   std::cout << "- Each guess must be a valid 5 letter word." << std::endl;
   std::cout << "- The color of the tiles will change to show \n  you how close your guess was to the word." << std::endl;
  
   std::cout << std::endl;
   std::cout << std::endl;


   //Correct position
   std::cout << BOLD << GREEN << " --- " << RESET << BOLD << " --- " << " --- " << " --- " << " --- " << RESET << std::endl;
   std::cout << BOLD << GREEN << "| W |" << RESET << BOLD << "| E |" << "| A |" << "| R |" << "| Y |" << RESET << std::endl;
   std::cout << BOLD << GREEN << " --- " << RESET << BOLD << " --- " << " --- " << " --- " << " --- " << RESET << std::endl;
   std::cout << BOLD << "W " << RESET << "is in the word and in the correct spot." << std::endl;
   std::cout << std::endl;


   //Incorrect position
   std::cout << BOLD << " --- " << YELLOW << " --- " << RESET << BOLD << " --- " << " --- " << " --- " << RESET << std::endl;
   std::cout << BOLD << "| P |" << YELLOW << "| I |" << RESET << BOLD << "| L |" << "| L |" << "| S |" << RESET << std::endl;
   std::cout << BOLD << " --- " << YELLOW << " --- " << RESET << BOLD << " --- " << " --- " << " --- " << RESET << std::endl;
   std::cout << BOLD << "I " << RESET << "is in the word but in the wrong spot." << std::endl;
   std::cout << std::endl;


   //No positions
   std::cout << BOLD << " --- " << " --- " << " --- " << GRAY << " --- " << RESET << BOLD << " --- " << RESET << std::endl;
   std::cout << BOLD << "| V |" << "| A |" << "| G |" << GRAY << "| U |" << RESET << BOLD << "| E |" << RESET << std::endl;
   std::cout << BOLD << " --- " << " --- " << " --- " << GRAY << " --- " << RESET << BOLD << " --- " << RESET << std::endl;
   std::cout << BOLD << "U " << RESET << "is not in the word in any spot." << std::endl;
   std::cout << std::endl;
   std::cout << std::endl;


   std::cout << "Press [enter] to continue";
   std::cin.ignore();
}


/*--------------------------------------------------------------------------------------------------------------------------------*/


//Use this algorithm to compute keyboard colors
//Testing for colors
std::string colorCode(std::vector<std::string> guessLetters, std::vector<std::string> correctWordLetters) {
   std::string colors = "";


   for(int k = 0; k < guessLetters.size(); k++) {
       for(int l = 0; l < correctWordLetters.size(); l++) {
           if(guessLetters[k] == correctWordLetters[l] && k == l) {
               colors += 'g';
               k++;
           } else if(std::count(correctWordLetters.begin(), correctWordLetters.end(), guessLetters[k])) {
               colors += 'y';
               k++;
           } else {
               colors += 'n';
               k++;
           }
       }
   }          
  
   return colors;
}


#endif