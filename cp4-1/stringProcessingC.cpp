#include <bits/stdc++.h>

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
    return 0;
}
