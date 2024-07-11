#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;
class New_note
{
    string todo;
};
int main()
{
    bool working = true;
    while (working == true)
    {
        system("cls");
        string note, existing_note;
        char enter_key = 10;
        char start_selection;

        cout << "Enter 1 for creating a new todo(list)& 2 for opening the existing todo list and q to exit the app: ";
        start_selection = getch();
        if (start_selection == '1')
        {
            cout << "Creating a new todo list will delete the existing to do list! \a  \n Are you sure ?  : ";
            start_selection = getch();
            ofstream out;
            out.open("todo.txt");
            if (start_selection == '1')
            {
                system("cls");
                cout << "You can start writing your things after completing a line if you press 'q' you will exit the edit mode : " << endl;
                while (getch() != 'q')
                {
                    getline(cin, note);

                    out << note << endl;
                }
                out.close();
            }
        }
        else if (start_selection == '2')
        {
            system("cls");
            ifstream in;
            in.open("todo.txt");

            while (in.eof() != 1)
            {
                getline(in, existing_note);
                cout << existing_note << endl;
            }
            in.close();
            cout << "Press 1 again if you want to add something to the note ! ";

            if (getch() == '1')
            {
                system("cls");
                cout << "Start Entering the things you want to add press q to exit :"<<endl;
                while (getch() != 'q')
                {
                    getline(cin, note);
                    ofstream out;
                out.open("todo.txt", std::ios::app);
                out << note << endl;
                 out.close();
                }
                
                

            }}
            else if (start_selection == 'q' || start_selection == 'Q')
            {
                working = false;
            }
            
            else
            {
                cout << "Invalid argument entered : ";
            }
        }

        return 0;
    }
