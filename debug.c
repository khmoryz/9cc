#include "9cc.h"

char tokenKindChar[4][15] = {
  "TK_RESERVED",
  "TK_IDENT",
  "TK_NUM",
  "TK_EOF",
};

char nodeKindChar[12][15] = {
  "ND_RETURN",
  "ND_ADD",
  "ND_SUB",
  "ND_MUL",
  "ND_DIV",
  "ND_EQ",
  "ND_NE",
  "ND_LT",
  "ND_LE",
  "ND_ASSIGN",
  "ND_LVAR",
  "ND_NUM",
};

void token_walk() {
  printf("======= Token Walk Start =======\n\n");

  Token *tokenCopy;
  tokenCopy = token;
  while (tokenCopy->next) {
    char buffer[20] = "";
    memcpy(buffer, tokenCopy->str, tokenCopy->len);

    printf("TokenKind: %s\n", tokenKindChar[tokenCopy->kind]);
    printf("TokenString: %s\n\n", buffer);

    tokenCopy = tokenCopy->next;
  }

  printf("======= Token Walk End =======\n");
}

void node_dump(int nodeKind) {
  printf("NodeKind: %s\n", nodeKindChar[nodeKind]);
}
