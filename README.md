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


🎵 APP DE MÚSICA - Versión Corregida

1. Layout Principal (igual)

📍 `app/_layout.tsx`

```typescript
import { QueryClient, QueryClientProvider } from '@tanstack/react-query';
import { Stack } from 'expo-router';

const queryClient = new QueryClient();

export default function RootLayout() {
  return (
    <QueryClientProvider client={queryClient}>
      <Stack>
        <Stack.Screen name="(tabs)" options={{ headerShown: false }} />
      </Stack>
    </QueryClientProvider>
  );
}
```

2. Configurar Tabs

📍 `app/(tabs)/_layout.tsx`

```typescript
import { Tabs } from 'expo-router';
import { FontAwesome } from '@expo/vector-icons';

export default function TabLayout() {
  return (
    <Tabs screenOptions={{ tabBarActiveTintColor: 'green' }}>
      <Tabs.Screen
        name="index"
        options={{
          title: 'Inicio',
          tabBarIcon: ({ color }) => <FontAwesome size={28} name="home" color={color} />,
        }}
      />
      <Tabs.Screen
        name="profile"
        options={{
          title: 'Mi Perfil',
          tabBarIcon: ({ color }) => <FontAwesome size={28} name="user" color={color} />,
        }}
      />
    </Tabs>
  );
}
```

3. Pantalla Home - Canciones Populares

📍 `app/(tabs)/index.tsx`

```typescript
import React from 'react';
import { View, Text, FlatList, ActivityIndicator, StyleSheet, TouchableOpacity } from 'react-native';
import { useQuery } from '@tanstack/react-query';
import { useRouter } from 'expo-router';

const getTopSongs = async () => {
  const apiKey = 'ac66e02c5316a0244f53b2cc88d16c3c';
  const response = await fetch(
    `http://ws.audioscrobbler.com/2.0/?method=chart.gettoptracks&api_key=${apiKey}&format=json&limit=15`
  );
  
  if (!response.ok) throw new Error('Error loading songs');
  
  const data = await response.json();
  return data.tracks.track;
};

export default function HomeScreen() {
  const router = useRouter();

  const { data: songs, isLoading, error } = useQuery({
    queryKey: ['songs'],
    queryFn: getTopSongs,
  });

  const goToSongDetail = (song: any) => {
    router.push({
      pathname: '/song-detail',
      params: { 
        songName: song.name,
        artist: song.artist.name,
        listeners: song.listeners
      }
    });
  };

  if (isLoading) {
    return (
      <View style={styles.center}>
        <ActivityIndicator size="large" />
        <Text>Loading songs...</Text>
      </View>
    );
  }

  if (error) {
    return (
      <View style={styles.center}>
        <Text>Error loading songs</Text>
      </View>
    );
  }

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Canciones Populares</Text>

      <FlatList
        data={songs}
        keyExtractor={(item) => item.url}
        renderItem={({ item, index }) => (
          <TouchableOpacity 
            style={styles.songItem}
            onPress={() => goToSongDetail(item)}
          >
            <Text style={styles.rank}>#{index + 1}</Text>
            <View style={styles.songInfo}>
              <Text style={styles.songName}>{item.name}</Text>
              <Text style={styles.artist}>{item.artist.name}</Text>
            </View>
            <Text style={styles.listeners}>{item.listeners}</Text>
          </TouchableOpacity>
        )}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 16,
    backgroundColor: '#fff'
  },
  title: {
    fontSize: 20,
    fontWeight: 'bold',
    marginBottom: 16,
    textAlign: 'center'
  },
  songItem: {
    flexDirection: 'row',
    padding: 12,
    borderBottomWidth: 1,
    borderBottomColor: '#eee',
    alignItems: 'center'
  },
  rank: {
    fontWeight: 'bold',
    marginRight: 12,
    color: 'green',
    width: 30
  },
  songInfo: {
    flex: 1
  },
  songName: {
    fontWeight: '600',
    fontSize: 16
  },
  artist: {
    color: 'gray',
    fontSize: 14
  },
  listeners: {
    color: 'gray',
    fontSize: 12
  },
  center: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center'
  }
});
```

4. Pantalla Detalle de Canción

📍 `app/song-detail.tsx`

```typescript
import React, { useState, useEffect } from 'react';
import { View, Text, StyleSheet, TouchableOpacity } from 'react-native';
import { useLocalSearchParams, useRouter } from 'expo-router';
import AsyncStorage from '@react-native-async-storage/async-storage';

export default function SongDetailScreen() {
  const params = useLocalSearchParams();
  const router = useRouter();
  
  const songName = params.songName as string;
  const artist = params.artist as string;
  const listeners = params.listeners as string;
  
  const [isFavorite, setIsFavorite] = useState(false);

  useEffect(() => {
    checkFavorite();
  }, [artist]);

  const checkFavorite = async () => {
    try {
      const favorites = await AsyncStorage.getItem('favorite_artists');
      const favoriteList = favorites ? JSON.parse(favorites) : [];
      setIsFavorite(favoriteList.includes(artist));
    } catch (error) {
      console.log('Error checking favorites');
    }
  };

  const toggleFavorite = async () => {
    try {
      const favorites = await AsyncStorage.getItem('favorite_artists');
      let favoriteList = favorites ? JSON.parse(favorites) : [];
      
      if (isFavorite) {
        favoriteList = favoriteList.filter((art: string) => art !== artist);
      } else {
        favoriteList.push(artist);
      }
      
      await AsyncStorage.setItem('favorite_artists', JSON.stringify(favoriteList));
      setIsFavorite(!isFavorite);
    } catch (error) {
      console.log('Error saving favorite');
    }
  };

  return (
    <View style={styles.container}>
      <Text style={styles.songTitle}>{songName}</Text>
      <Text style={styles.artist}>por {artist}</Text>
      
      <View style={styles.infoBox}>
        <Text style={styles.infoText}>Oyentes: {listeners}</Text>
      </View>

      <TouchableOpacity 
        style={[styles.favoriteButton, isFavorite && styles.favoriteActive]}
        onPress={toggleFavorite}
      >
        <Text style={styles.favoriteText}>
          {isFavorite ? '★ En Favoritos' : '☆ Agregar a Favoritos'}
        </Text>
      </TouchableOpacity>

      <TouchableOpacity 
        style={styles.backButton}
        onPress={() => router.back()}
      >
        <Text style={styles.backText}>Volver</Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 20,
    backgroundColor: '#fff',
    justifyContent: 'center',
    alignItems: 'center'
  },
  songTitle: {
    fontSize: 28,
    fontWeight: 'bold',
    textAlign: 'center',
    marginBottom: 8
  },
  artist: {
    fontSize: 20,
    color: 'gray',
    marginBottom: 30,
    textAlign: 'center'
  },
  infoBox: {
    backgroundColor: '#f0f0f0',
    padding: 20,
    borderRadius: 10,
    marginBottom: 30,
    width: '80%',
    alignItems: 'center'
  },
  infoText: {
    fontSize: 18,
    fontWeight: '600'
  },
  favoriteButton: {
    backgroundColor: '#4CAF50',
    padding: 15,
    borderRadius: 8,
    marginBottom: 20,
    width: '80%',
    alignItems: 'center'
  },
  favoriteActive: {
    backgroundColor: '#FF9800'
  },
  favoriteText: {
    color: 'white',
    fontSize: 16,
    fontWeight: 'bold'
  },
  backButton: {
    padding: 12,
    borderRadius: 6,
    borderWidth: 1,
    borderColor: '#ccc',
    width: '60%',
    alignItems: 'center'
  },
  backText: {
    fontSize: 16,
    color: '#666'
  }
});
```

5. Pantalla Perfil (Favoritos)

📍 `app/(tabs)/profile.tsx`

```typescript
import React, { useState, useEffect } from 'react';
import { View, Text, FlatList, StyleSheet, TouchableOpacity } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { useRouter } from 'expo-router';

export default function ProfileScreen() {
  const [favoriteArtists, setFavoriteArtists] = useState<string[]>([]);
  const router = useRouter();

  useEffect(() => {
    loadFavorites();
  }, []);

  const loadFavorites = async () => {
    try {
      const favorites = await AsyncStorage.getItem('favorite_artists');
      if (favorites) {
        setFavoriteArtists(JSON.parse(favorites));
      }
    } catch (error) {
      console.log('Error loading favorites');
    }
  };

  const removeFavorite = async (artistName: string) => {
    try {
      const updatedFavorites = favoriteArtists.filter(artist => artist !== artistName);
      setFavoriteArtists(updatedFavorites);
      await AsyncStorage.setItem('favorite_artists', JSON.stringify(updatedFavorites));
    } catch (error) {
      console.log('Error removing favorite');
    }
  };

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Mis Artistas Favoritos</Text>
      
      {favoriteArtists.length === 0 ? (
        <View style={styles.empty}>
          <Text>No tienes artistas favoritos</Text>
          <Text>Agrega artistas desde el detalle de una canción</Text>
        </View>
      ) : (
        <FlatList
          data={favoriteArtists}
          keyExtractor={(item) => item}
          renderItem={({ item }) => (
            <View style={styles.artistItem}>
              <Text style={styles.artistName}>{item}</Text>
              <TouchableOpacity 
                style={styles.removeButton}
                onPress={() => removeFavorite(item)}
              >
                <Text style={styles.removeText}>Eliminar</Text>
              </TouchableOpacity>
            </View>
          )}
        />
      )}
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 16,
    backgroundColor: '#fff'
  },
  title: {
    fontSize: 20,
    fontWeight: 'bold',
    marginBottom: 16,
    textAlign: 'center'
  },
  empty: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center'
  },
  artistItem: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    padding: 16,
    borderBottomWidth: 1,
    borderBottomColor: '#eee'
  },
  artistName: {
    fontSize: 16,
    fontWeight: '500'
  },
  removeButton: {
    backgroundColor: '#ff4444',
    padding: 8,
    borderRadius: 4
  },
  removeText: {
    color: 'white',
    fontSize: 12
  }
});
```

Flujo corregido:

1. Home → Lista de canciones populares
2. Tocar canción → Va a detalle de esa canción (pantalla grande)
3. En detalle → Puedes agregar el artista a favoritos
4. Perfil → Muestra artistas favoritos guardados

Simple y creíble para 2 horas 🎵
import React, { useState, useEffect } from 'react';
import { View, Text, StyleSheet, TouchableOpacity, Image, ActivityIndicator } from 'react-native';
import { useLocalSearchParams, useRouter } from 'expo-router';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { useQuery } from '@tanstack/react-query';

// ✅ SEGUNDO ENDPOINT para obtener imagen del artista
const getArtistImage = async (artistName: string) => {
  const apiKey = 'ac66e02c5316a0244f53b2cc88d16c3c';
  const response = await fetch(
    `http://ws.audioscrobbler.com/2.0/?method=artist.getinfo&artist=${encodeURIComponent(artistName)}&api_key=${apiKey}&format=json`
  );
  
  if (!response.ok) throw new Error('Error loading artist image');
  
  const data = await response.json();
  return data.artist.image[3]?.['#text']; // ← Imagen extra large
};

export default function SongDetailScreen() {
  const params = useLocalSearchParams();
  const router = useRouter();
  
  const songName = params.songName as string;
  const artist = params.artist as string;
  const listeners = params.listeners as string;
  
  const [isFavorite, setIsFavorite] = useState(false);

  // ✅ USAR useQuery PARA OBTENER LA IMAGEN
  const { data: artistImage, isLoading: imageLoading } = useQuery({
    queryKey: ['artist-image', artist],
    queryFn: () => getArtistImage(artist),
  });

  useEffect(() => {
    loadFavorites();
  }, []);

  const loadFavorites = async () => {
    try {
      const favorites = await AsyncStorage.getItem('favorite_artists');
      const favoriteList = favorites ? JSON.parse(favorites) : [];
      setIsFavorite(favoriteList.includes(artist));
    } catch (error) {
      console.log('Error loading favorites');
    }
  };

  const toggleFavorite = async () => {
    try {
      const favorites = await AsyncStorage.getItem('favorite_artists');
      let favoriteList = favorites ? JSON.parse(favorites) : [];
      
      if (isFavorite) {
        favoriteList = favoriteList.filter((art: string) => art !== artist);
      } else {
        favoriteList.push(artist);
      }
      
      await AsyncStorage.setItem('favorite_artists', JSON.stringify(favoriteList));
      setIsFavorite(!isFavorite);
    } catch (error) {
      console.log('Error saving favorite');
    }
  };

  return (
    <View style={styles.container}>
      {/* ✅ MOSTRAR IMAGEN DEL ARTISTA */}
      {imageLoading ? (
        <ActivityIndicator size="large" color="#1DB954" />
      ) : artistImage ? (
        <Image 
          source={{ uri: artistImage }} 
          style={styles.artistImage}
        />
      ) : (
        <View style={styles.placeholderImage}>
          <Text>🎤</Text>
        </View>
      )}
      
      <Text style={styles.songTitle}>{songName}</Text>
      <Text style={styles.artist}>por {artist}</Text>
      
      <View style={styles.infoBox}>
        <Text style={styles.infoText}>Oyentes: {listeners}</Text>
      </View>

      <TouchableOpacity 
        style={[styles.favoriteButton, isFavorite && styles.favoriteActive]}
        onPress={toggleFavorite}
      >
        <Text style={styles.favoriteText}>
          {isFavorite ? '★ En Favoritos' : '☆ Agregar a Favoritos'}
        </Text>
      </TouchableOpacity>

      <TouchableOpacity 
        style={styles.backButton}
        onPress={() => router.back()}
      >
        <Text style={styles.backText}>Volver</Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 20,
    backgroundColor: '#fff',
    justifyContent: 'center',
    alignItems: 'center'
  },
  artistImage: {
    width: 200,
    height: 200,
    borderRadius: 100, // ← Circular para foto de artista
    marginBottom: 20
  },
  placeholderImage: {
    width: 200,
    height: 200,
    borderRadius: 100,
    marginBottom: 20,
    backgroundColor: '#f0f0f0',
    justifyContent: 'center',
    alignItems: 'center'
  },
  songTitle: {
    fontSize: 28,
    fontWeight: 'bold',
    textAlign: 'center',
    marginBottom: 8
  },
  artist: {
    fontSize: 20,
    color: 'gray',
    marginBottom: 30,
    textAlign: 'center'
  },
  infoBox: {
    backgroundColor: '#f0f0f0',
    padding: 20,
    borderRadius: 10,
    marginBottom: 30,
    width: '80%',
    alignItems: 'center'
  },
  infoText: {
    fontSize: 18,
    fontWeight: '600'
  },
  favoriteButton: {
    backgroundColor: '#4CAF50',
    padding: 15,
    borderRadius: 8,
    marginBottom: 20,
    width: '80%',
    alignItems: 'center'
  },
  favoriteActive: {
    backgroundColor: '#FF9800'
  },
  favoriteText: {
    color: 'white',
    fontSize: 16,
    fontWeight: 'bold'
  },
  backButton: {
    padding: 12,
    borderRadius: 6,
    borderWidth: 1,
    borderColor: '#ccc',
    width: '60%',
    alignItems: 'center'
  },
  backText: {
    fontSize: 16,
    color: '#666'
  }
});



import React, { useState, useEffect } from 'react';
import { View, Text, StyleSheet, TouchableOpacity, Image, ActivityIndicator } from 'react-native';
import { useLocalSearchParams, useRouter } from 'expo-router';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { useQuery } from '@tanstack/react-query';

const getArtistImage = async (artistName: string) => {
  const apiKey = 'ac66e02c5316a0244f53b2cc88d16c3c';
  const response = await fetch(
    `http://ws.audioscrobbler.com/2.0/?method=artist.getinfo&artist=${encodeURIComponent(artistName)}&api_key=${apiKey}&format=json`
  );
  
  if (!response.ok) throw new Error('Error loading artist image');
  
  const data = await response.json();
  return data.artist.image[3]?.['#text'];
};

export default function SongDetailScreen() {
  const params = useLocalSearchParams();
  const router = useRouter();
  
  const songName = params.songName as string;
  const artist = params.artist as string;
  const listeners = params.listeners as string;
  
  const [isFavorite, setIsFavorite] = useState(false);

  const { data: artistImage, isLoading: imageLoading } = useQuery({
    queryKey: ['artist-image', artist],
    queryFn: () => getArtistImage(artist),
  });

  useEffect(() => {
    loadFavorites();
  }, []);

  const loadFavorites = async () => {
    try {
      const favorites = await AsyncStorage.getItem('favorite_artists');
      const favoriteList = favorites ? JSON.parse(favorites) : [];
      setIsFavorite(favoriteList.includes(artist));
    } catch (error) {
      console.log('Error loading favorites');
    }
  };

  const toggleFavorite = async () => {
    try {
      const favorites = await AsyncStorage.getItem('favorite_artists');
      let favoriteList = favorites ? JSON.parse(favorites) : [];
      
      if (isFavorite) {
        favoriteList = favoriteList.filter((art: string) => art !== artist);
      } else {
        favoriteList.push(artist);
      }
      
      await AsyncStorage.setItem('favorite_artists', JSON.stringify(favoriteList));
      setIsFavorite(!isFavorite);
    } catch (error) {
      console.log('Error saving favorite');
    }
  };

  return (
    <View style={styles.container}>
      {imageLoading ? (
        <ActivityIndicator size="large" color="#1DB954" />
      ) : artistImage ? (
        <Image 
          source={{ uri: artistImage }} 
          style={styles.artistImage}
        />
      ) : (
        <View style={styles.placeholderImage}>
          <Text>🎤</Text>
        </View>
      )}
      
      <Text style={styles.songTitle}>{songName}</Text>
      <Text style={styles.artist}>por {artist}</Text>
      
      <View style={styles.infoBox}>
        <Text style={styles.infoText}>Oyentes: {listeners}</Text>
      </View>

      <TouchableOpacity 
        style={[styles.favoriteButton, isFavorite && styles.favoriteActive]}
        onPress={toggleFavorite}
      >
        <Text style={styles.favoriteText}>
          {isFavorite ? '★ En Favoritos' : '☆ Agregar a Favoritos'}
        </Text>
      </TouchableOpacity>

      <TouchableOpacity 
        style={styles.backButton}
        onPress={() => router.back()}
      >
        <Text style={styles.backText}>Volver</Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 20,
    backgroundColor: '#fff',
    justifyContent: 'center',
    alignItems: 'center'
  },
  artistImage: {
    width: 200,
    height: 200,
    borderRadius: 100,
    marginBottom: 20
  },
  placeholderImage: {
    width: 200,
    height: 200,
    borderRadius: 100,
    marginBottom: 20,
    backgroundColor: '#f0f0f0',
    justifyContent: 'center',
    alignItems: 'center'
  },
  songTitle: {
    fontSize: 28,
    fontWeight: 'bold',
    textAlign: 'center',
    marginBottom: 8
  },
  artist: {
    fontSize: 20,
    color: 'gray',
    marginBottom: 30,
    textAlign: 'center'
  },
  infoBox: {
    backgroundColor: '#f0f0f0',
    padding: 20,
    borderRadius: 10,
    marginBottom: 30,
    width: '80%',
    alignItems: 'center'
  },
  infoText: {
    fontSize: 18,
    fontWeight: '600'
  },
  favoriteButton: {
    backgroundColor: '#4CAF50',
    padding: 15,
    borderRadius: 8,
    marginBottom: 20,
    width: '80%',
    alignItems: 'center'
  },
  favoriteActive: {
    backgroundColor: '#FF9800'
  },
  favoriteText: {
    color: 'white',
    fontSize: 16,
    fontWeight: 'bold'
  },
  backButton: {
    padding: 12,
    borderRadius: 6,
    borderWidth: 1,
    borderColor: '#ccc',
    width: '60%',
    alignItems: 'center'
  },
  backText: {
    fontSize: 16,
    color: '#666'
  }
});



🎵 detalle.tsx - Completo

```typescript
import React, { useState, useEffect } from 'react';
import { View, Text, StyleSheet, TouchableOpacity, Image, ActivityIndicator } from 'react-native';
import { useLocalSearchParams, useRouter } from 'expo-router';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { useQuery } from '@tanstack/react-query';

const getArtistImage = async (artistName: string) => {
  const apiKey = 'ac66e02c5316a0244f53b2cc88d16c3c';
  const response = await fetch(
    `http://ws.audioscrobbler.com/2.0/?method=artist.getinfo&artist=${encodeURIComponent(artistName)}&api_key=${apiKey}&format=json`
  );
  
  if (!response.ok) throw new Error('Error loading artist image');
  
  const data = await response.json();
  return data.artist.image[3]?.['#text'];
};

export default function SongDetailScreen() {
  const params = useLocalSearchParams();
  const router = useRouter();
  
  const songName = params.songName as string;
  const artist = params.artist as string;
  const listeners = params.listeners as string;
  
  const [isFavorite, setIsFavorite] = useState(false);

  const { data: artistImage, isLoading: imageLoading } = useQuery({
    queryKey: ['artist-image', artist],
    queryFn: () => getArtistImage(artist),
  });

  useEffect(() => {
    loadFavorites();
  }, []);

  const loadFavorites = async () => {
    try {
      const favorites = await AsyncStorage.getItem('favorite_artists');
      const favoriteList = favorites ? JSON.parse(favorites) : [];
      setIsFavorite(favoriteList.includes(artist));
    } catch (error) {
      console.log('Error loading favorites');
    }
  };

  const toggleFavorite = async () => {
    try {
      const favorites = await AsyncStorage.getItem('favorite_artists');
      let favoriteList = favorites ? JSON.parse(favorites) : [];
      
      if (isFavorite) {
        favoriteList = favoriteList.filter((art: string) => art !== artist);
      } else {
        favoriteList.push(artist);
      }
      
      await AsyncStorage.setItem('favorite_artists', JSON.stringify(favoriteList));
      setIsFavorite(!isFavorite);
    } catch (error) {
      console.log('Error saving favorite');
    }
  };

  return (
    <View style={styles.container}>
      {imageLoading ? (
        <ActivityIndicator size="large" color="#1DB954" />
      ) : artistImage ? (
        <Image 
          source={{ uri: artistImage }} 
          style={styles.artistImage}
        />
      ) : (
        <View style={styles.placeholderImage}>
          <Text>🎤</Text>
        </View>
      )}
      
      <Text style={styles.songTitle}>{songName}</Text>
      <Text style={styles.artist}>por {artist}</Text>
      
      <View style={styles.infoBox}>
        <Text style={styles.infoText}>Oyentes: {listeners}</Text>
      </View>

      <TouchableOpacity 
        style={[styles.favoriteButton, isFavorite && styles.favoriteActive]}
        onPress={toggleFavorite}
      >
        <Text style={styles.favoriteText}>
          {isFavorite ? '★ En Favoritos' : '☆ Agregar a Favoritos'}
        </Text>
      </TouchableOpacity>

      <TouchableOpacity 
        style={styles.backButton}
        onPress={() => router.back()}
      >
        <Text style={styles.backText}>Volver</Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 20,
    backgroundColor: '#fff',
    justifyContent: 'center',
    alignItems: 'center'
  },
  artistImage: {
    width: 200,
    height: 200,
    borderRadius: 100,
    marginBottom: 20
  },
  placeholderImage: {
    width: 200,
    height: 200,
    borderRadius: 100,
    marginBottom: 20,
    backgroundColor: '#f0f0f0',
    justifyContent: 'center',
    alignItems: 'center'
  },
  songTitle: {
    fontSize: 28,
    fontWeight: 'bold',
    textAlign: 'center',
    marginBottom: 8
  },
  artist: {
    fontSize: 20,
    color: 'gray',
    marginBottom: 30,
    textAlign: 'center'
  },
  infoBox: {
    backgroundColor: '#f0f0f0',
    padding: 20,
    borderRadius: 10,
    marginBottom: 30,
    width: '80%',
    alignItems: 'center'
  },
  infoText: {
    fontSize: 18,
    fontWeight: '600'
  },
  favoriteButton: {
    backgroundColor: '#4CAF50',
    padding: 15,
    borderRadius: 8,
    marginBottom: 20,
    width: '80%',
    alignItems: 'center'
  },
  favoriteActive: {
    backgroundColor: '#FF9800'
  },
  favoriteText: {
    color: 'white',
    fontSize: 16,
    fontWeight: 'bold'
  },
  backButton: {
    padding: 12,
    borderRadius: 6,
    borderWidth: 1,
    borderColor: '#ccc',
    width: '60%',
    alignItems: 'center'
  },
  backText: {
    fontSize: 16,
    color: '#666'
  }
});
```