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
  int zerOne = (cipherChar>>n)%2;
  return zerOne;
}

int Steganography::convertBinDeci(vector<int>::iterator &iter){
  int baseBin[8];
  int decaNum = 0;
  
  for(int i=0; i<8; i++){
    baseBin[i] = *iter;
    iter++;
  }

  for(int i=0; i<8; i++){
    if(baseBin[i]==1){
      baseBin[i] = baseBin[i]*128;
      for(int j=0; j<i; j++){
	baseBin[i] = baseBin[i]/2;
      }
    }
  }

  for(int i=0; i<8; i++){
    decaNum += baseBin[i];
  }

  return decaNum;
}

void Steganography::readImage(string fileName){
  ifstream inFile;
  int colNum;
  
  inFile.open(fileName);
  
  inFile >> magicNumber;
  inFile >> width >> height;
  inFile >> maxColor;

  inFile >> colNum;
  for(int i=0; inFile; i++){
    colorData.push_back(colNum);
    inFile >> colNum;
  }
  
  inFile.close();
}

void Steganography::printImage(string fileName){
  ofstream outFile;
  vector<int>::iterator iter;
  
  outFile.open(fileName);
  
  outFile << magicNumber << endl << width << " " << height << endl << maxColor << endl;
  for(iter=colorData.begin(); iter!=colorData.end(); iter++){
    outFile << *iter << " ";
  }
  
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
  ofstream outFile;
  
  outFile.open(fileName);

  outFile << cipherText;

  outFile.close();
}

void Steganography::cleanImage(){
  vector<int>::iterator iter;
  for(iter=colorData.begin(); iter!=colorData.end(); iter++){
    
    if(*iter%2!=0)
      *iter-=1;
  }
}

void Steganography::encipher(){
  vector<int> binData;
  
  for(int i=0; i<cipherText.length(); i++){
    for(int j=8; j>0; j--){
      binData.push_back(getNthBit(cipherText.at(i), (j-1)));
    }
  }

  cleanImage();

  for(int i=0; i<cipherText.length()*8; i++){
    colorData[i] += binData[i];
  }
}

void Steganography::decipher(){
  vector<int> binData;
  vector<int> decaData;
  vector<int>::iterator iter;

  for(iter=colorData.begin(); iter!=colorData.end(); iter++){
    if(*iter%2 == 0){
      binData.push_back(0);
    }
    else{
      binData.push_back(1);
    }
  }

  for(iter=binData.begin(); iter!=binData.end(); iter++){
    decaData.push_back(convertBinDeci(iter));
  }

  for(iter=decaData.begin(); iter!=decaData.end(); iter++){
    cipherText += *iter;
  }
}
