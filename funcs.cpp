#include <iostream>
#include "funcs.h"
#include <cctype>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

//frequencies for the alphabet in the english language
std::vector<double> eng_freq = 
{
    0.082,
    0.015,
    0.028,
    0.043,
    0.13,
    0.022,
    0.02,
    0.061,
    0.07,
    0.0015,
    0.0077,
    0.04,
    0.024,
    0.067,
    0.075,
    0.019,
    0.00095,
    0.06,
    0.063,
    0.091,
    0.028,
    0.0098,
    0.024,
    0.0015,
    0.02,
    0.0074
};


char shiftCharRight(char c, int rshift) // for encrypt
{
    if(int(c) <= 90){
        int ascii = (((int(c) - 65) + rshift) % 26) + 65; 
        char result = (char)ascii;
        return result;
    }
    else
    {
       int ascii = (((int(c) - 97) + rshift) % 26) + 97; 
        char result = (char)ascii;
        return result; 
    }
}

char shiftCharLeft(char c, int lshift) // for decrypt
{
    char result;
    if(int(c) <= 90)
    {
        if((int(c) - 65) - lshift < 0)
        {
            int increment = abs(((int(c) - 65) - lshift) % 26);
            int ascii = 91 - increment;
            result = char(ascii);
        }
        else
        {
            int ascii = (((int(c) - 65) - lshift) % 26) + 65; 
            result = (char)ascii;
        }
    }
    if(int(c) >= 97)
    {
        if((int(c) - 97) - lshift < 0)
        {
            int increment = abs(((int(c) - 97) - lshift) % 26);
            int ascii = 123 - increment;
            result = char(ascii);
        } 
        else
        {
            int ascii = (((int(c) - 97) - lshift) % 26) + 97; 
            result = (char)ascii;
        }
    }
    return result;
}

std::string decryptCaesar(std::string ciphertext, int shift)
{
    std::string result = "";
    for(int i = 0; i < ciphertext.length(); i++)
    {
        char newChar;
        if(isalpha(ciphertext[i]))
        {
            newChar = shiftCharLeft(ciphertext[i], shift);
            result += newChar;
        }
        else
        {
            newChar = ciphertext[i];
            result += newChar;
        }
    }
    return result;
}

std::string encryptCaesar(std::string plaintext, int rshift)
{
    std::string result = "";
    for(int i = 0; i < plaintext.length(); i++)
    {
        char newChar;
        if(isalpha(plaintext[i]))
        {
            newChar = shiftCharRight(plaintext[i], rshift);
            result += newChar;
        }
        else
        {
            newChar = plaintext[i];
            result += newChar;
        }
    }
    return result;
}

int indexLetter(char c) //grabs letter index in alphabet
{
    int num = (int)c;
    if(num >= 65 && num <= 90)
    {
        return ((c - 65) % 26);
    }
    else if(num >= 97 && num <= 122)
    {
        return ((c - 97) % 26);
    }
    else
    {
        return -1;
    }

}

void print_vector(std::vector<double> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ",";
    }
}

//distance formula between two vectors
double distance(std::vector<double> one, std::vector<double> two)
{
    double sum = 0;
    for(int i = 0; i < one.size(); i++)
    {
        double difference = one[i] - two[i];
        sum += std::pow(difference,2);
    }
    return std::sqrt(sum);
}

//rotates contents of the vector by 1
std::vector<double> rotateFreqs(std::vector<double> v) 
{
	int index;
	std::vector<double> result(v.size());
	for(int i = 0; i < v.size();i++) 
    {
		index = (i + 1) % v.size();
		result[index] = v[i]; 
	}
	return result;
}

std::vector<double> getFreqs(std::string encryptedString){
    std::vector<double> frequencies(26);
    int c = 0;
    for(int i = 0; i < encryptedString.length();i++){
        int index = indexLetter(encryptedString[i]);
        if(index != -1){
            frequencies[index] += 1;
            c++;
        }
    }
    for(int i = 0; i < frequencies.size(); i++){
        frequencies[i] = frequencies[i] / (double(c));
    }
    return frequencies;
}

std::string solve(std::string encryptedString)
{
	std::vector<double> frequencies(26); //vector for encryptedString's letter frequencies
	frequencies = getFreqs(encryptedString); 
	int shift = 0;
	double closestDistance = INT_MAX;
	double currentDistance; 
	for(int i = 1; i < 26; i++) 
    {
		frequencies =  rotateFreqs(frequencies); //rotates frequencies by one
		currentDistance = distance(frequencies, eng_freq);
		if (closestDistance > currentDistance) {
			closestDistance = currentDistance;
			shift = i;
		}
	}
	return encryptCaesar(encryptedString, shift);
}
