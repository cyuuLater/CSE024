#ifndef KEYBOARD_H
#define KEYBOARD_H


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
#define WHITE "\033[39m"


#include "../wordle/wordle.h"


std::vector<std::string> guess() {
   //Getting the guess
   std::vector<std::string> guess;


   std::ifstream key;
   key.open("guesses.txt", std::ios::in);


   if(key.is_open()) {
       std::string letter;
       while(getline(key, letter)) {
           guess.push_back(letter);
       }
   }
   key.close();


   return guess;
}


std::vector<std::string> colors() {
   //Getting the guess
   std::vector<std::string> colors;


   std::ifstream key;
   key.open("colors.txt", std::ios::in);


   if(key.is_open()) {
       std::string letter;
       while(getline(key, letter)) {
           colors.push_back(letter);
       }
   }
   key.close();


   return colors;
}


void updateKeyboard(std::vector<std::string> letters) {
   system("clear");
   std::vector<std::string> g = guess();
   std::vector<std::string> c = colors();
   std::vector<std::string> code;
  
   for (int i = 0; i < letters.size(); i++){
       code.push_back(WHITE);
   }


   for(int i = 0; i < letters.size(); i++) {
       for(int j = 0; j < g.size(); j++) {
           if(letters[i] == g[j]) {
               if(c[j] == "g") {
                   code[i] = GREEN;
                   break;
               } else if(c[j] == "y" && code[i] != GREEN) {
                   code[i] = YELLOW;
                   break;
               } else if(c[j] == "b" && code[i] != GREEN) {
                   code[i] = GRAY;
                   break;
               }
           }
       }
   }


   //Row 1
   for(int i = 0; i < 10; i++) {
       std::cout << code[i] << BOLD << " --- " << RESET;
   }
   std::cout << std::endl;


   for(int i = 0; i < 10; i++) {
       std::cout << code[i] << BOLD <<  "| " << letters[i] << " |"<< RESET;
   }
   std::cout << std::endl;


   for(int i = 0; i < 10; i++) {
       std::cout << code[i] << BOLD << " --- " << RESET;
   }
   std::cout << std::endl;




   //Row 2
   std::cout << "  ";
   for(int i = 10; i < 19; i++) {
       std::cout << code[i] << BOLD << " --- " << RESET;
   }
   std::cout << std::endl;


   std::cout << "  ";
   for(int i = 10; i < 19; i++) {
       std::cout << code[i] << BOLD <<  "| " << letters[i] << " |"<< RESET;
   }
   std::cout << std::endl;


   std::cout << "  ";
   for(int i = 10; i < 19; i++) {
       std::cout << code[i] << BOLD << " --- " << RESET;
   }
   std::cout << std::endl;




   //Row 3
   std::cout << "       ";
   for(int i = 19; i < 26; i++) {
       std::cout << code[i] << BOLD << " --- " << RESET;
   }
   std::cout << std::endl;


   std::cout << "       ";
   for(int i = 19; i < 26; i++) {
       std::cout << code[i] << BOLD <<  "| " << letters[i] << " |"<< RESET;
   }
   std::cout << std::endl;


   std::cout << "       ";
   for(int i = 19; i < 26; i++) {
       std::cout << code[i] << BOLD << " --- " << RESET;
   }
   std::cout << std::endl;
}


void keyboard() {
   std::vector<std::string> alphabet = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P",
                                        "A", "S", "D", "F", "G", "H", "J", "K", "L",
                                        "Z", "X", "C", "V", "B", "N", "M"};
  
   updateKeyboard(alphabet);
}


#endif
