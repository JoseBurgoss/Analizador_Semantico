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


# **🗺️ PLAN DETALLADO - App de Mapas Maracaibo**

## **📋 PLAN 1: ESTRUCTURA BÁSICA (Sin funcionalidad)**
*Para mostrar la estructura de la app sin implementar features*

### **HORA 1-2: ESTRUCTURA Y NAVEGACIÓN**

#### **1. Configuración inicial (30 min)**
```bash
npx create-expo-app mapa-maracaibo
cd mapa-maracaibo
```

#### **2. Estructura de archivos básica (1.5 horas)**
```
app/
├── _layout.tsx
└── (tabs)/
    ├── _layout.tsx
    ├── index.tsx      # Pantalla de inicio
    ├── mapa.tsx       # Mapa básico
    ├── lugares.tsx    # Lista básica
    └── perfil.tsx     # Perfil básico
```

### **HORA 2-3: PANTALLAS BÁSICAS**

#### **3. Pantalla de Inicio** (`app/(tabs)/index.tsx`)
```typescript
import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

export default function InicioScreen() {
  return (
    <View style={styles.container}>
      <Text style={styles.title}>Mapa Maracaibo</Text>
      <Text>Explora los lugares de Maracaibo, Venezuela</Text>
    </View>
  );
}
```

#### **4. Pantalla de Mapa** (`app/(tabs)/mapa.tsx`)
```typescript
import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

export default function MapaScreen() {
  return (
    <View style={styles.container}>
      <Text>Mapa de Maracaibo</Text>
      <Text>Aquí irá el mapa interactivo</Text>
    </View>
  );
}
```

#### **5. Pantalla de Lugares** (`app/(tabs)/lugares.tsx`)
```typescript
import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

export default function LugaresScreen() {
  return (
    <View style={styles.container}>
      <Text>Lugares de Maracaibo</Text>
      <Text>Lista de sitios importantes</Text>
    </View>
  );
}
```

#### **6. Pantalla de Perfil** (`app/(tabs)/perfil.tsx`)
```typescript
import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

export default function PerfilScreen() {
  return (
    <View style={styles.container}>
      <Text>Mi Perfil</Text>
      <Text>Configuración de la app</Text>
    </View>
  );
}
```

Tienes razón. Aquí está el plan **realista para desarrollar en 2 horas**:

## **🎯 PLAN EXPRESS - App Mapa Maracaibo**

### **1. Mapa Básico Interactivo** (`app/(tabs)/mapa.tsx`)
```typescript
import React, { useState } from 'react';
import { View, Text, StyleSheet, TouchableOpacity } from 'react-native';

export default function MapaScreen() {
  const [lugarSeleccionado, setLugarSeleccionado] = useState<any>(null);

  const lugares = [
    { id: 1, nombre: "Basílica", tipo: "Religioso", coordenadas: "10.646, -71.613" },
    { id: 2, nombre: "Teatro Baralt", tipo: "Cultural", coordenadas: "10.644, -71.611" },
    { id: 3, nombre: "Vereda del Lago", tipo: "Parque", coordenadas: "10.639, -71.625" }
  ];

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Mapa de Maracaibo</Text>
      
      <View style={styles.mapa}>
        <View style={styles.lago} />
        <View style={styles.ciudad} />
        
        {lugares.map((lugar, index) => (
          <TouchableOpacity
            key={lugar.id}
            style={[styles.marcador, { left: 50 + (index * 100), top: 150 }]}
            onPress={() => setLugarSeleccionado(lugar)}
          >
            <View style={styles.punto} />
          </TouchableOpacity>
        ))}
      </View>

      {lugarSeleccionado && (
        <View style={styles.info}>
          <Text style={styles.nombre}>{lugarSeleccionado.nombre}</Text>
          <Text>{lugarSeleccionado.tipo}</Text>
          <Text>{lugarSeleccionado.coordenadas}</Text>
        </View>
      )}
    </View>
  );
}

const styles = StyleSheet.create({
  container: { flex: 1, padding: 20 },
  title: { fontSize: 20, fontWeight: 'bold', textAlign: 'center', marginBottom: 20 },
  mapa: { flex: 1, backgroundColor: '#e0f7fa', borderRadius: 10, marginBottom: 20 },
  lago: { position: 'absolute', top: 50, left: 0, right: 0, height: 100, backgroundColor: '#81d4fa' },
  ciudad: { position: 'absolute', top: 150, left: 40, right: 40, height: 200, backgroundColor: '#a5d6a7' },
  marcador: { position: 'absolute' },
  punto: { width: 20, height: 20, backgroundColor: 'red', borderRadius: 10 },
  info: { backgroundColor: 'white', padding: 15, borderRadius: 8 }
});
```

### **2. Lista Simple** (`app/(tabs)/lugares.tsx`)
```typescript
import React from 'react';
import { View, Text, FlatList, StyleSheet } from 'react-native';

export default function LugaresScreen() {
  const lugares = [
    { id: 1, nombre: "Basílica de Chiquinquirá", tipo: "Religioso" },
    { id: 2, nombre: "Teatro Baralt", tipo: "Cultural" },
    { id: 3, nombre: "Parque Vereda del Lago", tipo: "Parque" }
  ];

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Lugares de Maracaibo</Text>
      <FlatList
        data={lugares}
        keyExtractor={(item) => item.id.toString()}
        renderItem={({ item }) => (
          <View style={styles.item}>
            <Text style={styles.nombre}>{item.nombre}</Text>
            <Text style={styles.tipo}>{item.tipo}</Text>
          </View>
        )}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: { flex: 1, padding: 20 },
  title: { fontSize: 20, fontWeight: 'bold', marginBottom: 20 },
  item: { backgroundColor: 'white', padding: 15, marginBottom: 10, borderRadius: 8 },
  nombre: { fontWeight: 'bold' },
  tipo: { color: 'gray' }
});
```

### **3. Perfil Básico** (`app/(tabs)/perfil.tsx`)
```typescript
import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

export default function PerfilScreen() {
  return (
    <View style={styles.container}>
      <Text style={styles.title}>Mi Perfil</Text>
      <Text>App Mapa Maracaibo</Text>
      <Text>Versión 1.0</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: { flex: 1, justifyContent: 'center', alignItems: 'center' },
  title: { fontSize: 20, fontWeight: 'bold', marginBottom: 20 }
});
```

### **4. Inicio Simple** (`app/(tabs)/index.tsx`)
```typescript
import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

export default function InicioScreen() {
  return (
    <View style={styles.container}>
      <Text style={styles.title}>Mapa Maracaibo</Text>
      <Text>Explora los lugares de la ciudad</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: { flex: 1, justifyContent: 'center', alignItems: 'center' },
  title: { fontSize: 24, fontWeight: 'bold', marginBottom: 10 }
});
```

## **✅ LO QUE OBTIENES EN 30 MINUTOS:**

- **Mapa interactivo** con marcadores
- **Lista de lugares** básica  
- **Navegación** entre 4 pantallas
- **Diseño funcional** y limpio
- **Código simple** y entendible

# **🗺️ PLAN FULLSTACK - React Native + Express + MySQL**

## **📁 ESTRUCTURA COMPLETA**

```
proyecto/
├── frontend/           # Tu app de React Native actual
├── backend/            # Nuevo - Express API
│   ├── package.json
│   ├── server.js
│   └── database.js
└── README.md
```

## **🔧 BACKEND - Express API** (15 minutos)

### **1. Crear carpeta backend**
```bash
mkdir backend
cd backend
```

### **2. package.json** (`backend/package.json`)
```json
{
  "name": "mapa-backend",
  "version": "1.0.0",
  "scripts": {
    "start": "node server.js",
    "dev": "nodemon server.js"
  },
  "dependencies": {
    "express": "^4.18.2",
    "cors": "^2.8.5",
    "mysql2": "^3.6.0",
    "dotenv": "^16.3.1"
  }
}
```

### **3. Configuración BD** (`backend/database.js`)
```javascript
const mysql = require('mysql2');
require('dotenv').config();

const connection = mysql.createConnection({
  host: process.env.DB_HOST || 'localhost',
  user: process.env.DB_USER || 'root',
  password: process.env.DB_PASSWORD || '',
  database: process.env.DB_NAME || 'mapa_maracaibo'
});

connection.connect((err) => {
  if (err) {
    console.error('Error conectando a MySQL:', err);
    return;
  }
  console.log('Conectado a MySQL');
  
  // Crear tabla si no existe
  const createTable = `
    CREATE TABLE IF NOT EXISTS lugares (
      id INT AUTO_INCREMENT PRIMARY KEY,
      nombre VARCHAR(255) NOT NULL,
      tipo VARCHAR(100),
      descripcion TEXT,
      latitud DECIMAL(10,8),
      longitud DECIMAL(11,8),
      created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
    )
  `;
  
  connection.query(createTable, (err) => {
    if (err) console.error('Error creando tabla:', err);
    else console.log('Tabla lugares lista');
  });
});

module.exports = connection;
```

### **4. Servidor Express** (`backend/server.js`)
```javascript
const express = require('express');
const cors = require('cors');
require('dotenv').config();
const db = require('./database');

const app = express();
const PORT = process.env.PORT || 3000;

app.use(cors());
app.use(express.json());

// 1. GET - Obtener todos los lugares
app.get('/api/lugares', (req, res) => {
  db.query('SELECT * FROM lugares', (err, results) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    res.json(results);
  });
});

// 2. GET - Obtener un lugar por ID
app.get('/api/lugares/:id', (req, res) => {
  const { id } = req.params;
  db.query('SELECT * FROM lugares WHERE id = ?', [id], (err, results) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    if (results.length === 0) {
      return res.status(404).json({ error: 'Lugar no encontrado' });
    }
    res.json(results[0]);
  });
});

// 3. POST - Crear nuevo lugar
app.post('/api/lugares', (req, res) => {
  const { nombre, tipo, descripcion, latitud, longitud } = req.body;
  
  db.query(
    'INSERT INTO lugares (nombre, tipo, descripcion, latitud, longitud) VALUES (?, ?, ?, ?, ?)',
    [nombre, tipo, descripcion, latitud, longitud],
    (err, results) => {
      if (err) {
        return res.status(500).json({ error: err.message });
      }
      res.status(201).json({ id: results.insertId, nombre, tipo });
    }
  );
});

// 4. PUT - Actualizar lugar
app.put('/api/lugares/:id', (req, res) => {
  const { id } = req.params;
  const { nombre, tipo, descripcion, latitud, longitud } = req.body;
  
  db.query(
    'UPDATE lugares SET nombre=?, tipo=?, descripcion=?, latitud=?, longitud=? WHERE id=?',
    [nombre, tipo, descripcion, latitud, longitud, id],
    (err, results) => {
      if (err) {
        return res.status(500).json({ error: err.message });
      }
      res.json({ message: 'Lugar actualizado' });
    }
  );
});

// 5. DELETE - Eliminar lugar
app.delete('/api/lugares/:id', (req, res) => {
  const { id } = req.params;
  
  db.query('DELETE FROM lugares WHERE id = ?', [id], (err, results) => {
    if (err) {
      return res.status(500).json({ error: err.message });
    }
    res.json({ message: 'Lugar eliminado' });
  });
});

app.listen(PORT, () => {
  console.log(`🚀 Servidor corriendo en http://localhost:${PORT}`);
});
```

### **5. Variables entorno** (`backend/.env`)
```env
DB_HOST=localhost
DB_USER=root
DB_PASSWORD=tu_password
DB_NAME=mapa_maracaibo
PORT=3000
```

## **📱 FRONTEND - React Native Actualizado** (10 minutos)

### **1. Mapa conectado a API** (`app/(tabs)/mapa.tsx`)
```typescript
import React, { useState, useEffect } from 'react';
import { View, Text, StyleSheet, TouchableOpacity, ActivityIndicator } from 'react-native';

const API_URL = 'http://localhost:3000/api';

export default function MapaScreen() {
  const [lugares, setLugares] = useState<any[]>([]);
  const [lugarSeleccionado, setLugarSeleccionado] = useState<any>(null);
  const [cargando, setCargando] = useState(true);

  useEffect(() => {
    cargarLugares();
  }, []);

  const cargarLugares = async () => {
    try {
      const response = await fetch(`${API_URL}/lugares`);
      const data = await response.json();
      setLugares(data);
    } catch (error) {
      console.error('Error cargando lugares:', error);
    } finally {
      setCargando(false);
    }
  };

  if (cargando) {
    return (
      <View style={styles.center}>
        <ActivityIndicator size="large" />
        <Text>Cargando lugares...</Text>
      </View>
    );
  }

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Mapa de Maracaibo</Text>
      
      <View style={styles.mapa}>
        <View style={styles.lago} />
        <View style={styles.ciudad} />
        
        {lugares.map((lugar, index) => (
          <TouchableOpacity
            key={lugar.id}
            style={[styles.marcador, { left: 50 + (index * 100), top: 150 }]}
            onPress={() => setLugarSeleccionado(lugar)}
          >
            <View style={styles.punto} />
          </TouchableOpacity>
        ))}
      </View>

      {lugarSeleccionado && (
        <View style={styles.info}>
          <Text style={styles.nombre}>{lugarSeleccionado.nombre}</Text>
          <Text>{lugarSeleccionado.tipo}</Text>
          <Text>{lugarSeleccionado.descripcion}</Text>
          <Text>Coordenadas: {lugarSeleccionado.latitud}, {lugarSeleccionado.longitud}</Text>
        </View>
      )}
    </View>
  );
}

const styles = StyleSheet.create({
  container: { flex: 1, padding: 20 },
  center: { flex: 1, justifyContent: 'center', alignItems: 'center' },
  title: { fontSize: 20, fontWeight: 'bold', textAlign: 'center', marginBottom: 20 },
  mapa: { flex: 1, backgroundColor: '#e0f7fa', borderRadius: 10, marginBottom: 20 },
  lago: { position: 'absolute', top: 50, left: 0, right: 0, height: 100, backgroundColor: '#81d4fa' },
  ciudad: { position: 'absolute', top: 150, left: 40, right: 40, height: 200, backgroundColor: '#a5d6a7' },
  marcador: { position: 'absolute' },
  punto: { width: 20, height: 20, backgroundColor: 'red', borderRadius: 10 },
  info: { backgroundColor: 'white', padding: 15, borderRadius: 8 }
});
```

### **2. Lista desde API** (`app/(tabs)/lugares.tsx`)
```typescript
import React, { useState, useEffect } from 'react';
import { View, Text, FlatList, StyleSheet, ActivityIndicator } from 'react-native';

const API_URL = 'http://localhost:3000/api';

export default function LugaresScreen() {
  const [lugares, setLugares] = useState<any[]>([]);
  const [cargando, setCargando] = useState(true);

  useEffect(() => {
    cargarLugares();
  }, []);

  const cargarLugares = async () => {
    try {
      const response = await fetch(`${API_URL}/lugares`);
      const data = await response.json();
      setLugares(data);
    } catch (error) {
      console.error('Error:', error);
    } finally {
      setCargando(false);
    }
  };

  if (cargando) {
    return (
      <View style={styles.center}>
        <ActivityIndicator size="large" />
        <Text>Cargando...</Text>
      </View>
    );
  }

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Lugares de Maracaibo ({lugares.length})</Text>
      <FlatList
        data={lugares}
        keyExtractor={(item) => item.id.toString()}
        renderItem={({ item }) => (
          <View style={styles.item}>
            <Text style={styles.nombre}>{item.nombre}</Text>
            <Text style={styles.tipo}>{item.tipo}</Text>
            <Text style={styles.coordenadas}>
              {item.latitud}, {item.longitud}
            </Text>
          </View>
        )}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: { flex: 1, padding: 20 },
  center: { flex: 1, justifyContent: 'center', alignItems: 'center' },
  title: { fontSize: 20, fontWeight: 'bold', marginBottom: 20 },
  item: { backgroundColor: 'white', padding: 15, marginBottom: 10, borderRadius: 8 },
  nombre: { fontWeight: 'bold', fontSize: 16 },
  tipo: { color: 'gray', marginTop: 4 },
  coordenadas: { fontSize: 12, color: '#666', marginTop: 2 }
});
```

## **🚀 COMANDOS PARA EJECUTAR**

### **Backend:**
```bash
cd backend
npm install
npm start
```

### **Frontend:**
```bash
# En otra terminal, desde la carpeta principal
npm start
```

## **📊 ENDPOINTS DISPONIBLES**

1. `GET /api/lugares` - Listar todos
2. `GET /api/lugares/:id` - Obtener uno
3. `POST /api/lugares` - Crear nuevo
4. `PUT /api/lugares/:id` - Actualizar
5. `DELETE /api/lugares/:id` - Eliminar

## **✅ RESULTADO EN 25 MINUTOS:**

- ✅ **Backend Express** con 5 endpoints
- ✅ **Base de datos MySQL** funcionando
- ✅ **Frontend React Native** consumiendo API
- ✅ **CRUD completo** para lugares
- ✅ **Arquitectura fullstack** real

**¿Listo para implementar? Solo copia y pega cada archivo en su carpeta correspondiente.**

**No, no funcionaría directamente. Te explico por qué:**

## **🚨 PROBLEMAS TÉCNICOS:**

### **1. Expo Go ≠ Servidor Web**
- **Expo Go** es solo un cliente para probar apps
- **No puede ejecutar servidores** Express o bases de datos
- Es como querer ejecutar Apache en Chrome

### **2. Backend necesita entorno Node.js**
- Express, MySQL requieren Node.js
- Expo Go solo ejecuta JavaScript del lado del cliente
- No tiene acceso al sistema de archivos ni puertos

### **3. MySQL necesita servidor dedicado**
- Base de datos debe correr en servidor separado
- No puedes instalar MySQL en Expo Go

## **🎯 OPCIONES REALES:**

### **Opción 1: Backend en la nube (Recomendado)**
```javascript
// Usar servicios como:
// - Render.com (gratis)
// - Railway.app (gratis) 
// - Heroku (gratis)
// - AWS/Azure (créditos gratis)

const API_URL = 'https://tu-api.render.com/api';
```

### **Opción 2: Backend local + Tunnel**
```bash
# 1. Ejecutar backend localmente
cd backend
npm start  # → http://localhost:3000

# 2. Crear tunnel público
npx localtunnel --port 3000  # → https://tu-app.loca.lt

# 3. En la app usar:
const API_URL = 'https://tu-app.loca.lt/api';
```

### **Opción 3: Servicios Backend-as-a-Service**
```javascript
// Usar Firebase, Supabase, etc.
const API_URL = 'https://tu-proyecto.supabase.co/rest/v1';
```

## **📱 SOLUCIÓN PARA PRUEBA TÉCNICA:**

### **Backend Desplegado + Frontend en Expo Go**
```
[Tu Computadora]          [Internet]              [Expo Go en Teléfono]
Backend Local    →    Tunnel/Cloud    →    App consumiendo API real
```

### **Implementación rápida:**
1. **Prepara tu backend** localmente
2. **Usa localtunnel** para exponerlo
3. **Conecta tu app** a la URL del tunnel
4. **¡Funciona en Expo Go!**

## **🔧 CÓDIGO LISTO PARA PROBAR:**

### **1. Backend (igual que antes)**
```javascript
// backend/server.js - Sin cambios
const express = require('express');
const app = express();
app.use(cors());

// Tus 5 endpoints aquí...
app.listen(3000);
```

### **2. Exponer backend**
```bash
cd backend
npm start  # En una terminal
npx localtunnel --port 3000  # En otra terminal
```

### **3. Frontend actualizado**
```typescript
// En tu app React Native
const API_URL = 'https://tu-app.loca.lt/api'; // ← URL que te da localtunnel

export default function MapaScreen() {
  const [lugares, setLugares] = useState([]);

  useEffect(() => {
    const cargarLugares = async () => {
      try {
        const response = await fetch(`${API_URL}/lugares`);
        const data = await response.json();
        setLugares(data);
      } catch (error) {
        console.log('Error cargando datos reales:', error);
      }
    };
    cargarLugares();
  }, []);

  // ... resto del código
}
```

## **✅ VENTAJAS DE ESTE ENFOQUE:**

- ✅ **Backend real** con Express + MySQL
- ✅ **Funciona en Expo Go** (vía tunnel)
- ✅ **Demuestras conocimiento fullstack**
- ✅ **API real con CRUD completo**
- ✅ **Más impresionante en entrevista**

## **⚠️ CONSIDERACIONES:**

- **Tunnel es temporal** - se cierra al parar el proceso
- **Para demo permanente** necesitas hosting real
- **Velocidad depende** de tu internet

**¿Quieres que te guíe paso a paso con localtunnel?** Es la forma más rápida de tener tu backend funcionando con Expo Go.
