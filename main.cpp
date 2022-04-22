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
    // ������������ seed ��� ��� srand
    srand(time(NULL));


//    HashTable object;//����������� ��� ������ HashTable
    tree object_tree;//����������� ��� ������ tree
    AVL_tree object_AVL;//����������� ��� ������ AVL

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
        char* string_copy = new char[100];//���������� ��� string �� ��� �������� �� tree ��� AVL

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
                    object.add(word, 1);//�������� ����� ��� hashmap
                } else {
                    object.add(word, previous_value + 1);//�������� ����� ��� hashmap
                }
*/
                word.copy(string_copy,word.length(),0);//���������� ��� string �� char* ��� ��� ����� tree ��� AVL
                string_copy[word.length()] = '\0';

               object_tree.insert_TREE(string_copy);//�������� string ���� ���� tree
                object_AVL.rootAVL = object_AVL.insert_AVLTREE(string_copy,object_AVL.rootAVL); //�������� string ���� ���� AVL
            }
            else {
                character_counter++;
            }
        }
    }

    unsigned int iterations = rand() % 200 + 1000;   // ������� ������� ��� 1000 ����� 1200!

    unsigned long int hashtable_ms_accumulator = 0;  // �������� ������ �� millisecond ��� �� hashtable
    unsigned long int avltree_ms_accumulator = 0;    // �������� ������ �� millisecond ��� �� avl tree
    unsigned long int btree_ms_accumulator = 0;      // �������� ������ �� millisecond ��� �� binary tree
    for(unsigned int i = 0; i < iterations; i++) {

        int word_count;

        std::chrono::time_point<std::chrono::system_clock> start, end; // ��������� ������

        unsigned int long random_word_index = rand() % total_words; // ������� ������� ��� ��� ����� ������� ������ ��� ��������!

        // ��������� ��� string �� char* ��� ��� ����� tree ��� AVL
        char* string_copy = new char[100];
        words[random_word_index].copy(string_copy,words[random_word_index].length(),0);
        string_copy[words[random_word_index].length()] = '\0';


        // ---- ������� ������ ��� Binary Tree ---- //
        start = std::chrono::system_clock::now();
        word_count = object_tree.search_tree(string_copy,object_tree.root);//������� �� ������� ��� string ���� ���� ���� tree
        end = std::chrono::system_clock::now();

        std::cout << "Binary Tree | Word : " << words[random_word_index] << ", count : " << word_count << std::endl;
        btree_ms_accumulator += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        // ---------------------------------------- //

        // ---- ������� ������ ��� AVL Tree ---- //
        start = std::chrono::system_clock::now();
        word_count = object_AVL.search_tree(string_copy,object_AVL.rootAVL); //������� �� ������� ��� string ���� ���� ���� AVL
        end = std::chrono::system_clock::now();
        std::cout << "AVL Tree | Word : " << words[random_word_index] << ", count : " << word_count << std::endl;
        avltree_ms_accumulator += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        // ------------------------------------- //

        // ---- ������� ������ ��� Hash Table ---- //

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

