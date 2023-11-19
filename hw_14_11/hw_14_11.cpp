#include <iostream>
#include <Windows.h>
#include <cstdio>
using namespace std;

/// task #1
string generatePassword(int length)
{
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+";
    string password = "";

    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        int index = rand() % charset.length();
        password += charset[index];
    }

    return password;
}

char mostFrequentLetter(const char* text_w) {
    int frequencies[256] = { 0 };

    for (int i = 0; text_w[i] != '\0'; i++) {
        if (text_w[i] != ' ') {
            frequencies[(int)text_w[i]]++;
        }
    }

    int maxFrequency = 0;
    char mostFrequent = ' ';

    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > maxFrequency) {
            maxFrequency = frequencies[i];
            mostFrequent = (char)i;
        }
    }

    return mostFrequent;
}

int main()
{
    /////task 1
    int length;

    cout << "enter password length: ";
    cin >> length;

    string password = generatePassword(length);
    cout << "password generated: " << password << "\n\n";

    

    ///////task 2

    char* text = new char[200];
    cout << "Input text: ";
    cin.getline(text,200);

    char* word = new char[50];
    cout << "\nInput word: ";
    cin.getline(word, 50);

    int countWords = 0;
    char* result = strstr(text, word);
    while (result != nullptr)
    {
        countWords++;
        int index = result - text;
        if (text[index] != '#')
        {
            text[index] = '#';
        }
        result = strstr(result + 1, word);
    }

    cout << "count word: " << word << ", in the text: " << countWords << "\n";


    /////////task 3

    char* letter_text = new char[200];
    cout << "input text: ";
    cin.getline(letter_text, 200);

    char mostFreqChar = mostFrequentLetter(letter_text);
    cout << "most common letter: " << mostFreqChar << "\n";

    Sleep(INFINITE);
}
