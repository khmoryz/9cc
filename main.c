#include "9cc.h"

int main(int argc, char **argv) {
  if (argc != 2)
      error("%s: invalid number of arguments", argv[0]);

  // トークナイズとパース
  user_input = argv[1];
  token = tokenize();
  Node *node = expr();

  // アセンブリの前半部分を出力
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  // アセンブリ生成のためASTをトラバースする
  gen(node);

  // スタックの最上階の結果をpopする
  printf("  pop rax\n");
  printf("  ret\n");
  return 0;
}
