# BARES

## Author
This program was developed by **Pedro Arthur & Johnnylee Bryan & Pedro Neto**
 - Github - https://github.com/pedroarthur-mf & https://github.com/kfjohnny2

## About
BARES (Basic Arithmetic Expression Evaluator based of Stacks).
Is a program that will receive a group of expressions and number and evaluate them, then convert to a notation type of called post-fixed and finally calculate it.


### Supported Operators
The symbols that are supported by de application are: "-" (unary or binary), "+" addition (binary), "*" multiplication (binary), "/" division (binary), "%" rest of a division (binary), "^" exponentiation (binary), "()" for precedence define.

## How it works?
The program will read a file with one or more lines with the expressions, then it will tokenize the the line to separate each operator and number.

After that, this will enqueue the terms converted to the post-fix notation (Reverse Polish Notation) and will remove the parentheses.

After all, the program will calculate the expression.

## Supported Errors
**C** is the column where the error was found at first time
 - Numeric constant out of range. Ex.: 1000000 − 2, col 1
 - Ill-formed expression or missing term detected. Ex.: 2+, col 3; ou 3 ∗ d, col 5.
 - Invalid operand: Ex.: 2 = 3, col 3; ou 2.3 + 4, col 2
 - Extraneous symbol: Ex.: 2 ∗ 3 4, col 7 ou (−3 ∗ 4)(10 ∗ 5), col 7.
 - Mismatch ')': Ex.: )2 − 4, col 1; ou 2 − 4), col 6; ou 2) − 4. col 2.
 - Lost operator: Ex.: 2 ∗∗ 3, col 4; ou /5 ∗ 10, col 1.
 - Missing closing ')' to match opening '(' at: Ex.: ((2%3) ∗ 8, col 1.
 - Division by zero! Ex.: 3/(1 − 1); ou 10/(3 ∗ 3ˆ−2).
 - Numeric overflow error! Ex.: 20 ∗ 20000.


## Compilation
To compile you just need to run the following commands:
```shell
make clean
make
```

## Execution
```shell
./bin/bares input_file [output_file]
```

The `output_file` is a optional parameter. It will print the program log on a txt file.



