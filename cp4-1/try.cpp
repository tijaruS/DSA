#include <bits/stdc++.h>
#include <cstring>

int main() {
    char str[10010];

    freopen("stringProcessingInput.txt", "r", stdin);
    strcpy(str, "");
    int first = true;
    int thisDash = false, prevDash = false;

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
        strcat(str, line);
        first = false;
        prevDash = thisDash;
    }
    freopen("tryOutput.txt", "w", stdout);
    std::cout << str << std::endl;

    return 0;
}
