#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
// #include <bits/stdc++.h>
#include <string>


//Header files
#include "wordle.h"
#include "statistics.h"


using namespace std;


//Main menu of wordle game
void mainMenu() {
   system("clear");


   ofstream keys;
   keys.open("../keyboard/status.txt", ios::out);
      
   if(keys.is_open()){
       keys << "1" << endl;
   }
   keys.close();


   //Menu popup
   cout << "=========================" << endl;
   cout << "    WELCOME TO WORDLE    " << endl;
   cout << "=========================" << endl;
   cout << endl;
   cout << endl;
   cout << "1. Play Wordle" << endl;
   cout << "2. How to Play" << endl;
   cout << "3. Statistics Summary" << endl;
   cout << "4. Reset Statistics" << endl;
   cout << "5. Exit" << endl;
   cout << endl;
   cout << endl;
   cout << "Select an option: ";
}


//The finishing touch. Will run the game.
int main() {  
    string allowedWords = "allowedWords.txt";
    string words = "solutions.txt";
   
    mainMenu();


    //Make your option
    int option;
    while (cin >> option) {
       if(option == 1) {
           wordleGame(allowedWords, words);
       } else if(option == 2) {
           howToPlay();
       } else if(option == 3) {
           statisticsDisplay();
       } else if(option == 4) {
           resetStatistics();
       } else if(option == 5) {
           ofstream keys;
           keys.open("../keyboard/status.txt", ios::out);

            if(keys.is_open()){
               keys << "0" << endl;
            }
            keys.close();

            break;
        }
        mainMenu();
    }


   return 0;
}
