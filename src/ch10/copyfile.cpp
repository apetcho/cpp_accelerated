#include<fstream>
#include<string>

int main(){
    std::ifstream infile("input");
    std::ofstream outfile("output");

    std::string text;

    while(std::getline(infile, text)){
        outfile << text << std::endl;
    }

    return EXIT_SUCCESS;
}
