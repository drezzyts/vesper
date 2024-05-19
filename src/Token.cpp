#include "Token.hpp"

std::string Token::getTokenTypeName()
{
    switch (this->type)
    {
        case TokenType::LEFT_PAREN: return "Left Parenthesis";
        case TokenType::RIGHT_PAREN: return "Right Parenthesis";
        case TokenType::LEFT_BRACE: return "Left Brace";
        case TokenType::RIGHT_BRACE: return "Right Brace";
        case TokenType::COMMA: return "Comma";
        case TokenType::DOT: return "Dot";
        case TokenType::MINUS: return "Minus";
        case TokenType::PLUS: return "Plus";
        case TokenType::SEMICOLON: return "Semicolon";
        case TokenType::SLASH: return "Slash";
        case TokenType::STAR: return "Star";
        case TokenType::BANG: return "Bang";
        case TokenType::BANG_EQUAL: return "Bang Equal";
        case TokenType::EQUAL: return "Equal";
        case TokenType::EQUAL_EQUAL: return "Equal Equal";
        case TokenType::GREATER: return "Greater";
        case TokenType::GREATER_EQUAL: return "Greater Equal";
        case TokenType::LESS: return "Less";
        case TokenType::LESS_EQUAL: return "Less Equal";
        case TokenType::IDENTIFIER: return "Identifier";
        case TokenType::CHAR: return "Character";
        case TokenType::STRING: return "String";
        case TokenType::INTEGER: return "Integer";
        case TokenType::FLOAT: return "Float";
        case TokenType::AND: return "And";
        case TokenType::CLASS: return "Class";
        case TokenType::ELSE: return "Else";
        case TokenType::FALSE: return "False";
        case TokenType::FUN: return "Function";
        case TokenType::FOR: return "For";
        case TokenType::IF: return "If";
        case TokenType::NIL: return "Nil";
        case TokenType::OR: return "Or";
        case TokenType::PUTS: return "Puts";
        case TokenType::RETURN: return "Return";
        case TokenType::SUPER: return "Super";
        case TokenType::SELF: return "Self";
        case TokenType::TRUE: return "True";
        case TokenType::LET: return "Let";
        case TokenType::WHILE: return "While";
        case TokenType::EOF_T: return "End of File";
        default: return "Invalid token";
    }
}

TokenType Token::getKeywordType(std::string keyword) {
    if (keyword == "and") {
        return TokenType::AND;
    } else if (keyword == "class") {
        return TokenType::CLASS;
    } else if (keyword == "else") {
        return TokenType::ELSE;
    } else if (keyword == "false") {
        return TokenType::FALSE;
    } else if (keyword == "fun") {
        return TokenType::FUN;
    } else if (keyword == "for") {
        return TokenType::FOR;
    } else if (keyword == "if") {
        return TokenType::IF;
    } else if (keyword == "nil") {
        return TokenType::NIL;
    } else if (keyword == "or") {
        return TokenType::OR;
    } else if (keyword == "puts") {
        return TokenType::PUTS;
    } else if (keyword == "return") {
        return TokenType::RETURN;
    } else if (keyword == "super") {
        return TokenType::SUPER;
    } else if (keyword == "self") {
        return TokenType::SELF;
    } else if (keyword == "true") {
        return TokenType::TRUE;
    } else if (keyword == "let") {
        return TokenType::LET;
    } else if (keyword == "while") {
        return TokenType::WHILE;
    } else {
        return TokenType::INVALID;
    }
}
