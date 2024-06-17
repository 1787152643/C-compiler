
typedef enum{Q_plusOp, Q_minusOp, Q_timesOp, Q_divideOp,
	     Q_eqOp, Q_neqOp, Q_ltOp, Q_leOp, Q_gtOp, Q_geOp, Q_assignOp,
         Q_bOp, Q_beqOp, Q_bneOp, Q_bltOp, Q_bleOp, Q_bgtOp, Q_bgeOp,
         Q_starOp} Q_operator;

typedef struct Q_operand_ *Q_operand;
typedef struct Q_addr Q_addr;


typedef struct Q_type_ *Q_type;
typedef struct Q_declarator_ *Q_declarator;

struct Q_type_{
    enum{Q_int, Q_pointer} kind;
    union{
        Q_type points;
    } u;
};

struct Q_declarator_{
    char* name;
    Q_type type;
};

struct Q_addr
{
    int reg;
    //int mem;
};

struct Q_operand_
{
    enum{Q_varOp, Q_tempOp, Q_immOp, Q_refOp} kind;
    Q_type type;
    union{
        struct{char* name; Q_addr addr;} var;
        struct{int id; Q_addr addr;} temp;
        struct{int value;} imm;
        struct{Q_operand mem_addr; Q_addr addr;} ref;
    } u;
};

typedef struct quadrupleList_ *quadrupleList;
typedef struct quadruple_ *quadruple;

struct quadrupleList_{
    quadrupleList head;
    quadruple tail;
};

struct quadruple_{
    int addr;
    Q_operator operator;
    Q_operand op1;
    Q_operand op2;
    Q_operand dest;
};

typedef struct Q_exp_ *Q_exp;
typedef struct Q_stmt_ *Q_stmt;
typedef struct Q_condition_ *Q_condition;

struct Q_exp_{
    Q_operand result;
};

struct Q_stmt_{
    quadrupleList nextList;
};

struct Q_condition_{
    quadrupleList falseList;
    quadrupleList trueList;
};


typedef struct Mtype_ *Mtype;
struct Mtype_{int instr;};


Q_type Q_Int(void);
Q_type Q_Pointer(Q_type inner);
int Q_typeEqual(Q_type t1, Q_type t2);
Q_declarator Q_Declarator(char* name, Q_type type);

Q_operand Q_VarOperand(char* name, Q_addr addr);
//Q_operand Q_TempOperand(int id, Q_addr addr);
Q_operand Q_TempOperand();
Q_operand Q_ImmOperand(int value);
Q_operand Q_RefOperand(Q_operand mem_addr, Q_type type);

Q_exp Q_Exp(Q_operand);
Q_stmt Q_Stmt();
Q_condition Q_Condition();

void backpatch(quadrupleList, int);
quadrupleList merge(quadrupleList, quadrupleList);
quadrupleList makelist(quadruple);


Q_addr find_free();

void quadruple_init();
quadruple gen(Q_operator, Q_operand, Q_operand, Q_operand);
void printQuads();
