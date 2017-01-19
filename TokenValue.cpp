#include "TokenValue.hpp"

TokenValue::TokenValue(std::string datatype, std::string value)
{
    this->datatype = datatype;
    this->data = value;
    if (this->datatype == "string") this->data = replaceString(this->data, "\"", "");
}

TokenValue::TokenValue(std::string value)
{
    this->datatype = "string";
    this->set(value);
}

TokenValue::TokenValue(int value)
{
    this->datatype = "int";
    this->set(value);
}

TokenValue::TokenValue(double value)
{
    this->datatype = "float";
    this->set(value);
}

TokenValue::TokenValue(bool value)
{
    this->datatype = "bool";
    this->set(value);
}

void TokenValue::set(int value) 
{
    if (this->datatype == "int") this->data = std::to_string(value);
    else std::cout << "<Error:TokenValue>[set] : " << this->data << " is not a <bool> TokenValue (" << this->datatype << ")" << std::endl;
}

void TokenValue::set(double value) 
{
    if (this->datatype == "float") this->data = std::to_string(value);
    else std::cout << "<Error:TokenValue>[set] : " << this->data << " is not a <float> TokenValue (" << this->datatype << ")" << std::endl;
}

void TokenValue::set(std::string value) 
{
    if (this->datatype == "string") this->data = value;
    else std::cout << "<Error:TokenValue>[set] : " << this->data << " is not a <string> TokenValue (" << this->datatype << ")" << std::endl;
}

void TokenValue::set(bool value) 
{
    if (this->datatype == "bool") 
    {
        if (value) this->data = "True";
        else this->data = "False";
    }
    else std::cout << "<Error:TokenValue>[set] : " << this->data << " is not a <bool> TokenValue (" << this->datatype << ")" << std::endl;
}

std::string TokenValue::returnData() 
{
    if (this->datatype != "string") return this->data;
    else return "\"" + this->data + "\"";
}

std::string TokenValue::getDataType() 
{
    return this->datatype;
}