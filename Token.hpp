#pragma once

#include <string>

#include "TokenValue.hpp"
#include "TokenType.hpp"

class Token
{
    private:
        std::vector<Token> children;
        TokenType type;
        TokenValue value;
    public:
        Token(TokenType type);
        TokenValue& getValue();
        void setValue(TokenValue& value);
        TokenType getType();
        Token& addChild(Token& child);
        std::vector<Token>& getChildren();
};
