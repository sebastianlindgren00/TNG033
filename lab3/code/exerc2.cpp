/*******************************
 * Lab 3: exercise 1            *
 * Frequency table of words     *
 *******************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>   //std::pair
#include <fstream>
#include <cassert>
#include <algorithm> //ADDED
#include <iterator> // ADDED


// A function to test the output of the program
void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n);

/***************************
 * Main function           *
 **************************/

int main() {
    //std::cout << "Text file: ";
    std::string file_name = "uppgift_kort.txt"; //ÄNDRA TILLBAKS SENARE !!!!!!!!!!!!!!!!!
    //std::cin >> file_name;

    std::ifstream in_File{"../code/" + file_name};  // modify path, if needed

    if (!in_File) {
        std::cout << "Could not open input file!!\n";
        return 0;
    }

    std::map<std::string, int> table;
    int counter{0};  // to count total number of words read from the input file

    //ADD CODE to build table
    std::string myString; //For every word
    char c; //For buidling up the words

    if (in_File.is_open()) { //Måste kolla så den ä öppen
        while (in_File){ //Stega igenom filen tecken för tecken
            c = std::tolower(in_File.get()); //ta ett steg och ta där första tecknet
            if (isalpha(c) || c == '\'' && c != ' ') { //ifall det är en bokstav eller apostrof och inte mellanrum så..
                myString += c; //lägg till tecknet på ordet
            }
            else if (myString != "") { //Om det inte är nåt av det och myString inte heller är helt tomt
                auto it = table.find(myString); //Kolla om ordet som är bildat redan finns i table

                if (it != table.end()) { table[myString]++; } //Addera siffran t de redan befitliga ordet
                else { table.insert({ myString , 1 }); } //Lägg till nytt ord

                counter++; //+1 ord
                myString = "";//Reset för att börja bilda nästa ord
            }
        }
    }

    std::vector<std::pair<std::string, int>> freq;

    //This works if you use #inlcude <iterator>
    std::copy(table.begin(), table.end(), std::back_inserter(freq));

    std::sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second > b.second; //sortera beroende på största int
        }
        return a.first < b.first; //alfabetisk ordning om de har samma second värde
    });

    /* ************** Testing **************** */

    test(table, freq, "uppgift_kort.txt", counter); //BYT TILL file_name SEN ISTÄLLET FÅR TEXTEN
}


/*******************************
 * Test implementation         *
 * Do not modify               *
 *******************************/

void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n) {

    std::ifstream file{"../code/out_" + file_name}; //modify path, if needed

    // Test if stream is in good state
    assert(bool(file) == true);

    std::map<std::string, int> result1;
    std::string word;
    int counter{0};
    int total{0};

    // load expected frequency table sorted alphabetically
    while (file >> word >> counter && counter > 0) {
        result1[word] = counter;
        total += counter;
    }

    /*
     * uppgift1_kort: 69 words
     * uppgift1.txt: 1063 words
     */

    assert(total == n);    // test if total number of words is correct
    assert(t == result1);  // test if map/table contents are correct

    std::vector<std::pair<std::string, int>> result2;

    // load expected frequency table sorted by frequence
    while (file >> word >> counter) {
        result2.push_back(std::pair{word, counter});
    }
    assert(v == result2);  // test if vector contents are correct

    std::cout << "\nPassed all tests successfully!!\n";
}