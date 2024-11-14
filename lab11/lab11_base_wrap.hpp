//-------------------------------------

#ifndef LAB11_BASE_WRAP_HPP_INCLUDED
#define LAB11_BASE_WRAP_HPP_INCLUDED

//-------------------------------------

template <class T>
class BaseWrap {
public:

    //-------------------------------------

    virtual void fillRandom(size_t max, std::function<T()> function) = 0;

    //-------------------------------------

    virtual T pushFrontMaxElement() = 0;

    //-------------------------------------

    virtual T popMinElement() = 0;

    //-------------------------------------

    virtual void print() = 0;

    //-------------------------------------

};

//-------------------------------------

#endif // LAB11_BASE_WRAP_HPP_INCLUDED

//-------------------------------------
