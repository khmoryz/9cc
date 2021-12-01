#include "9cc.h"

void token_walk() {
  printf("======= Token Walk Start =======\n\n");

  // enumの整数値を文字列で表示する
  char tokenKindChar[4][15] = {
    "TK_RESERVED",
    "TK_IDENT",
    "TK_NUM",
    "TK_EOF",
  };

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
