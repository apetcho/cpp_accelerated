#include<iostream>
#include<string>

// --- MAIN DRIVER ---
int main(){
    std::string text;
    while(std::cin >> text){
        std::cout << text << std::endl;
    }
    return EXIT_SUCCESS;
}
