#include <iostream>
#include <fstream>
//#include "HashTable.h"

#include <chrono>

#include "tree.h"
#include "foo.h"
#include "AVL_tree.h"

using namespace std;


template <typename T>
void realloc(T** pinakas, unsigned long int size, unsigned long int new_size) {
    T* new_array = new T[new_size] {} ;
    for(unsigned int long i = 0; i < size; i++)
    {
        new_array[i] = (*pinakas)[i];
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

bool isExtra(char ch) {
    if (ch == '\'') { return true; }
    return false;

}
int main()
{
    // Αρχικοποιήση seed για την srand
    srand(time(NULL));


//    HashTable object;//Αντικειμενο της κλασης HashTable
    tree object_tree;//Αντικειμενο της κλασης tree
    AVL_tree object_AVL;//Αντικειμενο της κλασης AVL

    std::string buffer;

    ifstream file_2;
    file_2.open("fenia_1.txt");

    int words_array_size = 10;
    std::string* words = new std::string[10];
    int total_words = 0;


    while (getline(file_2, buffer)) {
        if(buffer.empty()){
            continue;
        }
        int counter = 0;
        int character_counter = 0; //0-2 is the entoli, so we start from the third character and beyond.
        char* string_copy = new char[100];//Αντιγραφει ενα string σε για εισαγωγη σε tree και AVL

        while (character_counter < buffer.size()) {
            if (isAlphanumeric(buffer.at(character_counter))) {
                // We are currently at a valid character
                std::string word;
                // Continue reading characters until it isn't valid.
                // Meanwhile we save the 'word' both in a word array
                // and in the protasi array.
                while (isAlphanumeric(buffer.at(character_counter)) || isExtra(buffer.at(character_counter)))
                {
                    word += buffer.at(character_counter);
                    character_counter++;
                    if ( character_counter == buffer.size()){
                        break;
                    }
                }

                for(unsigned int i = 0; i < word.size(); i++)
                {
                    if(isAlphanumeric(word[i])){
                        word[i] = tolower(word[i]);
                    }
                }

                for(unsigned int i = word.size() - 1; i >= 0; i--){
                    if (isExtra(word[i])) {
                        word.pop_back();
                    } else if (isAlphanumeric(word[i])) {
                        break;
                    }

                }

                words[total_words] = word;
                total_words++;
                if(total_words == words_array_size) {
                    realloc<std::string>(&words,words_array_size, words_array_size * 2);
                    words_array_size *= 2;
                    fflush(stdout);
                }

/*                int previous_value = object.get(word);
                if (previous_value == -1) {
                    object.add(word, 1);//Εισαγωγή λεξης στο hashmap
                } else {
                    object.add(word, previous_value + 1);//Εισαγωγη λεξης στο hashmap
                }
*/
                word.copy(string_copy,word.length(),0);//μετατροπει του string σε char* για τις δομες tree και AVL
                string_copy[word.length()] = '\0';

               object_tree.insert_TREE(string_copy);//Εισαγωγη string στην δομη tree
                object_AVL.rootAVL = object_AVL.insert_AVLTREE(string_copy,object_AVL.rootAVL); //Εισαγωγη string στην δομη AVL
            }
            else {
                character_counter++;
            }
        }
    }

    unsigned int iterations = rand() % 200 + 1000;   // Τυχαιος αριθμος απο 1000 μεχρι 1200!

    unsigned long int hashtable_ms_accumulator = 0;  // μετρητης χρονου σε millisecond για το hashtable
    unsigned long int avltree_ms_accumulator = 0;    // μετρητης χρονου σε millisecond για το avl tree
    unsigned long int btree_ms_accumulator = 0;      // μετρητης χρονου σε millisecond για το binary tree
    for(unsigned int i = 0; i < iterations; i++) {

        int word_count;

        std::chrono::time_point<std::chrono::system_clock> start, end; // μεταβλητη χρονου

        unsigned int long random_word_index = rand() % total_words; // τυχαιος αριθμος που μας δινει τυχαιες λεξεις του κειμενου!

        // μετατροπη του string σε char* για τις δομες tree και AVL
        char* string_copy = new char[100];
        words[random_word_index].copy(string_copy,words[random_word_index].length(),0);
        string_copy[words[random_word_index].length()] = '\0';


        // ---- Μέτρηση χρόνου στο Binary Tree ---- //
        start = std::chrono::system_clock::now();
        word_count = object_tree.search_tree(string_copy,object_tree.root);//Ελεγχος αν υπαρχει ενα string μεσα στην δομη tree
        end = std::chrono::system_clock::now();

        std::cout << "Binary Tree | Word : " << words[random_word_index] << ", count : " << word_count << std::endl;
        btree_ms_accumulator += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        // ---------------------------------------- //

        // ---- Μέτρηση χρόνου στο AVL Tree ---- //
        start = std::chrono::system_clock::now();
        word_count = object_AVL.search_tree(string_copy,object_AVL.rootAVL); //Ελεγχος αν υπαρχει ενα string μεσα στην δομη AVL
        end = std::chrono::system_clock::now();
        std::cout << "AVL Tree | Word : " << words[random_word_index] << ", count : " << word_count << std::endl;
        avltree_ms_accumulator += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        // ------------------------------------- //

        // ---- Μέτρηση χρόνου στο Hash Table ---- //

        start = std::chrono::system_clock::now();
//        word_count = object.get(words[random_word_index]);
        end = std::chrono::system_clock::now();

      /*  std::cout << "HashTable | Word : " << words[random_word_index] << ", count : " << word_count << std::endl;
        hashtable_ms_accumulator += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        */// --------------------------------------- //

    }

    std::cout << "Xronos Binary Tree : " << btree_ms_accumulator << "ms" << std::endl;
    std::cout << "Xronos AVL Tree : " << avltree_ms_accumulator << "ms" << std::endl;
    //std::cout << "Xronos Hash Table : " << hashtable_ms_accumulator << "ms" << std::endl;

    file_2.close();

    return 0;
}

