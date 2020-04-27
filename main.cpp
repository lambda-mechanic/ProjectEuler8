#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
//function prototype;
std::string getPath();

int main(){
    // create read-only filestream
    std::ifstream file;
    // string will hold filepath
    std::string filePath;
    filePath = getPath() + "\\pe_8.txt";
    file.open(filePath);
    // will hold 13 digits being tested
    int long long input[13];
    int long long num = 0;
    int long long constant = 1;
    int long long product = 0;
    std::string line = "";
    // initialize arrays:
    for(int i = 1; i < 14; i++){
        input[13] = 1;
    }
    //substr
    std::string sub_str= "";
    //substr length
    const int strlength = 13;
    // get number:
    if(file.is_open()){
        // get num, is all on one line
        std::getline(file, line);
        //get 13 digit substring
        for(int i = 0; i < (1000 - strlength); i++){
            // set substring to 13 digits, starting from digit indexes 0-12
            sub_str = line.substr(i, strlength);
            // conv str to long long
            num = std::stoll(sub_str);
            // set each digit to a place in array(backwards from 13th from len(strlength))
            for(int j=0; j < 13; j++){
                input[j] = num % 10;
                num /= 10;
                // create product by multiplying each digit by constant:
                constant *= input[j];
            }
            // if new greatest product, set product = constant, reset constant
            if(constant > product){
                    product = constant;
                    constant = 1;
                }
            // otherwise, simply reset constant
            else {
                constant = 1;
            }
        }
        file.close();
    }
    else {
        std::cout << "File did not open" << std::endl;
    }
    std::cout << product << std::endl;
    return 0;
}
// source: https://stackoverflow.com/questions/875249/how-to-get-current-directory
// WARNING: Windows specific code for file retrieval:
std::string getPath(){
    // character array with MAX_PATH as length
    char buffer[MAX_PATH];
    // Gets current executable directory
    GetModuleFileName(NULL, buffer, MAX_PATH);
    // create string::size_type to hold length of filepath string
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    // return substring which includes filepath
    return std::string(buffer).substr(0, pos);

}
