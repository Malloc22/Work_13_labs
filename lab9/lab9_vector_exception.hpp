//-------------------------------------

#ifndef LAB9_VECTOR_EXCEPTION_HPP_INCLUDED
#define LAB9_VECTOR_EXCEPTION_HPP_INCLUDED

//-------------------------------------

#include <exception>

//-------------------------------------

class VectorException : public std::exception {
public:

    enum ErrorCode {
        Index = 0,
        Remove,
        Shift,
    };

public:

    explicit VectorException(const std::string& message, ErrorCode code) {
        m_message = message;
        m_code = code;
    }

    virtual ~VectorException() noexcept {  }

    virtual const char* what() const noexcept {
        return m_message.c_str();
    }

    ErrorCode getCode() noexcept {
        return m_code;
    }

protected:

    std::string m_message;

    ErrorCode m_code;
};

//-------------------------------------

#endif // LAB9_VECTOR_EXCEPTION_HPP_INCLUDED

//-------------------------------------
