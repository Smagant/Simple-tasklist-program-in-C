#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> v{ "one", "two", "three" };
    std::ofstream outFile("my_file.txt");
    // the important part
    for (const auto &e : v) outFile << e << "\n";
}
