# Language Implementation

The language is specifically designed to compute expressions involving arithmetic and logical operators. The
operands can be of different types such as integer, real, boolean and arrays. The language implements two types
of arrays- rectangular and jagged. The rows of rectangular arrays have same number of columns, and that of
jagged arrays can have varying number of columns. A jagged array can be two or three dimensional while the
rectangular arrays can be of any dimensions. The rectangular arrays can be static or dynamic in nature depending
upon the range values available at compile time or run time respectively, but the jagged arrays are always static.
The program uses keywords, variable identifiers, special symbols etc. The variable identifier name can be of at
most 20 characters, including alphabet, digits and underscore, but it never starts with a digit. The symbols used
are (, ), {, }, :, ;, [, ] etc. The language has only two types of statements – declaration and assignment statements.
A declaration statement can declare the type of one variable or type of the list of variables. The keywords used
in this language are program, declare, list, of, variables, array, size, values, jagged, of, integer, real and boolean.
An assignment statement has a left valued variable and a right hand side expression. The expression can be
arithmetic or Boolean, and is constructed recursively. The expression uses arithmetic operators such as plus,
minus, multiplication and division. The operators * and / have more precedence than the + and -. The Boolean
operators &&& and ||| (used for logical ‘and’ and ‘or’ respectively) can only be applied to two variables of
Boolean type. The logical ‘and’ has more precedence than logical ‘or’. The language does not have any relational
operator such as less than, greater than etc. The values for variables are not initialized for integer, real and Boolean
data types. However, the array variables are initialized using the description given below. All declaration
statements must appear before any assignment statement in the program. This means that no assignment statement
can be written before a declaration statement. The program must have at least one declaration statement and one
assignment statement.
Static constants are the numbers available statically at code level. The language supports only integer numbers at
text level as static constant. This means any number such as 234, 65, 53458754, 01981731, 000, 45, 16 and 7777
are valid numbers of type integers. The static real numbers are not valid at text level. This means 23.45 is not
valid in the source code. Similarly, the language does not support true and false as Boolean constants.
The delimiter used in the program to separate the significant entities is the blank space. This delimiter is imposed
to save you from implementing the deterministic finite automaton for pattern matching by reaching the accept
state, which you will implement in your compiler construction.
