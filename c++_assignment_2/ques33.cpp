#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
// Global game difficulty level
int level = 1;
// Nested namespace: Engine::Audio
namespace Engine {
    namespace Audio {
        void playSound(string name) {
            cout << "Playing: " << name << endl;
        }
    }
}
int main() {
    int R, C;
    // Read rows and columns
    cout << "Enter number of rows: ";
    cin >> R;
    cout << "Enter number of columns: ";
    cin >> C;
    // Allocate outer array
    int** gameMap = new int*[R];
    // Allocate each row
    for (int i = 0; i < R; i++) {
        gameMap[i] = new int[C];
    }
    // Seed random number generator
    srand(time(0));
    // Fill the map using random tile types
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            gameMap[i][j] = rand() % 5;
        }
    }
    // Display the map
    cout << "\n===== GAME MAP ("<< R << " x " << C << ") =====" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << gameMap[i][j] << " ";
        }
        cout << endl;
    }
    // Count each tile type
    int count[5] = {0};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            count[gameMap[i][j]]++;
        }
    }
    // Display tile counts
    cout << "\nTile Count:" << endl;
    cout << "Grass    : " << count[0] << endl;
    cout << "Water    : " << count[1] << endl;
    cout << "Mountain : " << count[2] << endl;
    cout << "Forest   : " << count[3] << endl;
    cout << "Dungeon  : " << count[4] << endl;
    // Optional Scope Resolution Bonus
    int level = 5;   // Local player level
    cout << "\n===== SCOPE RESOLUTION =====" << endl;
    cout << "Local Player Level  : " << level << endl;
    cout << "Global Game Level   : " << ::level << endl;
    // Nested namespace function
    cout << "\n===== AUDIO =====" << endl;
    Engine::Audio::playSound("sword_clash");
    // Deallocate the 2D array
    for (int i = 0; i < R; i++) {
        delete[] gameMap[i];
    }
    delete[] gameMap;
    cout << "\nGame map memory released successfully." << endl;
    return 0;
}