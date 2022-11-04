#pragma once
#include <iostream>
#include "funcs.h"
#include <cctype>
#include <vector>
#include <cmath>

char shiftCharRight(char c, int rshift);
char shiftCharLeft(char c, int lshift);
std::string decryptCaesar(std::string ciphertext, int shift);
std::string encryptCaesar(std::string ciphertext, int rshift);
int ascii(char c);
void print_vector(std::vector<double> v);
double distance(std::vector<double> one, std::vector<double> two);
std::vector<double> rotateFreqs(std::vector<double> v, int shift);
std::vector<double> getFreqs(std::string encryptedString);
std::string solve(std::string encryptedString);
