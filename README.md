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



# **🏆 PLAN INTENSIVO 6 HORAS - Código Humano + Explicaciones**

## **⏰ PLAN DE 6 HORAS**

### **HORA 1-2: CONFIGURACIÓN Y ESTRUCTURA BASE**

#### **1. Crear Proyecto y Configuración (30 min)**
```bash
npx create-expo-app prueba-tecnica
cd prueba-tecnica
npm install @tanstack/react-query
```

#### **2. App.js - Configuración Principal (30 min)**
```javascript
import React from 'react';
import { QueryClient, QueryClientProvider } from '@tanstack/react-query';
import PantallaPrincipal from './PantallaPrincipal';

// ⚡ EXPLICACIÓN: QueryClient maneja el cache y estado de todas las queries
// Lo creamos FUERA del componente para que no se reinicie en cada render
const clienteQuery = new QueryClient({
  defaultOptions: {
    queries: {
      // 🎯 POR QUÉ: Los datos se consideran "frescos" por 5 minutos
      // Evita llamadas innecesarias a la API mientras los datos son recientes
      staleTime: 5 * 60 * 1000,
    },
  },
});

export default function App() {
  return (
    // 🔧 EXPLICACIÓN: QueryClientProvider provee el cliente a toda la app
    // Así cualquier componente puede usar useQuery sin configurar nada
    <QueryClientProvider client={clienteQuery}>
      <PantallaPrincipal />
    </QueryClientProvider>
  );
}
```

**🎯 DEFENSA:**
- "Uso QueryClient fuera del componente para evitar recrearlo en cada render"
- "Configuro staleTime para optimizar llamadas a la API"
- "QueryClientProvider centraliza la gestión de estado de las APIs"

---

### **HORA 2-4: COMPONENTE PRINCIPAL Y LÓGICA**

#### **3. PantallaPrincipal.js - Componente Completo (2 horas)**
```javascript
import React, { useState } from 'react';
import { 
  View, 
  Text, 
  FlatList, 
  ActivityIndicator, 
  TextInput, 
  StyleSheet,
  RefreshControl 
} from 'react-native';
import { useQuery } from '@tanstack/react-query';

// 🎯 EXPLICACIÓN: Función separada para llamadas a API
// POR QUÉ: Separa la lógica de datos de la lógica de UI
// Facilita testing y reutilización
const obtenerUsuarios = async () => {
  console.log('🔍 Solicitando usuarios a la API...');
  
  // ⏱️ EXPLICACIÓN: Simulamos delay de red para testing
  await new Promise(resolve => setTimeout(resolve, 1000));
  
  const respuesta = await fetch('https://jsonplaceholder.typicode.com/users');
  
  // 🚨 POR QUÉ: Verificamos si la respuesta fue exitosa
  // Fetch no lanza error automáticamente para códigos 400/500
  if (!respuesta.ok) {
    throw new Error(`Error ${respuesta.status}: ${respuesta.statusText}`);
  }
  
  const datos = await respuesta.json();
  console.log(`✅ Recibidos ${datos.length} usuarios`);
  return datos;
};

function PantallaPrincipal() {
  const [textoBusqueda, setTextoBusqueda] = useState('');
  
  // 🎯 EXPLICACIÓN: useQuery maneja loading, error, data y cache automáticamente
  // POR QUÉ usar TanStack Query vs useEffect+useState:
  // - Cache automático
  // - Reintentos automáticos
  // - Actualizaciones en background
  // - DevTools para debugging
  const { 
    data: usuarios, 
    isLoading: cargando,
    isError: hayError, 
    error,
    refetch: recargar,
    isFetching: recargando
  } = useQuery({
    queryKey: ['usuarios'], // 🔑 Key única para identificar esta query
    queryFn: obtenerUsuarios, // 🛠️ Función que obtiene los datos
    retry: 2, // 🔄 Reintentar 2 veces antes de mostrar error
  });

  // 🎯 EXPLICACIÓN: Filtrado en el cliente
  // POR QUÉ: Simple y rápido para datasets pequeños
  // Para datasets grandes: implementar paginación en el servidor
  const usuariosFiltrados = usuarios?.filter(usuario =>
    usuario.name.toLowerCase().includes(textoBusqueda.toLowerCase())
  ) || [];

  // 🎯 EXPLICACIÓN: Estados de UI separados
  // POR QUÉ: Mejor experiencia de usuario mostrando estados específicos
  if (cargando && !recargando) {
    return (
      <View style={estilos.centrado}>
        <ActivityIndicator size="large" color="#007AFF" />
        <Text style={estilos.textoCarga}>Cargando lista de usuarios...</Text>
      </View>
    );
  }

  if (hayError) {
    return (
      <View style={estilos.centrado}>
        <Text style={estilos.textoError}>Error cargando datos</Text>
        <Text style={estilos.textoErrorSecundario}>{error.message}</Text>
        <Text style={estilos.textoReintentar} onPress={recargar}>
          Tocá para reintentar
        </Text>
      </View>
    );
  }

  // 🎯 EXPLICACIÓN: Renderizado principal
  return (
    <View style={estilos.contenedor}>
      <Text style={estilos.titulo}>Lista de Usuarios</Text>
      
      {/* 🎯 EXPLICACIÓN: Input controlado */}
      {/* POR QUÉ: value + onChangeText = input controlado */}
      {/* Ventajas: Validación fácil, reset fácil, estado predecible */}
      <TextInput
        style={estilos.buscador}
        placeholder="Buscar por nombre..."
        value={textoBusqueda}
        onChangeText={setTextoBusqueda}
        clearButtonMode="while-editing"
      />

      {/* 🎯 EXPLICACIÓN: FlatList vs ScrollView */}
      {/* POR QUÉ FlatList: Rendimiento con listas grandes, lazy rendering */}
      <FlatList
        data={usuariosFiltrados}
        keyExtractor={item => item.id.toString()}
        renderItem={({ item }) => (
          <TarjetaUsuario usuario={item} />
        )}
        refreshControl={
          <RefreshControl 
            refreshing={recargando}
            onRefresh={recargar}
            colors={['#007AFF']}
          />
        }
        ListEmptyComponent={
          <Text style={estilos.listaVacia}>
            {textoBusqueda ? 'No hay usuarios que coincidan' : 'No hay usuarios'}
          </Text>
        }
        showsVerticalScrollIndicator={false}
        contentContainerStyle={estilos.contenidoLista}
      />
    </View>
  );
}

// 🎯 EXPLICACIÓN: Componente separado para cada item
// POR QUÉ: Mejor organización, reutilizable, más fácil de testear
function TarjetaUsuario({ usuario }) {
  return (
    <View style={estilos.tarjeta}>
      <Text style={estilos.nombre}>{usuario.name}</Text>
      <Text style={estilos.correo}>{usuario.email}</Text>
      <Text style={estilos.empresa}>{usuario.company.name}</Text>
      <Text style={estilos.telefono}>{usuario.phone}</Text>
    </View>
  );
}

// 🎯 EXPLICACIÓN: StyleSheet.create vs estilos en línea
// POR QUÉ StyleSheet: Mejor rendimiento, validación, organización
const estilos = StyleSheet.create({
  contenedor: {
    flex: 1,
    padding: 16,
    backgroundColor: '#f8f9fa'
  },
  titulo: {
    fontSize: 24,
    fontWeight: '700',
    textAlign: 'center',
    marginVertical: 16,
    color: '#1c1c1e'
  },
  buscador: {
    backgroundColor: 'white',
    padding: 12,
    borderRadius: 10,
    marginBottom: 16,
    borderWidth: 1,
    borderColor: '#c6c6c8',
    fontSize: 16
  },
  contenidoLista: {
    paddingBottom: 20
  },
  tarjeta: {
    backgroundColor: 'white',
    padding: 16,
    borderRadius: 12,
    marginBottom: 12,
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.1,
    shadowRadius: 4,
    elevation: 3
  },
  nombre: {
    fontWeight: '600',
    fontSize: 18,
    marginBottom: 6,
    color: '#000'
  },
  correo: {
    color: '#007AFF',
    marginBottom: 4,
    fontSize: 15
  },
  empresa: {
    fontStyle: 'italic',
    color: '#3c3c43',
    marginBottom: 2,
    fontSize: 14
  },
  telefono: {
    color: '#8e8e93',
    fontSize: 14
  },
  centrado: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    padding: 20
  },
  textoCarga: {
    marginTop: 12,
    color: '#8e8e93',
    fontSize: 16
  },
  textoError: {
    color: '#ff3b30',
    fontSize: 18,
    fontWeight: '600',
    marginBottom: 8
  },
  textoErrorSecundario: {
    color: '#ff3b30',
    textAlign: 'center',
    marginBottom: 16,
    fontSize: 14
  },
  textoReintentar: {
    color: '#007AFF',
    fontSize: 16,
    fontWeight: '500'
  },
  listaVacia: {
    textAlign: 'center',
    color: '#8e8e93',
    fontSize: 16,
    marginTop: 20
  }
});

export default PantallaPrincipal;
```

---

### **HORA 4-5: PRÁCTICA Y MODIFICACIONES**

#### **4. Ejercicios de Modificación (1 hora)**
**Cambiar a API de Posts:**
```javascript
// En PantallaPrincipal.js, modifica:

const obtenerPosts = async () => {
  const respuesta = await fetch('https://jsonplaceholder.typicode.com/posts');
  if (!respuesta.ok) throw new Error('Error cargando posts');
  return respuesta.json();
};

// En useQuery:
queryKey: ['posts'],
queryFn: obtenerPosts,

// En el render:
<Text style={estilos.titulo}>Lista de Posts</Text>

// En TarjetaUsuario:
<Text style={estilos.nombre}>{usuario.title}</Text>
<Text style={estilos.correo}>{usuario.body}</Text>
```

**Agregar Contador:**
```javascript
const [contador, setContador] = useState(0);

// En el return, después del título:
<Text style={estilos.contador}>
  Mostrando {usuariosFiltrados.length} de {usuarios?.length || 0} usuarios
</Text>
```

---

### **HORA 5-6: DEFENSA Y PREGUNTAS TÍPICAS**

#### **5. Preguntas que Pueden Hacerte**

**¿Por qué TanStack Query?**
```
"Porque simplifica enormemente el manejo de estado asíncrono.
Me da cache automático, reintentos, actualizaciones en background,
y me evita escribir boilerplate code para loading y error states."
```

**¿useEffect vs useQuery?**
```
"useEffect es para efectos secundarios genéricos, useQuery está
especializado en datos asíncronos. useQuery me da mejor performance
con cache y no necesita dependencias manuales."
```

**¿Por qué FlatList y no ScrollView?**
```
"FlatList es más eficiente para listas largas porque solo renderiza
los elementos visibles. ScrollView renderiza todo de una vez, lo que
puede causar problemas de performance con muchos elementos."
```

**¿Cómo manejarías paginación?**
```
"Usaría useInfiniteQuery de TanStack Query, que está diseñado
específicamente para paginación. Cargaría más datos cuando el
usuario llegue al final de la lista."
```

**¿Por qué separar en componentes?**
```
"Para mantener el código mantenible y reutilizable. Cada componente
tiene una responsabilidad única. Además, es más fácil de testear
y debuggear."
```

---

## **🎯 CHECKLIST FINAL 6 HORAS**

### **✅ HORA 1-2:**
- [ ] Proyecto creado con Expo
- [ ] TanStack Query instalado
- [ ] App.js configurado con QueryClient

### **✅ HORA 2-4:**
- [ ] PantallaPrincipal.js completo y funcional
- [ ] Entiendo cada hook y función
- [ ] Puedo explicar por qué cada decisión

### **✅ HORA 4-5:**
- [ ] Puedo modificar para usar diferente API
- [ ] Puedo agregar funcionalidades simples
- [ ] Entiendo los estilos y puedo modificarlos

### **✅ HORA 5-6:**
- [ ] Puedo defender mis decisiones técnicas
- [ ] Sé responder preguntas comunes
- [ ] Puedo debuggear problemas básicos

## **🚀 ESTRATEGIA DURANTE LA PRUEBA**

1. **Empieza simple** - Haz que algo funcione primero
2. **Comenta en voz alta** - Explica lo que estás haciendo
3. **Si te atoras** - Di "Voy a intentar esto..." en lugar de quedarte callado
4. **Muestra progreso** - Commit mental de cada funcionalidad completada

**¡Tú puedes! Este plan te da las herramientas para demostrar tu conocimiento.**

