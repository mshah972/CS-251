#include <iostream>
#include <string>
#include <vector>

using namespace std;

void counter(string sen)
{
    vector<string> words;
    string temp = sen;

    // push back the words into the vector
    for(int i = 0; i < sen.length(); i++)   // loop through the sentence
    {
        if(sen.at(i) == ' ' && sen.at(i+1) != ' ')  // if the character is a space and the next character is not a space
        {
            temp = sen.substr(0, i); // get the word
            sen = sen.substr(i+1, sen.length()); // remove the word from the sentence
            words.push_back(temp);  // push the word into the vector
            i = 0;  // reset the counter
        }
    }
    words.push_back(temp);  // push the last word into the vector

    cout << endl;

    cout << "Using Vectors !!!" << endl;
    int size = words.size();

    cout << "The number of words in the sentence is: " << size << endl;

}

int main()
{
    string sentence = "i have cs 251    lab today";
    int temp = 0;

    for(int i = 0; i < sentence.length(); i++)
    {
        if(sentence.at(i) == ' ' && sentence.at(i+1) != ' ')
        {
            temp++;
        }
    }


    cout << "The number of words in the sentence is: " << temp + 1 << endl;

    counter(sentence);

    return 0;
}