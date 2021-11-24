#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// parse.c
//

// トークンの種類
typedef enum {
  TK_RESERVED, // 記号
  TK_NUM,      // 整数トークン
  TK_EOF,      // EOF
} TokenKind;

typedef struct Token Token;

struct Token {
  TokenKind kind; // トークンの型
  Token *next;    // 次の入力トークン
  int val;        // kindがTK_NUMの場合、その数値
  char *str;      // トークン文字列
  int len;        // トークンの長さ
};

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
bool consume(char *op);
void expect(char *op);
int expect_number();
bool at_eof();
Token *tokenize();

// 入力プログラム
char *user_input;
// 現在着目しているトークン;
Token *token;


typedef enum {
  ND_ADD, // *
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_EQ, // =
  ND_NE, // !=
  ND_LT, // <
  ND_LE, // <=
  ND_NUM, // Integer
} NodeKind;

typedef struct Node Node;
struct Node {
  NodeKind kind; // Node kind
  Node *lhs;     // Left-hand side
  Node *rhs;     // Right-hand side
  int val;       // ND_NUMの場合、その値
};

Node *expr();
Node *equality();
Node *relational();
Node *add();
Node *mul();
Node *unary();
Node *primary();

//
// codegen.c
//

void gen(Node *node);
