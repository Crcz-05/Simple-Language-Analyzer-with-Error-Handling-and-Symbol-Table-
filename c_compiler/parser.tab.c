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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "symbol_table.h"

void yyerror(const char *s);
int yylex(void);

extern int line_no;   /* ✅ from lexer */

ASTNode* root;
char currentType[20];

int syntaxError = 0;   /* ✅ track syntax errors */

#line 90 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_FLOAT_NUMBER = 4,               /* FLOAT_NUMBER  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_STRING_TYPE = 7,                /* STRING_TYPE  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_BOOL = 11,                      /* BOOL  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 23,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 24,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 25,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 26,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 27,                /* MOD_ASSIGN  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_LSHIFT = 31,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 32,                    /* RSHIFT  */
  YYSYMBOL_INC = 33,                       /* INC  */
  YYSYMBOL_DEC = 34,                       /* DEC  */
  YYSYMBOL_LOWER_THAN_ELSE = 35,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_36_ = 36,                       /* '|'  */
  YYSYMBOL_37_ = 37,                       /* '^'  */
  YYSYMBOL_38_ = 38,                       /* '&'  */
  YYSYMBOL_39_ = 39,                       /* '<'  */
  YYSYMBOL_40_ = 40,                       /* '>'  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_45_ = 45,                       /* '%'  */
  YYSYMBOL_UMINUS = 46,                    /* UMINUS  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_external_list = 55,             /* external_list  */
  YYSYMBOL_external = 56,                  /* external  */
  YYSYMBOL_function = 57,                  /* function  */
  YYSYMBOL_parameter_list = 58,            /* parameter_list  */
  YYSYMBOL_parameter = 59,                 /* parameter  */
  YYSYMBOL_type = 60,                      /* type  */
  YYSYMBOL_declaration = 61,               /* declaration  */
  YYSYMBOL_init_list = 62,                 /* init_list  */
  YYSYMBOL_init = 63,                      /* init  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_compound_statement = 65,        /* compound_statement  */
  YYSYMBOL_statement_list = 66,            /* statement_list  */
  YYSYMBOL_expression_statement = 67,      /* expression_statement  */
  YYSYMBOL_selection_statement = 68,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 69,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 70,            /* jump_statement  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_assignment_expression = 72,     /* assignment_expression  */
  YYSYMBOL_additive_expression = 73,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 74, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 75,          /* unary_expression  */
  YYSYMBOL_primary_expression = 76,        /* primary_expression  */
  YYSYMBOL_argument_list = 77              /* argument_list  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
       2,     2,     2,     2,     2,     2,     2,    45,    38,     2,
      48,    49,    43,    41,    50,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      39,     2,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    36,    52,     2,     2,     2,     2,
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
      35,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    79,    82,    86,    87,    92,    96,   104,
     107,   111,   119,   120,   121,   122,   123,   124,   129,   133,
     136,   140,   147,   158,   159,   160,   161,   162,   163,   167,
     168,   172,   173,   178,   179,   183,   184,   188,   189,   193,
     194,   198,   203,   210,   220,   225,   228,   231,   235,   238,
     241,   244,   248,   251,   256,   257,   258,   260,   267,   274,
     279,   282
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER",
  "FLOAT_NUMBER", "ID", "STRING", "STRING_TYPE", "INT", "FLOAT", "CHAR",
  "BOOL", "VOID", "IF", "ELSE", "WHILE", "FOR", "RETURN", "EQ", "NE", "LE",
  "GE", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "OR", "AND", "NOT", "LSHIFT", "RSHIFT", "INC", "DEC",
  "LOWER_THAN_ELSE", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UMINUS", "';'", "'('", "')'", "','", "'{'", "'}'",
  "$accept", "program", "external_list", "external", "function",
  "parameter_list", "parameter", "type", "declaration", "init_list",
  "init", "statement", "compound_statement", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "expression", "assignment_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "primary_expression", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     153,   -88,   -88,   -88,   -88,   -88,   -88,    12,   153,   -88,
     -88,    39,   -28,   -88,   -88,    -2,     6,   -88,   -88,   136,
      -4,    43,   -88,   -88,    14,   -88,    56,   151,   136,   -88,
     -88,    10,    36,   -88,   -88,    31,     5,   -88,    58,    88,
     -88,   136,   136,   -88,   -88,   -88,    16,   151,   151,   151,
     151,   151,    22,   -88,    31,   153,   -88,   -88,   -88,    26,
     -88,    36,    36,   -88,   -88,   -88,    47,    70,    74,    11,
     -88,   -88,    43,    77,   -88,   -88,    81,   -88,   -88,   -88,
     -88,    78,   -88,   -88,   -88,   136,   136,   136,   111,   -88,
      79,   -88,   -88,   -88,   -88,   -88,    82,    86,   111,   -88,
      96,    96,   136,   113,   -88,    87,    96,    96,   -88,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    17,    12,    13,    14,    15,    16,     0,     2,     4,
       5,     0,     0,     1,     3,    21,    18,    20,     6,     0,
       0,     0,    54,    55,    57,    56,     0,     0,     0,    22,
      41,    44,    47,    51,    53,     0,     0,    10,     0,    21,
      19,     0,     0,    58,    57,    52,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,    11,    42,    61,     0,
      59,    45,    46,    48,    49,    50,     0,     0,     0,     0,
      34,    30,     0,     0,    32,    24,     0,    23,    25,    26,
      27,     0,     7,     9,    43,     0,     0,     0,     0,    40,
       0,    28,    29,    31,    33,    60,     0,     0,     0,    39,
       0,     0,     0,    35,    37,     0,     0,     0,    36,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   -88,   122,   -88,   -88,    90,     2,    13,   -88,
     116,   -29,   -11,   -88,   -87,   -88,   -88,   -88,   -19,   105,
     -88,    73,    -9,   -88,   -88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    36,    37,    72,    73,    16,
      17,    74,    75,    76,    77,    78,    79,    80,    81,    30,
      31,    32,    33,    34,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      29,    98,    11,     1,     2,     3,     4,     5,     6,    46,
      11,   102,    13,    12,    22,    23,    24,    25,    45,    18,
      19,    12,    38,    58,    53,    22,    23,    24,    25,     1,
       2,     3,     4,     5,     6,    66,    41,    67,    68,    69,
      63,    64,    65,    82,    15,    35,    20,    93,    39,    26,
      90,    47,    48,    27,    54,    55,    21,    38,    89,    28,
      26,    43,    42,    56,    27,    60,    95,    96,    97,    70,
      28,   103,   104,    52,    71,    84,    85,   108,   109,    49,
      50,    51,    52,   105,    22,    23,    24,    25,     1,     2,
       3,     4,     5,     6,    66,    86,    67,    68,    69,    22,
      23,    24,    25,     1,     2,     3,     4,     5,     6,    66,
      19,    67,    68,    69,    22,    23,    24,    25,    87,    26,
      61,    62,    88,    27,    91,    94,    99,   106,    70,    28,
      14,   100,    52,    92,    26,   101,   107,    40,    27,    22,
      23,    24,    25,    70,    28,    83,    57,    52,     0,    26,
       0,     0,     0,    27,    22,    23,    44,    25,    70,    28,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,    27,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,    26,
       0,     0,     0,    27,     0,     0,     0,     0,     0,    28
};

static const yytype_int8 yycheck[] =
{
      19,    88,     0,     7,     8,     9,    10,    11,    12,    28,
       8,    98,     0,     0,     3,     4,     5,     6,    27,    47,
      22,     8,    20,    42,    35,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    22,    15,    16,    17,
      49,    50,    51,    54,     5,    49,    48,    76,     5,    38,
      69,    41,    42,    42,    49,    50,    50,    55,    47,    48,
      38,     5,    48,     5,    42,    49,    85,    86,    87,    47,
      48,   100,   101,    51,    52,    49,    50,   106,   107,    43,
      44,    45,    51,   102,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    48,    15,    16,    17,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      22,    15,    16,    17,     3,     4,     5,     6,    48,    38,
      47,    48,    48,    42,    47,    47,    47,    14,    47,    48,
       8,    49,    51,    52,    38,    49,    49,    21,    42,     3,
       4,     5,     6,    47,    48,    55,    41,    51,    -1,    38,
      -1,    -1,    -1,    42,     3,     4,     5,     6,    47,    48,
       7,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    12,    54,    55,    56,
      57,    60,    61,     0,    56,     5,    62,    63,    47,    22,
      48,    50,     3,     4,     5,     6,    38,    42,    48,    71,
      72,    73,    74,    75,    76,    49,    58,    59,    60,     5,
      63,    22,    48,     5,     5,    75,    71,    41,    42,    43,
      44,    45,    51,    65,    49,    50,     5,    72,    71,    77,
      49,    74,    74,    75,    75,    75,    13,    15,    16,    17,
      47,    52,    60,    61,    64,    65,    66,    67,    68,    69,
      70,    71,    65,    59,    49,    50,    48,    48,    48,    47,
      71,    47,    52,    64,    47,    71,    71,    71,    67,    47,
      49,    49,    67,    64,    64,    71,    14,    49,    64,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    60,    60,    60,    60,    60,    60,    61,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    72,    72,    72,    73,    73,    73,    74,    74,
      74,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     6,     5,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     3,
       2,     2,     1,     2,     1,     5,     7,     5,     7,     3,
       2,     1,     3,     4,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     1,     1,     1,     1,     1,     2,     3,
       3,     1
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
  case 2: /* program: external_list  */
#line 74 "parser.y"
                    { root = (yyvsp[0].node); }
#line 1246 "parser.tab.c"
    break;

  case 3: /* external_list: external_list external  */
#line 79 "parser.y"
                             {
        (yyval.node) = createStatementList((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1254 "parser.tab.c"
    break;

  case 4: /* external_list: external  */
#line 82 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1260 "parser.tab.c"
    break;

  case 7: /* function: type ID '(' parameter_list ')' compound_statement  */
#line 92 "parser.y"
                                                        {
        insertSymbol((yyvsp[-4].str), "function");
        (yyval.node) = (yyvsp[0].node);
    }
#line 1269 "parser.tab.c"
    break;

  case 8: /* function: type ID '(' ')' compound_statement  */
#line 96 "parser.y"
                                         {
        insertSymbol((yyvsp[-3].str), "function");
        (yyval.node) = (yyvsp[0].node);
    }
#line 1278 "parser.tab.c"
    break;

  case 9: /* parameter_list: parameter_list ',' parameter  */
#line 104 "parser.y"
                                   {
        (yyval.node) = createStatementList((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1286 "parser.tab.c"
    break;

  case 10: /* parameter_list: parameter  */
#line 107 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1292 "parser.tab.c"
    break;

  case 11: /* parameter: type ID  */
#line 111 "parser.y"
              {
        insertSymbol((yyvsp[0].str), currentType);
        (yyval.node) = createDeclaration((yyvsp[0].str), NULL);
    }
#line 1301 "parser.tab.c"
    break;

  case 12: /* type: INT  */
#line 119 "parser.y"
            { strcpy(currentType, "int"); }
#line 1307 "parser.tab.c"
    break;

  case 13: /* type: FLOAT  */
#line 120 "parser.y"
            { strcpy(currentType, "float"); }
#line 1313 "parser.tab.c"
    break;

  case 14: /* type: CHAR  */
#line 121 "parser.y"
            { strcpy(currentType, "char"); }
#line 1319 "parser.tab.c"
    break;

  case 15: /* type: BOOL  */
#line 122 "parser.y"
            { strcpy(currentType, "bool"); }
#line 1325 "parser.tab.c"
    break;

  case 16: /* type: VOID  */
#line 123 "parser.y"
            { strcpy(currentType, "void"); }
#line 1331 "parser.tab.c"
    break;

  case 17: /* type: STRING_TYPE  */
#line 124 "parser.y"
                  { strcpy(currentType, "string"); }
#line 1337 "parser.tab.c"
    break;

  case 18: /* declaration: type init_list  */
#line 129 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1343 "parser.tab.c"
    break;

  case 19: /* init_list: init_list ',' init  */
#line 133 "parser.y"
                         {
        (yyval.node) = createStatementList((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1351 "parser.tab.c"
    break;

  case 20: /* init_list: init  */
#line 136 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1357 "parser.tab.c"
    break;

  case 21: /* init: ID  */
#line 140 "parser.y"
         {
        if (searchSymbol((yyvsp[0].str)) != -1)
            printf("Semantic Warning: Redeclaration of %s\n", (yyvsp[0].str));

        insertSymbol((yyvsp[0].str), currentType);
        (yyval.node) = createDeclaration((yyvsp[0].str), NULL);
    }
#line 1369 "parser.tab.c"
    break;

  case 22: /* init: ID ASSIGN expression  */
#line 147 "parser.y"
                           {
        if (searchSymbol((yyvsp[-2].str)) != -1)
            printf("Semantic Warning: Redeclaration of %s\n", (yyvsp[-2].str));

        insertSymbol((yyvsp[-2].str), currentType);
        (yyval.node) = createDeclaration((yyvsp[-2].str), (yyvsp[0].node));
    }
#line 1381 "parser.tab.c"
    break;

  case 23: /* statement: expression_statement  */
#line 158 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1387 "parser.tab.c"
    break;

  case 24: /* statement: compound_statement  */
#line 159 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1393 "parser.tab.c"
    break;

  case 25: /* statement: selection_statement  */
#line 160 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1399 "parser.tab.c"
    break;

  case 26: /* statement: iteration_statement  */
#line 161 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1405 "parser.tab.c"
    break;

  case 27: /* statement: jump_statement  */
#line 162 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1411 "parser.tab.c"
    break;

  case 28: /* statement: declaration ';'  */
#line 163 "parser.y"
                      { (yyval.node) = (yyvsp[-1].node); }
#line 1417 "parser.tab.c"
    break;

  case 29: /* compound_statement: '{' statement_list '}'  */
#line 167 "parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 1423 "parser.tab.c"
    break;

  case 30: /* compound_statement: '{' '}'  */
#line 168 "parser.y"
              { (yyval.node) = NULL; }
#line 1429 "parser.tab.c"
    break;

  case 31: /* statement_list: statement_list statement  */
#line 172 "parser.y"
                               { (yyval.node) = createStatementList((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1435 "parser.tab.c"
    break;

  case 32: /* statement_list: statement  */
#line 173 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1441 "parser.tab.c"
    break;

  case 33: /* expression_statement: expression ';'  */
#line 178 "parser.y"
                     { (yyval.node) = (yyvsp[-1].node); }
#line 1447 "parser.tab.c"
    break;

  case 34: /* expression_statement: ';'  */
#line 179 "parser.y"
          { (yyval.node) = NULL; }
#line 1453 "parser.tab.c"
    break;

  case 35: /* selection_statement: IF '(' expression ')' statement  */
#line 183 "parser.y"
                                                            { (yyval.node) = (yyvsp[-2].node); }
#line 1459 "parser.tab.c"
    break;

  case 36: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 184 "parser.y"
                                                     { (yyval.node) = (yyvsp[-4].node); }
#line 1465 "parser.tab.c"
    break;

  case 37: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 188 "parser.y"
                                         { (yyval.node) = (yyvsp[-2].node); }
#line 1471 "parser.tab.c"
    break;

  case 38: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 189 "parser.y"
                                                                                 { (yyval.node) = (yyvsp[-4].node); }
#line 1477 "parser.tab.c"
    break;

  case 39: /* jump_statement: RETURN expression ';'  */
#line 193 "parser.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1483 "parser.tab.c"
    break;

  case 40: /* jump_statement: RETURN ';'  */
#line 194 "parser.y"
                 { (yyval.node) = NULL; }
#line 1489 "parser.tab.c"
    break;

  case 42: /* assignment_expression: ID ASSIGN assignment_expression  */
#line 203 "parser.y"
                                      {
        if (searchSymbol((yyvsp[-2].str)) == -1)
            printf("Semantic Error at line %d: Undeclared variable %s\n", line_no, (yyvsp[-2].str));

        (yyval.node) = createBinary('=', createIdentifier((yyvsp[-2].str)), (yyvsp[0].node));
    }
#line 1500 "parser.tab.c"
    break;

  case 43: /* assignment_expression: ID '(' argument_list ')'  */
#line 210 "parser.y"
                               {
        if (searchSymbol((yyvsp[-3].str)) == -1) {
            if (strcmp((yyvsp[-3].str), "printf") == 0 || strcmp((yyvsp[-3].str), "scanf") == 0)
                insertSymbol((yyvsp[-3].str), "function");
            else
                printf("Semantic Error at line %d: Function %s not declared\n", line_no, (yyvsp[-3].str));
        }
        (yyval.node) = createFunctionCall((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 1514 "parser.tab.c"
    break;

  case 44: /* assignment_expression: additive_expression  */
#line 220 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1520 "parser.tab.c"
    break;

  case 45: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 225 "parser.y"
                                                        {
        (yyval.node) = createBinary('+', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1528 "parser.tab.c"
    break;

  case 46: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 228 "parser.y"
                                                        {
        (yyval.node) = createBinary('-', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1536 "parser.tab.c"
    break;

  case 47: /* additive_expression: multiplicative_expression  */
#line 231 "parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 1542 "parser.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression '*' unary_expression  */
#line 235 "parser.y"
                                                     {
        (yyval.node) = createBinary('*', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1550 "parser.tab.c"
    break;

  case 49: /* multiplicative_expression: multiplicative_expression '/' unary_expression  */
#line 238 "parser.y"
                                                     {
        (yyval.node) = createBinary('/', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1558 "parser.tab.c"
    break;

  case 50: /* multiplicative_expression: multiplicative_expression '%' unary_expression  */
#line 241 "parser.y"
                                                     {
        (yyval.node) = createBinary('%', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1566 "parser.tab.c"
    break;

  case 51: /* multiplicative_expression: unary_expression  */
#line 244 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1572 "parser.tab.c"
    break;

  case 52: /* unary_expression: '-' unary_expression  */
#line 248 "parser.y"
                                        {
        (yyval.node) = createBinary('~', (yyvsp[0].node), NULL);
    }
#line 1580 "parser.tab.c"
    break;

  case 53: /* unary_expression: primary_expression  */
#line 251 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1586 "parser.tab.c"
    break;

  case 54: /* primary_expression: NUMBER  */
#line 256 "parser.y"
             { (yyval.node) = createNumber((yyvsp[0].num)); }
#line 1592 "parser.tab.c"
    break;

  case 55: /* primary_expression: FLOAT_NUMBER  */
#line 257 "parser.y"
                   { (yyval.node) = createNumber((yyvsp[0].num)); }
#line 1598 "parser.tab.c"
    break;

  case 56: /* primary_expression: STRING  */
#line 258 "parser.y"
             { (yyval.node) = createString((yyvsp[0].str)); }
#line 1604 "parser.tab.c"
    break;

  case 57: /* primary_expression: ID  */
#line 260 "parser.y"
         {
        if (searchSymbol((yyvsp[0].str)) == -1)
            printf("Semantic Error at line %d: Undeclared variable %s\n", line_no, (yyvsp[0].str));

        (yyval.node) = createIdentifier((yyvsp[0].str));
    }
#line 1615 "parser.tab.c"
    break;

  case 58: /* primary_expression: '&' ID  */
#line 267 "parser.y"
             {
        if (searchSymbol((yyvsp[0].str)) == -1)
            printf("Semantic Error at line %d: Undeclared variable %s\n", line_no, (yyvsp[0].str));

        (yyval.node) = createBinary('&', createIdentifier((yyvsp[0].str)), NULL);
    }
#line 1626 "parser.tab.c"
    break;

  case 59: /* primary_expression: '(' expression ')'  */
#line 274 "parser.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 1632 "parser.tab.c"
    break;

  case 60: /* argument_list: argument_list ',' expression  */
#line 279 "parser.y"
                                   {
        (yyval.node) = createArgumentList((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1640 "parser.tab.c"
    break;

  case 61: /* argument_list: expression  */
#line 282 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1646 "parser.tab.c"
    break;


#line 1650 "parser.tab.c"

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

#line 285 "parser.y"


/* ================= ERROR ================= */
void yyerror(const char *s)
{
    syntaxError = 1;
    printf("Syntax Error at line %d: %s\n", line_no, s);
}

/* ================= MAIN ================= */
int main()
{
    printf("\n========== COMPILATION STARTED ==========\n");

    printf("\n--- LEXICAL ANALYSIS ---\n\n");

    int result = yyparse();

    if (result == 0 && syntaxError == 0) {

        printf("\n✔ Lexical Analysis Completed\n");

        printf("\n--- SYNTAX ANALYSIS ---\n");
        printf("✔ No Syntax Errors\n");

        printf("\n--- SEMANTIC ANALYSIS ---\n");
        printf("✔ Completed Successfully\n");

        printf("\n--- PARSE TREE ---\n\n");
        if (root)
            printAST(root);

        printf("\n--- SYMBOL TABLE ---\n");
        displaySymbolTable();

        printf("\n========== COMPILATION SUCCESSFUL ==========\n");
    }
    else {
        printf("\n--- SYNTAX ANALYSIS ---\n");
        printf("✖ Compilation Failed due to Syntax Errors\n");

        printf("\n========== COMPILATION FAILED ==========\n");
    }

    return 0;
}
