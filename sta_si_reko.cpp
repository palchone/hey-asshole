#include<iostream>
#include<fstream>
#include<cstring>
#include<unordered_map>
#include<vector>
#include<random>
#include<time.h>
using namespace std;

int
main()
{
    //file -> array
    srand(time(NULL));
    ifstream file("jeb.txt");
    int maxCount = 500;
    int count = 0;
    string* words = (string*)malloc(sizeof(string)*maxCount);
    string word;
    while(file >> word)
    {
        if(count == maxCount)
        {
            maxCount *= 2;
            string *temp = (string *)malloc(sizeof(string)*maxCount);
            memcpy(temp, words, count*sizeof(string));
            free(words);
            words = temp;
        }
        words[count++] = word;
    //     ccout << word << "-" << words[count];
    //     ccout << endl;
    }

    //array -> map

    unordered_map<string, vector<string>> map;
    for(int i = 0; i < count; i++)
    {
        if (map.find(words[i]) == map.end())
        {
            vector<string> possibilities;
            if(i+1 < count) possibilities.push_back(words[i+1]);
            map[words[i]] = possibilities;
        }
        else
        {
            vector<string> possibilities = map.at(words[i]);
            if(i+1 < count) possibilities.push_back(words[i+1]);
            map.at(words[i]) = possibilities;
        }
    } 
    // for(int i = 0; i < count; i ++)
    // {
    //     vector<string> = 
    // }
    srand(time(NULL));
    string firstWord = words[rand() % count];
    if(firstWord.back() == '.')
    {
        firstWord.pop_back();
        cout << firstWord<< " ";
    }
    else
    {
        while(1)
        {
            vector<string> posWords = map.at(firstWord);
            if(posWords.empty()) break;
            string nextWord = posWords.at(rand() % posWords.size());
            if(nextWord.back() == '.') 
            {  
                nextWord.pop_back();
                cout << nextWord;
                break;
            }
            cout << nextWord << " ";
            firstWord = nextWord;
        }
    }
    
    cout<<endl;
}
