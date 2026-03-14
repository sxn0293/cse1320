#include <stdio.h>

extern void loadFromFile();
extern void saveToFile();
extern void mainMenu();

int main() {
    loadFromFile();
    mainMenu();
    saveToFile();
    return 0;
}
