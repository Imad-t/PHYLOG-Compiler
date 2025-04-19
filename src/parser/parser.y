%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "../../src/symbol-table/symbol-table.h"
  #include "../../src/quadruplet/quadruplet.h"
  typedef struct Stack
  {
    int *items;
    int top;
  } Stack;
  int is_empty(Stack *stack);
  int pop(Stack *stack);
  void push(Stack *stack, int item);
  extern Stack *returns_stack;
  char stocked_type[20];
  extern int Qc;
  int qc_saver, end_saver;
  int error = 0;
  char temp[25]; 
  int tempCounter = 1;
  int condCounter = 1;
  extern int number_of_lines, column_position;
  extern int yylex();
  void yyerror(const char*);
  int debug = 1; // Enable debug output
%}

%union 
{ 
  int integer;
  float reel;
  char* str;
}

%token <str> IDENTIFIER INTEGER_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE CONST
%token <str> DATA CODE END VECTOR
%token <str> FOR IF ELSE
%token <str> LOGICAL_AND LOGICAL_NOT LOGICAL_OR
%token <str> ASSIGN EQUAL NOT_EQUAL LESS LESS_OR_EQUAL GREATER GREATER_OR_EQUAL
%token <str> LPAREN RPAREN LBRACKET RBRACKET COLON COMMA SEMICOLON BAR
%token <str> PLUS MINUS MUL DIV
%token <str> READ DISPLAY AT 
%token <str> INTEGER_CONST FLOAT_CONST CHAR_CONST STRING_CONST

%type <str> declaration type item constant condition expression term
%type <str> math_operator comparision_operator logical_operator
%type <str> program program_header data_section code_section program_end
%type <str> declarations type_declaration vector_declaration const_declaration
%type <str> var_list statements statement assignment read_statement
%type <str> display_statement if_statement if_body else_body for_statement
%type <str> left_hand_side array_access

/* Set operator precedence to resolve shift/reduce conflicts */
%left LOGICAL_OR
%left LOGICAL_AND
%left EQUAL NOT_EQUAL
%left LESS LESS_OR_EQUAL GREATER GREATER_OR_EQUAL
%left PLUS MINUS
%left MUL DIV
%right LOGICAL_NOT

/* Resolve the dangling else problem */
%nonassoc IFX
%nonassoc ELSE

%start program

%%

program: program_header data_section code_section program_end {
  printf("SYNTAX CORRECT \n");
  YYACCEPT;
}

program_header: IDENTIFIER { 
  if(debug) printf("DEBUG: Parsed program header: %s\n", $1);
  $$ = $1; 
}

data_section: DATA declarations END { 
  if(debug) printf("DEBUG: Parsed data section\n");
  $$ = "DATA_SECTION"; 
}

code_section: CODE { if(debug) printf("DEBUG: Starting code section\n"); } 
              statements { if(debug) printf("DEBUG: Completed statements\n"); } 
              END { 
                if(debug) printf("DEBUG: Completed code section\n");
                $$ = "CODE_SECTION"; 
              }

program_end: END { 
  if(debug) printf("DEBUG: Parsed program end\n");
  $$ = "END"; 
}

declarations: declaration { 
  if(debug) printf("DEBUG: Parsed declaration\n");
  $$ = $1; 
}
  | declarations declaration { 
    if(debug) printf("DEBUG: Parsed multiple declarations\n");
    $$ = $1; 
  }

declaration: type_declaration { 
  if(debug) printf("DEBUG: Parsed type declaration\n");
  $$ = "TYPE_DECLARATION"; 
}
  | vector_declaration { 
    if(debug) printf("DEBUG: Parsed vector declaration\n");
    $$ = "VECTOR_DECLARATION"; 
  }
  | const_declaration { 
    if(debug) printf("DEBUG: Parsed const declaration\n");
    $$ = "CONST_DECLARATION"; 
  }

type_declaration: type COLON var_list SEMICOLON { 
  if(debug) printf("DEBUG: Completed type declaration\n");
  $$ = $1; 
}

var_list: IDENTIFIER {
  if(debug) printf("DEBUG: Parsing identifier in var_list: %s\n", $1);
  if(isDoubleDeclared($1)){
    printf("Semantic error: double declaration of %s, in line %d \n", $1, number_of_lines);
    error=1;
    YYERROR;
  }else{
    symbol_table_insert_type($1, stocked_type);
    $$ = $1;
  }
}
  | IDENTIFIER BAR var_list {
  if(debug) printf("DEBUG: Parsing identifier with bar in var_list: %s\n", $1);
  if(isDoubleDeclared($1)){
    printf("Semantic error: double declaration of %s, in line %d \n", $1, number_of_lines);
    error=1;
    YYERROR;
  }else{
    symbol_table_insert_type($1, stocked_type);
    $$ = $1;
  }
}

vector_declaration: VECTOR COLON IDENTIFIER LBRACKET INTEGER_CONST COMMA INTEGER_CONST COLON type RBRACKET SEMICOLON {
  if(debug) printf("DEBUG: Parsing vector declaration for: %s\n", $3);
  if(isDoubleDeclared($3)){
    printf("Semantic error: double declaration of %s, in line %d \n", $3, number_of_lines);
    error=1;
    YYERROR;
  }else{
    char vector_type[50];
    sprintf(vector_type, "VECTOR_%s", stocked_type);
    symbol_table_insert_type($3, vector_type);
    $$ = $3;
  }
}

const_declaration: CONST COLON IDENTIFIER ASSIGN constant SEMICOLON {
  if(debug) printf("DEBUG: Parsing const declaration for: %s\n", $3);
  if(isDoubleDeclared($3)){
    printf("Semantic error: double declaration of %s, in line %d \n", $3, number_of_lines);
    error=1;
    YYERROR;
  }else{
    symbol_table_insert_type($3, "CONST");
    quad(":=", $5, "", $3);
    $$ = $3;
  }
}

type: INTEGER_TYPE {
    strcpy(stocked_type,"INTEGER");
    $$ = "INTEGER";
  }
  | FLOAT_TYPE {
    strcpy(stocked_type,"FLOAT");
    $$ = "FLOAT";
  }
  | CHAR_TYPE {
    strcpy(stocked_type,"CHAR");
    $$ = "CHAR";
  }
  | STRING_TYPE {
    strcpy(stocked_type,"STRING");
    $$ = "STRING";
  }

statements: statement { 
  if(debug) printf("DEBUG: Parsed statement\n");
  $$ = "STATEMENTS"; 
}
  | statements statement { 
    if(debug) printf("DEBUG: Parsed multiple statements\n");
    $$ = "STATEMENTS"; 
  }

statement: assignment { 
  if(debug) printf("DEBUG: Parsed assignment statement\n");
  $$ = "ASSIGNMENT"; 
}
  | read_statement { 
    if(debug) printf("DEBUG: Parsed read statement\n");
    $$ = "READ_STATEMENT"; 
  }
  | display_statement { 
    if(debug) printf("DEBUG: Parsed display statement\n");
    $$ = "DISPLAY_STATEMENT"; 
  }
  | if_statement { 
    if(debug) printf("DEBUG: Parsed if statement\n");
    $$ = "IF_STATEMENT"; 
  }
  | for_statement { 
    if(debug) printf("DEBUG: Parsed for statement\n");
    $$ = "FOR_STATEMENT"; 
  }

left_hand_side: IDENTIFIER {
  if(debug) printf("DEBUG: Parsing left-hand side as identifier: %s\n", $1);
  element *identifier = symbol_table_search($1);
  if(identifier == NULL){
    printf("Semantic error: undeclared identifier %s, in line %d \n", $1, number_of_lines);
    error=1;
    YYERROR;
  }
  $$ = $1;
}
  | array_access {
    if(debug) printf("DEBUG: Parsing left-hand side as array access: %s\n", $1);
    $$ = $1;
  }

assignment: left_hand_side ASSIGN expression SEMICOLON {
  if(debug) printf("DEBUG: Parsing assignment for: %s = %s\n", $1, $3);
  if(strchr($1, '[') != NULL){ // Check if it's an array access
    char *array_name = strtok($1, "[");
    char *index = strtok(NULL, "]");
    quad("[]=", $3, index, array_name); // Corrected order: value, index, array
  }else{
    quad(":=", $3, "", $1);
  }
  $$ = "ASSIGNMENT";
}

read_statement: READ LPAREN STRING_CONST COLON AT IDENTIFIER RPAREN SEMICOLON {
  if(debug) printf("DEBUG: Parsing READ statement for: %s\n", $6);
  element *identifier = symbol_table_search($6);
  if(identifier == NULL){
    printf("Semantic error: undeclared identifier %s, in line %d \n", $6, number_of_lines);
    error=1;
    YYERROR;
  }else{
    quad("READ", $3, "", $6);
    $$ = "READ";
  }
}

display_statement: DISPLAY LPAREN STRING_CONST COLON item RPAREN SEMICOLON {
  if(debug) printf("DEBUG: Parsing DISPLAY statement\n");
  quad("DISPLAY", $3, $5, "");
  $$ = "DISPLAY";
}

if_statement: IF LPAREN condition RPAREN COLON if_body END %prec IFX {
  if(debug) printf("DEBUG: Parsed IF statement without ELSE\n");
  sprintf(temp, "%d", Qc);
  quad_updated(qc_saver, 2, temp);
  $$ = "IF_STATEMENT";
}
  | IF LPAREN condition RPAREN COLON if_body ELSE COLON else_body END {
  if(debug) printf("DEBUG: Parsed IF-ELSE statement\n");
  sprintf(temp, "%d", Qc);
  quad_updated(qc_saver, 2, temp);
  $$ = "IF_STATEMENT";
}

if_body: statements {
  if(debug) printf("DEBUG: Parsed IF body\n");
  qc_saver = Qc;
  quad("BR", " ", " ", " ");
  $$ = "IF_BODY";
}

else_body: statements { 
  if(debug) printf("DEBUG: Parsed ELSE body\n");
  $$ = "ELSE_BODY"; 
}

for_statement: FOR LPAREN IDENTIFIER COLON expression COLON condition RPAREN statements END {
  if(debug) printf("DEBUG: Parsed FOR statement\n");
  char* loop_var = $3;
  char* step = $5;
  quad("+", loop_var, step, loop_var); // Increment: Counter = Counter + step
  int loop_start = qc_saver; // Condition’s quadruplet index
  sprintf(temp, "%d", loop_start);
  quad("BR", "", "", temp); // Jump back to condition
  sprintf(temp, "%d", Qc);
  quad_updated(qc_saver, 2, temp); // Update condition’s exit target
  $$ = "FOR_STATEMENT";
}

condition: expression comparision_operator expression {
  if(debug) printf("DEBUG: Parsed condition with comparison\n");
  sprintf(temp, "t%d", tempCounter++);
  qc_saver = Qc;
  if(strcmp($2, ".G.") == 0){
    quad("BLE", $1, $3, " ");
  }
  else if(strcmp($2, ".GE.") == 0){
    quad("BL", $1, $3, " ");
  }
  else if(strcmp($2, ".L.") == 0){
    quad("BGE", $1, $3, " ");
  }
  else if(strcmp($2, ".LE.") == 0){
    quad("BG", $1, $3, " ");
  }
  else if(strcmp($2, ".EQ.") == 0){
    quad("BNE", $1, $3, " ");
  }
  else if(strcmp($2, ".DI.") == 0){
    quad("BE", $1, $3, " ");
  }
  $$ = temp;
}
  | LPAREN condition RPAREN { 
    if(debug) printf("DEBUG: Parsed parenthesized condition\n");
    $$ = $2; 
  }
  | condition logical_operator condition {
    if(debug) printf("DEBUG: Parsed logical condition\n");
    sprintf(temp, "t%d", tempCounter++);
    if(strcmp($2, ".AND.") == 0){
      quad("AND", $1, $3, temp);
    }
    else if(strcmp($2, ".OR.") == 0){
      quad("OR", $1, $3, temp);
    }
    $$ = temp;
  }
  | LOGICAL_NOT expression {
    if(debug) printf("DEBUG: Parsed NOT condition\n");
    sprintf(temp, "t%d", tempCounter++);
    quad("NOT", $2, "", temp);
    $$ = temp;
  }

comparision_operator: GREATER { 
  if(debug) printf("DEBUG: Parsed GREATER operator\n");
  $$ = ".G."; 
}
  | GREATER_OR_EQUAL { 
    if(debug) printf("DEBUG: Parsed GREATER_OR_EQUAL operator\n");
    $$ = ".GE."; 
  }
  | LESS { 
    if(debug) printf("DEBUG: Parsed LESS operator\n");
    $$ = ".L."; 
  }
  | LESS_OR_EQUAL { 
    if(debug) printf("DEBUG: Parsed LESS_OR_EQUAL operator\n");
    $$ = ".LE."; 
  }
  | EQUAL { 
    if(debug) printf("DEBUG: Parsed EQUAL operator\n");
    $$ = ".EQ."; 
  }
  | NOT_EQUAL { 
    if(debug) printf("DEBUG: Parsed NOT_EQUAL operator\n");
    $$ = ".DI."; 
  }

logical_operator: LOGICAL_AND { 
  if(debug) printf("DEBUG: Parsed AND operator\n");
  $$ = ".AND."; 
}
  | LOGICAL_OR { 
    if(debug) printf("DEBUG: Parsed OR operator\n");
    $$ = ".OR."; 
  }

expression: expression math_operator term {
  if(debug) printf("DEBUG: Parsed expression with math op\n");
  sprintf(temp, "t%d", tempCounter++);
  quad($2, $1, $3, temp);
  $$ = temp;
}
  | term { 
    if(debug) printf("DEBUG: Parsed expression as term: %s\n", $1);
    $$ = $1; 
  }

term: item { 
  if(debug) printf("DEBUG: Parsed term as item: %s\n", $1);
  $$ = $1; 
}
  | LPAREN expression RPAREN { 
    if(debug) printf("DEBUG: Parsed term with parentheses\n");
    $$ = $2; 
  }

math_operator: PLUS { 
  if(debug) printf("DEBUG: Parsed PLUS operator\n");
    $$ = "+"; 
}
  | MINUS { 
    if(debug) printf("DEBUG: Parsed MINUS operator\n");
    $$ = "-"; 
  }
  | MUL { 
    if(debug) printf("DEBUG: Parsed MUL operator\n");
    $$ = "*"; 
  }
  | DIV { 
    if(debug) printf("DEBUG: Parsed DIV operator\n");
    $$ = "/"; 
  }

item: IDENTIFIER {
  if(debug) printf("DEBUG: Parsing item as identifier: %s\n", $1);
  element *identifier = symbol_table_search($1);
  if(identifier == NULL){
    printf("Semantic error: undeclared identifier %s, in line %d \n", $1, number_of_lines);
    error=1;
    YYERROR;
  }
  $$ = $1;
}
  | constant { 
    if(debug) printf("DEBUG: Parsing item as constant: %s\n", $1);
    $$ = $1; 
  }
  | array_access { 
    if(debug) printf("DEBUG: Parsing item as array access\n");
    $$ = $1; 
  }

array_access: IDENTIFIER LBRACKET expression RBRACKET {
  if(debug) printf("DEBUG: Parsing array access for: %s\n", $1);
  element *identifier = symbol_table_search($1);
  if(identifier == NULL){
    printf("Semantic error: undeclared identifier %s, in line %d \n", $1, number_of_lines);
    error=1;
    YYERROR;
  }
  char *result = (char*)malloc(strlen($1) + strlen($3) + 3);
  sprintf(result, "%s[%s]", $1, $3);
  $$ = result;
}

constant: INTEGER_CONST { 
  if(debug) printf("DEBUG: Parsed integer constant: %s\n", $1);
  $$ = $1; 
}
  | FLOAT_CONST { 
    if(debug) printf("DEBUG: Parsed float constant: %s\n", $1);
  $$ = $1; 
  }
  | CHAR_CONST { 
    if(debug) printf("DEBUG: Parsed char constant: %s\n", $1);
    $$ = $1; 
  }
  | STRING_CONST { 
    if(debug) printf("DEBUG: Parsed string constant: %s\n", $1);
    $$ = $1; 
  }

%%

void yyerror(const char* s)
{
  printf ("Syntax error in line %d column %d \n", number_of_lines, column_position);
  // exit(1); // Comment this out to avoid immediate exit on syntax error
}