#include <stdio.h>
#include <string.h>

int robo(char *intake) {
    for (int x = 0; x < strlen(intake); x++) {
        if (intake[x] == 'U') {
            return 1;
        }
    }
    return 0;
}

void shortestPath(char *input) {
    while (robo(input) == 1) {
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] == 'S' && input[i + 1] == 'U' && input[i + 2] == 'R') {
                memmove(&input[i], &input[i + 3], strlen(input) - i);
                input[strlen(input) - 3] = 'L';
                break;
            } else if (input[i] == 'R' && input[i + 1] == 'U' && input[i + 2] == 'R') {
                memmove(&input[i], &input[i + 3], strlen(input) - i);
                input[strlen(input) - 3] = 'S';
                break;
            }
        }
    }
    printf("%s", input);
}

int main() {
    char input[] = "SRURSUR";
    shortestPath(input);
    return 0;
}
