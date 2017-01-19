#pragma once

#include <string>
#include <iostream>

#include "Functions.hpp"

class TokenValue
{
    private:
        std::string data;
        std::string datatype;
    public:
        TokenValue(std::string datatype, std::string value);
        TokenValue(std::string value);
        TokenValue(int value);
        TokenValue(double value);
        TokenValue(bool value);
        std::string returnData();
        void set(int value);
        void set(double value);
        void set(std::string value);
        void set(bool value);
        std::string getDataType();
        template <class T> T get() {}
};

template <> inline int TokenValue::get() {
    if (this->datatype == "int") return std::stoi(this->data);
    else std::cout << "<Error:TokenValue>[getData] : " << this->data << " is not a <int> TokenValue (" << this->datatype << ")" << std::endl;
}

template <> inline double TokenValue::get() {
    if (this->datatype == "float") return std::stod(this->data);
    else std::cout << "<Error:TokenValue>[getData] : " << this->data << " is not a <float> TokenValue (" << this->datatype << ")" << std::endl;
}

template <> inline bool TokenValue::get() {
    if (this->datatype == "bool") return (this->data == "True") ? true : false;
    else std::cout << "<Error:TokenValue>[get] : " << this->data << " is not a <bool> TokenValue (" << this->datatype << ")" << std::endl;
}

template <> inline std::string TokenValue::get() {
    if (this->datatype == "string") return this->data;
    else std::cout << "<Error:TokenValue>[get] : " << this->data << " is not a <string> TokenValue (" << this->datatype << ")" << std::endl;
}