#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_FUNCIONES 50
typedef enum {
    TIPO_INTEGER,
    TIPO_STRING,
    TIPO_REAL,
    TIPO_BOOLEAN,
    TIPO_CHAR,
    TIPO_DESCONOCIDO
} TipoDato;

typedef struct {
    char nombre[50];
    TipoDato tipo;
    bool inicializada;
    int linea_declaracion;
} Variable;

typedef struct {
    char nombre[50];
    TipoDato tipo_retorno;
    Variable parametros[20];
    int num_parametros;
    bool retorno_asignado;
    int linea_declaracion;
    bool tiene_retorno;
} Funcion;

typedef struct {
    Variable variables[100];
    int num_variables;
    Funcion funciones[50];
    int num_funciones;
    char ambito_actual[50]; 
} TablaSimbolos;

TablaSimbolos tabla;

TipoDato obtener_tipo_desde_string(const char* tipo_str);
void inicializar_tabla_simbolos();
void agregar_variable(const char* nombre, TipoDato tipo, int linea);
void agregar_funcion(const char* nombre, TipoDato tipo_retorno, int linea);
void agregar_parametro_funcion(const char* nombre_funcion, const char* nombre_param, TipoDato tipo);
bool variable_existe(const char* nombre);
bool funcion_existe(const char* nombre);
Variable* buscar_variable(const char* nombre);
Funcion* buscar_funcion(const char* nombre);
void marcar_variable_inicializada(const char* nombre);
void marcar_funcion_con_retorno(const char* nombre);
bool verificar_tipos_compatibles(TipoDato tipo1, TipoDato tipo2);
TipoDato inferir_tipo_expresion(const char* expr);
void analizar_llamada_funcion(const char* nombre_funcion, const char* argumentos, int num_linea);
char* extraer_argumentos_funcion(const char* str);
bool es_llamada_funcion(const char* expr);
void procesar_llamada_funcion(const char* expr, int num_linea);
void toLowerCase(char *str);

TipoDato obtener_tipo_desde_string(const char* tipo_str) {
    if (strcmp(tipo_str, "integer") == 0) return TIPO_INTEGER;
    if (strcmp(tipo_str, "string") == 0) return TIPO_STRING;
    if (strcmp(tipo_str, "real") == 0) return TIPO_REAL;
    if (strcmp(tipo_str, "boolean") == 0) return TIPO_BOOLEAN;
    if (strcmp(tipo_str, "char") == 0) return TIPO_CHAR;
    return TIPO_DESCONOCIDO;
}

void inicializar_tabla_simbolos() {
    tabla.num_variables = 0;
    tabla.num_funciones = 0;
    strcpy(tabla.ambito_actual, "global");
}

void agregar_variable(const char* nombre, TipoDato tipo, int linea) {
    if (tabla.num_variables < 100) {
        strcpy(tabla.variables[tabla.num_variables].nombre, nombre);
        tabla.variables[tabla.num_variables].tipo = tipo;
        tabla.variables[tabla.num_variables].inicializada = false;
        tabla.variables[tabla.num_variables].linea_declaracion = linea;
        tabla.num_variables++;
    }
}

void agregar_funcion(const char* nombre, TipoDato tipo_retorno, int linea_declaracion) {
    if (tabla.num_funciones >= MAX_FUNCIONES) {
        fprintf(stderr, "Error: Número máximo de funciones alcanzado\n");
        exit(1);
    }
    
    char nombre_lower[50];
    strcpy(nombre_lower, nombre);
    toLowerCase(nombre_lower);
    
    strcpy(tabla.funciones[tabla.num_funciones].nombre, nombre_lower);
    tabla.funciones[tabla.num_funciones].tipo_retorno = tipo_retorno;
    tabla.funciones[tabla.num_funciones].num_parametros = 0;
    tabla.funciones[tabla.num_funciones].linea_declaracion = linea_declaracion;
    tabla.funciones[tabla.num_funciones].tiene_retorno = false;
    tabla.num_funciones++;
}

void agregar_parametro_funcion(const char* nombre_funcion, const char* nombre_param, TipoDato tipo) {
    for (int i = 0; i < tabla.num_funciones; i++) {
        if (strcmp(tabla.funciones[i].nombre, nombre_funcion) == 0) {
            int num = tabla.funciones[i].num_parametros;
            strcpy(tabla.funciones[i].parametros[num].nombre, nombre_param);
            tabla.funciones[i].parametros[num].tipo = tipo;
            tabla.funciones[i].parametros[num].inicializada = true; 
            tabla.funciones[i].num_parametros++;
            return;
        }
    }
}

bool variable_existe(const char* nombre) {
    char lowerNombre[50];
    strcpy(lowerNombre, nombre);
    toLowerCase(lowerNombre);
    
    for (int i = 0; i < tabla.num_variables; i++) {
        char lowerVarName[50];
        strcpy(lowerVarName, tabla.variables[i].nombre);
        toLowerCase(lowerVarName);
        if (strcmp(lowerVarName, lowerNombre) == 0) {
            return true;
        }
    }
    return false;
}

bool funcion_existe(const char* nombre) {
    char lowerNombre[50];
    strcpy(lowerNombre, nombre);
    toLowerCase(lowerNombre);
    
    for (int i = 0; i < tabla.num_funciones; i++) {
        char lowerFuncName[50];
        strcpy(lowerFuncName, tabla.funciones[i].nombre);
        toLowerCase(lowerFuncName);
        if (strcmp(lowerFuncName, lowerNombre) == 0) {
            return true;
        }
    }
    return false;
}

Variable* buscar_variable(const char* nombre) {
    char lowerNombre[50];
    strcpy(lowerNombre, nombre);
    toLowerCase(lowerNombre);
    
    for (int i = 0; i < tabla.num_variables; i++) {
        char lowerVarName[50];
        strcpy(lowerVarName, tabla.variables[i].nombre);
        toLowerCase(lowerVarName);
        if (strcmp(lowerVarName, lowerNombre) == 0) {
            return &tabla.variables[i];
        }
    }
    return NULL;
}

Funcion* buscar_funcion(const char* nombre) {
    char nombre_lower[50];
    strcpy(nombre_lower, nombre);
    toLowerCase(nombre_lower);
    
    for (int i = 0; i < tabla.num_funciones; i++) {
        char func_nombre_lower[50];
        strcpy(func_nombre_lower, tabla.funciones[i].nombre);
        toLowerCase(func_nombre_lower);
        
        if (strcmp(func_nombre_lower, nombre_lower) == 0) {
            return &tabla.funciones[i];
        }
    }
    return NULL;
}

void marcar_variable_inicializada(const char* nombre) {
    Variable* var = buscar_variable(nombre);
    if (var) {
        var->inicializada = true;
    }
}

void marcar_funcion_con_retorno(const char* nombre) {
    Funcion* func = buscar_funcion(nombre);
    if (func) {
        func->retorno_asignado = true;
    }
}

bool verificar_tipos_compatibles(TipoDato tipo1, TipoDato tipo2) {
    if (tipo1 == tipo2) return true;

    if ((tipo1 == TIPO_INTEGER && tipo2 == TIPO_REAL) ||
        (tipo1 == TIPO_REAL && tipo2 == TIPO_INTEGER)) {
        return true;
    }

    if ((tipo1 == TIPO_CHAR && (tipo2 == TIPO_INTEGER || tipo2 == TIPO_REAL)) ||
    (tipo2 == TIPO_CHAR && (tipo1 == TIPO_INTEGER || tipo1 == TIPO_REAL))) {
    return false;
}
    
    return false;
}

TipoDato inferir_tipo_expresion(const char* expr) {
    if (strstr(expr, "\"") != NULL || strstr(expr, "'") != NULL) {
        return TIPO_STRING;
    }
    
    if (strstr(expr, ".") != NULL) {
        return TIPO_REAL;
    }
    
    if (strcmp(expr, "true") == 0 || strcmp(expr, "false") == 0) {
        return TIPO_BOOLEAN;
    }
    
    Variable* var = buscar_variable(expr);
    if (var) {
        return var->tipo;
    }
    
    return TIPO_INTEGER;
}

const char* palabras_clave[] = {"begin", "end", "then", "else", "while", "do", "for", "to", "downto", 
                                "repeat", "until", "case", "of", "const", "type", "record", "array", "var",
                                "function", "procedure"};

const char* tipos_validos[] = {"integer", "string", "real", "boolean", "char"};

const char* operadoresAritmeticos[] = {"*", "/","mod","+","-"};

const char* operadoresDeComparacion[] = {"<>", "<=", ">=", "<", ">", "="};


typedef struct Nodo {
    char tipo[20];      
    char valor[50];      
    struct Nodo** hijos;  
    int num_hijos;       
} Nodo;

Nodo* crear_nodo(const char* tipo, const char* valor);
void agregar_hijo(Nodo* padre, Nodo* hijo);
bool end_with_semicolon(const char* str);
void removeSpaces(char *str);
void trim(char *str);
bool contiene_elemento(const char *cadena, const char *array[], int tam_array);
void trim_semicolon(char *str);
int contar_elementos(char **array);
void toLowerCase(char *str);
char **split_function(const char *str, int *count);
char *extraer_parentesis(const char *str);
char **split(const char *str, const char *delim, int *count);
void mostrar_error(const char* mensaje, int linea, const char* detalle);
void mostrar_advertencia(const char* mensaje, int linea);
int es_tipo_valido(const char* tipo);
void analizar_palabra_clave(Nodo* arbol, const char* linea, int *num_linea, bool fromF_Or_P, FILE* archivo);
void analizar_cabecera_funcion(Nodo* arbol, char* linea, int num_linea, char* nombre_funcion);
void analizar_funcion(Nodo* arbol, char* linea, int* num_linea, FILE* archivo, char* nombre_funcion);
void analizar_expresion(Nodo* arbol, char* expr, int num_linea);
void analizar_asignacion(Nodo* arbol, const char* linea, int num_linea);
void imprimir_arbol(Nodo* nodo, int nivel);
void analizar_writeln(Nodo* arbol, const char* linea, int num_linea);
void analizar_if(Nodo* arbol, const char* linea, int *num_linea, FILE* archivo);
void analizar_while(Nodo* arbol, const char* linea, int *num_linea, FILE* archivo);
void analizar_for(Nodo* arbol, const char* linea, int *num_linea, FILE* archivo);

bool es_palabra_clave_similar(const char* palabra, int num_linea);
bool validar_asignacion(const char* linea, int num_linea);
bool validar_condicion(const char* condicion, int num_linea);
bool validar_parametros_funcion(const char* parametros, int num_linea);

bool es_palabra_clave_similar(const char* palabra, int num_linea) {
    char palabra_sin_puntuacion[256];
    strcpy(palabra_sin_puntuacion, palabra);
  
    int len = strlen(palabra_sin_puntuacion);
    if (len > 0 && (palabra_sin_puntuacion[len-1] == '.' || palabra_sin_puntuacion[len-1] == ';')) {
        palabra_sin_puntuacion[len-1] = '\0';
    }
    
    for (int i = 0; i < sizeof(palabras_clave) / sizeof(palabras_clave[0]); i++) {
        if (strcmp(palabra_sin_puntuacion, palabras_clave[i]) == 0) {
            return false; 
        }
    }

    if (strcmp(palabra_sin_puntuacion, "en") == 0) {
        mostrar_error("Palabra clave incorrecta: 'en' (¿quiso escribir 'end'?)", num_linea, palabra);
        return true;
    }
    
    for (int i = 0; i < sizeof(palabras_clave) / sizeof(palabras_clave[0]); i++) {
        int len1 = strlen(palabra_sin_puntuacion);
        int len2 = strlen(palabras_clave[i]);
        
        if (abs(len1 - len2) <= 1) {
            int differences = 0;
            int minLen = (len1 < len2) ? len1 : len2;
            
            for (int j = 0; j < minLen && differences <= 2; j++) {
                if (palabra_sin_puntuacion[j] != palabras_clave[i][j]) {
                    differences++;
                }
            }
            differences += abs(len1 - len2);
            
            if (differences <= 2) {
                char mensaje[100];
                sprintf(mensaje, "Posible error tipográfico: '%s' (¿quiso escribir '%s'?)", 
                        palabra_sin_puntuacion, palabras_clave[i]);
                mostrar_error(mensaje, num_linea, palabra);
                return true;
            }
        }
    }
    
    return false;
}

bool validar_asignacion(const char* linea, int num_linea) {
    if (strstr(linea, "=") != NULL && strstr(linea, ":=") == NULL) {
        mostrar_error("Operador de asignación invalido. Debe usar ':='", num_linea, linea);
        return false;
    }

    char* dos_puntos = strstr(linea, ":");
    char* igual = strstr(linea, "=");
    if ((dos_puntos && !igual) || (!dos_puntos && igual)) {
        mostrar_error("Operador de asignacion mal formado. Debe ser ':='", num_linea, linea);
        return false;
    }
    if (strstr(linea, ":=") != NULL) {
        int count = 0;
        char** partes = split(linea, ":=", &count);
        if (!partes || count != 2 || !partes[0] || !partes[1] || 
            strlen(partes[0]) == 0 || strlen(partes[1]) == 0) {
            if (partes) {
                for(int i = 0; i < count; i++) {
                    free(partes[i]);
                }
                free(partes);
            }
            mostrar_error("Asignación mal formada", num_linea, linea);
            return false;
        }
        for(int i = 0; i < count; i++) {
            free(partes[i]);
        }
        free(partes);
    }
    return true;
}

bool validar_condicion(const char* condicion, int num_linea) {
    bool operador_encontrado = false;
    for (int i = 0; i < sizeof(operadoresDeComparacion)/sizeof(operadoresDeComparacion[0]); i++) {
        if (strstr(condicion, operadoresDeComparacion[i]) != NULL) {
            operador_encontrado = true;
            if (strstr(condicion, "''") != NULL) {
                return true;
            }
            break;
        }
    }
    
    if (!operador_encontrado) {
        mostrar_error("Condición invalida: falta operador de comparacion valido", num_linea, condicion);
        return false;
    }
    return true;
}

bool validar_parametros_funcion(const char* parametros, int num_linea) {
    char* copia = strdup(parametros);
    char* token = strtok(copia, ":");
    
    while (token != NULL) {
        char* params = strchr(token, ',');
        if (params != NULL) {
            char* antes = token;
            while (isspace(*antes)) antes++;
            if (*antes == ',') {
                mostrar_error("Error en la lista de parametros: falta variable antes de la coma", num_linea, parametros);
                free(copia);
                return false;
            }

            char* despues = params + 1;
            while (*despues && isspace(*despues)) despues++;
            if (*despues == '\0' || *despues == ':') {
                mostrar_error("Error en la lista de parametros: falta variable después de la coma", num_linea, parametros);
                free(copia);
                return false;
            }
        }
        token = strtok(NULL, ":");
    }
    free(copia);
    return true;
}

Nodo* crear_nodo(const char* tipo, const char* valor) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nodo->tipo, tipo);
    strcpy(nodo->valor, valor);
    nodo->hijos = NULL;
    nodo->num_hijos = 0;
    return nodo;
}

void agregar_hijo(Nodo* padre, Nodo* hijo) {
    padre->num_hijos++;
    padre->hijos = (Nodo**)realloc(padre->hijos, padre->num_hijos * sizeof(Nodo*));
    padre->hijos[padre->num_hijos - 1] = hijo;
}

void extraer_condicion_while(const char* linea, char* condicion) {
    const char* inicio_while = strstr(linea, "while");  
    if (inicio_while != NULL) {
        inicio_while += 5;
        while (*inicio_while && isspace(*inicio_while)) {
            inicio_while++;
        }

        const char* fin_do = strstr(inicio_while, "do");
        if (fin_do != NULL) {
            size_t longitud = fin_do - inicio_while;
            strncpy(condicion, inicio_while, longitud);
            condicion[longitud] = '\0';  
        } else {
            condicion[0] = '\0';  
        }
    } else {
        condicion[0] = '\0';  
    }
}

void obtenerNombreFuncion(const char* linea, char* nombre, size_t tam) {
    const char *ptr = linea;

    if (strncmp(ptr, "function ", 9) == 0) {
        ptr += 9;
    }

    while (*ptr && isspace(*ptr)) {
        ptr++;
    }
    
    size_t i = 0;
    while (*ptr && !isspace(*ptr) && *ptr != '(' && i < tam - 1) {
        nombre[i++] = *ptr;
        ptr++;
    }
    nombre[i] = '\0';

    toLowerCase(nombre);
    
    printf("DEBUG: nombre de funcion extraida: '%s' en la linea '%s'\n", nombre, linea);
}

void obtenerNombreProcedure(const char* linea, char* nombre, size_t tam) {
    const char *ptr = linea;
    while (*ptr && isspace(*ptr)) {
        ptr++;
    }
    
    const char *palabra = "procedure";
    size_t len = strlen(palabra);
    
    if (strncasecmp(ptr, palabra, len) != 0) {
        nombre[0] = '\0';
        return;
    }
    
    ptr += len;
    
    while (*ptr && isspace(*ptr)) {
        ptr++;
    }
    
    size_t i = 0;
    while (*ptr && !isspace(*ptr) && *ptr != '(' && *ptr != ';' && i < tam - 1) {
        nombre[i++] = *ptr;
        ptr++;
    }
    nombre[i] = '\0';

    toLowerCase(nombre);
}

void contenidoWriteln(char* linea, char* contenido) {
    const char *ptr = linea;
    while (*ptr && *ptr != '(') {
        ptr++;
    }
    ptr++;
    size_t i = 0;
    while (*ptr && *ptr != ')') {
        contenido[i++] = *ptr;
        ptr++;
    }
    contenido[i] = '\0';
}

bool starts_with(const char* str, const char* prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

bool ends_with(const char* str, const char* suffix) {
    if (!str || !suffix) {
        return false;
    }
    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);
    if (suffix_len > str_len) {
        return false;
    }
    return strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0;
}

void extraer_condicion_if(const char* linea, char* condicion) {
    const char* inicio_if = strstr(linea, "if");  
    if (inicio_if != NULL) {
        inicio_if += 2;

        while (*inicio_if && isspace(*inicio_if)) {
            inicio_if++;
        }

        const char* fin_then = strstr(inicio_if, "then");
        if (fin_then != NULL) {
            size_t longitud = fin_then - inicio_if;
            strncpy(condicion, inicio_if, longitud);
            condicion[longitud] = '\0';  
        } else {
            condicion[0] = '\0';  
        }
    } else {
        condicion[0] = '\0'; 
    }
}

bool starts_with_case_insensitive(const char* str, const char* prefix) {
    size_t prefix_len = strlen(prefix);
    if (strlen(str) < prefix_len) {
        return false;
    }
    
    for (size_t i = 0; i < prefix_len; i++) {
        if (tolower((unsigned char)str[i]) != tolower((unsigned char)prefix[i])) {
            return false;
        }
    }
    return true;
}

bool validar_condicion_for(const char* linea, int num_linea) {
    if (!starts_with_case_insensitive(linea, "for ")) {
        mostrar_error("La estructura for debe comenzar con 'for'", num_linea, linea);
        return false;
    }
    
    if (strstr(linea, ":=") == NULL) {
        mostrar_error("La estructura for debe contener una asignación (:=)", num_linea, linea);
        return false;
    }
    
    if (strstr(linea, " to ") == NULL && strstr(linea, " downto ") == NULL) {
        mostrar_error("La estructura for debe contener 'to' o 'downto'", num_linea, linea);
        return false;
    }
    
    if (!ends_with(linea, "do")) {
        mostrar_error("La estructura for debe terminar con 'do'", num_linea, linea);
        return false;
    }
    
    return true;
}


void extraer_condicion_for(const char* linea, char* inicializacion, char* operador_control, char* final) {
    const char* ptr = linea + 4;
    while (*ptr && isspace(*ptr)) ptr++;
    
    const char* asignacion_pos = strstr(ptr, ":=");
    if (asignacion_pos == NULL) {
        strcpy(inicializacion, "");
        strcpy(operador_control, "");
        strcpy(final, "");
        return;
    }
    
    size_t var_len = asignacion_pos - ptr;
    char variable[50];
    strncpy(variable, ptr, var_len);
    variable[var_len] = '\0';
    trim(variable);

    const char* to_pos = strstr(ptr, " to ");
    const char* downto_pos = strstr(ptr, " downto ");
    
    const char* op_pos = NULL;
    if (to_pos != NULL && (downto_pos == NULL || to_pos < downto_pos)) {
        op_pos = to_pos;
        strcpy(operador_control, "to");
    } else if (downto_pos != NULL) {
        op_pos = downto_pos;
        strcpy(operador_control, "downto");
    } else {
        strcpy(inicializacion, "");
        strcpy(operador_control, "");
        strcpy(final, "");
        return;
    }
    
    const char* valor_inicial_pos = asignacion_pos + 2;
    while (*valor_inicial_pos && isspace(*valor_inicial_pos)) valor_inicial_pos++;
    
    size_t valor_inicial_len = op_pos - valor_inicial_pos;
    char valor_inicial[50];
    strncpy(valor_inicial, valor_inicial_pos, valor_inicial_len);
    valor_inicial[valor_inicial_len] = '\0';
    trim(valor_inicial);
    
    sprintf(inicializacion, "%s := %s", variable, valor_inicial);
    
    ptr = op_pos + strlen(operador_control) + 1;
    while (*ptr && isspace(*ptr)) ptr++;
    
    const char* do_pos = strstr(ptr, " do");
    if (do_pos != NULL) {
        size_t final_len = do_pos - ptr;
        strncpy(final, ptr, final_len);
        final[final_len] = '\0';
        trim(final);
    } else {
        strcpy(final, "");
    }
}

bool end_with_semicolon(const char* str) {
    trim((char*)str);
    size_t len = strlen(str);
    if (str[len - 1] != ';') {
        return false;
    }
    return true;
}

void removeSpaces(char *str) {
    char *dst = str; 
    while (*str) {
        if (!isspace((unsigned char)*str)) { 
            *dst++ = *str; 
        }
        str++;
    }
    *dst = '\0'; 
}

void trim(char *str) {
    char *start = str;
    char *end;

    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    if (*start == '\0') {
        *str = '\0';
        return;
    }

    end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    memmove(str, start, end - start + 1);
    str[end - start + 1] = '\0';
}

bool contiene_elemento(const char *cadena, const char *array[], int tam_array) {
    for (int i = 0; i < tam_array; i++) {
        if (strstr(cadena, array[i]) != NULL) { 
            return true;  
			}
    }
    return false;  
}

void trim_semicolon(char *str) {
    int len = strlen(str);

    while (len > 0 && str[len - 1] == ';') {
        str[len - 1] = '\0';
        len--;
    }
}

int contar_elementos(char **array) {
    int count = 0;
    while (array[count] != NULL) {
        count++;
    }
    return count;
}

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char) *str);
        str++;
    }
}

bool contiene_palabra_clave(const char *cadena, const char *array[], int tam_array) {
    char *copia = strdup(cadena);
    char *token = strtok(copia, " ,.;()[]{}<>+-*/=!:\"\'\t\n\r"); 
    while (token != NULL) {
        for (int i = 0; i < tam_array; i++) {
            if (strcmp(token, array[i]) == 0) {
                free(copia);
                return true;
            }
        }
        token = strtok(NULL, " ,.;()[]{}<>+-*/=!:\"\'\t\n\r");
    }
    free(copia);
    return false;
}

char **split_function(const char *str, int *count) {
    char *copia = strdup(str);
    char **resultado = (char **)malloc(2 * sizeof(char *));
    *count = 1;  

    char *pos = strrchr(copia, ':'); 
    
    if (pos == NULL) {
        resultado[0] = strdup(copia);
        resultado[1] = NULL;
    } else {
        *pos = '\0'; 
        resultado[0] = strdup(copia);
        resultado[1] = strdup(pos + 1);
        *count = 2;  
    }

    free(copia);
    return resultado;
}

char *extraer_parentesis(const char *str) {
    const char *inicio = strchr(str, '('); 
    const char *fin = strrchr(str, ')');   
    if (inicio == NULL || fin == NULL || inicio > fin) {
        return NULL; 
    }

    size_t len = fin - inicio - 1; 
    char *resultado = (char *)malloc(len + 1); 
    if (resultado == NULL) {
        return NULL; 
    }

    strncpy(resultado, inicio + 1, len); 
    resultado[len] = '\0';

    return resultado;
}

char *extraer_string(const char *str) {
    const char *inicioComillasSimples = strchr(str, '\'');  
    const char *finComillasSimples = strrchr(str, '\'');    

    const char *inicioComillasDobles = strchr(str, '\"');   
    const char *finComillasDobles = strrchr(str, '\"');     

    if (inicioComillasSimples && finComillasSimples && inicioComillasSimples < finComillasSimples) {
        size_t len = finComillasSimples - inicioComillasSimples - 1;
        char *resultado = (char *)malloc(len + 1);
        if (resultado) {
            strncpy(resultado, inicioComillasSimples + 1, len);
            resultado[len] = '\0';
            return resultado;
        }
    }

    if (inicioComillasDobles && finComillasDobles && inicioComillasDobles < finComillasDobles) {
        size_t len = finComillasDobles - inicioComillasDobles - 1;
        char *resultado = (char *)malloc(len + 1);
        if (resultado) {
            strncpy(resultado, inicioComillasDobles + 1, len);
            resultado[len] = '\0';
            return resultado;
        }
    }

    return NULL;  
}

char* extraer_argumentos_funcion(const char* str) {
    const char* inicio = strchr(str, '(');
    if (!inicio) return NULL;
    
    const char* fin = strrchr(str, ')');
    if (!fin || fin < inicio) return NULL;
    
    size_t len = fin - inicio - 1;
    char* resultado = (char*)malloc(len + 1);
    if (!resultado) return NULL;
    
    strncpy(resultado, inicio + 1, len);
    resultado[len] = '\0';
    return resultado;
}

char **split(const char *str, const char *delim, int *count) {
    char *copia = strdup(str); 
    int capacidad = 10; 
    char **resultado = (char **)malloc(capacidad * sizeof(char *)); 
    int index = 0;

    char *token = strtok(copia, delim);
    while (token != NULL) { 
        if (index >= capacidad) { 
            capacidad *= 2;
            resultado = (char **)realloc(resultado, capacidad * sizeof(char *));
        }
        resultado[index++] = strdup(token);  

        token = strtok(NULL, delim); 
    }

    resultado[index] = NULL;  
     *count = index; 

    free(copia); 

    return resultado; 
}

void mostrar_error(const char* mensaje, int linea, const char* detalle) {
    fprintf(stderr, "Error en la linea %d: %s -> %s\n", linea+2, mensaje, detalle);
    exit(1);
}

void mostrar_advertencia(const char* mensaje, int linea) {
    fprintf(stderr, "Advertencia en la linea %d: %s\n", linea, mensaje);
}

int es_tipo_valido(const char* tipo) {
    for (int i = 0; i < sizeof(tipos_validos) / sizeof(tipos_validos[0]); i++) {
        if (strcmp(tipo, tipos_validos[i]) == 0) {
            return true;  
        }
    }
    return false; 
}

void analizar_inicializacion_variables(Nodo* arbol, char* linea, int* num_linea, FILE* archivo, char* ultima_linea) {
    char buffer[256];
    trim((char*)linea);
    Nodo* nodo_keyword = crear_nodo("palabra_clave", linea);
    agregar_hijo(arbol, nodo_keyword);
    int count = 0;
    while(fgets(buffer, sizeof(buffer), archivo)) {
        if (starts_with(buffer, "begin") || starts_with(buffer, "procedure") || starts_with(buffer, "function") || starts_with(buffer, "writeln")) {
            break;
        }
        (*num_linea)++;
        trim(buffer);
        if(buffer[0] == '\0'){
            continue;
        }
        if(!end_with_semicolon(buffer)){
            mostrar_error("; faltante", *num_linea, buffer);
        }
        trim_semicolon(buffer);
        char** partesInicializacion = split(buffer, ":", &count);
        Nodo* nodo_asignacion = crear_nodo("asignacion", buffer);
        agregar_hijo(nodo_keyword, nodo_asignacion);
        Nodo* nodo_variables = crear_nodo("variables", partesInicializacion[0]);
        agregar_hijo(nodo_asignacion, nodo_variables);
        char** partesVariableMismoTipo = split(partesInicializacion[0], ",", &count);
        int numVariablesMismoTipo = contar_elementos(partesVariableMismoTipo);
        if(numVariablesMismoTipo == 0){
            mostrar_error("No se han declarado variables", *num_linea, buffer);
        }
        
        trim(partesInicializacion[1]);
        toLowerCase(partesInicializacion[1]);
        TipoDato tipo = obtener_tipo_desde_string(partesInicializacion[1]);
        
        if(numVariablesMismoTipo > 1){
            for(int i = 0; i < numVariablesMismoTipo; i++){
                trim(partesVariableMismoTipo[i]);
                Nodo* nodo_variable = crear_nodo("variable", partesVariableMismoTipo[i]);
                agregar_hijo(nodo_variables, nodo_variable);
                
                if (variable_existe(partesVariableMismoTipo[i])) {
                    mostrar_error("Variable ya declarada", *num_linea, partesVariableMismoTipo[i]);
                } else {
                    agregar_variable(partesVariableMismoTipo[i], tipo, *num_linea);
                }
                
                if(i < numVariablesMismoTipo - 1){
                    Nodo* nodo_coma = crear_nodo("coma", ",");
                    agregar_hijo(nodo_variables, nodo_coma);
                }
            }
        } else {
            trim(partesVariableMismoTipo[0]);
            if (variable_existe(partesVariableMismoTipo[0])) {
                mostrar_error("Variable ya declarada", *num_linea, partesVariableMismoTipo[0]);
            } else {
                agregar_variable(partesVariableMismoTipo[0], tipo, *num_linea);
            }
        }

        int isValidType = es_tipo_valido(partesInicializacion[1]);
        if(!isValidType){
            mostrar_error("Tipo de dato no valido", *num_linea, buffer);
        }
        Nodo* nodo_dos_puntos = crear_nodo("dos_puntos", ":");
        agregar_hijo(nodo_asignacion, nodo_dos_puntos);
        Nodo* nodo_tipo = crear_nodo("tipo", partesInicializacion[1]);
        agregar_hijo(nodo_asignacion, nodo_tipo);
        
        for(int i = 0; i < count; i++){
            free(partesInicializacion[i]);
        }
        free(partesInicializacion);
        
        for(int i = 0; i < numVariablesMismoTipo; i++){
            free(partesVariableMismoTipo[i]);
        }
        free(partesVariableMismoTipo);
    }
    strcpy(linea, buffer);
}

void analizar_palabra_clave(Nodo* arbol, const char* linea, int *num_linea, bool fromF_Or_P, FILE* archivo) {
    char buffer[256]; 
    trim((char*)linea);
    char palabra_temp[256];
    strcpy(palabra_temp, linea);
    
    char first_word[256] = {0};
    sscanf(palabra_temp, "%s", first_word);
    trim_semicolon(first_word);

    if (strncmp(first_word, "end", 3) == 0) {
        if (strlen(linea) > 3) {
            char last_char = linea[strlen(linea) - 1];
            if (last_char == '.' || last_char == ';') {
                Nodo* nodo_keyword = crear_nodo("palabra_clave", linea);
                agregar_hijo(arbol, nodo_keyword);
                return;
            }
        }
    }
   
    if (es_palabra_clave_similar(first_word, *num_linea)) {
        return;
    }

    const int num_palabras_clave = sizeof(palabras_clave) / sizeof(palabras_clave[0]);
    bool palabra_clave_valida = false;
    
    for (int i = 0; i < num_palabras_clave; i++) {
        if (strcmp(first_word, palabras_clave[i]) == 0) {
            palabra_clave_valida = true;
            break;
        }
    }
    
    if (!palabra_clave_valida) {
        mostrar_error("Palabra clave no reconocida", *num_linea, first_word);
        return;
    }

    if (strcmp(first_word, "begin") == 0) {
        Nodo* nodo_keyword = crear_nodo("palabra_clave", linea);
        agregar_hijo(arbol, nodo_keyword);
        while (fgets(buffer, sizeof(buffer), archivo)) {
            (*num_linea)++;
            trim(buffer);
            if (buffer[0] == '\0') continue;

            if (starts_with(buffer, "if")) {
                analizar_if(nodo_keyword, buffer, num_linea, archivo);
            }
            else if (starts_with(buffer, "while")) {
                analizar_while(nodo_keyword, buffer, num_linea, archivo);
            }
            else if (starts_with(buffer, "writeln")) {
                analizar_writeln(nodo_keyword, buffer, *num_linea);
            }
            else if (starts_with(buffer, "for")) {
                analizar_for(nodo_keyword, buffer, num_linea, archivo);
            }
            else if (starts_with(buffer, "end")) {
                Nodo* nodo_keyword = crear_nodo("palabra_clave", buffer);
                agregar_hijo(arbol, nodo_keyword);
                break;
            }
            else if (strstr(buffer, ":=") != NULL) {
                analizar_asignacion(nodo_keyword, buffer, *num_linea);
            }
            else if (es_llamada_funcion(buffer)) {
                procesar_llamada_funcion(buffer, *num_linea);
            }
        }
        return;
    } else {
        Nodo* nodo_keyword = crear_nodo("palabra_clave", linea);
        agregar_hijo(arbol, nodo_keyword);
    }
}



void analizar_cabecera_funcion(Nodo* arbol, char* linea, int num_linea, char* nombre_funcion) {
    obtenerNombreFuncion(linea, nombre_funcion, 50);
    char nombre_funcion_nosirve[256];
    int count = 0;
    bool semicolon = end_with_semicolon(linea);

    if (strlen(nombre_funcion) == 0) {
        mostrar_error("No se pudo extraer el nombre de la funcion", num_linea, linea);
        return;
    }
    
    printf("DEBUG: Procesando declaracion de funcion: '%s'\n", nombre_funcion);

    if (strncmp(linea, "function ", 9) != 0) {
        mostrar_error("La declaracion debe iniciar con 'function'", num_linea, linea);
    }

    char *abre_paren = strchr(linea, '(');
    char *cierra_paren = strchr(linea, ')');
    if (abre_paren == NULL || cierra_paren == NULL || cierra_paren < abre_paren) {
        mostrar_error("Error en la definicion de los parentesis", num_linea, linea);
    }

    char *dos_puntos = strchr(cierra_paren, ':');
    if (dos_puntos == NULL) {
        mostrar_error("Se esperaba ':' despues de la lista de parametros", num_linea, linea);
    }

    if (!semicolon) {
        mostrar_error("La declaracion debe terminar con ';'", num_linea, linea);
    }

    Nodo* nodo_funcion = crear_nodo("funcion", nombre_funcion); 
    agregar_hijo(arbol, nodo_funcion);
    Nodo *nodo_cabecera_funcion = crear_nodo("cabecera", ""); 
    agregar_hijo(nodo_funcion, nodo_cabecera_funcion);
    char **partes = split_function(linea, &count);
    trim(partes[0]);
    Nodo *nodo_funcion1 = crear_nodo("header pt1", partes[0]); 
    agregar_hijo(nodo_cabecera_funcion, nodo_funcion1);
    Nodo* nodo_dos_puntos = crear_nodo("dos puntos", ":"); 
    agregar_hijo(nodo_cabecera_funcion, nodo_dos_puntos);
    Nodo* nodo_funcion2 = crear_nodo("header pt2", partes[1]); 
    agregar_hijo(nodo_cabecera_funcion, nodo_funcion2);
    
    trim(partes[1]);
    trim_semicolon(partes[1]);
    toLowerCase(partes[1]);
    TipoDato tipo_retorno = obtener_tipo_desde_string(partes[1]);
    Funcion* func = buscar_funcion(nombre_funcion);
    if (func) {
        func->tipo_retorno = tipo_retorno;
        func->linea_declaracion = num_linea;
        printf("DEBUG: Actualizada funcion '%s' con tipo %d\n", nombre_funcion, tipo_retorno);
    } else {
        agregar_funcion(nombre_funcion, tipo_retorno, num_linea);
        printf("DEBUG: Agregada funcion '%s' con tipo %d\n", nombre_funcion, tipo_retorno);
    }
    
    if (sscanf(partes[0], "function %[^;];", nombre_funcion_nosirve) == 1) {
        char *contenido_parentesis = extraer_parentesis(partes[0]);
        if (contenido_parentesis != NULL) {
            if (!validar_parametros_funcion(contenido_parentesis, num_linea)) {
                return;
            }
        }
        Nodo* nodo_parentesis1 = crear_nodo("parentesis", "'('");
        Nodo* nodo_parentesis2 = crear_nodo("parametros", contenido_parentesis);
        Nodo* nodo_parentesis3 = crear_nodo("parentesis", "')'");
        agregar_hijo(nodo_funcion1, nodo_parentesis1);
        agregar_hijo(nodo_funcion1, nodo_parentesis2);
        agregar_hijo(nodo_funcion1, nodo_parentesis3);
        if (contenido_parentesis == NULL) {
            free(partes);
            mostrar_error("Funcion mal formada", num_linea, linea);
        }
        char **params = split(contenido_parentesis, ";", &count);
        int elem = contar_elementos(params);
        for (int i = 0; i < elem; i++) {
            Nodo* nodo_parametro = crear_nodo("parametro", params[i]);
            agregar_hijo(nodo_parentesis2, nodo_parametro);
            if (i < elem - 1) {
                Nodo* nodo_coma = crear_nodo("punto y coma", ";");
                agregar_hijo(nodo_parentesis2, nodo_coma);
            }

            char **parametros = split(params[i], ":", &count);
            int count3 = contar_elementos(parametros);
            char **paramsSameType = split(parametros[0], ",", &count);
            int numParamsSameType = contar_elementos(paramsSameType);
            
            trim(parametros[1]);
            toLowerCase(parametros[1]);
            TipoDato tipo_param = obtener_tipo_desde_string(parametros[1]);
            
            for (int k = 0; k < numParamsSameType; k++) {
                trim(paramsSameType[k]);
                agregar_parametro_funcion(nombre_funcion, paramsSameType[k], tipo_param);
                agregar_variable(paramsSameType[k], tipo_param, num_linea);
                marcar_variable_inicializada(paramsSameType[k]); 
            }
            
            for (int j = 0; j < count3; j++) {
                Nodo* nodo_param_inner = crear_nodo("parametro_inner", parametros[j]);
                agregar_hijo(nodo_parametro, nodo_param_inner);
                if (j < count3 - 1) {
                    Nodo* nodo_dos_puntos = crear_nodo("dos puntos", ":");
                    agregar_hijo(nodo_parametro, nodo_dos_puntos);
                    if (numParamsSameType > 1) {
                        for (int k = 0; k < numParamsSameType; k++) {
                            Nodo* nodo_param_inner2 = crear_nodo("parametro_inner", paramsSameType[k]);
                            agregar_hijo(nodo_param_inner, nodo_param_inner2);
                            if (k < numParamsSameType - 1) {
                                Nodo* nodo_coma = crear_nodo("coma", ",");
                                agregar_hijo(nodo_param_inner, nodo_coma);
                            }
                        }
                    }
                }
                trim(parametros[1]);
                toLowerCase(parametros[1]);
                int chars = strlen(parametros[1]);
                int isValidType = es_tipo_valido(parametros[1]);
                if (!isValidType) {
                    mostrar_error("Tipo de dato no valido", num_linea, linea);
                }
            }
            trim(partes[1]);
            trim_semicolon(partes[1]);
            toLowerCase(partes[1]);
            int isValidType = es_tipo_valido(partes[1]);
            if (!isValidType) {
                mostrar_error("Tipo de retorno de la funcion dato no valido", num_linea, linea);
            }
            free(parametros);
        }
        free(partes);
        free(contenido_parentesis);
        free(params);
    } else {
        mostrar_error("Expresion ilegal", num_linea, linea);
    }
}

void analizar_funcion(Nodo* arbol, char* linea, int* num_linea, FILE* archivo, char* nombre_funcion) {
    char buffer[256]; 
    bool cabecera_analizada = false; 
    int count = 0;
    if(!cabecera_analizada) {
        analizar_cabecera_funcion(arbol, linea, *num_linea, nombre_funcion);
        cabecera_analizada = true;
    }
    Nodo* nodo_cuerpo_funcion = crear_nodo("cuerpo_funcion", "");
    agregar_hijo(arbol, nodo_cuerpo_funcion);
    
    char ambito_anterior[50];
    strcpy(ambito_anterior, tabla.ambito_actual);
    strcpy(tabla.ambito_actual, nombre_funcion);
    
    bool retorno_encontrado = false;
    Funcion* func = buscar_funcion(nombre_funcion);
    TipoDato tipo_retorno = func ? func->tipo_retorno : TIPO_DESCONOCIDO;

    while (fgets(buffer, sizeof(buffer), archivo)) {
        (*num_linea)++;
        trim(buffer);
        if(buffer[0] == '\0'){
            continue;
        }

        if(strstr(buffer, ":=") != NULL){
            char** partesRetornoFuncion = split(buffer, ":=", &count);
            if (count >= 2) {
                trim(partesRetornoFuncion[0]);
                trim(partesRetornoFuncion[1]);

                char lowerFuncName[50];
                char lowerVarName[50];
                strcpy(lowerFuncName, nombre_funcion);
                strcpy(lowerVarName, partesRetornoFuncion[0]);
                toLowerCase(lowerFuncName);
                toLowerCase(lowerVarName);
                
                if(partesRetornoFuncion[0][0] == '\0'){
                    mostrar_error("No se ha asignado una variable al valor de retorno", *num_linea, buffer);
                }else if(partesRetornoFuncion[1][0] == '\0'){
                    mostrar_error("No se ha asignado un valor a la variable de retorno", *num_linea, buffer);
                }else if(strcmp(lowerVarName, lowerFuncName) == 0){
                    retorno_encontrado = true;
                    marcar_funcion_con_retorno(nombre_funcion);
                    
                    TipoDato tipo_valor = inferir_tipo_expresion(partesRetornoFuncion[1]);
                    if (!verificar_tipos_compatibles(tipo_retorno, tipo_valor)) {
                        char mensaje[100];
                        sprintf(mensaje, "Tipo de retorno incompatible. Se esperaba %d pero se encontro %d", 
                                tipo_retorno, tipo_valor);
                        mostrar_error(mensaje, *num_linea, buffer);
                    }
                }
                analizar_asignacion(nodo_cuerpo_funcion, buffer, *num_linea);

                for(int i = 0; i < count; i++) {
                    free(partesRetornoFuncion[i]);
                }
                free(partesRetornoFuncion);
            }
        } else if(strstr(buffer, "writeln") != NULL){
            analizar_writeln(nodo_cuerpo_funcion, buffer, *num_linea);
        } else if(contiene_palabra_clave(buffer, palabras_clave, sizeof(palabras_clave) / sizeof(palabras_clave[0]))){
            analizar_palabra_clave(nodo_cuerpo_funcion, buffer, num_linea, true, archivo);
        }
        
        if (strcmp(buffer, "end;") == 0) {
    if (!retorno_encontrado && tipo_retorno != TIPO_DESCONOCIDO) {
        char mensaje[100];
        sprintf(mensaje, "La funcion '%s' debe retornar un valor de tipo %d", nombre_funcion, tipo_retorno);
        mostrar_error(mensaje, *num_linea, nombre_funcion);
    }
  
    strcpy(tabla.ambito_actual, ambito_anterior);
            break;
        }
    }
}

void analizar_expresion(Nodo* arbol, char* expr, int num_linea) {
    removeSpaces(expr);
    trim_semicolon(expr);
    int count = strlen(expr);
    int num_operadores = sizeof(operadoresAritmeticos) / sizeof(operadoresAritmeticos[0]);
    
    char temp_expr[256];
    strcpy(temp_expr, expr);
    char *token = strtok(temp_expr, "+-*/()");

    TipoDato tipo_resultado = TIPO_DESCONOCIDO;
    bool first_operand = true;

    while (token != NULL) {
        trim(token);
        if (isalpha(token[0])) {  
            Variable* var = buscar_variable(token);
            if (var) {
                if (!var->inicializada) {
                    char mensaje[100];
                    sprintf(mensaje, "Variable '%s' utilizada antes de ser inicializada", token);
                    mostrar_advertencia(mensaje, num_linea);
                }

                if (first_operand) {
                    tipo_resultado = var->tipo;
                    first_operand = false;
                } else {
                    if (!verificar_tipos_compatibles(tipo_resultado, var->tipo)) {
                        char mensaje[100];
                        sprintf(mensaje, "Tipos incompatibles en la expresion. No se puede operar %d con %d", 
                                tipo_resultado, var->tipo);
                        mostrar_error(mensaje, num_linea, expr);
                    }
                    
                    if ((tipo_resultado == TIPO_CHAR && (var->tipo == TIPO_INTEGER || var->tipo == TIPO_REAL)) ||
                        (var->tipo == TIPO_CHAR && (tipo_resultado == TIPO_INTEGER || tipo_resultado == TIPO_REAL))) {
                        char mensaje[100];
                        sprintf(mensaje, "No se puede realizar operaciones aritmeticas entre char y tipos numericos");
                        mostrar_error(mensaje, num_linea, expr);
                    }
                }
            }
        }
        token = strtok(NULL, "+-*/()");
    }
    
    TipoDato tipo_expr = inferir_tipo_expresion(expr);
    
    for (int i = 0; i < count; i++) {
        bool es_operador = false;
        for (int j = 0; j < num_operadores; j++) {  
            int op_len = strlen(operadoresAritmeticos[j]);

            if (i + op_len <= count && strncmp(&expr[i], operadoresAritmeticos[j], op_len) == 0) {
                Nodo* nodo_operador = crear_nodo("operador", operadoresAritmeticos[j]);
                agregar_hijo(arbol, nodo_operador);
                es_operador = true;
                i += op_len - 1; 
                break;
            }
        }

        if (!es_operador) {
            char operando[2] = {expr[i], '\0'};
            Nodo* nodo_operando = crear_nodo("operando", operando);
            agregar_hijo(arbol, nodo_operando);
        }
    }
}

void analizar_llamada_funcion(const char* nombre_funcion, const char* argumentos, int num_linea) {
    Funcion* func = buscar_funcion(nombre_funcion);
    if (!func) {
        mostrar_error("Funcion no declarada", num_linea, nombre_funcion);
        return;
    }
    
    int count = 0;
    char** args = NULL;
    if (strlen(argumentos) > 0) {
        args = split(argumentos, ",", &count);
    }
    
    if (count != func->num_parametros) {
        char mensaje[100];
        sprintf(mensaje, "Numero incorrecto de argumentos. Se esperaban %d pero se encontraron %d", 
                func->num_parametros, count);
        mostrar_error(mensaje, num_linea, nombre_funcion);
    } else {
        for (int i = 0; i < count; i++) {
            trim(args[i]);
            TipoDato tipo_arg = inferir_tipo_expresion(args[i]);
            TipoDato tipo_param = func->parametros[i].tipo;
            
            if (!verificar_tipos_compatibles(tipo_param, tipo_arg)) {
                char mensaje[100];
                sprintf(mensaje, "Tipo incompatible en el argumento %d. Se esperaba %d pero se encontro %d", 
                        i+1, tipo_param, tipo_arg);
                mostrar_error(mensaje, num_linea, args[i]);
            }
        }
    }
    
    if (args) {
        for (int i = 0; i < count; i++) {
            free(args[i]);
        }
        free(args);
    }
}

bool es_llamada_funcion(const char* expr) {
    char* copia = strdup(expr);
    char* token = strtok(copia, "( \t\n");
    
    if (token) {
        trim(token);
        if (isalpha(token[0]) || token[0] == '_') {
            const char* resto = expr + strlen(token);
            while (*resto && isspace(*resto)) resto++;
            
            free(copia);
            return (*resto == '(');
        }
    }
    
    free(copia);
    return false;
}

void procesar_llamada_funcion(const char* expr, int num_linea) {
    char nombre_funcion[50] = {0};
    int i = 0;
    
    while (expr[i] && expr[i] != '(' && i < 49) {
        nombre_funcion[i] = expr[i];
        i++;
    }
    nombre_funcion[i] = '\0';
    trim(nombre_funcion);
    
    printf("DEBUG: Buscando funcion: '%s'\n", nombre_funcion);
    printf("DEBUG: Funciones disponibles: %d\n", tabla.num_funciones);
    for (int j = 0; j < tabla.num_funciones; j++) {
        printf("DEBUG: Funcion %d: '%s'\n", j, tabla.funciones[j].nombre);
    }

    char nombre_lower[50];
    strcpy(nombre_lower, nombre_funcion);
    toLowerCase(nombre_lower);
    
    Funcion* func = buscar_funcion(nombre_lower);
    if (!func) {
        char error_msg[100];
        sprintf(error_msg, "Funcion no declarada -> %s -> %s", nombre_funcion, expr);
        mostrar_error(error_msg, num_linea, expr);
        return;
    }

    char* argumentos = extraer_argumentos_funcion(expr);
    if (!argumentos) {
        mostrar_error("Error al extraer argumentos de la funcion", num_linea, expr);
        return;
    }
    
    int num_args = 0;
    if (strlen(argumentos) > 0) {
        char* args_copy = strdup(argumentos);
        char* token = strtok(args_copy, ",");
        while (token) {
            num_args++;
            token = strtok(NULL, ",");
        }
        free(args_copy);
    }

    if (num_args != func->num_parametros) {
        char error_msg[100];
        sprintf(error_msg, "Numero incorrecto de argumentos para la funcion %s. Esperados: %d, Recibidos: %d", 
                nombre_funcion, func->num_parametros, num_args);
        mostrar_error(error_msg, num_linea, expr);
        free(argumentos);
        return;
    }
    
    free(argumentos);
}

void analizar_asignacion(Nodo* arbol, const char* linea, int num_linea){
    printf("ANALIZAR ASIGNACION\n");
    printf("linea: %s\n", linea);
     if (!validar_asignacion(linea, num_linea)) {
        return;
    }
    
    
    int count = 0;
    char** partes = split(linea, ":=", &count);
    printf("Count: %i\n", count);
    printf("Partes 0 %s\n", partes[0]);
    printf("Partes 1 %s\n", partes[1]);
    
    if (!partes || count != 2) {
        mostrar_error("Asignacion mal formada", num_linea, linea);
        return;
    }

    trim(partes[0]);
    trim(partes[1]);
    
    char lowerPartes0[256];
    char lowerPartes1[256];
    strcpy(lowerPartes0, partes[0]);
    strcpy(lowerPartes1, partes[1]);
    toLowerCase(lowerPartes0);
    toLowerCase(lowerPartes1);

    bool var_exists = false;
    bool func_exists = false;
    
    for (int i = 0; i < tabla.num_variables; i++) {
        char lowerVarName[50];
        strcpy(lowerVarName, tabla.variables[i].nombre);
        toLowerCase(lowerVarName);
        if (strcmp(lowerVarName, lowerPartes0) == 0) {
            var_exists = true;
            break;
        }
    }
    
    for (int i = 0; i < tabla.num_funciones; i++) {
        char lowerFuncName[50];
        strcpy(lowerFuncName, tabla.funciones[i].nombre);
        toLowerCase(lowerFuncName);
        if (strcmp(lowerFuncName, lowerPartes0) == 0) {
            func_exists = true;
            break;
        }
    }
    
    if (!var_exists && !func_exists) {
        mostrar_error("Variable o funcion no declarada", num_linea, partes[0]);
        return;
    }

    TipoDato tipo_izquierda;
    if (variable_existe(partes[0])) {
        Variable* var = buscar_variable(partes[0]);
        tipo_izquierda = var->tipo;
        marcar_variable_inicializada(partes[0]);
    } else {
        Funcion* func = buscar_funcion(partes[0]);
        tipo_izquierda = func->tipo_retorno;
        marcar_funcion_con_retorno(partes[0]);
    }

    if (es_llamada_funcion(partes[1])) {
        char func_name[50] = {0};
        int i = 0;
        while (partes[1][i] && partes[1][i] != '(' && i < 49) {
            func_name[i] = partes[1][i];
            i++;
        }
        func_name[i] = '\0';
        trim(func_name);

        char func_name_lower[50];
        strcpy(func_name_lower, func_name);
        toLowerCase(func_name_lower);

        Funcion* func = buscar_funcion(func_name_lower);
        if (func) {
            char* argumentos = extraer_argumentos_funcion(partes[1]);
            if (!argumentos) {
                mostrar_error("Error al extraer argumentos de la funcion", num_linea, partes[1]);
                for (int i = 0; i < count; i++) {
                    free(partes[i]);
                }
                free(partes);
                return;
            }

            int num_args = 0;
            if (strlen(argumentos) > 0) {
                char* args_copy = strdup(argumentos);
                char* token = strtok(args_copy, ",");
                while (token) {
                    num_args++;
                    token = strtok(NULL, ",");
                }
                free(args_copy);
            }
       
            if (num_args != func->num_parametros) {
                char error_msg[100];
                sprintf(error_msg, "Numero incorrecto de argumentos para la funcion %s. Esperados: %d, Recibidos: %d", 
                        func_name, func->num_parametros, num_args);
                mostrar_error(error_msg, num_linea, partes[1]);
                free(argumentos);
                for (int i = 0; i < count; i++) {
                    free(partes[i]);
                }
                free(partes);
                return;
            }
            
            free(argumentos);

            if (func->tipo_retorno != TIPO_DESCONOCIDO && !func->tiene_retorno) {
                char mensaje[100];
                sprintf(mensaje, "La funcion '%s' no tiene un valor de retorno asignado", func_name);
                mostrar_error(mensaje, num_linea, partes[1]);
 
                for (int i = 0; i < count; i++) {
                    free(partes[i]);
                }
                free(partes);
                return;
            }
        }
    }

    TipoDato tipo_derecha = inferir_tipo_expresion(partes[1]);
    
    if (!verificar_tipos_compatibles(tipo_izquierda, tipo_derecha)) {
        char mensaje[100];
        sprintf(mensaje, "Tipos incompatibles en la asignacion. Se esperaba %d pero se encontro %d", 
                tipo_izquierda, tipo_derecha);
        mostrar_error(mensaje, num_linea, linea);
    }

    Nodo* nodo_asignacion = crear_nodo("asignacion", "");
    agregar_hijo(arbol, nodo_asignacion);
    
    Nodo* nodo_variable = crear_nodo("variable", partes[0]);
    Nodo* nodo_asignacion_operador = crear_nodo("asignacion_operador", ":=");
    Nodo* nodo_expresion = crear_nodo("expresion", partes[1]);

    agregar_hijo(nodo_asignacion, nodo_variable);
    agregar_hijo(nodo_asignacion, nodo_asignacion_operador);
    agregar_hijo(nodo_asignacion, nodo_expresion);
    if(strlen(partes[1]) > 1){
        analizar_expresion(nodo_expresion, partes[1], num_linea);
    }
    for (int i = 0; i < count; i++) {
        free(partes[i]);
    }
    free(partes);
}

void analizar_procedure(Nodo* arbol, const char* linea, int* num_linea, FILE* archivo, char* nombre_procedure) {
    char buffer[256]; 
	trim((char*)linea);
    obtenerNombreProcedure(linea, nombre_procedure, sizeof(nombre_procedure));
    
    if (strncmp(linea, "procedure ", 10) != 0) {
        mostrar_error("La declaracion debe iniciar con 'procedure'", *num_linea, linea);
    }

    if (!end_with_semicolon(linea)) {
        mostrar_error("La declaracion debe terminar con ';'", *num_linea, linea);
    }

    Nodo* nodo_procedure = crear_nodo("procedure", nombre_procedure);
    agregar_hijo(arbol, nodo_procedure);

    while (fgets(buffer, sizeof(buffer), archivo)) {
        (*num_linea)++;
        trim(buffer);
        
        if (buffer[0] == '\0') {
            
            continue;
        }
        if(contiene_palabra_clave(buffer, palabras_clave, sizeof(palabras_clave) / sizeof(palabras_clave[0]))){
            analizar_palabra_clave(nodo_procedure, buffer, num_linea, true, archivo);
        }

        if(strstr(buffer, "writeln") != NULL){
            analizar_writeln(nodo_procedure, buffer, *num_linea);
        }

        if(strcmp(buffer, "end;") == 0){
            break;
        }
    }
}

void analizar_writeln(Nodo* arbol, const char* linea, int num_linea) {
    char contenido[256];
    contenidoWriteln((char*)linea, contenido);
    trim((char*)linea);
    if (!end_with_semicolon(linea)) {
        mostrar_error("La declaracion debe terminar con ';'", num_linea, linea);
    }
    if (strstr(linea, "writel") != NULL && strstr(linea, "writeln") == NULL) {
        mostrar_error("Comando incorrecto. ¿Quiso escribir 'writeln'?", num_linea, linea);
        return;
    }
    Nodo* nodo_writeln = crear_nodo("writeln", linea);
    agregar_hijo(arbol, nodo_writeln);
    char* contenido_en_parentesis = extraer_parentesis(linea);
    if((starts_with(contenido_en_parentesis, "\'"))){
        printf("%s empieza con comillas simples\n", contenido_en_parentesis);
        if(!ends_with(contenido_en_parentesis, "\'")){
            printf("no termina con comillas simples\n");
            mostrar_error("Comilla simple faltante", num_linea, linea);
        }
    }
    if(ends_with(contenido_en_parentesis, "\'")){
        printf("%s termina con comillas simples\n", contenido_en_parentesis);
        if(!starts_with(contenido_en_parentesis, "\'")){
            printf("no empieza con comillas simples\n");
            mostrar_error("Comilla simple faltante", num_linea, linea);
        }
    }

    size_t len = strlen(contenido_en_parentesis);

    if (contenido[0] != '\'' ||  contenido[len - 1] != '\'') {
          int espacio_en_medio = 0;
          for (size_t i = 1; i < len - 1; i++) { 
              if (isspace(contenido[i])) {
                  espacio_en_medio = 1;
                  break;
              }
          }
          if (espacio_en_medio) {
              mostrar_error("El contenido del writeln no puede contener espacios en medio de los caracteres a menos que este encerrado entre comillas simples", num_linea, linea);
          }
      }

    if(!starts_with(contenido_en_parentesis, "\'") && !ends_with(contenido_en_parentesis, "\'")){
    }
    Nodo* contenido_writeln = crear_nodo("contenido", contenido_en_parentesis);
    agregar_hijo(nodo_writeln, contenido_writeln);
    
}

void analizar_if(Nodo* arbol, const char* linea, int *num_linea, FILE* archivo) {
    char condicion[256];
    char buffer[256];
    extraer_condicion_if(linea, condicion);
    trim((char*)linea);
    
    if (strstr(linea, "then") != NULL && !starts_with(linea, "if")) {
        mostrar_error("'then' debe ser precedido por 'if'", *num_linea, linea);
        return;
    }

    int terminaConThen = ends_with(linea, "then");
    if (!terminaConThen) {
        mostrar_error("La estructura if debe terminar con 'then'", *num_linea, linea);
    }

    if (!validar_condicion(condicion, *num_linea)) {
        return;
    }
    Nodo* nodo_if_statement = crear_nodo("if_statement", linea);
    agregar_hijo(arbol, nodo_if_statement);
    Nodo* nodo_if = crear_nodo("if", "if");
    agregar_hijo(nodo_if_statement, nodo_if);
    Nodo* contenido_if = crear_nodo("contenido", condicion);
    agregar_hijo(nodo_if, contenido_if);
    int num_operadores = sizeof(operadoresDeComparacion) / sizeof(operadoresDeComparacion[0]);
    int count = 0;
    for (int i = 0; i < sizeof(operadoresDeComparacion) / sizeof(operadoresDeComparacion[0]); i++) {
        if (strstr(condicion, operadoresDeComparacion[i]) != NULL) {
            char** partesCondicion = split(condicion, operadoresDeComparacion[i], &count);
            Nodo* nodo_operador_izq = crear_nodo("nodo_operador_izq", partesCondicion[0]);
            Nodo* nodo_operador_der = crear_nodo("nodo_operador_der", partesCondicion[1]);
            Nodo* nodo_operador = crear_nodo("operador", operadoresDeComparacion[i]);
            agregar_hijo(contenido_if, nodo_operador_izq);
            agregar_hijo(contenido_if, nodo_operador);
            agregar_hijo(contenido_if, nodo_operador_der);
            break;
        }
    }
    Nodo* then = crear_nodo("then", "then");
    agregar_hijo(nodo_if_statement, then);
    while (fgets(buffer, sizeof(buffer), archivo)) {
        (*num_linea)++;
        trim((char*)buffer);
        if (linea[0] == '\0') {
            continue;
        }
        if (starts_with(buffer, "while") || starts_with(buffer, "for")) {
            strcpy((char*)linea, buffer);
            break;
        }
        Nodo* nodo_sentencia = crear_nodo("sentencia", "");
        agregar_hijo(nodo_if_statement, nodo_sentencia);
        if (strstr(buffer, "writeln") != NULL) {
            analizar_writeln(nodo_sentencia, buffer, *num_linea);
        }
    }
}

void analizar_while(Nodo* arbol, const char* linea, int *num_linea, FILE* archivo){
    char condicion[256];
    char buffer[256];
    trim((char*)linea);
    extraer_condicion_while(linea, condicion);
    if (!validar_condicion(condicion, *num_linea)) {
        return;
    }
    int terminaConDo = ends_with(linea, "do");
    printf("Termina con do: %i\n", terminaConDo);
    if(!terminaConDo){
        mostrar_error("La estructura while debe terminar con 'do'", *num_linea, linea);
    }
    Nodo* while_statement = crear_nodo("while_statement", linea);
    agregar_hijo(arbol, while_statement);
    Nodo* nodo_while = crear_nodo("while", "while");
    agregar_hijo(while_statement, nodo_while);
    trim(condicion);
    Nodo* contenido_while = crear_nodo("contenido", condicion);
    agregar_hijo(nodo_while, contenido_while);
    int num_operadores = sizeof(operadoresDeComparacion) / sizeof(operadoresDeComparacion[0]);
    int count = 0;
    for(int i = 0; i < num_operadores; i++){
        if(strstr(condicion, operadoresDeComparacion[i]) != NULL){
           char** partesCondicion = split(condicion, operadoresDeComparacion[i], &count);
            Nodo* nodo_operador_izq = crear_nodo("nodo_operador_izq", partesCondicion[0]);
            Nodo* nodo_operador_der = crear_nodo("nodo_operador_der", partesCondicion[1]);
            Nodo* nodo_operador = crear_nodo("operador", operadoresDeComparacion[i]);
            agregar_hijo(contenido_while, nodo_operador_izq);
            agregar_hijo(contenido_while, nodo_operador);
            agregar_hijo(contenido_while, nodo_operador_der);
            break;
        }
    }

    Nodo* nodo_do = crear_nodo("do", "do");
    agregar_hijo(while_statement, nodo_do);
    while(fgets(buffer, sizeof(buffer), archivo)){
        (*num_linea)++;
        trim((char*)buffer);
        if(linea[0] == '\0'){
            continue;
        }
        if(starts_with(buffer, "if") || starts_with(buffer, "for") || starts_with(buffer, "while")){
            strcpy((char*)linea, buffer);
            break;
        }
        Nodo* nodo_sentencia = crear_nodo("sentencia", "");
        agregar_hijo(while_statement, nodo_sentencia);
        if(strstr(buffer, "writeln") != NULL){
            analizar_writeln(nodo_sentencia, buffer, *num_linea);
        }
    }

}



void analizar_for(Nodo* arbol, const char* linea, int *num_linea, FILE* archivo) {
    char buffer[256];
    char inicializacion[256];
    char operador_control[10];
    char final[50];
    

    const char* ptr = linea + 4; 
    while (*ptr && isspace(*ptr)) ptr++;
    
    char variable[50] = {0};
    int i = 0;
    while (*ptr && !isspace(*ptr) && *ptr != ':' && i < 49) {
        variable[i++] = *ptr++;
    }
    variable[i] = '\0';
    
    if (!variable_existe(variable)) {
        char error_msg[100];
        sprintf(error_msg, "Variable o funcion no declarada -> %s", variable);
        mostrar_error(error_msg, *num_linea, linea);
        return;
    }
    
    if (!validar_condicion_for(linea, *num_linea)) {
        return;
    }
    
    extraer_condicion_for(linea, inicializacion, operador_control, final);
    
    printf("Inicializacion del for: %s\n", inicializacion);
    printf("Operador de control: %s\n", operador_control);
    printf("Valor final: %s\n", final);
    
    
    Nodo* nodo_for_statement = crear_nodo("for_statement", linea);
    agregar_hijo(arbol, nodo_for_statement);
    
    Nodo* nodo_for = crear_nodo("for", "for");
    agregar_hijo(nodo_for_statement, nodo_for);
    
    analizar_asignacion(nodo_for_statement, inicializacion, *num_linea);
    
    Nodo* nodo_operador_control = crear_nodo("operador_control", operador_control);
    agregar_hijo(nodo_for_statement, nodo_operador_control);
    
    Nodo* nodo_final = crear_nodo("final", final);
    agregar_hijo(nodo_for_statement, nodo_final);
    
    Nodo* nodo_do = crear_nodo("do", "do");
    agregar_hijo(nodo_for_statement, nodo_do);
    
    bool has_begin_block = false;
    long pos = ftell(archivo); 
    
    if (fgets(buffer, sizeof(buffer), archivo)) {
        trim(buffer);
        if (strcmp(buffer, "begin") == 0) {
            has_begin_block = true;
            (*num_linea)++;
            analizar_palabra_clave(nodo_for_statement, buffer, num_linea, false, archivo);
        } else {
            fseek(archivo, pos, SEEK_SET); 
        }
    } else {
        fseek(archivo, pos, SEEK_SET);  
    }
    
    if (!has_begin_block) {
        if (fgets(buffer, sizeof(buffer), archivo)) {
            (*num_linea)++;
            trim(buffer);
            
            Nodo* nodo_sentencia = crear_nodo("sentencia", "");
            agregar_hijo(nodo_for_statement, nodo_sentencia);
            
            if (starts_with(buffer, "writeln")) {
                analizar_writeln(nodo_sentencia, buffer, *num_linea);
            } 
            else if (strstr(buffer, ":=") != NULL) {
                analizar_asignacion(nodo_sentencia, buffer, *num_linea);
            }
            else if (es_llamada_funcion(buffer)) {
                procesar_llamada_funcion(buffer, *num_linea);
            }
        }
    }
    
    printf("Termina con do: %d\n", 1);
}


void imprimir_arbol(Nodo* nodo, int nivel) {
    for (int i = 0; i < nivel; i++) printf("  ");  
    printf("%s(%s)\n", nodo->tipo, nodo->valor);  

    for (int i = 0; i < nodo->num_hijos; i++) {
        imprimir_arbol(nodo->hijos[i], nivel + 1); 
    }
}

int main() {
    FILE* archivo = fopen("codigo_pascal.txt", "r");
    if (!archivo) {
        perror("Error al abrir el archivo");
        return 1; 
    }

    inicializar_tabla_simbolos();

    Nodo* arbol = crear_nodo("programaPrueba", "");
    char linea[256];
    char nombre_funcion[50];
    char nombre_procedure[50];  
    int num_linea = 0;
 
    while (fgets(linea, sizeof(linea), archivo)) {
        trim(linea);
        if (*linea == '\0') {
            num_linea++;
            continue;
        }
 
        char linea_lower[256];
        strcpy(linea_lower, linea);
        toLowerCase(linea_lower);
        
        if (starts_with(linea_lower, "function")) {
            char temp_nombre[50] = {0};
            
            const char* ptr = linea + 9; 
            while (*ptr && isspace(*ptr)) ptr++; 
            
            int i = 0;
            while (*ptr && !isspace(*ptr) && *ptr != '(' && i < 49) {
                temp_nombre[i++] = *ptr++;
            }
            temp_nombre[i] = '\0';

            toLowerCase(temp_nombre);
            
            printf("DEBUG: declaracion de funcion encontrada: '%s'\n", temp_nombre);

            char* dos_puntos = strrchr(linea, ':');
            if (dos_puntos) {
                char tipo_str[50] = {0};
                char* semicolon = strchr(dos_puntos, ';');
                if (semicolon) {
                    strncpy(tipo_str, dos_puntos + 1, semicolon - dos_puntos - 1);
                } else {
                    strcpy(tipo_str, dos_puntos + 1);
                }
                trim(tipo_str);
                toLowerCase(tipo_str);
                
                TipoDato tipo_retorno = obtener_tipo_desde_string(tipo_str);
                if (!funcion_existe(temp_nombre)) {
                agregar_funcion(temp_nombre, tipo_retorno, num_linea);
                printf("DEBUG: Funcion pre-registrada '%s' con tipo %d\n", temp_nombre, tipo_retorno);
                }
            }
        }
        
        num_linea++;
    }

    rewind(archivo);
    num_linea = 0;

    while (fgets(linea, sizeof(linea), archivo)) {
        trim(linea);
        char ultima_linea[256];
        if (*linea == '\0') {
            num_linea++;
            continue;
        };  
        for (int i = 0; linea[i]; i++) linea[i] = tolower(linea[i]);

        char palabra_temp[256];
        strcpy(palabra_temp, linea);
        trim_semicolon(palabra_temp);
        if (es_palabra_clave_similar(palabra_temp, num_linea)) {
            continue;
        }

        if(starts_with(linea, "var")) {
            analizar_inicializacion_variables(arbol, linea, &num_linea, archivo, ultima_linea);
        }
        else if (starts_with(linea, "function")) {
            analizar_funcion(arbol, linea, &num_linea, archivo, nombre_funcion);
        }
        else if(starts_with(linea, "procedure")){
            analizar_procedure(arbol, linea, &num_linea, archivo, nombre_procedure);
        }
        else if(starts_with(linea, "if")){
            analizar_if(arbol, linea, &num_linea, archivo);
        }
        else if(starts_with(linea, "begin")){
            analizar_palabra_clave(arbol, linea, &num_linea, false, archivo);
        }
        else if(starts_with(linea, "while")){
            analizar_while(arbol, linea, &num_linea, archivo);
        }
        else if(starts_with(linea, "for")){
            analizar_for(arbol, linea, &num_linea, archivo);
        }
        else if(starts_with(linea, "writeln")){
            analizar_writeln(arbol, linea, num_linea);
        }
        num_linea++;
    }

    fclose(archivo);
    imprimir_arbol(arbol, 0);

    return 0; 
}