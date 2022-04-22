#include <iostream>
#include <fstream>
#include <ctime>
#include "hashmap.h"

using namespace std;


template <typename T>
void realloc(T** pinakas, unsigned long int size, unsigned long int new_size) {
    std::cout << "realloc " << new_size << std::endl;
    T* new_array = new T[new_size] {} ;
    for(unsigned int long i = 0; i < size; i++)
    {
        new_array[i] = (*pinakas)[i];
        std::cout << "moved";
        fflush(stdout);
    }
    delete [] (*pinakas);
    *pinakas = new_array;
}


bool isAlphanumeric(char ch)
{
    if((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <='z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{

    hashmap object;
    std::string buffer;

    ifstream file_2;
    file_2.open("fenia_2.txt");
    int words_array_size = 10;
    std::string* words = new std::string[10];
    int total_words = 0;
    while (getline(file_2, buffer))
    {
        if(buffer.empty()){
            continue;
        }
        int counter = 0;
        int character_counter = 0; //0-2 is the entoli, so we start from the third character and beyond.

        while (character_counter < buffer.size() - 1) {
            if (isAlphanumeric(buffer.at(character_counter))) {
                // We are currently at a valid character
                std::string word;
                // Continue reading characters until it isn't valid.
                // Meanwhile we save the 'word' both in a word array
                // and in the protasi array.
                while (isAlphanumeric(buffer.at(character_counter)))
                {
                    word += buffer.at(character_counter);
                    character_counter++;
                    if ( character_counter == buffer.size()){
                        break;
                    }
                }

                for(unsigned int i = 0; i < word.size(); i++)
                {
                    word[i] = tolower(word[i]);
                }


                words[total_words] = word;
                total_words++;
                if(total_words == words_array_size) {
                    realloc<std::string>(&words,words_array_size, words_array_size * 2);
                    words_array_size *= 2;
                    std::cout << "realloc done" << std::endl;
                    fflush(stdout);
                }
                int previous_value = object.get(word);
                if (previous_value == -1) {
                    object.add(word, 1);
                } else {
                    object.add(word, previous_value + 1);
                }
            }
            else {
                character_counter++;
            }
        }
    }
    // object.print();
    for (int i = 0; i < total_words; i++){
        std::cout << words[i] << std::endl;
        //cout<<"NUMBER IS:  "<<object.get(words[i])<<endl;
    }
}
