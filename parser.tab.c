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

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"util.h"
#include"absyn.h"
#include"symbol.h"
#include"prabsyn.h"
#include"quadruple.h"

#define DEBUG

void yyerror(const char*);
int yylex (void);

A_pos pos = 0;

int line = 1;

A_stmts root_stmts = NULL;

S_table var_table = NULL;

extern int nextquad;


#line 98 "parser.tab.c"

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
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_AND = 9,                        /* AND  */
  YYSYMBOL_OR = 10,                        /* OR  */
  YYSYMBOL_EQ = 11,                        /* EQ  */
  YYSYMBOL_NE = 12,                        /* NE  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_17_ = 17,                       /* '!'  */
  YYSYMBOL_18_ = 18,                       /* '='  */
  YYSYMBOL_19_ = 19,                       /* '-'  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '*'  */
  YYSYMBOL_22_ = 22,                       /* '/'  */
  YYSYMBOL_NEG = 23,                       /* NEG  */
  YYSYMBOL_STAR = 24,                      /* STAR  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* ','  */
  YYSYMBOL_30_ = 30,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_fun_def_list = 33,              /* fun_def_list  */
  YYSYMBOL_fun_def = 34,                   /* fun_def  */
  YYSYMBOL_var_dec_seq = 35,               /* var_dec_seq  */
  YYSYMBOL_var_dec_seq1 = 36,              /* var_dec_seq1  */
  YYSYMBOL_var_dec = 37,                   /* var_dec  */
  YYSYMBOL_declarator = 38,                /* declarator  */
  YYSYMBOL_stmts = 39,                     /* stmts  */
  YYSYMBOL_stmt = 40,                      /* stmt  */
  YYSYMBOL_condition = 41,                 /* condition  */
  YYSYMBOL_M = 42,                         /* M  */
  YYSYMBOL_N = 43,                         /* N  */
  YYSYMBOL_bs = 44,                        /* bs  */
  YYSYMBOL_es = 45,                        /* es  */
  YYSYMBOL_exp_seq = 46,                   /* exp_seq  */
  YYSYMBOL_exp = 47                        /* exp  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


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
       2,     2,     2,    17,     2,     2,     2,     2,     2,     2,
      25,    26,    21,    20,    29,    19,     2,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
       2,    18,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    23,    24
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    76,    77,    80,    87,    88,    90,    91,
      95,   104,   115,   119,   157,   161,   169,   173,   178,   183,
     191,   201,   219,   227,   236,   243,   247,   253,   259,   265,
     271,   277,   283,   291,   296,   301,   305,   310,   311,   315,
     326,   334,   344,   353,   360,   367,   383,   396,   400
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID", "IF",
  "ELSE", "WHILE", "INT", "AND", "OR", "EQ", "NE", "LT", "LE", "GT", "GE",
  "'!'", "'='", "'-'", "'+'", "'*'", "'/'", "NEG", "STAR", "'('", "')'",
  "'{'", "'}'", "','", "';'", "$accept", "program", "fun_def_list",
  "fun_def", "var_dec_seq", "var_dec_seq1", "var_dec", "declarator",
  "stmts", "stmt", "condition", "M", "N", "bs", "es", "exp_seq", "exp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-35)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      20,    30,    35,    20,   -61,    22,   -61,   -61,    50,     8,
      33,    52,   -61,    64,    40,   -61,    56,    50,    29,   -61,
     -61,     6,   -61,   -61,   -61,    88,    29,    89,    60,   -61,
     -61,    49,    67,   -61,    82,    29,    29,   -61,    29,    29,
      29,    29,    45,    71,   -61,   -61,     6,   -61,    89,   -25,
      89,   -16,   -16,   -61,   -61,    16,    45,    45,    54,    78,
      45,   -61,   -61,    29,   -61,    58,   -61,   -61,   -61,    29,
      29,    29,    29,    29,    29,    62,    89,   -61,    45,    45,
     -61,    89,    89,    89,    89,    89,    89,   -61,   -61,    96,
      80,   -61,     6,    87,    90,     6,   -61,    91,   109,   -61,
     110,   -61,   -61,   -61,    93,     6,    94,   -61,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,     6,     0,
       0,     7,     8,    12,     0,    10,     0,     0,     0,    12,
      13,     0,     9,    48,    40,    39,     0,    11,     0,    33,
      16,     0,    33,    14,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,    18,     5,     0,    17,    41,     0,
      37,    43,    42,    44,    45,    48,     0,     0,     0,     0,
       0,    15,    47,     0,    24,     0,    33,    33,    33,     0,
       0,     0,     0,     0,     0,     0,    38,    25,     0,     0,
      35,    26,    27,    28,    29,    30,    31,    33,    23,    22,
       0,    35,     0,     0,    33,     0,    36,    33,    19,    36,
       0,    21,    33,    35,     0,     0,    33,    36,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,   114,   -61,   -61,    61,   107,   -19,    77,
     -41,   -27,   -61,   -60,   -42,   -61,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    10,    11,    31,    15,    32,    33,
      58,    46,   100,    90,    98,    49,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    62,    43,    34,    63,    40,    41,    23,    37,    24,
      25,    28,    13,    29,     9,    64,    65,    48,    50,    75,
      51,    52,    53,    54,     1,   -32,   -32,    26,    34,    14,
      23,    93,    24,    25,     5,     6,    30,    88,    89,    78,
      79,    80,   -32,   104,    19,    76,    55,     8,    24,    25,
      26,    81,    82,    83,    84,    85,    86,   101,     9,    16,
      91,    14,    56,    66,    67,   108,    26,    66,    67,    12,
      57,    66,    67,    94,    34,   103,    97,    34,    22,    44,
      68,    17,    18,    21,    77,    42,   106,    34,    87,    69,
      70,    71,    72,    73,    74,    45,    60,    38,    39,    40,
      41,    38,    39,    40,    41,    66,    35,    92,    38,    39,
      40,    41,    47,    36,    95,   -34,   102,     7,    96,    99,
     105,    20,   107,    61
};

static const yytype_int8 yycheck[] =
{
      18,    26,    29,    21,    29,    21,    22,     1,    26,     3,
       4,     5,     4,     7,     8,    56,    57,    35,    36,    60,
      38,    39,    40,    41,     4,     9,    10,    21,    46,    21,
       1,    91,     3,     4,     4,     0,    30,    78,    79,    66,
      67,    68,    26,   103,     4,    63,     1,    25,     3,     4,
      21,    69,    70,    71,    72,    73,    74,    99,     8,    26,
      87,    21,    17,     9,    10,   107,    21,     9,    10,     8,
      25,     9,    10,    92,    92,   102,    95,    95,    17,    30,
      26,    29,    18,    27,    26,    25,   105,   105,    26,    11,
      12,    13,    14,    15,    16,    28,    25,    19,    20,    21,
      22,    19,    20,    21,    22,     9,    18,    27,    19,    20,
      21,    22,    30,    25,    27,     6,     6,     3,    28,    28,
      27,    14,    28,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    32,    33,    34,     4,     0,    34,    25,     8,
      35,    36,    37,     4,    21,    38,    26,    29,    18,     4,
      38,    27,    37,     1,     3,     4,    21,    47,     5,     7,
      30,    37,    39,    40,    47,    18,    25,    47,    19,    20,
      21,    22,    25,    42,    30,    28,    42,    30,    47,    46,
      47,    47,    47,    47,    47,     1,    17,    25,    41,    47,
      25,    40,    26,    29,    41,    41,     9,    10,    26,    11,
      12,    13,    14,    15,    16,    41,    47,    26,    42,    42,
      42,    47,    47,    47,    47,    47,    47,    26,    41,    41,
      44,    42,    27,    44,    39,    27,    28,    39,    45,    28,
      43,    45,     6,    42,    44,    27,    39,    28,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    35,    35,    36,    36,
      37,    37,    38,    38,    39,    39,    40,    40,    40,    40,
      40,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    42,    43,    44,    45,    46,    46,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     8,     0,     1,     1,     3,
       2,     4,     1,     2,     1,     3,     1,     2,     2,    10,
      18,    11,     4,     4,     2,     3,     3,     3,     3,     3,
       3,     3,     1,     0,     0,     0,     0,     1,     3,     1,
       1,     3,     3,     3,     3,     3,     2,     4,     1
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
  case 5: /* fun_def: ID ID '(' var_dec_seq ')' '{' stmts '}'  */
#line 81 "parser.y"
       {
         //root_stmts = A_reverseStmts($7);
         free((yyvsp[-1].stmt));
       }
#line 1195 "parser.tab.c"
    break;

  case 10: /* var_dec: INT declarator  */
#line 96 "parser.y"
       {
         //$$ = A_VarDec(pos, S_Symbol($2), S_Symbol($1), 0);
         S_symbol sym = S_Symbol((yyvsp[0].dctor)->name);
         Q_addr addr = find_free();
         Q_operand op = Q_VarOperand((yyvsp[0].dctor)->name, addr);
         op->type = (yyvsp[0].dctor)->type;
         S_enter(var_table, sym, op);
       }
#line 1208 "parser.tab.c"
    break;

  case 11: /* var_dec: INT ID '=' exp  */
#line 105 "parser.y"
       {
         //$$ = A_VarDec(pos, S_Symbol($2), S_Symbol($1), $4);
         S_symbol sym = S_Symbol((yyvsp[-2].sval));
         Q_addr addr = find_free();
         Q_operand op = Q_VarOperand((yyvsp[-2].sval), addr);
         S_enter(var_table, sym, op);
         gen(Q_assignOp, (yyvsp[0].exp)->result, NULL, op);
       }
#line 1221 "parser.tab.c"
    break;

  case 12: /* declarator: ID  */
#line 116 "parser.y"
      {
         (yyval.dctor) = Q_Declarator((yyvsp[0].sval), Q_Int());
      }
#line 1229 "parser.tab.c"
    break;

  case 13: /* declarator: '*' declarator  */
#line 120 "parser.y"
      {
         Q_type inner = (yyvsp[0].dctor)->type;
         (yyval.dctor) = Q_Declarator((yyvsp[0].dctor)->name, Q_Pointer(inner));
      }
#line 1238 "parser.tab.c"
    break;

  case 14: /* stmts: stmt  */
#line 158 "parser.y"
     {
      (yyval.stmt) = (yyvsp[0].stmt);
     }
#line 1246 "parser.tab.c"
    break;

  case 15: /* stmts: stmts M stmt  */
#line 162 "parser.y"
     {
      (yyval.stmt) = Q_Stmt();
      backpatch((yyvsp[-2].stmt)->nextList, (yyvsp[-1].m)->instr);
      (yyval.stmt)->nextList = (yyvsp[0].stmt)->nextList;
      free((yyvsp[-2].stmt)); free((yyvsp[-1].m)); free((yyvsp[0].stmt));
     }
#line 1257 "parser.tab.c"
    break;

  case 16: /* stmt: ';'  */
#line 170 "parser.y"
    {
      (yyval.stmt) = Q_Stmt();
    }
#line 1265 "parser.tab.c"
    break;

  case 17: /* stmt: exp ';'  */
#line 174 "parser.y"
    {
      //$$ = A_ExpStmt(pos, $1);
      (yyval.stmt) = Q_Stmt();
    }
#line 1274 "parser.tab.c"
    break;

  case 18: /* stmt: var_dec ';'  */
#line 179 "parser.y"
    {
      //$$ = A_DecStmt(pos, $1);
      (yyval.stmt) = Q_Stmt();
    }
#line 1283 "parser.tab.c"
    break;

  case 19: /* stmt: IF '(' condition ')' M bs '{' stmts '}' es  */
#line 184 "parser.y"
    {
      //$$ = A_IfStmt(pos, $3, $6, NULL);
      (yyval.stmt) = Q_Stmt();
      backpatch((yyvsp[-7].con)->trueList, (yyvsp[-5].m)->instr);
      (yyval.stmt)->nextList = merge((yyvsp[-7].con)->falseList, (yyvsp[-2].stmt)->nextList);
      free((yyvsp[-7].con)); free((yyvsp[-2].stmt));
    }
#line 1295 "parser.tab.c"
    break;

  case 20: /* stmt: IF '(' condition ')' M bs '{' stmts '}' es N ELSE M bs '{' stmts '}' es  */
#line 192 "parser.y"
    {
      //$$ = A_IfStmt(pos, $3, A_reverseStmts($6), A_reverseStmts($10));
      (yyval.stmt) = Q_Stmt();
      backpatch((yyvsp[-15].con)->trueList, (yyvsp[-13].m)->instr);
      backpatch((yyvsp[-15].con)->falseList, (yyvsp[-5].m)->instr);
      quadrupleList temp = merge((yyvsp[-10].stmt)->nextList, (yyvsp[-7].stmt)->nextList);
      (yyval.stmt)->nextList = merge(temp, (yyvsp[-2].stmt)->nextList);
      free((yyvsp[-15].con)); free((yyvsp[-13].m)); free((yyvsp[-10].stmt)); free((yyvsp[-7].stmt)); free((yyvsp[-5].m)); free((yyvsp[-2].stmt));
    }
#line 1309 "parser.tab.c"
    break;

  case 21: /* stmt: WHILE M '(' condition ')' M bs '{' stmts '}' es  */
#line 202 "parser.y"
    {
      (yyval.stmt) = Q_Stmt();
      backpatch((yyvsp[-2].stmt)->nextList, (yyvsp[-9].m)->instr);
      backpatch((yyvsp[-7].con)->trueList, (yyvsp[-5].m)->instr);
      (yyval.stmt)->nextList = (yyvsp[-7].con)->falseList;
      gen(Q_bOp, NULL, NULL, Q_ImmOperand((yyvsp[-9].m)->instr));
      free((yyvsp[-9].m)); free((yyvsp[-7].con)); free((yyvsp[-5].m)); free((yyvsp[-2].stmt));
    }
#line 1322 "parser.tab.c"
    break;

  case 22: /* condition: condition OR M condition  */
#line 220 "parser.y"
   {
      (yyval.con) = Q_Condition();
      backpatch((yyvsp[-3].con)->falseList, (yyvsp[-1].m)->instr);
      (yyval.con)->trueList = merge((yyvsp[-3].con)->trueList, (yyvsp[0].con)->trueList);
      (yyval.con)->falseList = (yyvsp[0].con)->falseList;
      free((yyvsp[-1].m)); free((yyvsp[-3].con)); free((yyvsp[0].con));
   }
#line 1334 "parser.tab.c"
    break;

  case 23: /* condition: condition AND M condition  */
#line 228 "parser.y"
   {
      (yyval.con) = Q_Condition();
      printf("AND\n");
      backpatch((yyvsp[-3].con)->trueList, (yyvsp[-1].m)->instr);
      (yyval.con)->trueList = (yyvsp[0].con)->trueList;
      (yyval.con)->falseList = merge((yyvsp[-3].con)->falseList, (yyvsp[0].con)->falseList);
      free((yyvsp[-1].m)); free((yyvsp[-3].con)); free((yyvsp[0].con));
   }
#line 1347 "parser.tab.c"
    break;

  case 24: /* condition: '!' condition  */
#line 237 "parser.y"
   {
      (yyval.con) = Q_Condition();
      (yyval.con)->trueList = (yyvsp[0].con)->falseList;
      (yyval.con)->falseList = (yyvsp[0].con)->trueList;
      free((yyvsp[0].con));
   }
#line 1358 "parser.tab.c"
    break;

  case 25: /* condition: '(' condition ')'  */
#line 244 "parser.y"
   {
      (yyval.con) = (yyvsp[-1].con);
   }
#line 1366 "parser.tab.c"
    break;

  case 26: /* condition: exp EQ exp  */
#line 248 "parser.y"
   {
      (yyval.con) = Q_Condition();
      (yyval.con)->trueList = makelist(gen(Q_beqOp, (yyvsp[-2].exp)->result, (yyvsp[0].exp)->result, NULL));
      (yyval.con)->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
#line 1376 "parser.tab.c"
    break;

  case 27: /* condition: exp NE exp  */
#line 254 "parser.y"
   {
      (yyval.con) = Q_Condition();
      (yyval.con)->trueList = makelist(gen(Q_bneOp, (yyvsp[-2].exp)->result, (yyvsp[0].exp)->result, NULL));
      (yyval.con)->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
#line 1386 "parser.tab.c"
    break;

  case 28: /* condition: exp LT exp  */
#line 260 "parser.y"
   {
      (yyval.con) = Q_Condition();
      (yyval.con)->trueList = makelist(gen(Q_bltOp, (yyvsp[-2].exp)->result, (yyvsp[0].exp)->result, NULL));
      (yyval.con)->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
#line 1396 "parser.tab.c"
    break;

  case 29: /* condition: exp LE exp  */
#line 266 "parser.y"
   {
      (yyval.con) = Q_Condition();
      (yyval.con)->trueList = makelist(gen(Q_bleOp, (yyvsp[-2].exp)->result, (yyvsp[0].exp)->result, NULL));
      (yyval.con)->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
#line 1406 "parser.tab.c"
    break;

  case 30: /* condition: exp GT exp  */
#line 272 "parser.y"
   {
      (yyval.con) = Q_Condition();
      (yyval.con)->trueList = makelist(gen(Q_bgtOp, (yyvsp[-2].exp)->result, (yyvsp[0].exp)->result, NULL));
      (yyval.con)->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
#line 1416 "parser.tab.c"
    break;

  case 31: /* condition: exp GE exp  */
#line 278 "parser.y"
   {
      (yyval.con) = Q_Condition();
      (yyval.con)->trueList = makelist(gen(Q_bgeOp, (yyvsp[-2].exp)->result, (yyvsp[0].exp)->result, NULL));
      (yyval.con)->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
#line 1426 "parser.tab.c"
    break;

  case 32: /* condition: error  */
#line 284 "parser.y"
   {
      (yyval.con) = Q_Condition();
      fprintf(stderr, "Syntax error when parsing condition in line %d\n", line);
      yyerrok;
   }
#line 1436 "parser.tab.c"
    break;

  case 33: /* M: %empty  */
#line 291 "parser.y"
  {
   (yyval.m) = checked_malloc(sizeof(*(yyval.m)));
   (yyval.m)->instr = nextquad;
  }
#line 1445 "parser.tab.c"
    break;

  case 34: /* N: %empty  */
#line 296 "parser.y"
  {
   (yyval.stmt) = Q_Stmt();
   (yyval.stmt)->nextList = makelist(gen(Q_bOp, NULL, NULL, NULL));
  }
#line 1454 "parser.tab.c"
    break;

  case 35: /* bs: %empty  */
#line 301 "parser.y"
  {
   S_beginScope(var_table);
  }
#line 1462 "parser.tab.c"
    break;

  case 36: /* es: %empty  */
#line 305 "parser.y"
  {
   S_endScope(var_table);
  }
#line 1470 "parser.tab.c"
    break;

  case 39: /* exp: ID  */
#line 316 "parser.y"
   {
#ifdef DEBUG
      printf("Found exp ID:%s\n", (yyvsp[0].sval));
#endif
      // $$ = A_VarExp(pos, A_SimpleVar(pos, S_Symbol($1)));
      S_symbol sym = S_Symbol((yyvsp[0].sval));
      Q_operand op = S_look(var_table, sym);
      if(op==NULL) fprintf(stderr, "Undefined variable: %s\n", (yyvsp[0].sval));
      (yyval.exp) = Q_Exp(op);
   }
#line 1485 "parser.tab.c"
    break;

  case 40: /* exp: NUM  */
#line 327 "parser.y"
   {
#ifdef DEBUG
      printf("Found exp INT:%d\n", (yyvsp[0].ival));
#endif
      //$$ = A_IntExp(pos, $1);
      (yyval.exp) = Q_Exp(Q_ImmOperand((yyvsp[0].ival)));
   }
#line 1497 "parser.tab.c"
    break;

  case 41: /* exp: ID '=' exp  */
#line 335 "parser.y"
   {
      //$$ = A_AssignExp(pos, A_SimpleVar(pos, S_Symbol($1)), $3);
      //Q_operand temp = Q_TempOperand();
      S_symbol sym = S_Symbol((yyvsp[-2].sval));
      Q_operand dest = S_look(var_table, sym);
      if(dest==NULL) fprintf(stderr, "Undefined variable: %s\n", (yyvsp[-2].sval));
      gen(Q_assignOp, (yyvsp[0].exp)->result, NULL, dest);
      (yyval.exp) = Q_Exp(dest);
   }
#line 1511 "parser.tab.c"
    break;

  case 42: /* exp: exp '+' exp  */
#line 345 "parser.y"
   {
      //$$ = A_OpExp(pos, A_plusOp, $1, $3);
      Q_operand dest = Q_TempOperand();
      if(Q_typeEqual((yyvsp[-2].exp)->result->type, (yyvsp[0].exp)->result->type)==0)
         yyerror("warning: type differs");
      gen(Q_plusOp, (yyvsp[-2].exp)->result, (yyvsp[0].exp)->result, dest);
      (yyval.exp) = Q_Exp(dest);
   }
#line 1524 "parser.tab.c"
    break;

  case 43: /* exp: exp '-' exp  */
#line 354 "parser.y"
   {
      //$$ = A_OpExp(pos, A_minusOp, $1, $3);
      Q_operand dest = Q_TempOperand();
      gen(Q_minusOp, (yyvsp[-2].exp)->result, (yyvsp[0].exp)->result, dest);
      (yyval.exp) = Q_Exp(dest);
   }
#line 1535 "parser.tab.c"
    break;

  case 44: /* exp: exp '*' exp  */
#line 361 "parser.y"
   {
      //$$ = A_OpExp(pos, A_timesOp, $1, $3);
      Q_operand dest = Q_TempOperand();
      gen(Q_timesOp, (yyvsp[-2].exp)->result, (yyvsp[0].exp)->result, dest);
      (yyval.exp) = Q_Exp(dest);
   }
#line 1546 "parser.tab.c"
    break;

  case 45: /* exp: exp '/' exp  */
#line 368 "parser.y"
   {
      //$$ = A_OpExp(pos, A_divideOp, $1, $3);
      Q_operand dest = Q_TempOperand();
      gen(Q_divideOp, (yyvsp[-2].exp)->result, (yyvsp[0].exp)->result, dest);
      (yyval.exp) = Q_Exp(dest);
   }
#line 1557 "parser.tab.c"
    break;

  case 46: /* exp: '*' exp  */
#line 384 "parser.y"
   {
      Q_type type;
      if((yyvsp[0].exp)->result->type->kind==Q_pointer){
         type = (yyvsp[0].exp)->result->type->u.points;
      }else{
         yyerror("warning");
         type = Q_Int();
      }
      Q_operand dest = Q_RefOperand((yyvsp[0].exp)->result, type);
      gen(Q_starOp, (yyvsp[0].exp)->result, NULL, dest);
      (yyval.exp) = Q_Exp(dest);
   }
#line 1574 "parser.tab.c"
    break;

  case 47: /* exp: ID '(' exp_seq ')'  */
#line 397 "parser.y"
   {
      printf("No implementation of function call.\n");
   }
#line 1582 "parser.tab.c"
    break;

  case 48: /* exp: error  */
#line 401 "parser.y"
   {
      fprintf(stderr, "Syntax error when parsing expression in line %d\n", line);
      yyerrok;
   }
#line 1591 "parser.tab.c"
    break;


#line 1595 "parser.tab.c"

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

#line 406 "parser.y"


void yyerror(const char* s){
	fprintf(stderr, "%s\n", s);
}
