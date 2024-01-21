#include <stdio.h>
#include <math.h>

void drawCircle(float radius) {
    for (float y = -radius; y <= radius; y++) {
        for (float x = -radius; x <= radius; x++) {
            
            if (x * x + y * y <= radius * radius) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    float radius;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    drawCircle(radius);

    return 0;
}
