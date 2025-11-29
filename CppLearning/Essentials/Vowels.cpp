#include <iostream>
#include <string>

using namespace std;

const char vowels[] = {'a', 'e', 'i', 'o', 'u'}; 

int countVowels(string str);

int main()
{
    string str;
    cout << "Enter a word: ";
    getline(cin, str); 
    cout << "The number of vowels in the word is: " << countVowels(str) << endl;
    return 0;
}

int countVowels(string str)
{
    int counter = 0;

    const size_t num_vowels = sizeof(vowels) / sizeof(vowels[0]); 

    for (size_t i = 0; i < str.length(); i++) {
        char current_char = tolower(str[i]);
        
        for (size_t j = 0; j < num_vowels; j++) {
            if (current_char == vowels[j]) {
                counter++;
                break; 
            }
        }
    } 
    return counter;
}