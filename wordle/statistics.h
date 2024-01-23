#ifndef STATISTICS_H
#define STATISTICS_H


#include "wordle.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
// #include <bits/stdc++.h>
#include <string>


/*--------------------------------------------------------------------------------------------------------------------------------*/


//Storing 2nd half of stats summary
void storeTheWAW() {
   std::ifstream file;
   file.open("guesses.txt", std::ios::in);


   std::ofstream outfile;
   outfile.open("stats.txt", std::ios::app);


   std::vector<std::string> data;
   std::string x;


   if(file.is_open()) {
       std::string line;


       while(getline(file, line)) {
           std::stringstream ss(line);
           getline(ss, x, ',');


           data.push_back(x);
       }


       file.close();
   }


   for(int i = 0; i < data.size(); i++) {
       outfile << data[i] << std::endl;
   }


   file.close();
   outfile.close();
}


//Storing the statistics
void statsStoring() {
   std::ofstream file;
   file.open("stats.txt", std::ios::out);
  
   file << "==========================" << std::endl;
   file << "    STATISTICS SUMMARY    " << std::endl;
   file << "==========================" << std::endl;
   file << "Times Played: " << std::setw(12) << std::right << timesPlayed << std::endl;
   file << "Average Attempts: " << std::setw(8) << std::right << averageAttempts << std::endl;
   file << "Win Percentage: " << std::setw(9) << std::right << winPercentage << std::setprecision(1) << std::fixed << "%" << std::endl;
   file << "Current Streak: " << std::setw(10) << std::right << currStreak << std::endl;
   file << "Longest Streak: " << std::setw(10) << std::right << longestStreak << std::endl;
  
   file << std::endl;
   file << std::endl;


   //Length of label: 26
   file << "--------------------------" << std::endl;
   file << "WORD     ATTEMPTS      WIN" << std::endl;
   file << "--------------------------" << std::endl;
   file.close();


   storeTheWAW();
}


//Prints the second half of stats summary
void printTheWAW() {
   std::ifstream file;
   file.open("guesses.txt", std::ios::in);


   std::vector<std::string> data;
   std::string x;


   if(file.is_open()) {
       std::string line;


       while(getline(file, line)) {
           std::stringstream ss(line);
           getline(ss, x, ',');


           data.push_back(x);
       }


       file.close();
   }


   for(int i = 0; i < data.size(); i++) {
       std::cout << data[i] << std::endl;
   }


   file.close();
}


//Option 3: Statistics Summary
void statisticsDisplay() {
   std::cin.ignore();
   system("clear");


   //Length of label: 26
   std::cout << "==========================" << std::endl;
   std::cout << "    STATISTICS SUMMARY    " << std::endl;
   std::cout << "==========================" << std::endl;
   std::cout << "Times Played: " << std::setw(12) << std::right << timesPlayed << std::endl;
   std::cout << "Average Attempts: " << std::setw(8) << std::right << averageAttempts << std::endl;
   std::cout << "Win Percentage: " << std::setw(9) << std::right << winPercentage << std::setprecision(1) << std::fixed << "%" << std::endl;
   std::cout << "Current Streak: " << std::setw(10) << std::right << currStreak << std::endl;
   std::cout << "Longest Streak: " << std::setw(10) << std::right << longestStreak << std::endl;
  
   std::cout << std::endl;
   std::cout << std::endl;


   //Length of label: 26
   std::cout << "--------------------------" << std::endl;
   std::cout << "WORD     ATTEMPTS      WIN" << std::endl;
   std::cout << "--------------------------" << std::endl;


   printTheWAW();


   std::cout << std::endl;
   std::cout << std::endl;


   std::cout << "Press [enter] to continue";
   std::cin.ignore();
}


/*--------------------------------------------------------------------------------------------------------------------------------*/


//Resets the stats.txt file
void fileResetStatistics() {
   std::ofstream file;
   file.open("stats.txt", std::ios::out);


   timesPlayed = 0;
   averageAttempts = 0;
   winPercentage = 0.0;
   currStreak = 0;
   longestStreak = 0;


   //Length of label: 26
   file << "==========================" << std::endl;
   file << "    STATISTICS SUMMARY    " << std::endl;
   file << "==========================" << std::endl;
   file << "Times Played: " << std::setw(12) << std::right << timesPlayed << std::endl;
   file << "Average Attempts: " << std::setw(8) << std::right << averageAttempts << std::endl;
   file << "Win Percentage: " << std::setw(9) << std::right << winPercentage << "%" << std::endl;
   file << "Current Streak: " << std::setw(10) << std::right << currStreak << std::endl;
   file << "Longest Streak: " << std::setw(10) << std::right << longestStreak << std::endl;
  
   file << std::endl;
   file << std::endl;


   //Length of label: 26
   file << "--------------------------" << std::endl;
   file << "WORD     ATTEMPTS      WIN" << std::endl;
   file << "--------------------------" << std::endl;


   file.close();
}


//Option 4: Reset Statistics
void resetStatistics() {
   std::cin.ignore();
   system("clear");


   //Resets values
   timesPlayed = 0;
   averageAttempts = 0;
   winPercentage = 0.0;
   currStreak = 0;
   longestStreak = 0;


   //Length of label: 26
   std::cout << "==========================" << std::endl;
   std::cout << "    STATISTICS SUMMARY    " << std::endl;
   std::cout << "==========================" << std::endl;
   std::cout << "Times Played: " << std::setw(12) << std::right << timesPlayed << std::endl;
   std::cout << "Average Attempts: " << std::setw(8) << std::right << averageAttempts << std::endl;
   std::cout << "Win Percentage: " << std::setw(9) << std::right << winPercentage << "%" << std::endl;
   std::cout << "Current Streak: " << std::setw(10) << std::right << currStreak << std::endl;
   std::cout << "Longest Streak: " << std::setw(10) << std::right << longestStreak << std::endl;
  
   std::cout << std::endl;
   std::cout << std::endl;


   //Length of label: 26
   std::cout << "--------------------------" << std::endl;
   std::cout << "WORD     ATTEMPTS      WIN" << std::endl;
   std::cout << "--------------------------" << std::endl;
  
   //Deletes everything in stats.txt
   fileResetStatistics();


   //Deletes everything in the guesses txt
   std::ofstream outfile;
   outfile.open("guesses.txt", std::ios::out);
   outfile.close();


   std::cout << std::endl;
   std::cout << std::endl;


   std::cout << "Press [enter] to continue";
   std::cin.ignore();
}


#endif