/**
 * @file main.cpp
 * @author Tucker Self, Braden Windsor
 * @date 2023-09-24
 * @brief main for steganography
 * 
 * The main file of a simple steganography program
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Steganography.h"

using namespace std;

int main() {
  Steganography notmySteganography;
  char userChoice;
  int check = 0;
  string ppmName, inputText, encodedImg, outputText;


  
  while(check != 2){

    cout << "Please choose your operation.\nE for encoding, D for decoding: ";
    cin >> userChoice;
    
    if((userChoice == 'e') || (userChoice == 'E')){
      cout << "Please enter the PPM, input text file, and the encoded image file names in that order\n";
      cin >> ppmName;

      cout << "\n";
      cin >> inputText;

      cout << "\n";
      cin >> encodedImg;

      notmySteganography.readImage(ppmName);
      notmySteganography.readCipherText(inputText);

      notmySteganography.encipher();
      notmySteganography.printImage(encodedImg);
      
      check = 2;
    }

    else if((userChoice == 'd') || (userChoice == 'D')){
      cout << "Please enter the PPM and the output text file names in that order\n";
      cin >> ppmName;

      cout << "\n";
      cin >> outputText;
      
      notmySteganography.readImage(ppmName);
      notmySteganography.decipher();
      notmySteganography.printCipherText(outputText);
      
      check = 2;
    }
    
    else{
      cout << "Please enter valid input\n\n";
    }
    
  } 
  return 0;
}
