#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
const int MAX_WRONG = 10;
vector<string> words;
words.push_back("GUESS");
words.push_back("DIFFICULT");
words.push_back("HANGMAN");

srand(static_cast<unsigned int>(time(0)));
random_shuffle(words.begin(),words.end()); 
const string THE_WORD = words[0]; 
int wrong = 0; 
string sofar(THE_WORD.size(),'-');
string used;

cout << "The hangman game" << endl;

while((wrong < MAX_WRONG) && (sofar != THE_WORD))
{

cout << "\n\nYou have to read " << (MAX_WRONG - wrong);
cout << " incorrect guesses left.\n";
cout << "\nYou’ve used the following letters:\n" << used << endl;
cout << "\nSo far, the word is:\n" << sofar << endl;

char guess;
cout << "Enter your guess";
cin >> guess;
guess = toupper(guess);
while(used.find(guess) != string::npos){

cout << "You have already guessed " << guess <<endl;
cout << "Enter your guess: ";
cin >> guess;
 }

used += guess;

if(THE_WORD.find(guess) != string::npos){
cout << "That's right " << guess << "is in the word";

int i = 0;
for(i=0; i < THE_WORD.size(); ++i){
if(THE_WORD[i] == guess){
sofar[i] = guess; }

}

}

else {
cout << "Sorry the " << guess << "is not in the word";
++wrong;}

}

if(wrong==MAX_WRONG){
cout << "You have been hang out";}

else{
cout << "you guessed it!";}

cout << "The word is " << THE_WORD;

return 0;

}
