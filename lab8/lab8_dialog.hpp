//-------------------------------------

#ifndef DIALOG_HPP_INCLUDED
#define DIALOG_HPP_INCLUDED

//-------------------------------------

#include "lab8_vector.hpp"

//-------------------------------------

struct Event {

    enum Command {
        Add = 0,
        Pop,
        Show,
        ShowObject,
        NameObject,
        Size,
        Exit
    };

    enum Type {
        None = 0,
        Message
    };

    Type    what;
    Command command;
    size_t arg;
};

//-------------------------------------

class Dialog : public Vector {
public:

    Dialog();
    ~Dialog();

    int execute();

    void pollEvent(Event& event);

    void handleEvent(Event& event);
    void clearEvent(Event& event);

private:

    int m_state;

    const std::string m_commands = "+-s?nlq";

    void addObject();
};

//-------------------------------------

#endif // DIALOG_HPP_INCLUDED

//-------------------------------------
