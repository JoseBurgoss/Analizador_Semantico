# Analizador Sintáctico y Semántico para Pascal

Este analizador es una herramienta completa diseñada para analizar y validar código Pascal, realizando tanto análisis sintáctico como semántico. Identifica errores en la estructura del código, compatibilidad de tipos, llamadas a funciones y uso de variables.

## Características

### Análisis Sintáctico
- Valida la estructura del programa Pascal
- Verifica la correcta declaración de variables, funciones y procedimientos
- Asegura la sintaxis correcta para estructuras de control (if, while, for)
- Valida la sintaxis de expresiones y el uso de operadores
- Verifica el uso adecuado de bloques begin/end

### Análisis Semántico
- Comprobación de tipos para asignaciones y expresiones
- Validación de llamadas a funciones (número correcto y tipos de argumentos)
- Seguimiento de inicialización de variables
- Verificación de valores de retorno para funciones
- Gestión de ámbito para variables y funciones

### Detección de Errores
- Variables y funciones no declaradas
- Incompatibilidad de tipos en asignaciones y expresiones
- Número incorrecto de argumentos en funciones
- Valores de retorno faltantes en funciones
- Variables utilizadas antes de su inicialización
- Operaciones incompatibles entre diferentes tipos de datos (por ejemplo, char y tipos numéricos)

## Detalles de Implementación

El analizador está implementado en C y utiliza un enfoque de análisis descendente recursivo con los siguientes componentes:

### Estructuras de Datos
- Árbol de Sintaxis Abstracta (AST) para representar la estructura del programa
- Tabla de símbolos para rastrear variables, funciones y sus propiedades
- Sistema de tipos que soporta los tipos básicos de Pascal (integer, real, string, boolean, char)

### Funciones Principales
- `analizar_asignacion`: Valida sentencias de asignación y compatibilidad de tipos
- `analizar_expresion`: Analiza expresiones y verifica errores de tipo
- `analizar_funcion`: Procesa declaraciones de funciones y verifica valores de retorno
- `procesar_llamada_funcion`: Valida llamadas a funciones y conteo de argumentos
- `analizar_if`, `analizar_while`, `analizar_for`: Procesa estructuras de control
- `verificar_tipos_compatibles`: Comprueba si dos tipos pueden usarse juntos

### Manejo de Errores
- Mensajes de error detallados con números de línea
- Advertencias para problemas potenciales (por ejemplo, variables no inicializadas)
- Terminación elegante en errores críticos

## Uso

El analizador lee código Pascal desde un archivo llamado `codigo_pascal.txt` y muestra los resultados del análisis, incluyendo cualquier error o advertencia encontrada durante el proceso de análisis.

```
./Sintactico_Semantico
```

## Ejemplos de Detección de Errores

El analizador puede detectar varios errores, incluyendo:

1. Incompatibilidad de tipos en asignaciones:
   ```
   Error en la linea 25: Tipos incompatibles en la asignacion. Se esperaba 0 pero se encontro 1
   ```

2. Argumentos incorrectos de función:
   ```
   Error en la linea 32: Numero incorrecto de argumentos para la funcion Sumar. Esperados: 2, Recibidos: 1
   ```

3. Valores de retorno faltantes:
   ```
   Error en la linea 35: La funcion 'SinRetorno' no tiene un valor de retorno asignado
   ```

4. Operaciones incompatibles:
   ```
   Error en la linea 28: No se puede realizar operaciones aritmeticas entre char y tipos numericos
   ```

5. Variables no inicializadas:
   ```
   Advertencia en la linea 20: Variable 'contador' utilizada antes de ser inicializada
   ```

Este analizador sirve como una herramienta robusta para validar código Pascal antes de la compilación, ayudando a los desarrolladores a identificar y corregir errores temprano en el proceso de desarrollo.





# Pascal Syntax and Semantic Analyzer

This analyzer is a comprehensive tool designed to parse and validate Pascal code, performing both syntactic and semantic analysis. It identifies errors in code structure, type compatibility, function calls, and variable usage.

## Features

### Syntactic Analysis
- Validates Pascal program structure
- Checks for proper declaration of variables, functions, and procedures
- Ensures correct syntax for control structures (if, while, for)
- Validates expression syntax and operator usage
- Verifies proper use of begin/end blocks

### Semantic Analysis
- Type checking for assignments and expressions
- Function call validation (correct number and types of arguments)
- Variable initialization tracking
- Return value verification for functions
- Scope management for variables and functions

### Error Detection
- Undeclared variables and functions
- Type incompatibility in assignments and expressions
- Incorrect number of function arguments
- Missing return values in functions
- Variables used before initialization
- Incompatible operations between different data types (e.g., char and numeric types)

## Implementation Details

The analyzer is implemented in C and uses a recursive descent parsing approach with the following components:

### Data Structures
- Abstract Syntax Tree (AST) for representing program structure
- Symbol table for tracking variables, functions, and their properties
- Type system supporting Pascal's basic types (integer, real, string, boolean, char)

### Key Functions
- `analizar_asignacion`: Validates assignment statements and type compatibility
- `analizar_expresion`: Analyzes expressions and checks for type errors
- `analizar_funcion`: Processes function declarations and checks return values
- `procesar_llamada_funcion`: Validates function calls and argument counts
- `analizar_if`, `analizar_while`, `analizar_for`: Process control structures
- `verificar_tipos_compatibles`: Checks if two types can be used together

### Error Handling
- Detailed error messages with line numbers
- Warnings for potential issues (e.g., uninitialized variables)
- Graceful termination on critical errors

## Usage

The analyzer reads Pascal code from a file named `codigo_pascal.txt` and outputs the analysis results, including any errors or warnings found during the analysis process.

```
./Sintactico_Semantico
```

## Example Error Detection

The analyzer can detect various errors, including:

1. Type incompatibility in assignments:
   ```
   Error en la linea 25: Tipos incompatibles en la asignacion. Se esperaba 0 pero se encontro 1
   ```

2. Incorrect function arguments:
   ```
   Error en la linea 32: Numero incorrecto de argumentos para la funcion Sumar. Esperados: 2, Recibidos: 1
   ```

3. Missing return values:
   ```
   Error en la linea 35: La funcion 'SinRetorno' no tiene un valor de retorno asignado
   ```

4. Incompatible operations:
   ```
   Error en la linea 28: No se puede realizar operaciones aritmeticas entre char y tipos numericos
   ```

5. Uninitialized variables:
   ```
   Advertencia en la linea 20: Variable 'contador' utilizada antes de ser inicializada
   ```

This analyzer serves as a robust tool for validating Pascal code before compilation, helping developers identify and fix errors early in the development process.
