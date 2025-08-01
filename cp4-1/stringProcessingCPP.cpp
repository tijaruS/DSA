#include <bits/stdc++.h>

int main() {
    std::ifstream inFile("stringProcessingInput.txt");
    std::ofstream outFile("stringProcessingCPPOutput.txt");

    if (!inFile || !outFile) {
        std::cerr << "Error opening file\n";
        return 1;
    }
    std::string final;
    std::string line;
    bool first = true;
    bool prevDash = false;
    while (std::getline(inFile, line)) {
        if (line.rfind(".......", 0) == 0)
            break;
        bool thisDash = false;
        if (!line.empty() && line.back() == '-') {
            line.pop_back();
            thisDash = true;
        }
        if (!first && !prevDash) {
            final += " ";
        }
        final += line;
        first = false;
        prevDash = thisDash;
    }
    outFile << final << std::endl;

    return 0;
}
