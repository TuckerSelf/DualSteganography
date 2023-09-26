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


/**
 * helper method to return nth bit to be encoded
 *
 * @param char cipherChar character in cipherText
 * @param int n given interger
 * @pre assumes valid cipher data is given
 * @return int the nth bit
 * @post the nth bit to be encoded is now accessable
 * 
 */
  int getNthBit(char cipherChar, int n);


/**
 * converts binary into a decimal
 *
 * @param std::vector<int>::iterator &iter the given binary
 * @pre assumes valid binary number with 8 digits is given
 * @return int decimal value
 * @post binary data is now stored as decimal data
 * 
 */
  int convertBinDeci(std::vector<int>::iterator &iter);

 public:
  

/**
 * reads the given ppm image
 *
 * @param std::string fileName the name of the ppm file
 * @pre assumes valid file name is given
 * @return void 
 * @post stores data in function
 * 
 */
  void readImage(std::string fileName);


/**
 * writes stored ppm image to given file name
 *
 * @param std::string fileName the name of the file to be given ppm data
 * @pre assumes data is already stored
 * @return void 
 * @post pushes data to file location
 * 
 */
  void printImage(std::string fileName);


/**
 * reads plain file text and stores its information
 *
 * @param std::string fileName file to be read
 * @pre assumes valid file given
 * @return void 
 * @post data stored in function
 * 
 */
  void readCipherText(std::string fileName);


/**
 * writes plain text to a given file name
 *
 * @param std::string fileName the name of the given file
 * @pre assumes data has been stored
 * @return void 
 * @post data pushed to file
 * 
 */
  void printCipherText(std::string fileName);


/**
 * zeros the least significant bit of color data
 *
 * @pre assumes color data has been stored
 * @return void 
 * @post data is changed for further encoding to occur
 * 
 */
  void cleanImage();


/**
 * stores text from cipherText into colorData
 *
 * @pre assumes valid text is stored and valid color data is stored
 * @return void 
 * @post changes stored color data to reflect stored text data
 * 
 */
  void encipher();


/**
 * reads ciphered text from colorData and stores it in cipherText
 *
 * @pre assumes valid text is stored and valid color data is stored
 * @return void 
 * @post deciphers stored color data into newly stored text data
 * 
 */
  void decipher();
  
};
#endif //STEGANOGRAPHY_H
