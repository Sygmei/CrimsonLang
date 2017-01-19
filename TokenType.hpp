#pragma once

#include <string>

class TokenType
{
    private:
        std::string tokenType;
    public:
        TokenType(std::string tokenType);
        std::string getType();
};