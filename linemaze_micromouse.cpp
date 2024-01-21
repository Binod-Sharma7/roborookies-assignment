#include <stdio.h>
#include <string.h>

int hasObstacle(char *sensorData) {
    for (int index = 0; index < strlen(sensorData); index++) {
        if (sensorData[index] == 'O') {
            return 1;
        }
    }
    return 0;
}

void navigatePath(char *robotInstructions) {
    while (hasObstacle(robotInstructions) == 1) {
        for (int i = 0; i < strlen(robotInstructions); i++) {
            if (robotInstructions[i] == 'F' && robotInstructions[i + 1] == 'O' && robotInstructions[i + 2] == 'R') {
                memmove(&robotInstructions[i], &robotInstructions[i + 3], strlen(robotInstructions) - i);
                robotInstructions[strlen(robotInstructions) - 3] = 'B';
                break;
            } else if (robotInstructions[i] == 'B' && robotInstructions[i + 1] == 'O' && robotInstructions[i + 2] == 'B') {
                memmove(&robotInstructions[i], &robotInstructions[i + 3], strlen(robotInstructions) - i);
                robotInstructions[strlen(robotInstructions) - 3] = 'L';
                break;
            }
        }
    }
    printf("Modified Instructions: %s\n", robotInstructions);
}

int main() {
    char instructions[] = "FORBOBFOR";
    navigatePath(instructions);
    return 0;
}
