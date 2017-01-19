#include "TokenType.hpp"

TokenType::TokenType(std::string tokenType)
{
    this->tokenType = tokenType;
}

std::string TokenType::getType()
{
    return tokenType;
}