# PHYLOG Compiler Specifications

## Project Overview
PHYLOG is a compiler designed for the PHYLOG language. The compiler performs lexical analysis, syntax analysis, semantic checking, and generates intermediate code (quadruplets) which can be further optimized and translated to assembly code.

## Project Structure
- `src/`: Source code directory
  - `lexer/`: Lexical analyzer using Flex 
    - `lexer.l`: Flex definition file for tokenizing PHYLOG code
  - `parser/`: Syntactic analyzer using Bison
    - `parser.y`: Bison grammar file for parsing PHYLOG
  - `data-structure/`: Helper data structures
    - `stack/`: Stack implementation used for control flow
  - `symbol-table/`: Symbol table implementation for tracking variables
  - `quadruplet/`: Intermediate code generation

- `tests/`: Test files
  - `program.phylog`: Sample PHYLOG program for testing

- `out/`: Generated outputs (created by build script)
  - `flex/`: Flex-generated lexer code
  - `bison/`: Bison-generated parser code
  - `quadruplets/`: Generated intermediate code files

- `runme.sh`: Build and execution script

## PHYLOG Language Features

### Program Structure
The general structure of a PHYLOG program is:
```
program_name
DATA
    declarations
END
CODE
    statements
END
END
```

### Comments
Comments begin with `§` symbol and continue until the end of the line.

### Data Types
- `INTEGER`: Integer numbers (-32768 to 32767), can be signed like (-5)
- `FLOAT`: Floating point numbers, can be signed like (-3.14)
- `CHAR`: Single character enclosed in single quotes ('a')
- `STRING`: Text enclosed in double quotes ("Hello")

### Declarations
- Variable declarations: `TYPE: variable_name;` or `TYPE: var1 | var2 | var3;`
- Vector declarations: `VECTOR: name[lower_bound, size: type];`
- Constant declarations: `CONST: name = value;`

### Identifiers
Identifiers begin with an uppercase letter followed by up to 7 letters or digits.

### Operators
- Arithmetic: `+`, `-`, `*`, `/`
- Logical: `.AND.`, `.OR.`, `NOT`
- Comparison: `.G.` (>), `.L.` (<), `.GE.` (>=), `.LE.` (<=), `.EQ.` (==), `.DI.` (!=)

### Statements
- Assignment: `identifier = expression;`
- Input: `READ ("format":@ identifier);`
- Output: `DISPLAY ("message format": value);`
- Conditional: 
  ```
  IF(condition):
      statements
  ELSE:
      statements
  END
  ```
- Loop: 
  ```
  FOR (identifier: step: condition)
      statements
  END
  ```

## Features Implemented

### Lexical Analysis
- Tokenization of PHYLOG syntax elements
- Recognition of operators, identifiers, and constants
- Line and column tracking for error reporting
- Comment handling

### Syntax Analysis
- Parsing of PHYLOG program structure
- Handling of declarations and statements
- Support for expressions and control structures
- Error reporting for syntax mistakes

### Semantic Analysis
- Symbol table for tracking identifiers and their properties
- Type checking
- Detection of duplicate declarations
- Undeclared identifier detection

### Intermediate Code Generation
- Generation of quadruplets (four-address code)
- Support for basic operations and control flow
- Handling of arithmetic and logical expressions

### Code Optimization
- Copy propagation
- Dead code elimination
- Common subexpression elimination
- Algebraic simplifications

### Code Generation
- Translation of quadruplets to assembly-like instructions
- Register allocation (basic)

## Coding Conventions
- C-based implementation
- Function and variable naming in snake_case
- Modular design with separate components for different compiler phases

## Libraries Used
- Flex for lexical analysis
- Bison for parsing
- Standard C libraries (stdio.h, stdlib.h, string.h, etc.)

## Build Process
The project is built using the `runme.sh` script which:
1. Creates output directories if they don't exist
2. Compiles the Bison grammar file to generate parser
3. Compiles the Flex lexer definition
4. Compiles the generated C files with GCC
5. Runs the compiler on a test PHYLOG program

## Error Handling
When errors are detected, the compiler provides:
- Error type (lexical, syntax, semantic)
- Line and column information
- Description of the error
- The entity that caused the error 