/**
 * @file Steganography.h
 * @author Tucker Self, Braden Windsor
 * @date 2023-09-24
 * @brief Steganography function declarations
 * 
 * creates prototype functions for the Steganography class
 */

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <string>
#include <vector>

class Steganography{
 private:
  std::string magicNumber;
  int width, height, maxColor;

  std::vector<int> colorData;

  std::string cipherText;

  int getNthBit(char cipherChar, int n);

 public:
  void readImage(string fileName);

  void printImage(string fileName);

  void readCipherText(string fileName);

  void printCipherText(string fileName);

  void cleanImage();

  void encipher();

  void decipher();
  
};
#endif //STEGANOGRAPHY_H
