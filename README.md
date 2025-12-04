# Simulación de Liga de Baloncesto en C++

##  Descripción del proyecto
Este proyecto implementa una simulación básica de una liga de baloncesto en C++ utilizando programación orientada a objetos.  
El sistema permite modelar una liga con conferencias (Este y Oeste), equipos, jugadores, entrenadores y balones, ofreciendo un menú interactivo para gestionar estos elementos.


##  ¿Para qué sirve?
-Simula una liga de baloncesto con conferencias (Este y Oeste), equipos y jugadores.
-Permite crear conferencias con nombre, región y tipo (Este/Oeste).
-Permite agregar equipos con ciudad, entrenador y balón asociado.
-Permite agregar jugadores con nombre, edad, posición y número de camiseta.
-Ofrece menús interactivos para mostrar la liga completa, una conferencia o un equipo específico.
-Permite eliminar conferencias, equipos o jugadores de forma controlada.
-Incluye validaciones de entrada para evitar datos vacíos, negativos o índices inválidos.


##  ¿Para qué no sirve?
-No simula partidos ni calcula estadísticas deportivas.
-No guarda datos en archivos ni en bases de datos (la información se pierde al cerrar el programa).
-No tiene interfaz gráfica: funciona únicamente en consola.
-No está diseñado para uso profesional en gestión de ligas deportivas, solo como proyecto académico.


## Cómo se usa
1. Compilar el proyecto con un compilador C++.  
2. Ejecutar el programa.  
3. Usar el menú principal para:
   - Agregar conferencias (máximo 2).  
   - Agregar equipos a una conferencia (máximo 15 por conferencia).  
   - Agregar jugadores a un equipo (máximo 10 por equipo).  
   - Mostrar información de la liga, conferencias o equipos.  
   - Eliminar conferencias, equipos o jugadores según sea necesario.  
4. Salir con la opción 9.


##  Casos en los que no funciona
El programa tiene ciertas limitaciones y entradas inválidas que generan mensajes de error o comportamiento restringido:

## Casos en los que no funciona
- Conferencias:
  - Intentar agregar más de 2 conferencias → se rechaza (límite máximo).
  - Intentar mostrar o eliminar conferencias cuando no existen → se muestra mensaje y no pide índices.

- Equipos:
  - Intentar agregar más de 15 equipos en una conferencia → se rechaza (límite máximo).
  - Intentar mostrar o eliminar equipos cuando la conferencia no tiene equipos → se muestra mensaje.
  - Intentar agregar jugadores en una conferencia sin equipos → se muestra mensaje de error.

- Jugadores:
  - Intentar agregar más de 10 jugadores en un equipo → se rechaza (límite máximo).
  - Intentar mostrar o eliminar jugadores cuando el equipo no tiene jugadores → se muestra mensaje.

- Entradas inválidas:
  - Índices fuera de rango (ejemplo: conferencia 5 cuando solo hay 2).
  - Datos vacíos (nombre, ciudad, posición).
  - Valores negativos o cero en edad, número de camiseta o tamaño del balón.

- Entorno:
  - Intentar usarlo fuera de consola (ejemplo: interfaz gráfica) → no funciona.

## Diagrama de clases
Para visualizar el diagrama de clases, da clic abajo:

[Diagrama de clases](./Diagramadeclases.png)


## Ejecución del programa
Para compilar y ejecutar el programa desde la terminal, siga estos pasos:
1. Ubíquese en la carpeta donde se encuentra main.cpp junto con todos los archivos .h.
2. Posteriormente, ejecute el siguiente comando:
  g++ main.cpp -o programa
  Esto genera el archivo ejecutable programa.exe.
3. Ejecución
   Ejecute el siguiente comando:
   .\programa.exe

## Correciones
A este programa se le realizaron las siguientes modificaciones:
  1. Utilizo el concepto de herencia en el diagrama de clases de manera adecuada, que pertenece a la sub-competencia de Toma de decisiones SICT0302A, el diagrama de clases puedes ser observado desde este repositorio.
  2. Utilizo el concepto de composición (o agreagación) en el diagrama de clases, que pertenece a la sub-competencia de Toma de decisiones SICT0302A, la corrección se puede observar directamente en el diagrama de clases, con los objetos de League, Conference y Team.
  3. Implemento las clases en c++ siguiendo el diseño del diagrama de clases en UML, que pertenece a la sub-competencia de Toma de decisiones SICT0302A, este cambio se puede observar en todo el proyecto.
  4. Implemento herencia de manera correcta y util, que pertenece a la sub-competencia de Implementa SICT0303A,la herencia se puede observar en el archivo Person.h, donde Player y Coach heredan de Person. En los archivos Team.h, League.h y Conference.h no hay herencia directa, pero sí se usan clases (Player, Coach) que implementan herencia.
  5. Implemento composición (o agregación) sieguiendo mi diagrama de clases, que pertenece a la sub-competencia de Implementa SICT0303A, el cambio se puede observar en los archivos League.h, Conference.h y Team.h, en todos los atributos que están definidos por valor dentro de las clases.
  6. Implemento clases apegadas a requerimientos a partir de un modelo, que pertenece a la sub-competencia de Implementa SICT0303A, cada clase representa una entidad del sistema (liga, conferencia, equipo, jugador, entrenador, balón) y las relaciones entre ellas reflejan lo que el modelo pedía: agregación en los atributos directos y herencia.
  7. Sigo estándares en todo mi código fuente: estilo, sangrías, comentarios, nombres, etcétera, que pertenece a la sub-competencia de Estándares SICT0401A, esto se puede observar en todo el proyecto.
  8. Guardo correctamente los avances en commits durante la materia, que pertenece a la sub-competencia de Estándares SICT0401A, esto se puede observar en todo mi repositorio.


