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



# **🏆 PLAN 6 HORAS - Adaptado a la Estructura Actual de Expo**

## **⏰ HORA 1-2: CONFIGURACIÓN Y ESTRUCTURA EXISTENTE**

### **1. Entender la Estructura Actual (30 min)**
```
mi-prueba/
├── app/                    # ✅ NUEVA ESTRUCTURA - App Router
│   ├── _layout.tsx        # ✅ Layout principal 
│   └── (tabs)/            # ✅ Navegación por tabs
│       ├── index.tsx      # ✅ Pantalla principal (HOME)
│       └── explore.tsx    # ✅ Otra pantalla
```

### **2. Instalar Dependencias (15 min)**
```bash
cd mi-prueba
npm install @tanstack/react-query
```

### **3. Configurar TanStack Query en el Layout (45 min)**
**📍 Archivo: `app/_layout.tsx`**

```typescript
import { QueryClient, QueryClientProvider } from '@tanstack/react-query';
import { Stack } from 'expo-router';

// 🎯 EXPLICACIÓN: QueryClient maneja cache y estado de las queries
// Lo creamos FUERA del componente para que no se reinicie en cada render
const clienteQuery = new QueryClient({
  defaultOptions: {
    queries: {
      // 🕒 Los datos se consideran "frescos" por 5 minutos
      staleTime: 5 * 60 * 1000,
      // 🔄 Reintentar 2 veces antes de mostrar error
      retry: 2,
    },
  },
});

export default function RootLayout() {
  return (
    // 🔧 EXPLICACIÓN: QueryClientProvider provee el cliente a TODA la app
    // Así cualquier pantalla puede usar useQuery sin configurar nada
    <QueryClientProvider client={clienteQuery}>
      <Stack>
        <Stack.Screen 
          name="(tabs)" 
          options={{ 
            // 🎯 Ocultar header porque usamos tabs
            headerShown: false 
          }} 
        />
      </Stack>
    </QueryClientProvider>
  );
}
```

---

## **⏰ HORA 2-4: PANTALLA PRINCIPAL CON TANSTACK QUERY**

### **4. Modificar la Pantalla Principal (2 horas)**
**📍 Archivo: `app/(tabs)/index.tsx`**

```typescript
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
const obtenerUsuarios = async () => {
  console.log('🔍 Solicitando usuarios a la API...');
  
  // ⏱️ Simulamos delay de red para testing
  await new Promise(resolve => setTimeout(resolve, 1000));
  
  const respuesta = await fetch('https://jsonplaceholder.typicode.com/users');
  
  // 🚨 VERIFICAMOS si la respuesta fue exitosa
  if (!respuesta.ok) {
    throw new Error(`Error ${respuesta.status}: ${respuesta.statusText}`);
  }
  
  const datos = await respuesta.json();
  console.log(`✅ Recibidos ${datos.length} usuarios`);
  return datos;
};

// 🎯 EXPLICACIÓN: Componente para cada item de la lista
// POR QUÉ: Mejor organización y reutilización
function TarjetaUsuario({ usuario }: { usuario: any }) {
  return (
    <View style={estilos.tarjeta}>
      <Text style={estilos.nombre}>{usuario.name}</Text>
      <Text style={estilos.correo}>{usuario.email}</Text>
      <Text style={estilos.empresa}>{usuario.company.name}</Text>
      <Text style={estilos.telefono}>{usuario.phone}</Text>
    </View>
  );
}

export default function TabOneScreen() {
  const [textoBusqueda, setTextoBusqueda] = useState('');
  
  // 🎯 EXPLICACIÓN: useQuery maneja loading, error, data automáticamente
  const { 
    data: usuarios, 
    isLoading: cargando,
    isError: hayError, 
    error,
    refetch: recargar,
    isFetching: recargando
  } = useQuery({
    queryKey: ['usuarios'], // 🔑 Key única para el cache
    queryFn: obtenerUsuarios, // 🛠️ Función que obtiene los datos
  });

  // 🎯 EXPLICACIÓN: Filtrado en el cliente para búsqueda
  const usuariosFiltrados = usuarios?.filter(usuario =>
    usuario.name.toLowerCase().includes(textoBusqueda.toLowerCase())
  ) || [];

  // 🎯 EXPLICACIÓN: Estados de UI separados para mejor UX
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

  return (
    <View style={estilos.contenedor}>
      <Text style={estilos.titulo}>Lista de Usuarios</Text>
      
      {/* 🎯 EXPLICACIÓN: Input controlado para búsqueda */}
      <TextInput
        style={estilos.buscador}
        placeholder="Buscar por nombre..."
        value={textoBusqueda}
        onChangeText={setTextoBusqueda}
        clearButtonMode="while-editing"
      />

      {/* 🎯 EXPLICACIÓN: FlatList para mejor rendimiento */}
      <FlatList
        data={usuariosFiltrados}
        keyExtractor={(item) => item.id.toString()}
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

// 🎯 EXPLICACIÓN: StyleSheet para mejor rendimiento y organización
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
```

---

## **⏰ HORA 4-5: PRÁCTICA Y MODIFICACIONES**

### **5. Ejercicio: Cambiar a API de Posts (30 min)**
**En `app/(tabs)/index.tsx`, modifica:**

```typescript
// Cambiar la función de fetch
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

### **6. Agregar Funcionalidades Extra (30 min)**
**Contador de resultados:**
```typescript
// Después del TextInput, agrega:
<Text style={estilos.contador}>
  Mostrando {usuariosFiltrados.length} de {usuarios?.length || 0} usuarios
</Text>

// Y en estilos:
contador: {
  textAlign: 'center',
  color: '#666',
  marginBottom: 12,
  fontSize: 14
}
```

---

## **⏰ HORA 5-6: DEFENSA Y PREGUNTAS TÉCNICAS**

### **7. Preguntas que Pueden Hacerte y Respuestas**

**¿Por qué usas esta estructura de Expo?**
```
"Expo App Router es la forma moderna de manejar rutas en React Native.
Me permite tener un sistema de archivos basado en rutas, similar a Next.js,
lo que hace el código más intuitivo y mantenible."
```

**¿Por qué TanStack Query en lugar de useEffect?**
```
"TanStack Query está especializado en datos asíncronos. Me da cache automático,
reintentos, actualizaciones en background, y evita el boilerplate de
manejar loading y error states manualmente."
```

**¿Cómo manejarías una API que requiere autenticación?**
```
"Usaría el sistema de interceptors de TanStack Query o configuraría los headers
de fetch globalmente. También podría usar el contexto de autenticación
de Expo para manejar tokens."
```

**¿Por qué separar TarjetaUsuario en otro componente?**
```
"Por el principio de responsabilidad única. Cada componente debe tener
una tarea específica. Esto hace el código más testeable, reutilizable
y fácil de mantener."
```

**¿Qué ventajas tiene FlatList sobre ScrollView?**
```
"FlatList usa virtualización - solo renderiza los elementos visibles,
lo que es crucial para performance con listas largas. ScrollView
renderiza todo de una vez, lo que puede causar lag."
```

**¿Cómo mejorarías esta app?**
```
"Agregaría paginación con useInfiniteQuery, búsqueda en el servidor
para datasets grandes, pull-to-refresh nativo, y maybe un sistema
de favoritos usando el cache de TanStack Query."
```

### **8. Comandos Finales para la Prueba**
```bash
# En la terminal de SU laptop:
npx create-expo-app prueba-tecnica
cd prueba-tecnica
npm install @tanstack/react-query

# Modificar:
# 1. app/_layout.tsx (agregar QueryClientProvider)
# 2. app/(tabs)/index.tsx (nuestra pantalla principal)

npm start
# Presionar 'w' para web
```

---

## **🎯 CHECKLIST FINAL 6 HORAS**

### **✅ CONFIGURACIÓN:**
- [ ] Entendí la estructura de Expo App Router
- [ ] Sé modificar `app/_layout.tsx` para TanStack Query
- [ ] Sé que `app/(tabs)/index.tsx` es la pantalla principal

### **✅ CÓDIGO:**
- [ ] Puedo crear la pantalla principal con useQuery
- [ ] Entiendo cada hook y función
- [ ] Puedo explicar por qué cada decisión técnica

### **✅ MODIFICACIONES:**
- [ ] Puedo cambiar a diferente API
- [ ] Puedo agregar funcionalidades simples
- [ ] Sé modificar estilos rápidamente

### **✅ DEFENSA:**
- [ ] Puedo explicar por qué useQuery vs useEffect
- [ ] Sé defender la estructura de componentes
- [ ] Puedo responder preguntas técnicas comunes

## **🚀 ESTRATEGIA DURANTE LA PRUEBA**

1. **Minuto 0-15:** Setup del proyecto y dependencias
2. **Minuto 15-45:** Layout principal con TanStack Query
3. **Minuto 45-90:** Pantalla principal funcional
4. **Minuto 90-105:** Testing y mejoras
5. **Minuto 105-120:** Preparar defensa y preguntas

**¡Tú puedes! Esta estructura es moderna y profesional - demuestra que estás actualizado.**

