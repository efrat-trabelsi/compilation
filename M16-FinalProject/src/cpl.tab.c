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
#line 1 "cpl.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "code_gen.h"

extern int yylex (void);

int has_errors = 0;

extern char* last_expression_result;
extern char* prev_temp;

int in_loop = 0;
int in_switch = 0;


#line 91 "cpl.tab.c"

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

#include "cpl.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUM = 4,                        /* NUM  */
  YYSYMBOL_BREAK = 5,                      /* BREAK  */
  YYSYMBOL_CASE = 6,                       /* CASE  */
  YYSYMBOL_DEFAULT = 7,                    /* DEFAULT  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_INPUT = 11,                     /* INPUT  */
  YYSYMBOL_INT = 12,                       /* INT  */
  YYSYMBOL_OUTPUT = 13,                    /* OUTPUT  */
  YYSYMBOL_SWITCH = 14,                    /* SWITCH  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_RELOP = 16,                     /* RELOP  */
  YYSYMBOL_ADDOP = 17,                     /* ADDOP  */
  YYSYMBOL_MULOP = 18,                     /* MULOP  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_CAST = 22,                      /* CAST  */
  YYSYMBOL_23_ = 23,                       /* ':'  */
  YYSYMBOL_24_ = 24,                       /* ';'  */
  YYSYMBOL_25_ = 25,                       /* ','  */
  YYSYMBOL_26_ = 26,                       /* '='  */
  YYSYMBOL_27_ = 27,                       /* '('  */
  YYSYMBOL_28_ = 28,                       /* ')'  */
  YYSYMBOL_29_ = 29,                       /* '{'  */
  YYSYMBOL_30_ = 30,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_declarations = 33,              /* declarations  */
  YYSYMBOL_declaration = 34,               /* declaration  */
  YYSYMBOL_type = 35,                      /* type  */
  YYSYMBOL_idlist = 36,                    /* idlist  */
  YYSYMBOL_stmt = 37,                      /* stmt  */
  YYSYMBOL_assignment_stmt = 38,           /* assignment_stmt  */
  YYSYMBOL_input_stmt = 39,                /* input_stmt  */
  YYSYMBOL_output_stmt = 40,               /* output_stmt  */
  YYSYMBOL_if_stmt = 41,                   /* if_stmt  */
  YYSYMBOL_42_1 = 42,                      /* @1  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_while_stmt = 44,                /* while_stmt  */
  YYSYMBOL_45_3 = 45,                      /* @3  */
  YYSYMBOL_46_4 = 46,                      /* @4  */
  YYSYMBOL_switch_stmt = 47,               /* switch_stmt  */
  YYSYMBOL_48_5 = 48,                      /* @5  */
  YYSYMBOL_49_6 = 49,                      /* $@6  */
  YYSYMBOL_caselist = 50,                  /* caselist  */
  YYSYMBOL_51_7 = 51,                      /* $@7  */
  YYSYMBOL_break_stmt = 52,                /* break_stmt  */
  YYSYMBOL_stmt_block = 53,                /* stmt_block  */
  YYSYMBOL_stmtlist = 54,                  /* stmtlist  */
  YYSYMBOL_boolexpr = 55,                  /* boolexpr  */
  YYSYMBOL_boolterm = 56,                  /* boolterm  */
  YYSYMBOL_boolfactor = 57,                /* boolfactor  */
  YYSYMBOL_expression = 58,                /* expression  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_factor = 60                     /* factor  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   103

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
      27,    28,     2,     2,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,    24,
       2,    26,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    71,    72,    74,    81,    85,    90,   100,
     110,   111,   112,   113,   114,   115,   116,   117,   119,   141,
     155,   165,   170,   164,   181,   186,   180,   199,   209,   198,
     226,   225,   236,   238,   250,   255,   256,   258,   265,   271,
     278,   284,   291,   299,   315,   322,   337,   344,   350,   359,
     375
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUM", "BREAK",
  "CASE", "DEFAULT", "ELSE", "FLOAT", "IF", "INPUT", "INT", "OUTPUT",
  "SWITCH", "WHILE", "RELOP", "ADDOP", "MULOP", "OR", "AND", "NOT", "CAST",
  "':'", "';'", "','", "'='", "'('", "')'", "'{'", "'}'", "$accept",
  "program", "declarations", "declaration", "type", "idlist", "stmt",
  "assignment_stmt", "input_stmt", "output_stmt", "if_stmt", "@1", "$@2",
  "while_stmt", "@3", "@4", "switch_stmt", "@5", "$@6", "caselist", "$@7",
  "break_stmt", "stmt_block", "stmtlist", "boolexpr", "boolterm",
  "boolfactor", "expression", "term", "factor", YY_NULLPTR
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

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -61,     6,    -2,   -61,   -61,   -61,   -61,   -16,   -61,     5,
      62,    27,    12,    19,    43,    52,    53,    54,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,    58,   -61,    -1,   -61,    42,    80,    -1,    -1,    57,
     -61,   -61,   -61,    59,    -1,    48,    67,   -61,    60,    -6,
      68,   -61,    45,    61,    -5,    -3,    42,    -1,    30,    -1,
     -61,    -1,    42,    42,   -61,    42,    -1,    66,    70,    63,
      32,    31,   -61,    67,   -61,    38,    68,    39,   -61,    74,
     -61,   -61,   -61,   -61,   -61,   -61,    85,   -61,    39,   -61,
      69,   -61,    39,    91,    73,   -61,    75,   -61,   -61,   -61,
     -61,    26,    39,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     9,    36,     3,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    34,
      35,    10,    11,    12,    13,    14,    15,    16,    17,     7,
       6,     0,     8,     0,    33,     0,     0,     0,     0,     0,
       5,    49,    50,     0,     0,     0,    44,    46,     0,     0,
      38,    40,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,    47,    43,    45,     0,    37,     0,    39,    42,
      19,    20,    27,    25,    48,    41,     0,    32,     0,    22,
       0,    26,     0,     0,     0,    23,     0,    28,    30,    36,
      36,     0,    31,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,   -61,   -61,   -61,   -60,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,    95,   -22,    11,    36,    35,   -33,    44,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    31,     7,    20,    21,    22,    23,
      24,    77,    92,    25,    39,    88,    26,    87,    99,    90,
     100,    27,    28,     9,    49,    50,    51,    52,    46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      45,     4,    41,    42,    54,    55,     3,    10,    12,    11,
      13,    58,    59,    63,    59,    14,    15,    86,    16,    17,
      18,    43,    64,    68,    71,    69,    44,     5,    91,    12,
      32,    13,    95,    79,     5,    19,    14,    15,    33,    16,
      17,    18,    12,    34,    13,    41,    42,    59,    59,    14,
      15,    63,    16,    17,    18,     5,   103,    63,    72,    84,
      83,    66,    59,    48,    43,    59,    85,    70,     5,    44,
      35,    29,    60,    75,    30,    93,    94,   101,   102,    36,
      37,    38,    40,    53,    56,    61,    57,    62,    65,    67,
      80,    59,    82,    89,    81,    96,    97,     8,    98,    76,
      78,    74,     0,    73
};

static const yytype_int8 yycheck[] =
{
      33,     3,     3,     4,    37,    38,     0,    23,     3,    25,
       5,    44,    17,    19,    17,    10,    11,    77,    13,    14,
      15,    22,    28,    28,    57,    28,    27,    29,    88,     3,
       3,     5,    92,    66,    29,    30,    10,    11,    26,    13,
      14,    15,     3,    24,     5,     3,     4,    17,    17,    10,
      11,    19,    13,    14,    15,    29,    30,    19,    28,    28,
      28,    16,    17,    21,    22,    17,    28,    56,    29,    27,
      27,     9,    24,    62,    12,     6,     7,    99,   100,    27,
      27,    27,    24,     3,    27,    18,    27,    27,    20,    28,
      24,    17,    29,     8,    24,     4,    23,     2,    23,    63,
      65,    61,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    33,     0,     3,    29,    34,    36,    53,    54,
      23,    25,     3,     5,    10,    11,    13,    14,    15,    30,
      37,    38,    39,    40,    41,    44,    47,    52,    53,     9,
      12,    35,     3,    26,    24,    27,    27,    27,    27,    45,
      24,     3,     4,    22,    27,    58,    59,    60,    21,    55,
      56,    57,    58,     3,    58,    58,    27,    27,    58,    17,
      24,    18,    27,    19,    28,    20,    16,    28,    28,    28,
      55,    58,    28,    59,    60,    55,    56,    42,    57,    58,
      24,    24,    29,    28,    28,    28,    37,    48,    46,     8,
      50,    37,    43,     6,     7,    37,     4,    23,    23,    49,
      51,    54,    54,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    35,    35,    36,    36,
      37,    37,    37,    37,    37,    37,    37,    37,    38,    39,
      40,    42,    43,    41,    45,    46,    44,    48,    49,    47,
      51,    50,    50,    52,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     4,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       5,     0,     0,     9,     0,     0,     7,     0,     0,    12,
       0,     6,     0,     2,     3,     2,     0,     3,     1,     3,
       1,     4,     3,     3,     1,     3,     1,     3,     4,     1,
       1
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
  case 2: /* program: declarations stmt_block  */
#line 65 "cpl.y"
                {
			if (!has_errors) {
				emit_halt();
			}
		}
#line 1206 "cpl.tab.c"
    break;

  case 5: /* declaration: idlist ':' type ';'  */
#line 75 "cpl.y"
                        {
				printf("Declaration: type %s\n",
						(yyvsp[-1].type_val) == INT_TYPE ? "int": "float");
				update_idlist_types((yyvsp[-1].type_val));
			}
#line 1216 "cpl.tab.c"
    break;

  case 6: /* type: INT  */
#line 82 "cpl.y"
        {
		(yyval.type_val) = INT_TYPE;
		}
#line 1224 "cpl.tab.c"
    break;

  case 7: /* type: FLOAT  */
#line 86 "cpl.y"
        {
		(yyval.type_val) = FLOAT_TYPE;
	}
#line 1232 "cpl.tab.c"
    break;

  case 8: /* idlist: idlist ',' ID  */
#line 91 "cpl.y"
                {
		  if (lookup_symbol((yyvsp[0].name)) != -1) {
			yyerror_format("Semantic: variable '%s' already declared", (yyvsp[0].name));
			has_errors = 1;
			} else {
				add_symbol((yyvsp[0].name), -1);
				mark_pending_symbol((yyvsp[0].name));
			}
		}
#line 1246 "cpl.tab.c"
    break;

  case 9: /* idlist: ID  */
#line 100 "cpl.y"
                     {
			if (lookup_symbol((yyvsp[0].name)) != -1) {
				yyerror_format("Semantic: variable '%s' already declared", (yyvsp[0].name));
				has_errors = 1;
			} else {
				add_symbol((yyvsp[0].name), -1);
				mark_pending_symbol((yyvsp[0].name));
			}
		}
#line 1260 "cpl.tab.c"
    break;

  case 18: /* assignment_stmt: ID '=' expression ';'  */
#line 120 "cpl.y"
                                {
					int var_index = lookup_symbol((yyvsp[-3].name));
					if (var_index == -1) {
						yyerror_format("Semantic: variable '%s' not declared", (yyvsp[-3].name));
						has_errors = 1;
					} else {
						int var_type = get_symbol_type((yyvsp[-3].name));
						int expr_type = (yyvsp[-1].expr_val).type;
						
						if (var_type == expr_type || 
							(var_type == FLOAT_TYPE && expr_type == INT_TYPE)) {
							printf("Assignment to %s (type compatible)\n", (yyvsp[-3].name));
							last_expression_result = (yyvsp[-1].expr_val).temp_name;
							emit_assignment((yyvsp[-3].name), var_type, expr_type);
						} else {
							yyerror_format("Semantic: type mismatch in assignment to '%s'", (yyvsp[-3].name));
							has_errors = 1;
						}
					} 
				}
#line 1285 "cpl.tab.c"
    break;

  case 19: /* input_stmt: INPUT '(' ID ')' ';'  */
#line 142 "cpl.y"
                        {
				int var_index = lookup_symbol((yyvsp[-2].name));
				if (var_index == -1) {
					yyerror_format("Semantic: variable '%s' not declared", (yyvsp[-2].name));
					has_errors = 1;
				} else {
					int var_type = get_symbol_type((yyvsp[-2].name));
					printf("Input to %s (type: %s)\n", (yyvsp[-2].name), 
						   var_type == INT_TYPE ? "int" : "float");
					emit_input((yyvsp[-2].name), var_type);
				}
			}
#line 1302 "cpl.tab.c"
    break;

  case 20: /* output_stmt: OUTPUT '(' expression ')' ';'  */
#line 156 "cpl.y"
                        {
				int expr_type = (yyvsp[-2].expr_val).type;
				printf("Output statement (type: %s)\n", 
					   expr_type == INT_TYPE ? "int" : "float");
				last_expression_result = (yyvsp[-2].expr_val).temp_name;
				emit_output(expr_type);
			}
#line 1314 "cpl.tab.c"
    break;

  case 21: /* @1: %empty  */
#line 165 "cpl.y"
                {
			// Save the label for the jump after ELSE
			(yyval.type_val) = emit_jump_if_zero_placeholder((yyvsp[-1].expr_val).temp_name);
		}
#line 1323 "cpl.tab.c"
    break;

  case 22: /* $@2: %empty  */
#line 170 "cpl.y"
                {
			(yyvsp[0].type_val) = emit_jump_placeholder();
			patch_instruction((yyvsp[-2].type_val), instruction_count + 1);
		}
#line 1332 "cpl.tab.c"
    break;

  case 23: /* if_stmt: IF '(' boolexpr ')' @1 stmt ELSE $@2 stmt  */
#line 175 "cpl.y"
                {
			patch_instruction((yyvsp[-2].type_val), instruction_count + 1);
			printf("If-Else statement completed\n");
		}
#line 1341 "cpl.tab.c"
    break;

  case 24: /* @3: %empty  */
#line 181 "cpl.y"
                        {
				in_loop++;
				(yyval.type_val) = instruction_count + 1;
			}
#line 1350 "cpl.tab.c"
    break;

  case 25: /* @4: %empty  */
#line 186 "cpl.y"
                        {
				(yyval.type_val) = emit_jump_if_zero_placeholder((yyvsp[-1].expr_val).temp_name);
			}
#line 1358 "cpl.tab.c"
    break;

  case 26: /* while_stmt: WHILE @3 '(' boolexpr ')' @4 stmt  */
#line 190 "cpl.y"
                        {
				emit_unconditional_jump((yyvsp[-5].type_val));
				patch_instruction((yyvsp[-1].type_val), instruction_count + 1);
				patch_all_breaks(instruction_count + 1);
				in_loop--;
				printf("While statement completed\n");
			}
#line 1370 "cpl.tab.c"
    break;

  case 27: /* @5: %empty  */
#line 199 "cpl.y"
                        {
				if ((yyvsp[-2].expr_val).type != INT_TYPE) {
					yyerror("Semantic: switch expression must be integer");
					has_errors = 1;
				}
				in_switch++;
				emit_switch_start((yyvsp[-2].expr_val).temp_name);
				strcpy((yyval.expr_val).temp_name, (yyvsp[-2].expr_val).temp_name);
			}
#line 1384 "cpl.tab.c"
    break;

  case 28: /* $@6: %empty  */
#line 209 "cpl.y"
                        {
				// Patch the last case to jump to default (current location)
                if (case_count > 0) {
                    int last_case_index = case_count - 1;
                    patch_instruction(case_table[last_case_index].jump_instruction_index, 
                                    get_current_instruction());
                }
			}
#line 1397 "cpl.tab.c"
    break;

  case 29: /* switch_stmt: SWITCH '(' expression ')' '{' @5 caselist DEFAULT ':' $@6 stmtlist '}'  */
#line 218 "cpl.y"
                        {
				patch_all_breaks(get_current_instruction());
				in_switch--;
				reset_case_table();
				printf("Switch statement completed\n");
			}
#line 1408 "cpl.tab.c"
    break;

  case 30: /* $@7: %empty  */
#line 226 "cpl.y"
                {
			if ((yyvsp[-1].num_val).type != INT_TYPE) {
				yyerror("Semantic: case value must be integer");
				has_errors = 1;
			} else {
				emit_case_jump_placeholder((yyvsp[-1].num_val).ival, (yyvsp[-4].expr_val).temp_name);
				printf("Case %d\n", (yyvsp[-1].num_val).ival);
             }
		}
#line 1422 "cpl.tab.c"
    break;

  case 33: /* break_stmt: BREAK ';'  */
#line 239 "cpl.y"
                        {
				if (in_loop == 0 && in_switch == 0) {
					yyerror("Syntax: break statement not within loop or switch");
					has_errors = 1;
				} else {
					int break_jump = emit_jump_placeholder();
					add_break_jump(break_jump);
					printf("Break statement\n");
				}
			}
#line 1437 "cpl.tab.c"
    break;

  case 34: /* stmt_block: '{' stmtlist '}'  */
#line 251 "cpl.y"
                        { 
				printf("Statement block\n"); 
			}
#line 1445 "cpl.tab.c"
    break;

  case 37: /* boolexpr: boolexpr OR boolterm  */
#line 259 "cpl.y"
                {
			printf("Boolean OR\n");
			emit_logical_or((yyvsp[-2].expr_val).temp_name, (yyvsp[0].expr_val).temp_name);
			(yyval.expr_val).type = INT_TYPE;
			strcpy((yyval.expr_val).temp_name, last_expression_result);		
		}
#line 1456 "cpl.tab.c"
    break;

  case 38: /* boolexpr: boolterm  */
#line 266 "cpl.y"
                {
			(yyval.expr_val).type = (yyvsp[0].expr_val).type;
			strcpy((yyval.expr_val).temp_name, (yyvsp[0].expr_val).temp_name);
		}
#line 1465 "cpl.tab.c"
    break;

  case 39: /* boolterm: boolterm AND boolfactor  */
#line 272 "cpl.y"
                {
			printf("Boolean AND\n");
			emit_logical_and((yyvsp[-2].expr_val).temp_name, (yyvsp[0].expr_val).temp_name);
			(yyval.expr_val).type = INT_TYPE;
			strcpy((yyval.expr_val).temp_name, last_expression_result);
		}
#line 1476 "cpl.tab.c"
    break;

  case 40: /* boolterm: boolfactor  */
#line 279 "cpl.y"
                {
			(yyval.expr_val).type = (yyvsp[0].expr_val).type;
			strcpy((yyval.expr_val).temp_name, (yyvsp[0].expr_val).temp_name);
		}
#line 1485 "cpl.tab.c"
    break;

  case 41: /* boolfactor: NOT '(' boolexpr ')'  */
#line 285 "cpl.y"
                  {
			printf("Boolean NOT\n");
			emit_logical_not((yyvsp[-1].expr_val).temp_name);
			(yyval.expr_val).type = INT_TYPE;
			strcpy((yyval.expr_val).temp_name, last_expression_result);
		  }
#line 1496 "cpl.tab.c"
    break;

  case 42: /* boolfactor: expression RELOP expression  */
#line 292 "cpl.y"
                  {
			printf("Relational operation\n");
			emit_relational_op((yyvsp[-1].op), (yyvsp[-2].expr_val).type, (yyvsp[0].expr_val).type, (yyvsp[-2].expr_val).temp_name, (yyvsp[0].expr_val).temp_name);
			(yyval.expr_val).type = INT_TYPE;
			strcpy((yyval.expr_val).temp_name, last_expression_result);
		  }
#line 1507 "cpl.tab.c"
    break;

  case 43: /* expression: expression ADDOP term  */
#line 300 "cpl.y"
                  {
			int left_type = (yyvsp[-2].expr_val).type;
			int right_type = (yyvsp[0].expr_val).type;
			int result_type = (left_type == FLOAT_TYPE || right_type == FLOAT_TYPE) 
								? FLOAT_TYPE : INT_TYPE;
			prev_temp = (yyvsp[-2].expr_val).temp_name;
			last_expression_result = (yyvsp[0].expr_val).temp_name;
			emit_binary_op((yyvsp[-1].op), result_type);
			
			(yyval.expr_val).type = result_type;
			strcpy((yyval.expr_val).temp_name, last_expression_result);
			
            printf("Addition/Subtraction (result type: %s)\n", 
                   result_type == INT_TYPE ? "int" : "float");
          }
#line 1527 "cpl.tab.c"
    break;

  case 44: /* expression: term  */
#line 316 "cpl.y"
                  {
			(yyval.expr_val).type = (yyvsp[0].expr_val).type;
			strcpy((yyval.expr_val).temp_name, (yyvsp[0].expr_val).temp_name);
		  }
#line 1536 "cpl.tab.c"
    break;

  case 45: /* term: term MULOP factor  */
#line 323 "cpl.y"
    {
	  int left_type = (yyvsp[-2].expr_val).type;
	  int right_type = (yyvsp[0].expr_val).type;
	  int result_type = (left_type == FLOAT_TYPE || right_type == FLOAT_TYPE) 
	  					? FLOAT_TYPE : INT_TYPE;
	  prev_temp = (yyvsp[-2].expr_val).temp_name;
	  last_expression_result = (yyvsp[0].expr_val).temp_name;
	  emit_binary_op((yyvsp[-1].op), result_type);
	  (yyval.expr_val).type = result_type;
	  strcpy((yyval.expr_val).temp_name, last_expression_result);
	  
	  printf("Multiplication/Division (result type: %s)\n", 
			 result_type == INT_TYPE ? "int" : "float");
	}
#line 1555 "cpl.tab.c"
    break;

  case 46: /* term: factor  */
#line 338 "cpl.y"
        {
	  (yyval.expr_val).type = (yyvsp[0].expr_val).type;
	  strcpy((yyval.expr_val).temp_name, (yyvsp[0].expr_val).temp_name);
	}
#line 1564 "cpl.tab.c"
    break;

  case 47: /* factor: '(' expression ')'  */
#line 345 "cpl.y"
          {
		printf("Parenthesized expression\n");
		(yyval.expr_val).type = (yyvsp[-1].expr_val).type;
		strcpy((yyval.expr_val).temp_name, (yyvsp[-1].expr_val).temp_name);
	  }
#line 1574 "cpl.tab.c"
    break;

  case 48: /* factor: CAST '(' expression ')'  */
#line 351 "cpl.y"
          {
		printf("Cast expression to %s\n", (yyvsp[-3].cast_type) == INT_TYPE ? "int" : "float");
		last_expression_result = (yyvsp[-1].expr_val).temp_name;
		emit_cast((yyvsp[-1].expr_val).type, (yyvsp[-3].cast_type));
		
		(yyval.expr_val).type = (yyvsp[-3].cast_type);
		strcpy((yyval.expr_val).temp_name, last_expression_result);
	  }
#line 1587 "cpl.tab.c"
    break;

  case 49: /* factor: ID  */
#line 360 "cpl.y"
          {
		int var_type = get_symbol_type((yyvsp[0].name));
		if (var_type == -1) {
		  yyerror_format("Semantic: variable '%s' not declared", (yyvsp[0].name));
		  has_errors = 1;
		  (yyval.expr_val).type = INT_TYPE;
		  strcpy((yyval.expr_val).temp_name, "error_var"); // needed??
		} else {
		  printf("Identifier: %s (type: %s)\n", (yyvsp[0].name), var_type == INT_TYPE ? "int" : "float");
		  emit_load_var((yyvsp[0].name));
		  
		  (yyval.expr_val).type = var_type;
		  strcpy((yyval.expr_val).temp_name, last_expression_result);
		}
	  }
#line 1607 "cpl.tab.c"
    break;

  case 50: /* factor: NUM  */
#line 376 "cpl.y"
          {
		if ((yyvsp[0].num_val).type == INT_TYPE) {
		  printf("Int: %d\n", (yyvsp[0].num_val).ival);
		  emit_load_constant_int((yyvsp[0].num_val).ival, (yyvsp[0].num_val).type);
		} else {
		  printf("Float: %f\n", (yyvsp[0].num_val).fval);
		  emit_load_constant_float((yyvsp[0].num_val).fval, (yyvsp[0].num_val).type);
		}
		
		(yyval.expr_val).type = (yyvsp[0].num_val).type;
		strcpy((yyval.expr_val).temp_name, last_expression_result);
	  }
#line 1624 "cpl.tab.c"
    break;


#line 1628 "cpl.tab.c"

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

#line 390 "cpl.y"

