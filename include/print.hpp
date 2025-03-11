#include <fstream>
#include <iostream>
#include <string>
void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ofstream& out= std::cout);
