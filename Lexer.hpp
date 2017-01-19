#pragma once

#include <map>
#include <string>
#include <fstream>
#include <regex>

#include "Token.hpp"
#include "TokenType.hpp"
#include "SegmentPile.hpp"

class Lexer
{
    private:
        std::map<std::string, std::pair<TokenType*, int>> matchList;
    public:
        Lexer();
        Lexer& addRule(std::string match, std::string tokenType, int rulePriority = 1);
        std::vector<Token> generate(std::string path);
};