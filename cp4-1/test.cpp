#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

int main() {
    char str[10010];
    freopen("stringProcessingInput.txt", "r", stdin);
    strcpy(str, "");
    bool first = true;
    bool prevDash = false;
    bool thisDash = false;

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
        if (first == false && prevDash == false)
            strcat(str, " ");
        first = false;
        strcat(str, line);
        prevDash = thisDash;
    }
    freopen("test.txt", "w", stdout);
    std::cout << str << std::endl;

    return 0;
}
