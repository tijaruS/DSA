#include <bits/stdc++.h>
#include <cctype>
#include <cstring>
int isVowel(char ch) {
    char vowel[6] = "aeiou";
    for (int i = 0; vowel[i]; i++) {
        if (vowel[i] == ch)
            return 1;
    }
    return 0;
}

int main() {
    char str[10010];

    freopen("stringProcessingInput.txt", "r", stdin);
    strcpy(str, "");

    bool first =
        true; // technique to differentiate the first line with the other line
    bool prevDash = false,
         thisDash = false; // to differentiate whether the previous line
                           // contains a dash or not
    while (1) {
        char line[110];
        fgets(line, 100, stdin);
        line[(int)strlen(line) - 1] = 0;
        if (strncmp(line, ".......", 7) == 0)
            break;
        if (line[(int)strlen(line) - 1] == '-') {
            line[(int)strlen(line) - 1] = 0;
            thisDash = true;

        } else
            thisDash = false;
        if (first == false && prevDash == false) {
            strcat(str, " ");
        }
        first = false;
        strcat(str, line);
        prevDash = thisDash;
    }
    freopen("stringProcessingOutput.txt", "w", stdout);

    std::cout << str << std::endl;

    int pos, digits, alpha, vowel, consonants;

    for (int i = digits = alpha = vowel = consonants = 0; str[i]; i++) {
        str[i] = std::tolower(str[i]);
        digits += isdigit(str[i]) ? 1 : 0;
        alpha += isalpha(str[i]) ? 1 : 0;

        vowel += isVowel(str[i]);
    }
    consonants = alpha - vowel;
    std::cout << str << std::endl;
    std::cout << "Digits: " << digits << std::endl
              << "Vowels: " << vowel << std::endl
              << "Consonants: " << consonants << std::endl;
    char *p;

    std::cout << str << std::endl;
    std::vector<std::string> tokens;
    std::map<std::string, int> freq;
    char test[10010];
    strcpy(test, str);

    for (p = strtok(test, " ."); p; p = strtok(NULL, " .")) {
        tokens.push_back(p);
        freq[p]++;
    }

    std::sort(tokens.begin(), tokens.end());
    std::cout << tokens[0].c_str() << std::endl
              << tokens[(int)tokens.size() - 1].c_str() << std::endl;

    int hascs3233 = (strstr(str, "cs3233") != NULL);
    std::cout << "has: " << hascs3233 << std::endl;
    std::cout << "Is there cs3233 in this string? "
              << (hascs3233 ? "Yes" : "No") << std::endl;
    char c;
    while (scanf("%c", &c), c != '\n') {
    }

    return 0;
}
