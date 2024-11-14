//-------------------------------------

#include <iostream>
#include <windows.h>
#include <filesystem>

#include "lab10_io_stream.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

const char* msg = "1.Create elements\n2.Show elements\n3.Remove elements\n4.Increase time\n5.Add elements start k\n6.Exit";

//-------------------------------------

enum Menu {
    Create,
    Show,
    Remove,
    Increase,
    Add,

    Exit
};

//-------------------------------------

void create(std::string& path) {

    std::cout << "enter path:";
    std::cin >> path;

    int n;
    std::cout << "enter n files:";
    std::cin >> n;

    std::ios_base::openmode mode = std::ios::out;
    if(std::filesystem::exists(path)) {
        char yesno;
        std::cout << "The file exists, should I delete the contents of the file? [y/n]:";
        std::cin >> yesno;

        if(yesno == 'n')
            mode = std::ios::app;

    }

    IOTime::write(path.c_str(), n, mode);
}

//-------------------------------------

void show(std::string& path) {
    std::cout << "enter path:";
    std::cin >> path;

    IOTime::read(path.c_str());
    system("pause");
}

//-------------------------------------

void remove(std::string& path) {
    Time time;

    std::cout << "enter path:";
    std::cin >> path;

    std::cout << "Enter the time to delete all entries:\n";
    std::cin >> time;

    std::cout << "removed: " << IOTime::remove(path.c_str(), time) << std::endl;
    system("pause");
}

//-------------------------------------

void increase(std::string& path) {
    Time    mod,
            time;

    std::cout << "enter path:";
    std::cin >> path;

    std::cout << "time for mod:\n";
    std::cin >> mod;

    std::cout << "increase by:\n";
    std::cin >> time;

    std::cout << "mod time: " << IOTime::increase_specified_time(path.c_str(), mod, time) << std::endl;
    std::cout << "show\n";
    IOTime::read(path.c_str());

    system("pause");
}

//-------------------------------------

void add(std::string& path) {

    std::cout << "enter path:";
    std::cin >> path;

    int n, shift;

    std::cout << "enter number elements:";
    std::cin >> n;

    std::cout << "enter start elements add:";
    std::cin >> shift;

    IOTime::add(path.c_str(), n, shift);

    std::cout << "show\n";
    IOTime::read(path.c_str());
    system("pause");
}

//-------------------------------------

int main() {

    bool isLoop = true;
    int num = 0;

    std::string path;

    while(isLoop) {

        std::cout << msg << std::endl;

        std::cin >> num;
        switch((Menu)(num-1)) {

            case Menu::Create:      create(path);   break;
            case Menu::Show:        show(path);     break;
            case Menu::Remove:      remove(path);   break;
            case Menu::Increase:    increase(path); break;
            case Menu::Add:         add(path);      break;

            case Menu::Exit:
                isLoop = false;
                break;
        }

        system("cls");
    }


    return 0;
}

//-------------------------------------
