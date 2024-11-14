//-------------------------------------

#include "lab8_dialog.hpp"
#include "lab8_object.hpp"

#include <windows.h>

//-------------------------------------

Dialog::Dialog() {

    m_state = 1;
}

//-------------------------------------

Dialog::~Dialog() {
    //
}

//-------------------------------------

void Dialog::addObject() {

    uint32_t value;

    std::cout << "1. Person\n2. Student\n3. Back\n";
    std::cin >> value;

    if(value > 3)
        throw std::runtime_error("error type not found!");

    else if(value == 3)
        return;

    value--;

    Object* object = value ? new Student() : new Person;
    object->input();

    add(object);
}

//-------------------------------------

int Dialog::execute() {

    Event event;

    while(m_state) {

        pollEvent(event);
        handleEvent(event);
    }

    return m_state;
}

//-------------------------------------

void Dialog::pollEvent(Event& event) {

    system("cls");

    std::string command;
    char code;

    std::cout   << "'+'     - Add element\n"
                << "'-'     - Remove last element\n"
                << "'s'     - Show array\n"
                << "'?<n>'  - Show element. n number element'\n"
                << "'n'     - name object\n"
                << "'l'     - size array\n"
                << "'q'     - Exit\n";

    std::cout << "> ";
    std::cin >> command;

    if(!command.empty())
        code = command[0];

    if(m_commands.find(code) >= 0) {

        event.what = Event::Type::Message;

        switch(code) {
            case '+': event.command = Event::Add;   break;
            case '-': event.command = Event::Pop;   break;
            case 's': event.command = Event::Show;  break;
            case '?': event.command = Event::ShowObject; break;
            case 'n': event.command = Event::NameObject; break;
            case 'l': event.command = Event::Size;  break;
            case 'q': event.command = Event::Exit;  break;
        }

        if(command.size() > 1)
            event.arg = std::atoi(&command[1]);

        return;
    }

    event.what = Event::Type::None;
}

//-------------------------------------

void Dialog::handleEvent(Event& event) {

    if(event.what == Event::Type::Message) {
        switch(event.command) {

            case Event::Add:    addObject();    clearEvent(event); break;
            case Event::Pop:    pop_back();     clearEvent(event); break;
            case Event::Show:   show();         clearEvent(event); break;

            case Event::ShowObject:
                if(event.arg >= this->size()) {
                    std::cerr << "event.arg >= m_size" << std::endl;
                    break;
                }

                (*this)[event.arg]->show();
                clearEvent(event);
                break;

            case Event::Size:
                std::cout << "size: " << this->size() << std::endl;
                break;

            case Event::Exit:
                m_state = 0;
                clearEvent(event);
                break;

            default:
                Vector::handleEvent(event);
                clearEvent(event);
                break;
        }
    }

    if(event.command != Event::Exit)
        system("pause");
}

//-------------------------------------

void Dialog::clearEvent(Event& event) {
    event.what = Event::Type::None;
}

//-------------------------------------
