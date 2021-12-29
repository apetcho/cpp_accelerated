#include<iostream>
#include<fstream>
#include<string>


// ---
int main(int argc, char **argv){
    int fail_count = 0;

    // -- for each file in the input list
    for(int i=1; i < argc; ++i){
        std::ifstream stream(argv[i]);
        // if it exists, write its contents, otherwise generate an error message
        if(stream){
            std::string text;
            while(std::getline(stream, text)){ std::cout << text << std::endl; }
        }else{
            std::cerr << "cannot open file " << argv[i] << std::endl;
            ++fail_count;
        }
    }

    return fail_count;
}
