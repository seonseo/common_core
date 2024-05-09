#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 1024

typedef enum {
    TOK_WORD,
    TOK_OPERATOR,
    TOK_QUOTE,
    TOK_EXPANSION,
    TOK_COMMENT,
    TOK_NEWLINE,
    TOK_BLANK,
    TOK_UNKNOWN
} TokenType;

// Checks if a character is an operator
int is_operator(char c) {
    return c == '|' || c == '&' || c == '<' || c == '>';  // Extend based on needed operators
}

// Print token for debug
void print_token(const char* start, int length, const char* type) {
    printf("%s: %.*s\n", type, length, start);
}

// Simple tokenizer function
void tokenize(const char *input) {
    int i = 0;
    int tokenStart = 0;
    TokenType currentType = TOK_UNKNOWN;
    char currentChar, quoteType = 0;

    while ((currentChar = input[i]) != '\0') {
        switch (currentType) {
            case TOK_UNKNOWN:
                if (is_operator(currentChar)) {
                    print_token(&input[i], 1, "Operator");
                } else if (isspace(currentChar)) {
                    if (currentChar == '\n') {
                        print_token(&input[i], 1, "Newline");
                    }
                } else if (currentChar == '#') {
                    print_token(&input[i], strlen(&input[i]), "Comment");
                    return;  // Stop parsing after comment
                } else if (currentChar == '\'' || currentChar == '"' || currentChar == '`') {
                    quoteType = currentChar;
                    tokenStart = i;
                    currentType = TOK_QUOTE;
                } else {
                    tokenStart = i;
                    currentType = TOK_WORD;
                }
                break;

            case TOK_QUOTE:
                if (currentChar == quoteType && (i == 0 || input[i-1] != '\\')) {
                    print_token(&input[tokenStart], i - tokenStart + 1, "Quote");
                    currentType = TOK_UNKNOWN;
                }
                break;

            case TOK_WORD:
                if (isspace(currentChar) || is_operator(currentChar) || currentChar == '#') {
                    print_token(&input[tokenStart], i - tokenStart, "Word");
                    currentType = TOK_UNKNOWN;
                    i--; // Re-evaluate this character
                }
                break;

            default:
                break;
        }
        i++;
    }

    if (currentType == TOK_WORD) {
        print_token(&input[tokenStart], i - tokenStart, "Word");
    }
}

int main() {
    const char *input = "echo $HOME && ls -l | grep \"test\" # This is a comment\n";
    tokenize(input);
    return 0;
}
