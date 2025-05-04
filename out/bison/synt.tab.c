/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser/parser.y"

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

#line 99 "out/bison/synt.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "synt.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER_TYPE = 4,               /* INTEGER_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 5,                 /* FLOAT_TYPE  */
  YYSYMBOL_CHAR_TYPE = 6,                  /* CHAR_TYPE  */
  YYSYMBOL_STRING_TYPE = 7,                /* STRING_TYPE  */
  YYSYMBOL_CONST = 8,                      /* CONST  */
  YYSYMBOL_DATA = 9,                       /* DATA  */
  YYSYMBOL_CODE = 10,                      /* CODE  */
  YYSYMBOL_END = 11,                       /* END  */
  YYSYMBOL_VECTOR = 12,                    /* VECTOR  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_LPAREN = 17,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 18,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 19,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 20,                  /* RBRACKET  */
  YYSYMBOL_COLON = 21,                     /* COLON  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 23,                 /* SEMICOLON  */
  YYSYMBOL_BAR = 24,                       /* BAR  */
  YYSYMBOL_READ = 25,                      /* READ  */
  YYSYMBOL_DISPLAY = 26,                   /* DISPLAY  */
  YYSYMBOL_AT = 27,                        /* AT  */
  YYSYMBOL_INTEGER_CONST = 28,             /* INTEGER_CONST  */
  YYSYMBOL_FLOAT_CONST = 29,               /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 30,                /* CHAR_CONST  */
  YYSYMBOL_STRING_CONST = 31,              /* STRING_CONST  */
  YYSYMBOL_LOGICAL_OR = 32,                /* LOGICAL_OR  */
  YYSYMBOL_EQUAL = 33,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 34,                 /* NOT_EQUAL  */
  YYSYMBOL_LOGICAL_AND = 35,               /* LOGICAL_AND  */
  YYSYMBOL_LESS = 36,                      /* LESS  */
  YYSYMBOL_LESS_OR_EQUAL = 37,             /* LESS_OR_EQUAL  */
  YYSYMBOL_GREATER = 38,                   /* GREATER  */
  YYSYMBOL_GREATER_OR_EQUAL = 39,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_PLUS = 40,                      /* PLUS  */
  YYSYMBOL_MINUS = 41,                     /* MINUS  */
  YYSYMBOL_MUL = 42,                       /* MUL  */
  YYSYMBOL_DIV = 43,                       /* DIV  */
  YYSYMBOL_LOGICAL_NOT = 44,               /* LOGICAL_NOT  */
  YYSYMBOL_IFX = 45,                       /* IFX  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_program_header = 48,            /* program_header  */
  YYSYMBOL_data_section = 49,              /* data_section  */
  YYSYMBOL_code_section = 50,              /* code_section  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_program_end = 53,               /* program_end  */
  YYSYMBOL_declarations = 54,              /* declarations  */
  YYSYMBOL_declaration = 55,               /* declaration  */
  YYSYMBOL_type_declaration = 56,          /* type_declaration  */
  YYSYMBOL_var_list = 57,                  /* var_list  */
  YYSYMBOL_vector_declaration = 58,        /* vector_declaration  */
  YYSYMBOL_const_declaration = 59,         /* const_declaration  */
  YYSYMBOL_type = 60,                      /* type  */
  YYSYMBOL_statements = 61,                /* statements  */
  YYSYMBOL_statement = 62,                 /* statement  */
  YYSYMBOL_left_hand_side = 63,            /* left_hand_side  */
  YYSYMBOL_assignment = 64,                /* assignment  */
  YYSYMBOL_read_statement = 65,            /* read_statement  */
  YYSYMBOL_display_statement = 66,         /* display_statement  */
  YYSYMBOL_if_statement = 67,              /* if_statement  */
  YYSYMBOL_if_body = 68,                   /* if_body  */
  YYSYMBOL_else_body = 69,                 /* else_body  */
  YYSYMBOL_for_statement = 70,             /* for_statement  */
  YYSYMBOL_condition = 71,                 /* condition  */
  YYSYMBOL_72_3 = 72,                      /* $@3  */
  YYSYMBOL_73_4 = 73,                      /* $@4  */
  YYSYMBOL_comparision_operator = 74,      /* comparision_operator  */
  YYSYMBOL_expression = 75,                /* expression  */
  YYSYMBOL_term = 76,                      /* term  */
  YYSYMBOL_math_operator = 77,             /* math_operator  */
  YYSYMBOL_item = 78,                      /* item  */
  YYSYMBOL_array_access = 79,              /* array_access  */
  YYSYMBOL_constant = 80                   /* constant  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    74,    79,    84,    85,    84,    91,    96,
     100,   105,   109,   113,   118,   123,   134,   146,   160,   173,
     177,   181,   185,   190,   194,   199,   203,   207,   211,   215,
     220,   230,   235,   247,   260,   266,   272,   279,   286,   291,
     303,   327,   331,   331,   340,   340,   349,   357,   361,   365,
     369,   373,   377,   383,   389,   394,   398,   403,   407,   411,
     415,   420,   430,   434,   439,   452,   456,   460,   464
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER_TYPE", "FLOAT_TYPE", "CHAR_TYPE", "STRING_TYPE", "CONST",
  "DATA", "CODE", "END", "VECTOR", "FOR", "IF", "ELSE", "ASSIGN", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "COLON", "COMMA", "SEMICOLON", "BAR",
  "READ", "DISPLAY", "AT", "INTEGER_CONST", "FLOAT_CONST", "CHAR_CONST",
  "STRING_CONST", "LOGICAL_OR", "EQUAL", "NOT_EQUAL", "LOGICAL_AND",
  "LESS", "LESS_OR_EQUAL", "GREATER", "GREATER_OR_EQUAL", "PLUS", "MINUS",
  "MUL", "DIV", "LOGICAL_NOT", "IFX", "$accept", "program",
  "program_header", "data_section", "code_section", "$@1", "$@2",
  "program_end", "declarations", "declaration", "type_declaration",
  "var_list", "vector_declaration", "const_declaration", "type",
  "statements", "statement", "left_hand_side", "assignment",
  "read_statement", "display_statement", "if_statement", "if_body",
  "else_body", "for_statement", "condition", "$@3", "$@4",
  "comparision_operator", "expression", "term", "math_operator", "item",
  "array_access", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -72,    13,     6,   -72,   150,    17,   -72,   -72,   -72,
     -72,    18,    19,   141,   -72,   -72,   -72,   -72,    20,   -72,
      37,    59,    80,   -72,   -72,    83,    68,   -72,   -72,    72,
      71,    67,    69,    84,   104,   105,   106,   107,    68,   -72,
     109,   -72,   -72,   -72,   -72,   -72,   -72,    -8,    99,    83,
     -72,     7,   123,     2,   119,   120,   125,   -72,     7,   -72,
     -72,   -72,   -72,   136,   138,   -72,    84,     7,    56,   -72,
     -72,   -72,   -72,   140,     2,     2,    96,   101,   142,   143,
     -72,    77,   -72,   137,    16,   -72,   -72,   -72,   -72,   -72,
       7,     7,    97,    27,   -72,   145,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,     7,   144,    23,   -72,   146,   -72,
     -72,    64,   -72,    68,     2,     2,    32,   165,   151,    73,
       2,    68,    -4,    15,   -72,   152,   149,   153,    98,   -72,
     154,   155,   -72,   156,    68,    68,   -72,   -72,     3,    68,
     163,   -72,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,     0,    19,    20,    21,
      22,     0,     0,     0,     9,    11,    12,    13,     0,     5,
       0,     0,     0,     4,    10,     0,     0,     8,     2,     0,
       0,    15,     0,    30,     0,     0,     0,     0,     6,    23,
       0,    25,    26,    27,    28,    29,    31,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,    24,     0,    65,
      66,    67,    68,     0,     0,    16,    61,     0,     0,    54,
      55,    63,    62,     0,     0,     0,     0,     0,     0,     0,
       7,     0,    18,     0,     0,    64,    57,    58,    59,    60,
       0,     0,     0,     0,    46,     0,    44,    42,    51,    52,
      49,    50,    47,    48,     0,     0,     0,    32,     0,    56,
      53,     0,    41,     0,     0,     0,    40,     0,     0,     0,
       0,    37,     0,    45,    43,     0,     0,     0,     0,    35,
       0,     0,    34,     0,     0,     0,    33,    17,     0,    38,
       0,    39,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   164,
     -72,   127,   -72,   -72,    61,   -24,   -37,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -71,   -72,   -72,   -72,   -49,
      91,   -72,    76,   -26,   139
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     6,    20,    26,    56,    28,    13,    14,
      15,    32,    16,    17,    18,    38,    39,    40,    41,    42,
      43,    44,   122,   140,    45,    76,   115,   114,   104,    77,
      69,    90,    70,    71,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    57,    68,    92,    94,    66,    33,   129,     1,    81,
      66,   130,    46,     4,   141,     5,    34,    35,    84,    74,
      59,    60,    61,    62,    67,    93,    66,    19,    36,    37,
      59,    60,    61,    62,   109,    59,    60,    61,    62,    21,
      22,    25,   111,   123,   124,   109,    75,    96,    27,   128,
      97,    59,    60,    61,    62,   116,    86,    87,    88,    89,
      98,    99,    29,   100,   101,   102,   103,    86,    87,    88,
      89,    33,    86,    87,    88,    89,    85,     7,     8,     9,
      10,    34,    35,    30,    57,   120,    31,    46,    47,   121,
      48,    49,    50,    36,    37,    46,    86,    87,    88,    89,
     107,    57,    57,    51,    86,    87,    88,    89,    46,    46,
     138,   139,    46,    46,    95,   112,   134,    86,    87,    88,
      89,    52,    53,    54,    55,    58,    73,    64,    96,    96,
      96,    97,    97,    97,    98,    99,    80,   100,   101,   102,
     103,    86,    87,    88,    89,     7,     8,     9,    10,    11,
      78,    79,    23,    12,     7,     8,     9,    10,    11,    82,
      83,    91,    12,   105,   106,   108,   113,   119,   125,   126,
     131,   117,   132,   133,   142,   135,    65,    24,   136,   137,
     127,   110,   118,     0,     0,     0,    63
};

static const yytype_int16 yycheck[] =
{
      26,    38,    51,    74,    75,     3,     3,    11,     3,    58,
       3,    15,    38,     0,    11,     9,    13,    14,    67,    17,
      28,    29,    30,    31,    17,    74,     3,    10,    25,    26,
      28,    29,    30,    31,    18,    28,    29,    30,    31,    21,
      21,    21,    91,   114,   115,    18,    44,    32,    11,   120,
      35,    28,    29,    30,    31,   104,    40,    41,    42,    43,
      33,    34,     3,    36,    37,    38,    39,    40,    41,    42,
      43,     3,    40,    41,    42,    43,    20,     4,     5,     6,
       7,    13,    14,     3,   121,    21,     3,   113,    16,   113,
      19,    24,    23,    25,    26,   121,    40,    41,    42,    43,
      23,   138,   139,    19,    40,    41,    42,    43,   134,   135,
     134,   135,   138,   139,    18,    18,    18,    40,    41,    42,
      43,    17,    17,    17,    17,    16,     3,    28,    32,    32,
      32,    35,    35,    35,    33,    34,    11,    36,    37,    38,
      39,    40,    41,    42,    43,     4,     5,     6,     7,     8,
      31,    31,    11,    12,     4,     5,     6,     7,     8,    23,
      22,    21,    12,    21,    21,    28,    21,    21,     3,    18,
      18,    27,    23,    20,    11,    21,    49,    13,    23,    23,
     119,    90,   106,    -1,    -1,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,    48,     0,     9,    49,     4,     5,     6,
       7,     8,    12,    54,    55,    56,    58,    59,    60,    10,
      50,    21,    21,    11,    55,    21,    51,    11,    53,     3,
       3,     3,    57,     3,    13,    14,    25,    26,    61,    62,
      63,    64,    65,    66,    67,    70,    79,    16,    19,    24,
      23,    19,    17,    17,    17,    17,    52,    62,    16,    28,
      29,    30,    31,    80,    28,    57,     3,    17,    75,    76,
      78,    79,    80,     3,    17,    44,    71,    75,    31,    31,
      11,    75,    23,    22,    75,    20,    40,    41,    42,    43,
      77,    21,    71,    75,    71,    18,    32,    35,    33,    34,
      36,    37,    38,    39,    74,    21,    21,    23,    28,    18,
      76,    75,    18,    21,    73,    72,    75,    27,    78,    21,
      21,    61,    68,    71,    71,     3,    18,    60,    71,    11,
      15,    18,    23,    20,    18,    21,    23,    23,    61,    61,
      69,    11,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    49,    51,    52,    50,    53,    54,
      54,    55,    55,    55,    56,    57,    57,    58,    59,    60,
      60,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      63,    63,    64,    65,    66,    67,    67,    68,    69,    70,
      71,    71,    72,    71,    73,    71,    71,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    78,    78,    78,    79,    80,    80,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     3,     0,     0,     5,     1,     1,
       2,     1,     1,     1,     4,     1,     3,    11,     6,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     8,     7,     7,    10,     1,     1,    10,
       3,     3,     0,     4,     0,     4,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: program_header data_section code_section program_end  */
#line 69 "src/parser/parser.y"
                                                              {
  printf("SYNTAX CORRECT \n");
  YYACCEPT;
}
#line 1276 "out/bison/synt.tab.c"
    break;

  case 3: /* program_header: IDENTIFIER  */
#line 74 "src/parser/parser.y"
                           { 
  if(debug) printf("DEBUG: Parsed program header: %s\n", (yyvsp[0].str));
  (yyval.str) = (yyvsp[0].str); 
}
#line 1285 "out/bison/synt.tab.c"
    break;

  case 4: /* data_section: DATA declarations END  */
#line 79 "src/parser/parser.y"
                                    { 
  if(debug) printf("DEBUG: Parsed data section\n");
  (yyval.str) = "DATA_SECTION"; 
}
#line 1294 "out/bison/synt.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 84 "src/parser/parser.y"
                   { if(debug) printf("DEBUG: Starting code section\n"); }
#line 1300 "out/bison/synt.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 85 "src/parser/parser.y"
                         { if(debug) printf("DEBUG: Completed statements\n"); }
#line 1306 "out/bison/synt.tab.c"
    break;

  case 7: /* code_section: CODE $@1 statements $@2 END  */
#line 86 "src/parser/parser.y"
                  { 
                if(debug) printf("DEBUG: Completed code section\n");
                (yyval.str) = "CODE_SECTION"; 
              }
#line 1315 "out/bison/synt.tab.c"
    break;

  case 8: /* program_end: END  */
#line 91 "src/parser/parser.y"
                 { 
  if(debug) printf("DEBUG: Parsed program end\n");
  (yyval.str) = "END"; 
}
#line 1324 "out/bison/synt.tab.c"
    break;

  case 9: /* declarations: declaration  */
#line 96 "src/parser/parser.y"
                          { 
  if(debug) printf("DEBUG: Parsed declaration\n");
  (yyval.str) = (yyvsp[0].str); 
}
#line 1333 "out/bison/synt.tab.c"
    break;

  case 10: /* declarations: declarations declaration  */
#line 100 "src/parser/parser.y"
                             { 
    if(debug) printf("DEBUG: Parsed multiple declarations\n");
    (yyval.str) = (yyvsp[-1].str); 
  }
#line 1342 "out/bison/synt.tab.c"
    break;

  case 11: /* declaration: type_declaration  */
#line 105 "src/parser/parser.y"
                              { 
  if(debug) printf("DEBUG: Parsed type declaration\n");
  (yyval.str) = "TYPE_DECLARATION"; 
}
#line 1351 "out/bison/synt.tab.c"
    break;

  case 12: /* declaration: vector_declaration  */
#line 109 "src/parser/parser.y"
                       { 
    if(debug) printf("DEBUG: Parsed vector declaration\n");
    (yyval.str) = "VECTOR_DECLARATION"; 
  }
#line 1360 "out/bison/synt.tab.c"
    break;

  case 13: /* declaration: const_declaration  */
#line 113 "src/parser/parser.y"
                      { 
    if(debug) printf("DEBUG: Parsed const declaration\n");
    (yyval.str) = "CONST_DECLARATION"; 
  }
#line 1369 "out/bison/synt.tab.c"
    break;

  case 14: /* type_declaration: type COLON var_list SEMICOLON  */
#line 118 "src/parser/parser.y"
                                                { 
  if(debug) printf("DEBUG: Completed type declaration\n");
  (yyval.str) = (yyvsp[-3].str); 
}
#line 1378 "out/bison/synt.tab.c"
    break;

  case 15: /* var_list: IDENTIFIER  */
#line 123 "src/parser/parser.y"
                     {
  if(debug) printf("DEBUG: Parsing identifier in var_list: %s\n", (yyvsp[0].str));
  if(isDoubleDeclared((yyvsp[0].str))){
    printf("Semantic error: double declaration of %s, in line %d \n", (yyvsp[0].str), number_of_lines);
    error=1;
    YYERROR;
  }else{
    symbol_table_insert_type((yyvsp[0].str), stocked_type);
    (yyval.str) = (yyvsp[0].str);
  }
}
#line 1394 "out/bison/synt.tab.c"
    break;

  case 16: /* var_list: IDENTIFIER BAR var_list  */
#line 134 "src/parser/parser.y"
                            {
  if(debug) printf("DEBUG: Parsing identifier with bar in var_list: %s\n", (yyvsp[-2].str));
  if(isDoubleDeclared((yyvsp[-2].str))){
    printf("Semantic error: double declaration of %s, in line %d \n", (yyvsp[-2].str), number_of_lines);
    error=1;
    YYERROR;
  }else{
    symbol_table_insert_type((yyvsp[-2].str), stocked_type);
    (yyval.str) = (yyvsp[-2].str);
  }
}
#line 1410 "out/bison/synt.tab.c"
    break;

  case 17: /* vector_declaration: VECTOR COLON IDENTIFIER LBRACKET INTEGER_CONST COMMA INTEGER_CONST COLON type RBRACKET SEMICOLON  */
#line 146 "src/parser/parser.y"
                                                                                                                     {
  if(debug) printf("DEBUG: Parsing vector declaration for: %s\n", (yyvsp[-8].str));
  if(isDoubleDeclared((yyvsp[-8].str))){
    printf("Semantic error: double declaration of %s, in line %d \n", (yyvsp[-8].str), number_of_lines);
    error=1;
    YYERROR;
  }else{
    char vector_type[50];
    sprintf(vector_type, "VECTOR_%s", stocked_type);
    symbol_table_insert_type((yyvsp[-8].str), vector_type);
    (yyval.str) = (yyvsp[-8].str);
  }
}
#line 1428 "out/bison/synt.tab.c"
    break;

  case 18: /* const_declaration: CONST COLON IDENTIFIER ASSIGN constant SEMICOLON  */
#line 160 "src/parser/parser.y"
                                                                    {
  if(debug) printf("DEBUG: Parsing const declaration for: %s\n", (yyvsp[-3].str));
  if(isDoubleDeclared((yyvsp[-3].str))){
    printf("Semantic error: double declaration of %s, in line %d \n", (yyvsp[-3].str), number_of_lines);
    error=1;
    YYERROR;
  }else{
    symbol_table_insert_type((yyvsp[-3].str), "CONST");
    quad(":=", (yyvsp[-1].str), "", (yyvsp[-3].str));
    (yyval.str) = (yyvsp[-3].str);
  }
}
#line 1445 "out/bison/synt.tab.c"
    break;

  case 19: /* type: INTEGER_TYPE  */
#line 173 "src/parser/parser.y"
                   {
    strcpy(stocked_type,"INTEGER");
    (yyval.str) = "INTEGER";
  }
#line 1454 "out/bison/synt.tab.c"
    break;

  case 20: /* type: FLOAT_TYPE  */
#line 177 "src/parser/parser.y"
               {
    strcpy(stocked_type,"FLOAT");
    (yyval.str) = "FLOAT";
  }
#line 1463 "out/bison/synt.tab.c"
    break;

  case 21: /* type: CHAR_TYPE  */
#line 181 "src/parser/parser.y"
              {
    strcpy(stocked_type,"CHAR");
    (yyval.str) = "CHAR";
  }
#line 1472 "out/bison/synt.tab.c"
    break;

  case 22: /* type: STRING_TYPE  */
#line 185 "src/parser/parser.y"
                {
    strcpy(stocked_type,"STRING");
    (yyval.str) = "STRING";
  }
#line 1481 "out/bison/synt.tab.c"
    break;

  case 23: /* statements: statement  */
#line 190 "src/parser/parser.y"
                      { 
  if(debug) printf("DEBUG: Parsed statement\n");
  (yyval.str) = "STATEMENTS"; 
}
#line 1490 "out/bison/synt.tab.c"
    break;

  case 24: /* statements: statements statement  */
#line 194 "src/parser/parser.y"
                         { 
    if(debug) printf("DEBUG: Parsed multiple statements\n");
    (yyval.str) = "STATEMENTS"; 
  }
#line 1499 "out/bison/synt.tab.c"
    break;

  case 25: /* statement: assignment  */
#line 199 "src/parser/parser.y"
                      { 
  if(debug) printf("DEBUG: Parsed assignment statement\n");
  (yyval.str) = "ASSIGNMENT"; 
}
#line 1508 "out/bison/synt.tab.c"
    break;

  case 26: /* statement: read_statement  */
#line 203 "src/parser/parser.y"
                   { 
    if(debug) printf("DEBUG: Parsed read statement\n");
    (yyval.str) = "READ_STATEMENT"; 
  }
#line 1517 "out/bison/synt.tab.c"
    break;

  case 27: /* statement: display_statement  */
#line 207 "src/parser/parser.y"
                      { 
    if(debug) printf("DEBUG: Parsed display statement\n");
    (yyval.str) = "DISPLAY_STATEMENT"; 
  }
#line 1526 "out/bison/synt.tab.c"
    break;

  case 28: /* statement: if_statement  */
#line 211 "src/parser/parser.y"
                 { 
    if(debug) printf("DEBUG: Parsed if statement\n");
    (yyval.str) = "IF_STATEMENT"; 
  }
#line 1535 "out/bison/synt.tab.c"
    break;

  case 29: /* statement: for_statement  */
#line 215 "src/parser/parser.y"
                  { 
    if(debug) printf("DEBUG: Parsed for statement\n");
    (yyval.str) = "FOR_STATEMENT"; 
  }
#line 1544 "out/bison/synt.tab.c"
    break;

  case 30: /* left_hand_side: IDENTIFIER  */
#line 220 "src/parser/parser.y"
                           {
  if(debug) printf("DEBUG: Parsing left-hand side as identifier: %s\n", (yyvsp[0].str));
  element *identifier = symbol_table_search((yyvsp[0].str));
  if(identifier == NULL){
    printf("Semantic error: undeclared identifier %s, in line %d \n", (yyvsp[0].str), number_of_lines);
    error=1;
    YYERROR;
  }
  (yyval.str) = (yyvsp[0].str);
}
#line 1559 "out/bison/synt.tab.c"
    break;

  case 31: /* left_hand_side: array_access  */
#line 230 "src/parser/parser.y"
                 {
    if(debug) printf("DEBUG: Parsing left-hand side as array access: %s\n", (yyvsp[0].str));
    (yyval.str) = (yyvsp[0].str);
  }
#line 1568 "out/bison/synt.tab.c"
    break;

  case 32: /* assignment: left_hand_side ASSIGN expression SEMICOLON  */
#line 235 "src/parser/parser.y"
                                                       {
  if(debug) printf("DEBUG: Parsing assignment for: %s = %s\n", (yyvsp[-3].str), (yyvsp[-1].str));
  if(strchr((yyvsp[-3].str), '[') != NULL){ // Check if it's an array access
    char *array_name = strtok((yyvsp[-3].str), "[");
    char *index = strtok(NULL, "]");
    quad("[]=", (yyvsp[-1].str), index, array_name); // Corrected order: value, index, array
  }else{
    quad(":=", (yyvsp[-1].str), "", (yyvsp[-3].str));
  }
  (yyval.str) = "ASSIGNMENT";
}
#line 1584 "out/bison/synt.tab.c"
    break;

  case 33: /* read_statement: READ LPAREN STRING_CONST COLON AT IDENTIFIER RPAREN SEMICOLON  */
#line 247 "src/parser/parser.y"
                                                                              {
  if(debug) printf("DEBUG: Parsing READ statement for: %s\n", (yyvsp[-2].str));
  element *identifier = symbol_table_search((yyvsp[-2].str));
  if(identifier == NULL){
    printf("Semantic error: undeclared identifier %s, in line %d \n", (yyvsp[-2].str), number_of_lines);
    error=1;
    YYERROR;
  }else{
    quad("READ", (yyvsp[-5].str), "", (yyvsp[-2].str));
    (yyval.str) = "READ";
  }
}
#line 1601 "out/bison/synt.tab.c"
    break;

  case 34: /* display_statement: DISPLAY LPAREN STRING_CONST COLON item RPAREN SEMICOLON  */
#line 260 "src/parser/parser.y"
                                                                           {
  if(debug) printf("DEBUG: Parsing DISPLAY statement\n");
  quad("DISPLAY", (yyvsp[-4].str), (yyvsp[-2].str), "");
  (yyval.str) = "DISPLAY";
}
#line 1611 "out/bison/synt.tab.c"
    break;

  case 35: /* if_statement: IF LPAREN condition RPAREN COLON if_body END  */
#line 266 "src/parser/parser.y"
                                                                     {
  if(debug) printf("DEBUG: Parsed IF statement without ELSE\n");
  sprintf(temp, "%d", Qc);
  quad_updated(qc_saver, 2, temp);
  (yyval.str) = "IF_STATEMENT";
}
#line 1622 "out/bison/synt.tab.c"
    break;

  case 36: /* if_statement: IF LPAREN condition RPAREN COLON if_body ELSE COLON else_body END  */
#line 272 "src/parser/parser.y"
                                                                      {
  if(debug) printf("DEBUG: Parsed IF-ELSE statement\n");
  sprintf(temp, "%d", Qc);
  quad_updated(qc_saver, 2, temp);
  (yyval.str) = "IF_STATEMENT";
}
#line 1633 "out/bison/synt.tab.c"
    break;

  case 37: /* if_body: statements  */
#line 279 "src/parser/parser.y"
                    {
  if(debug) printf("DEBUG: Parsed IF body\n");
  qc_saver = Qc;
  quad("BR", " ", " ", " ");
  (yyval.str) = "IF_BODY";
}
#line 1644 "out/bison/synt.tab.c"
    break;

  case 38: /* else_body: statements  */
#line 286 "src/parser/parser.y"
                      { 
  if(debug) printf("DEBUG: Parsed ELSE body\n");
  (yyval.str) = "ELSE_BODY"; 
}
#line 1653 "out/bison/synt.tab.c"
    break;

  case 39: /* for_statement: FOR LPAREN IDENTIFIER COLON expression COLON condition RPAREN statements END  */
#line 291 "src/parser/parser.y"
                                                                                            {
  if(debug) printf("DEBUG: Parsed FOR statement\n");
  char* loop_var = (yyvsp[-7].str);
  char* step = (yyvsp[-5].str);
  quad("+", loop_var, step, loop_var); // Increment: Counter = Counter + step
  int loop_start = qc_saver; // Condition’s quadruplet index
  sprintf(temp, "%d", loop_start);
  quad("BR", "", "", temp); // Jump back to condition
  sprintf(temp, "%d", Qc);
  quad_updated(qc_saver, 2, temp); // Update condition’s exit target
  (yyval.str) = "FOR_STATEMENT";
}
#line 1670 "out/bison/synt.tab.c"
    break;

  case 40: /* condition: expression comparision_operator expression  */
#line 303 "src/parser/parser.y"
                                                      {
  if(debug) printf("DEBUG: Parsed condition with comparison\n");
  sprintf(temp, "t%d", tempCounter++);
  qc_saver = Qc;
  if(strcmp((yyvsp[-1].str), ".G.") == 0){
    quad("BLE", (yyvsp[-2].str), (yyvsp[0].str), " ");
  }
  else if(strcmp((yyvsp[-1].str), ".GE.") == 0){
    quad("BL", (yyvsp[-2].str), (yyvsp[0].str), " ");
  }
  else if(strcmp((yyvsp[-1].str), ".L.") == 0){
    quad("BGE", (yyvsp[-2].str), (yyvsp[0].str), " ");
  }
  else if(strcmp((yyvsp[-1].str), ".LE.") == 0){
    quad("BG", (yyvsp[-2].str), (yyvsp[0].str), " ");
  }
  else if(strcmp((yyvsp[-1].str), ".EQ.") == 0){
    quad("BNE", (yyvsp[-2].str), (yyvsp[0].str), " ");
  }
  else if(strcmp((yyvsp[-1].str), ".DI.") == 0){
    quad("BE", (yyvsp[-2].str), (yyvsp[0].str), " ");
  }
  (yyval.str) = temp;
}
#line 1699 "out/bison/synt.tab.c"
    break;

  case 41: /* condition: LPAREN condition RPAREN  */
#line 327 "src/parser/parser.y"
                            { 
    if(debug) printf("DEBUG: Parsed parenthesized condition\n");
    (yyval.str) = (yyvsp[-1].str); 
  }
#line 1708 "out/bison/synt.tab.c"
    break;

  case 42: /* $@3: %empty  */
#line 331 "src/parser/parser.y"
                          {
    if(debug) printf("DEBUG: Parsed AND operator\n");
    (yyvsp[0].str) = ".AND.";
  }
#line 1717 "out/bison/synt.tab.c"
    break;

  case 43: /* condition: condition LOGICAL_AND $@3 condition  */
#line 334 "src/parser/parser.y"
              {
    if(debug) printf("DEBUG: Parsed logical AND condition\n");
    sprintf(temp, "t%d", tempCounter++);
    quad("AND", (yyvsp[-3].str), (yyvsp[0].str), temp);
    (yyval.str) = temp;
  }
#line 1728 "out/bison/synt.tab.c"
    break;

  case 44: /* $@4: %empty  */
#line 340 "src/parser/parser.y"
                         { 
    if(debug) printf("DEBUG: Parsed OR operator\n");
    (yyvsp[0].str) = ".OR."; 
  }
#line 1737 "out/bison/synt.tab.c"
    break;

  case 45: /* condition: condition LOGICAL_OR $@4 condition  */
#line 343 "src/parser/parser.y"
              {
    if(debug) printf("DEBUG: Parsed logical OR condition\n");
    sprintf(temp, "t%d", tempCounter++);
    quad("OR", (yyvsp[-3].str), (yyvsp[0].str), temp);
    (yyval.str) = temp;
  }
#line 1748 "out/bison/synt.tab.c"
    break;

  case 46: /* condition: LOGICAL_NOT condition  */
#line 349 "src/parser/parser.y"
                          {
    if(debug) printf("DEBUG: Parsed logical NOT condition\n");
    sprintf(temp, "t%d", tempCounter++);
    quad("NOT", (yyvsp[0].str), "", temp);
    (yyval.str) = temp;
  }
#line 1759 "out/bison/synt.tab.c"
    break;

  case 47: /* comparision_operator: GREATER  */
#line 357 "src/parser/parser.y"
                              { 
  if(debug) printf("DEBUG: Parsed GREATER operator\n");
  (yyval.str) = ".G."; 
}
#line 1768 "out/bison/synt.tab.c"
    break;

  case 48: /* comparision_operator: GREATER_OR_EQUAL  */
#line 361 "src/parser/parser.y"
                     { 
    if(debug) printf("DEBUG: Parsed GREATER_OR_EQUAL operator\n");
    (yyval.str) = ".GE."; 
  }
#line 1777 "out/bison/synt.tab.c"
    break;

  case 49: /* comparision_operator: LESS  */
#line 365 "src/parser/parser.y"
         { 
    if(debug) printf("DEBUG: Parsed LESS operator\n");
    (yyval.str) = ".L."; 
  }
#line 1786 "out/bison/synt.tab.c"
    break;

  case 50: /* comparision_operator: LESS_OR_EQUAL  */
#line 369 "src/parser/parser.y"
                  { 
    if(debug) printf("DEBUG: Parsed LESS_OR_EQUAL operator\n");
    (yyval.str) = ".LE."; 
  }
#line 1795 "out/bison/synt.tab.c"
    break;

  case 51: /* comparision_operator: EQUAL  */
#line 373 "src/parser/parser.y"
          { 
    if(debug) printf("DEBUG: Parsed EQUAL operator\n");
    (yyval.str) = ".EQ."; 
  }
#line 1804 "out/bison/synt.tab.c"
    break;

  case 52: /* comparision_operator: NOT_EQUAL  */
#line 377 "src/parser/parser.y"
              { 
    if(debug) printf("DEBUG: Parsed NOT_EQUAL operator\n");
    (yyval.str) = ".DI."; 
  }
#line 1813 "out/bison/synt.tab.c"
    break;

  case 53: /* expression: expression math_operator term  */
#line 383 "src/parser/parser.y"
                                          {
  if(debug) printf("DEBUG: Parsed expression with math op\n");
  sprintf(temp, "t%d", tempCounter++);
  quad((yyvsp[-1].str), (yyvsp[-2].str), (yyvsp[0].str), temp);
  (yyval.str) = temp;
}
#line 1824 "out/bison/synt.tab.c"
    break;

  case 54: /* expression: term  */
#line 389 "src/parser/parser.y"
         { 
    if(debug) printf("DEBUG: Parsed expression as term: %s\n", (yyvsp[0].str));
    (yyval.str) = (yyvsp[0].str); 
  }
#line 1833 "out/bison/synt.tab.c"
    break;

  case 55: /* term: item  */
#line 394 "src/parser/parser.y"
           { 
  if(debug) printf("DEBUG: Parsed term as item: %s\n", (yyvsp[0].str));
  (yyval.str) = (yyvsp[0].str); 
}
#line 1842 "out/bison/synt.tab.c"
    break;

  case 56: /* term: LPAREN expression RPAREN  */
#line 398 "src/parser/parser.y"
                             { 
    if(debug) printf("DEBUG: Parsed term with parentheses\n");
    (yyval.str) = (yyvsp[-1].str); 
  }
#line 1851 "out/bison/synt.tab.c"
    break;

  case 57: /* math_operator: PLUS  */
#line 403 "src/parser/parser.y"
                    { 
  if(debug) printf("DEBUG: Parsed PLUS operator\n");
    (yyval.str) = "+"; 
}
#line 1860 "out/bison/synt.tab.c"
    break;

  case 58: /* math_operator: MINUS  */
#line 407 "src/parser/parser.y"
          { 
    if(debug) printf("DEBUG: Parsed MINUS operator\n");
    (yyval.str) = "-"; 
  }
#line 1869 "out/bison/synt.tab.c"
    break;

  case 59: /* math_operator: MUL  */
#line 411 "src/parser/parser.y"
        { 
    if(debug) printf("DEBUG: Parsed MUL operator\n");
    (yyval.str) = "*"; 
  }
#line 1878 "out/bison/synt.tab.c"
    break;

  case 60: /* math_operator: DIV  */
#line 415 "src/parser/parser.y"
        { 
    if(debug) printf("DEBUG: Parsed DIV operator\n");
    (yyval.str) = "/"; 
  }
#line 1887 "out/bison/synt.tab.c"
    break;

  case 61: /* item: IDENTIFIER  */
#line 420 "src/parser/parser.y"
                 {
  if(debug) printf("DEBUG: Parsing item as identifier: %s\n", (yyvsp[0].str));
  element *identifier = symbol_table_search((yyvsp[0].str));
  if(identifier == NULL){
    printf("Semantic error: undeclared identifier %s, in line %d \n", (yyvsp[0].str), number_of_lines);
    error=1;
    YYERROR;
  }
  (yyval.str) = (yyvsp[0].str);
}
#line 1902 "out/bison/synt.tab.c"
    break;

  case 62: /* item: constant  */
#line 430 "src/parser/parser.y"
             { 
    if(debug) printf("DEBUG: Parsing item as constant: %s\n", (yyvsp[0].str));
    (yyval.str) = (yyvsp[0].str); 
  }
#line 1911 "out/bison/synt.tab.c"
    break;

  case 63: /* item: array_access  */
#line 434 "src/parser/parser.y"
                 { 
    if(debug) printf("DEBUG: Parsing item as array access\n");
    (yyval.str) = (yyvsp[0].str); 
  }
#line 1920 "out/bison/synt.tab.c"
    break;

  case 64: /* array_access: IDENTIFIER LBRACKET expression RBRACKET  */
#line 439 "src/parser/parser.y"
                                                      {
  if(debug) printf("DEBUG: Parsing array access for: %s\n", (yyvsp[-3].str));
  element *identifier = symbol_table_search((yyvsp[-3].str));
  if(identifier == NULL){
    printf("Semantic error: undeclared identifier %s, in line %d \n", (yyvsp[-3].str), number_of_lines);
    error=1;
    YYERROR;
  }
  char *result = (char*)malloc(strlen((yyvsp[-3].str)) + strlen((yyvsp[-1].str)) + 3);
  sprintf(result, "%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));
  (yyval.str) = result;
}
#line 1937 "out/bison/synt.tab.c"
    break;

  case 65: /* constant: INTEGER_CONST  */
#line 452 "src/parser/parser.y"
                        { 
  if(debug) printf("DEBUG: Parsed integer constant: %s\n", (yyvsp[0].str));
  (yyval.str) = (yyvsp[0].str); 
}
#line 1946 "out/bison/synt.tab.c"
    break;

  case 66: /* constant: FLOAT_CONST  */
#line 456 "src/parser/parser.y"
                { 
    if(debug) printf("DEBUG: Parsed float constant: %s\n", (yyvsp[0].str));
  (yyval.str) = (yyvsp[0].str); 
  }
#line 1955 "out/bison/synt.tab.c"
    break;

  case 67: /* constant: CHAR_CONST  */
#line 460 "src/parser/parser.y"
               { 
    if(debug) printf("DEBUG: Parsed char constant: %s\n", (yyvsp[0].str));
    (yyval.str) = (yyvsp[0].str); 
  }
#line 1964 "out/bison/synt.tab.c"
    break;

  case 68: /* constant: STRING_CONST  */
#line 464 "src/parser/parser.y"
                 { 
    if(debug) printf("DEBUG: Parsed string constant: %s\n", (yyvsp[0].str));
    (yyval.str) = (yyvsp[0].str); 
  }
#line 1973 "out/bison/synt.tab.c"
    break;


#line 1977 "out/bison/synt.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 469 "src/parser/parser.y"


void yyerror(const char* s)
{
  printf ("Syntax error in line %d column %d \n", number_of_lines, column_position);
  // exit(1); // Comment this out to avoid immediate exit on syntax error
}
