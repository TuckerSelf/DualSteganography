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

  int convertBinDeci(std::vector<int>::iterator &iter);

 public:
  void readImage(std::string fileName);

  void printImage(std::string fileName);

  void readCipherText(std::string fileName);

  void printCipherText(std::string fileName);

  void cleanImage();

  void encipher();

  void decipher();
  
};
#endif //STEGANOGRAPHY_H
