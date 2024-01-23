#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "keyboard.h"


#include <thread>
#include <chrono>


using namespace std;


vector<string> update() {
   ifstream keys;
   keys.open("status.txt", ios::in);


   vector<string> key;


   if(keys.is_open()) {
       string line;
       while(getline(keys, line)) {
           key.push_back(line);
       }
   }


   return key;
}


void updateKeyboardFiles() {
   vector<string> g = guess();
   vector<string> c = colors();


   bool guessUpdate = true;
   bool colorsUpdate = true;


   while(guessUpdate) {
       vector<string> recent = guess();
       if(recent != g){
           guessUpdate = false;
           g = recent;
       }
   }


   while(colorsUpdate) {
       vector<string> recent = colors();
       if(recent != c){
           colorsUpdate = false;
           c = recent;
       }
   }


   keyboard();
}


int main(int argc, char* argv[]) {
   vector<string> key = update();


   while(true){
       bool escape = true;  


       while(escape){
           vector<string> recent = update();
           if(recent != key){
               escape = false;
               key = recent;
           }
       }


       system("clear");
       if(key[0] == "0"){
           cout << "Please launch the Wordle Game" << endl;
       } else if(key[0] == "1") {
           cout << "Waiting for Wordle Game round to start" << endl;
       } else {
           keyboard();
           updateKeyboardFiles();
           updateKeyboardFiles();
           updateKeyboardFiles();
           updateKeyboardFiles();
           updateKeyboardFiles();
       }


       chrono::milliseconds duration(200);
       this_thread::sleep_for(duration);
   }


   return 0;
}
