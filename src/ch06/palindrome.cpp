#include<algorithm>
#include<cctype>
#include<iostream>
#include<string>

bool is_palindrome(const std::string& word){
    return std::equal(word.begin(), word.end(), word.rbegin());
}

int main(){
    std::string word;
    while(std::cin >> word){
        if(is_palindrome(word)){
            std::cout << word << " is a palindrome" << std::endl;
        }else{
            std::cout << word << " is not a palindrome" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
