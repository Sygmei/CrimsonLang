#include "Lexer.hpp"

Lexer::Lexer()
{

}

Lexer& Lexer::addRule(std::string match, std::string tokenType, int rulePriority)
{
    matchList[match] = std::pair<TokenType*, int>(new TokenType(tokenType), rulePriority);
    return *this;
}

std::vector<Token> Lexer::generate(std::string path)
{
    std::vector<Token> programTokens;
    std::ifstream useFile;
    useFile.open(path);
    std::string currentLine;
    if (useFile.is_open())
    {
        while (getline(useFile, currentLine))
        {
            SegmentPile<TokenType*> sPile;
            std::cout << "Line : " << currentLine << std::endl;
            for (std::pair<std::string, std::pair<TokenType*, int>> regMatch : matchList)
            {
                std::cout << "Testing rule : '" << regMatch.first << "'" << std::endl;
                std::regex re(regMatch.first);
                std::smatch match;
                std::regex_search(currentLine, match, re);
                std::string::const_iterator searchStart(currentLine.cbegin());
                int currentIndex = 0;
                while (std::regex_search(searchStart, currentLine.cend(), match, re))
                {
                    std::cout << ( searchStart == currentLine.cbegin() ? "" : " " ) << match[0];
                    searchStart += match.position() + match.length();
                    currentIndex += match.position();
                    int regSize = std::string(match[0]).size();
                    std::cout << "Matched : '" << std::string(match[0]) << "' at pos " << currentIndex << std::endl;
                    sPile.allocate(currentIndex, regSize, regMatch.second.first, regMatch.second.second);
                    sPile.print();
                    currentIndex += match.length();
                }
            }
            
        }
    }
    useFile.close();
    std::cout << "Generation over" << std::endl;
    return programTokens;
}
