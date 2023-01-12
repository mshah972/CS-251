#include <iostream>
#include <string>
using namespace std;

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

    return 0;
}