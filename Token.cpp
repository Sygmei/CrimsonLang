#include "Token.hpp"

Token::Token(TokenType type) : type(type), value("")
{
    this->type = type;
}

TokenValue& Token::getValue()
{
    return this->value;
}

void Token::setValue(TokenValue& value)
{
    this->value = value;
}

TokenType Token::getType()
{
    return this->type;
}

Token& Token::addChild(Token& child)
{
    this->children.push_back(child);
}

std::vector<Token>& Token::getChildren()
{
    return this->children;
}