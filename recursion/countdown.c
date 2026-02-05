#include <stdio.h>
void countdown(int n);

int main() {
    countdown(100);
    return 0;
}

void countdown(int n) {
    if (n > 0) {
        printf("%d " , n);
        countdown(n - 1);
    }
}