// Joshua Fashe
// Prof. Gooch - COSC-1436
// Created on 11/14/2023
// Non-Linear Growth Assignment
// A Simple Model of Cancer Detection and Intervention in C++
// 

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main () {
  

  
  // variables
  int stage; // integer for which state of Sarcoma
  int day = 1; // integer for day of detection
  int decday = 1;
  double rate; // double for cell division rate
  double rate1 = 1.1; // stage 1 rate
  double rate2 = 1.25; // stage 2 rate
  double rate3 = 1.5; // stage 3 rate
  double size = 2; // double for size of sarcoma tumor
  double irate = .79; // double for intervention reduction rate
  string feels; // string for how you're feeling

  // main code
  cout << "Soft Tissue Sarcoma Detector "<< endl;
  cout << "Which Stage of Sarcoma is the patient currently in?  ";
  cin >> stage;
  cout << stage << endl;
  cout << "How big is the Sarcoma tumor?  ";
  cin >> size;
  cout << size << endl;
  cout << "It is currently day " << day << ", and a " << size << "sq mm. tumor may be present in the patient. Further analysis required." << endl;

   switch (stage) {
     case 1:
       cout << "Your patient has State 1 Sarcoma. are you okay?" << endl;
       cin >> feels;
       while (size < 10) {
         cout << "Day " << day << " of detection. Patients Sarcoma tumor (" << setprecision(3) << size << ")sq. mm. too small (less than 10mm2) to be detected. Rescan." << endl;
         size = size * rate1;
         day++;
       }
       cout << "Sarcoma has been detected. This is now a stage 2 matter." << endl;
       stage = 2;
     case 2:
       cout << "Your patient has Stage 2 Sarcoma. are you okay?  " << endl;
       cin >> feels;
       cout << "Day " << decday << " since confirmed detection, day " << day << " since detection. Patients Sarcoma tumor (" << setprecision(3) << size << ")sq. mm. has been be detected. Attempting intervention." << endl; size++;

       while (size >= 10 && size < 23) {
         cout << "Intervention attempt #" << decday << ". - unsuccessful. current size: " << size << "sq. mm." << endl;
         size = size * rate2;
         size = size * irate;
         day++; decday ++;
       }
       cout << "Intervention successful, tumor has been maintained at " << size << "sq. mm. Congrats!";
       break;
     case 3:
       cout << "Your patient has Stage 3 Sarcoma";
       break;
     default:
       cout << "Invalid Response. Please try again.";
       break;
   }

  return 0;
}