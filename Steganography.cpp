/**
 * @file Steganography.cpp
 * @author Tucker Self, Braden Windsor
 * @date 2023-09-24
 * @brief Steganography definitions
 * 
 * gives meaning to the Steganography class functions
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Steganography.h"

using namespace std;

int Steganography::getNthBit(char cipherChar, int n){

}

void Steganography::readImage(string fileName){
  ifstream inFile;
  string imageData;
  inFile.open(fileName);
  
  getline(inFile, magicNumber);
  inFile >> width >> height;
  getline(inFile, ignore);
  inFile >> maxColor;
  
  for(int i=0; inFile; i++){
    getline(inFile, imageData);
    colorData[i] = imageData;
  }
  inFile.close();
}

void Steganography::printImage(string fileName){
  ofstream outFile;
  outFile.open(fileName);
  outFile << magicNumber;
  outFile.close();
}

void Steganography::readCipherText(string fileName){
  ifstream inFile;
  string imageData;
  inFile.open(fileName);
  getline(inFile, imageData);
  cipherText = imageData;
  while(inFile){
    getline(inFile, imageData);
    cipherText += imageData;
  }
  inFile.close();
}

void Steganography::printCipherText(string fileName){
}

void Steganography::cleanImage(){
  for(int i=0; i<(width*height); i++){
    if(colorData[i]%2!=0)
      colorData[i]-=1;
  }
}

void Steganography::encipher(){
}

void Steganography::decipher(){
}
