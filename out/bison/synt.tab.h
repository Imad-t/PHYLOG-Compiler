/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_OUT_BISON_SYNT_TAB_H_INCLUDED
# define YY_YY_OUT_BISON_SYNT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER_TYPE = 259,            /* INTEGER_TYPE  */
    FLOAT_TYPE = 260,              /* FLOAT_TYPE  */
    CHAR_TYPE = 261,               /* CHAR_TYPE  */
    STRING_TYPE = 262,             /* STRING_TYPE  */
    CONST = 263,                   /* CONST  */
    DATA = 264,                    /* DATA  */
    CODE = 265,                    /* CODE  */
    END = 266,                     /* END  */
    VECTOR = 267,                  /* VECTOR  */
    FOR = 268,                     /* FOR  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    LOGICAL_AND = 271,             /* LOGICAL_AND  */
    LOGICAL_NOT = 272,             /* LOGICAL_NOT  */
    LOGICAL_OR = 273,              /* LOGICAL_OR  */
    ASSIGN = 274,                  /* ASSIGN  */
    EQUAL = 275,                   /* EQUAL  */
    NOT_EQUAL = 276,               /* NOT_EQUAL  */
    LESS = 277,                    /* LESS  */
    LESS_OR_EQUAL = 278,           /* LESS_OR_EQUAL  */
    GREATER = 279,                 /* GREATER  */
    GREATER_OR_EQUAL = 280,        /* GREATER_OR_EQUAL  */
    LPAREN = 281,                  /* LPAREN  */
    RPAREN = 282,                  /* RPAREN  */
    LBRACKET = 283,                /* LBRACKET  */
    RBRACKET = 284,                /* RBRACKET  */
    COLON = 285,                   /* COLON  */
    COMMA = 286,                   /* COMMA  */
    SEMICOLON = 287,               /* SEMICOLON  */
    BAR = 288,                     /* BAR  */
    PLUS = 289,                    /* PLUS  */
    MINUS = 290,                   /* MINUS  */
    MUL = 291,                     /* MUL  */
    DIV = 292,                     /* DIV  */
    READ = 293,                    /* READ  */
    DISPLAY = 294,                 /* DISPLAY  */
    AT = 295,                      /* AT  */
    INTEGER_CONST = 296,           /* INTEGER_CONST  */
    FLOAT_CONST = 297,             /* FLOAT_CONST  */
    CHAR_CONST = 298,              /* CHAR_CONST  */
    STRING_CONST = 299,            /* STRING_CONST  */
    IFX = 300                      /* IFX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "src/parser/parser.y"
 
  int integer;
  float reel;
  char* str;

#line 115 "out/bison/synt.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_OUT_BISON_SYNT_TAB_H_INCLUDED  */
