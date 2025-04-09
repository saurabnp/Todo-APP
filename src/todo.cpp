#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

class TodoApp {
private:
    string note, existing_note;
    bool working;

    void clearScreen() {
        system("cls");
    }

    void createNewTodo() {
        clearScreen();
        cout << "Creating a new todo list will delete the existing list! Are you sure? Press 1 to confirm: ";
        char confirm = getch();
        if (confirm == '1') {
            ofstream out("data/todo.txt");
            clearScreen();
            cout << "Enter your tasks. Press 'q' to exit edit mode.\n";
            while (getch() != 'q') {
                getline(cin, note);
                out << note << endl;
            }
            out.close();
        }
    }

    void openTodo() {
        clearScreen();
        ifstream in("data/todo.txt");
        while (getline(in, existing_note)) {
            cout << existing_note << endl;
        }
        in.close();

        cout << "\nPress 1 to add more to your list: ";
        if (getch() == '1') {
            clearScreen();
            cout << "Start entering your tasks. Press 'q' to exit.\n";
            while (getch() != 'q') {
                getline(cin, note);
                ofstream out("data/todo.txt", ios::app);
                out << note << endl;
                out.close();
            }
        }
    }

public:
    TodoApp() : working(true) {}

    void run() {
        while (working) {
            clearScreen();
            cout << "1. Create New Todo\n2. View/Edit Existing Todo\nq. Quit\nSelect an option: ";
            char selection = getch();
            switch (selection) {
            case '1':
                createNewTodo();
                break;
            case '2':
                openTodo();
                break;
            case 'q':
            case 'Q':
                working = false;
                break;
            default:
                cout << "\nInvalid input. Press any key to try again.";
                getch();
            }
        }
    }
};

int main() {
    TodoApp app;
    app.run();
    return 0;
}