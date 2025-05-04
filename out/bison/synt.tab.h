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
    ASSIGN = 271,                  /* ASSIGN  */
    LPAREN = 272,                  /* LPAREN  */
    RPAREN = 273,                  /* RPAREN  */
    LBRACKET = 274,                /* LBRACKET  */
    RBRACKET = 275,                /* RBRACKET  */
    COLON = 276,                   /* COLON  */
    COMMA = 277,                   /* COMMA  */
    SEMICOLON = 278,               /* SEMICOLON  */
    BAR = 279,                     /* BAR  */
    READ = 280,                    /* READ  */
    DISPLAY = 281,                 /* DISPLAY  */
    AT = 282,                      /* AT  */
    INTEGER_CONST = 283,           /* INTEGER_CONST  */
    FLOAT_CONST = 284,             /* FLOAT_CONST  */
    CHAR_CONST = 285,              /* CHAR_CONST  */
    STRING_CONST = 286,            /* STRING_CONST  */
    LOGICAL_OR = 287,              /* LOGICAL_OR  */
    EQUAL = 288,                   /* EQUAL  */
    NOT_EQUAL = 289,               /* NOT_EQUAL  */
    LOGICAL_AND = 290,             /* LOGICAL_AND  */
    LESS = 291,                    /* LESS  */
    LESS_OR_EQUAL = 292,           /* LESS_OR_EQUAL  */
    GREATER = 293,                 /* GREATER  */
    GREATER_OR_EQUAL = 294,        /* GREATER_OR_EQUAL  */
    PLUS = 295,                    /* PLUS  */
    MINUS = 296,                   /* MINUS  */
    MUL = 297,                     /* MUL  */
    DIV = 298,                     /* DIV  */
    LOGICAL_NOT = 299,             /* LOGICAL_NOT  */
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
