%option noyywrap

%{
  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
  #include "../../out/bison/synt.tab.h"
  #include "../../src/data-structure/stack/stack.h"
  Stack *returns_stack;
  Stack *create_stack();
  int symbol_table_insert(char *name, char *code, char *type, float value);
  int init_symbol_table();
  void print_table();
  void display_quad();
  void save_quad_to_file(const char* filename);
  void generate_code();
  void optimize_quad();
  int number_of_lines = 1;
  int column_position = 1;
%}


DIGIT [0-9]
LETTER [A-Z]
LOWERCASE [a-z]
IDENTIFIER {LETTER}({LETTER}|{LOWERCASE}|{DIGIT}){0,7}
CHAR \'[^\']\' 
STRING \"[^\"]*\"
FLOAT {DIGIT}+\.{DIGIT}+
SIGNED_FLOAT \(\-?{DIGIT}+\.{DIGIT}+\)
INTEGER {DIGIT}+
SIGNED_INTEGER \(\-{DIGIT}+\)

%%

"DATA" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "KEYWORD", "", 0);
  return DATA;
}

"CODE" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "KEYWORD", "", 0);
  return CODE;
}

"END" {
  printf("Returning token END\n");
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "KEYWORD", "", 0);
  return END;
}

"VECTOR" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "KEYWORD", "", 0);
  return VECTOR;
}

"INTEGER" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "TYPE", "", 0);
  return INTEGER_TYPE;
}

"FLOAT" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "TYPE", "", 0);
  return FLOAT_TYPE;
}

"CHAR" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "TYPE", "", 0);
  return CHAR_TYPE;
}

"STRING" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "TYPE", "", 0);
  return STRING_TYPE;
}

"CONST" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "KEYWORD", "", 0);
  return CONST;
}

"READ" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "FUNCTION", "", 0);
  return READ;
}

"DISPLAY" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "FUNCTION", "", 0);
  return DISPLAY;
}

"IF" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "KEYWORD", "", 0);
  return IF;
}

"ELSE" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "KEYWORD", "", 0);
  return ELSE;
}

"FOR" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "KEYWORD", "", 0);
  return FOR;
}

\.G\. {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return GREATER;
}

\.GE\. {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return GREATER_OR_EQUAL;
}

\.L\. {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return LESS;
}

\.LE\. {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return LESS_OR_EQUAL;
}

\.EQ\. {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return EQUAL;
}

\.DI\. {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return NOT_EQUAL;
}

\.AND\. {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return LOGICAL_AND;
}

\.OR\. {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return LOGICAL_OR;
}

"NOT" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return LOGICAL_NOT;
}

{INTEGER} {
  if(atoi(yytext) > -32768 && atoi(yytext) < 32767){
    yylval.str = strdup(yytext);
    column_position = column_position + yyleng;
    symbol_table_insert(yytext, "CONSTANT", "INTEGER", atoi(yytext));
    return INTEGER_CONST;
  }else{
    printf("Integer invalid at line: %d, column: %d\n", number_of_lines, column_position);
  }
}

{SIGNED_INTEGER} {
  char *value = strdup(yytext + 1);
  value[strlen(value) - 1] = '\0';
  int val = atoi(value);
  if(val > -32768 && val < 32767){
    yylval.str = strdup(yytext);
    column_position = column_position + yyleng;
    symbol_table_insert(yytext, "CONSTANT", "INTEGER", val);
    return INTEGER_CONST;
  }else{
    printf("Integer invalid at line: %d, column: %d\n", number_of_lines, column_position);
  }
}

{FLOAT} {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "CONSTANT", "FLOAT", atof(yytext));
  return FLOAT_CONST; 
}

{SIGNED_FLOAT} {
  char *value = strdup(yytext + 1);
  value[strlen(value) - 1] = '\0';
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;  
  symbol_table_insert(yytext, "CONSTANT", "FLOAT", atof(value));
  return FLOAT_CONST; 
}

{CHAR} {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "CONSTANT", "CHAR", 0);
  return CHAR_CONST;
}

{STRING} {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng;
  symbol_table_insert(yytext, "CONSTANT", "STRING", 0);
  return STRING_CONST;
}

"=" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return ASSIGN; 
}

"+" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return PLUS; 
}

"-" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return MINUS; 
}

"*" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return MUL; 
}

"/" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return DIV; 
}

"(" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "SEPARATOR", "", 0);
  return LPAREN; 
}

")" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "SEPARATOR", "", 0);
  return RPAREN; 
}

"[" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "SEPARATOR", "", 0);
  return LBRACKET; 
}

"]" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "SEPARATOR", "", 0);
  return RBRACKET; 
}

"," {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "SEPARATOR", "", 0);
  return COMMA; 
}

":" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "SEPARATOR", "", 0);
  return COLON; 
}

";" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "SEPARATOR", "", 0);
  return SEMICOLON; 
}

"|" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "SEPARATOR", "", 0);
  return BAR; 
}

"@" {
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "OPERATOR", "", 0);
  return AT; 
}

{IDENTIFIER} { 
  printf("Returning token IDENTIFIER: %s\n", yytext);
  yylval.str = strdup(yytext);
  column_position = column_position + yyleng; 
  symbol_table_insert(yytext, "IDENTIFIER", "", 0);
  return IDENTIFIER; 
}

"§"[^\n]* {
  /* Comment - ignore */
  column_position = column_position + yyleng;
}

\r?\n { 
  number_of_lines++;
  column_position = 0;
}

[ \t] {
  column_position += 1;
}

. {
  column_position++;
  fprintf(stderr, "Lexical error at line: %d, column: %d, Unknown token: %s\n", number_of_lines, column_position, yytext);
  yyterminate(); 
}

%%

int main() {
  returns_stack = create_stack();
  init_symbol_table();
  yyparse();
  printf("\n\n\n");
  printf("\n\n--------------------------------------------------------\n\n");
  printf("                    1-Symbole Table\n\n");
  printf("--------------------------------------------------------\n");
  print_table();
  printf("\n\n\n");
  printf("\n\n--------------------------------------------------------\n\n");
  printf("                    2-Quadruplets\n\n");
  printf("--------------------------------------------------------\n");
  display_quad();
  save_quad_to_file("out/quadruplets/Quadruplets.txt");
  printf("\n\n\n");
  printf("\n\n--------------------------------------------------------\n\n");
  printf("                    3-Generated Code\n\n");
  printf("--------------------------------------------------------\n");
  generate_code();
  optimize_quad();
  printf("\n\n\n");
  printf("\n\n--------------------------------------------------------\n\n");
  printf("               4-Quadruplets after Optimization\n\n");
  printf("--------------------------------------------------------\n");
  display_quad();
  save_quad_to_file("out/quadruplets/Quadruplets Optimized.txt");
  printf("\n\n\n");
  printf("\n\n--------------------------------------------------------\n\n");
  printf("            5-Generated Code after Optimization\n\n");
  printf("--------------------------------------------------------\n");
  generate_code();
  printf("\n\n\n");
}