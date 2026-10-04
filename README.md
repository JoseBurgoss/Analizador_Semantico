# Pascal Syntax and Semantic Analyzer

A command-line analyzer written in C that reads a small Pascal program, validates its syntax and semantics line by line, and prints the resulting parse tree.

This was built as a compilers course project. It targets a practical subset of Pascal (variable declarations, functions, procedures, `if`, `while`, `for`, assignments and `writeln`), not the full language.

## Features

**Syntax checks**
- `var` declarations: missing `;`, duplicate variables, invalid types.
- Function and procedure headers: parentheses, parameter lists, `:` before the return type, trailing `;`.
- Control structures: `if ... then`, `while ... do`, `for ... := ... to|downto ... do`.
- Assignment operator (`:=` only) and `writeln(...)` arguments, including missing quotes.
- Typo detection for keywords (for example `en` instead of `end`).

**Semantic checks**
- Symbol table for variables and functions (name, type, declaration line, initialization state).
- Type checking for assignments and arithmetic expressions over `integer`, `real`, `string`, `boolean` and `char`.
- Function calls: undeclared functions, wrong number of arguments, incompatible argument types.
- Functions whose return value is never assigned.
- Warnings for variables used before being initialized.

**Output**
- A parse tree built from `Nodo` structures, printed with indentation at the end of a successful run.
- Errors are reported on `stderr` with the line number, and the analysis stops at the first error.

Running it on the included `codigo_pascal.txt` (a function that never assigns its return value) ends with:

```text
Error en la linea 34: La funcion 'SinRetorno' no tiene un valor de retorno asignado -> SinRetorno();
```

Other messages include `Numero incorrecto de argumentos para la funcion ...`, `Tipos incompatibles en la asignacion ...`, `No se puede realizar operaciones aritmeticas entre char y tipos numericos` and the warning `Variable '...' utilizada antes de ser inicializada`.

## Tech stack

- C (C99, standard library only: `stdio`, `stdlib`, `string`, `stdbool`, `ctype`)
- Hand-written, line-oriented recursive descent analysis with a two-pass approach (functions are pre-registered first, then the file is analyzed)

## Getting started

Requirements: a C compiler such as GCC (MinGW on Windows).

```bash
git clone https://github.com/JoseBurgoss/Analizador_Semantico.git
cd Analizador_Semantico
gcc Semantico.c -o Semantico
./Semantico
```

The program always reads `codigo_pascal.txt` from the current directory. Edit that file (or replace its contents) to analyze a different Pascal program. A precompiled `Semantico.exe` for Windows is also included.

### Test programs

`Untitled.txt` contains five sample Pascal programs, each with one intentional error:

1. Incompatible type in an assignment
2. Variable used before initialization
3. Wrong number of function arguments
4. Function without a return value
5. Incompatible types in an expression

Copy any of them into `codigo_pascal.txt` and run the analyzer to see the corresponding error.

## Project structure

```text
Analizador_Semantico/
├── Semantico.c          # Analyzer source (symbol table, parse tree, checks, main)
├── Semantico.exe        # Prebuilt Windows binary
├── codigo_pascal.txt    # Input program read by the analyzer
└── Untitled.txt         # Sample programs with intentional errors
```

## Limitations

- Analysis is line based, so each statement is expected on its own line.
- Only one error is reported per run (the program exits on the first error).
- The analyzer prints verbose debug traces (`DEBUG: ...`, `ANALIZAR ASIGNACION`, ...) to stdout while it runs.
- Type names in error messages are shown as internal enum values (`0` = integer, `1` = string, `2` = real, `3` = boolean, `4` = char).

## Español

Analizador sintáctico y semántico en C para un subconjunto de Pascal. Lee `codigo_pascal.txt`, valida declaraciones, funciones, procedimientos y estructuras de control, verifica tipos, argumentos, retornos e inicialización de variables, e imprime el árbol de análisis. Proyecto académico de la materia de compiladores.

---

Author: José Burgos — https://jose-burgos-portfolio.vercel.app · https://www.linkedin.com/in/jose-burgos-/
