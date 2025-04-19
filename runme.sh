#!/bin/bash

echo "Starting build process..."

# Ensure output directories exist
rm -rf out
mkdir -p out/flex out/bison out/quadruplets

echo "Created output directories"

# Generate parser from Bison grammar
echo "Compiling parser..."
bison -d -o out/bison/synt.tab.c src/parser/parser.y
if [ $? -ne 0 ]; then
    echo "Failed to compile parser"
    exit 1
fi

# Generate lexer from Flex definition
echo "Compiling lexer..."
flex -o out/flex/lex.yy.c src/lexer/lexer.l
if [ $? -ne 0 ]; then
    echo "Failed to compile lexer"
    exit 1
fi

# Compile everything together
echo "Compiling the program..."
gcc -o out/phylog out/flex/lex.yy.c out/bison/synt.tab.c -I./src -w
if [ $? -ne 0 ]; then
    echo "Failed to compile program"
    exit 1
fi

echo "Build successful. Running the program..."

# Run the compiler on the test program
./out/phylog < tests/program.phylog

echo "Program execution complete."