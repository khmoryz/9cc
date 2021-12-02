#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool debug;

//
// parse.c
//

// トークンの種類
// 更新する場合はdebug.cにも反映する
typedef enum {
  TK_RESERVED, // 記号
  TK_IDENT,    // 識別子
  TK_NUM,      // 整数トークン
  TK_EOF,      // EOF
} TokenKind;

typedef struct Token Token;
typedef struct LVar LVar;

struct Token {
  TokenKind kind; // トークンの型
  Token *next;    // 次の入力トークン
  int val;        // kindがTK_NUMの場合、その数値
  char *str;      // トークン文字列
  int len;        // トークンの長さ
};

struct LVar {
  LVar *next;  // 次の変数またはNULL
  char *name;  // 変数の名前
  int len;     // 名前の長さ
  int offset;  // RBPからのオフセット
};

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
bool consume(char *op);
Token *consume_ident();
void expect(char *op);
int expect_number();
bool at_eof();
Token *tokenize();

// 入力プログラム
char *user_input;
// 現在着目しているトークン;
Token *token;
// ローカル変数
LVar *locals;


// 更新する場合はdebug.cにも反映する
typedef enum {
  ND_RETURN, // return
  ND_ADD,    // *
  ND_SUB,    // -
  ND_MUL,    // *
  ND_DIV,    // /
  ND_EQ,     // =
  ND_NE,     // !=
  ND_LT,     // <
  ND_LE,     // <=
  ND_ASSIGN, // =
  ND_LVAR,   // ローカル変数
  ND_NUM,    // Integer
} NodeKind;

typedef struct Node Node;
struct Node {
  NodeKind kind; // Node kind
  Node *lhs;     // Left-hand side
  Node *rhs;     // Right-hand side
  int val;       // kindがND_NUMの場合のみ使う
  int offset;    // kindがND_LVARの場合のみ使う。ベースポインタからのオフセット。
};

Node *code[100];
void program();
Node *stmt();
Node *expr();
Node *assign();
Node *equality();
Node *relational();
Node *add();
Node *mul();
Node *unary();
Node *primary();

//
// codegen.c
//

void gen_lval(Node *node);
void gen(Node *node);

//
// debug.c
//
void token_walk();
void node_dump();
