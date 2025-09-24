#include <iostream>
#include <cmath>
#include <vector>
#include <string>



std::vector<std::string> read_words(int n){
    std::vector<std::string> words;
    std::string word;
    
    std::getline(std::cin, word, '\n'); // get rid of the previous line \n
    for(int i=0; i<n-1; i++){
        std::getline(std::cin, word, ' '); 
        words.push_back(word);
    }
    if(n != 0){
        std::getline(std::cin, word, '\n');
        words.push_back(word);
    } 
    return words;
}


int main(){
    int n;
    char _;
    std::cin >> n;
    auto words = read_words(n);

    int m;
    std::cin >> m;
    auto sentence = read_words(m);

    for(int i=0; i<m; i++){
        bool in_allowed = false;
        for(int j=0; j<n; j++){
            if(sentence.at(i) == words.at(j)){
                in_allowed = true;
            }
        }
        if(!in_allowed){
            std::cout << sentence.at(i) << std::endl;
            break; 
        }
    }
    

    return 0;
}