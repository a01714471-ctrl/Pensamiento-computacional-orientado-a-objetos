# Proyecto: Basketball C++

## Descripción
Este proyecto es una simulación básica de un sistema de gestión de equipos de baloncesto, implementado en C++ usando programación orientada a objetos.  

Permite crear jugadores, entrenadores, equipos, conferencias y una liga, y mostrar información de todos ellos, así como simular acciones sencillas de la pelota.


## Estructura de Clases

### Clase Person
Clase base para Player y Coach.

- **Atributos**:
  - name (string): nombre de la persona.
  - age (int): edad de la persona.
- **Métodos**:
  - showInfo(): muestra la información de la persona.

### Clase Player : hereda de Person
Representa a un jugador de baloncesto.

- **Atributos**:
  - position (string): posición en la cancha.
  - number (int): número del jugador.
  - height (float): altura en metros.
- **Métodos**:
  - showInfo(): muestra nombre, número, posición y altura.

### Clase Coach : hereda de Person
Representa al entrenador de un equipo.

- **Atributos**:
  - experienceYears (int): años de experiencia.
  - specialty (string): área de especialidad.
- **Métodos**:
  - showInfo(): muestra nombre, años de experiencia y especialidad.

### Clase Ball
Representa la pelota de baloncesto asociada a un equipo.

- **Atributos**:
  - brand (string): marca de la pelota.
  - color (string): color de la pelota.
  - size (float): tamaño de la pelota.
- **Métodos**:
  - showInfo(): muestra información de la pelota.
  - bounce(): simula un rebote de la pelota.

### Clase Team
Representa un equipo de baloncesto.

- **Atributos**:
  - teamName (string): nombre del equipo.
  - city (string): ciudad del equipo.
  - players (array de Player): jugadores del equipo.
  - coach (Coach): entrenador del equipo.
  - ball (Ball): pelota del equipo.
- **Métodos**:
  - addPlayer(Player p): agrega un jugador.
  - setCoach(Coach c): asigna un coach.
  - showInfo(): muestra información completa del equipo, incluyendo jugadores, coach y pelota.

### Clase Conference
Representa una conferencia de la liga, base de EastConference y WestConference.

- **Atributos**:
  - name (string): nombre de la conferencia.
  - region (string): región geográfica.
  - teams (array de Team): equipos en la conferencia.
- **Métodos**:
  - addTeam(Team t): agrega un equipo.
  - showInfo(): muestra información de la conferencia y sus equipos.

### Clase EastConference / WestConference
Hereda de Conference y agrega:

- **Atributos**:
  - conferenceId (int): ID de la conferencia.
  - maxTeams (int): máximo de equipos permitidos.
- **Métodos**:
  - showInfo(): muestra información adicional del ID y límite de equipos, luego llama a Conference::showInfo().

### Clase League
Representa la liga de baloncesto.

- **Atributos**:
  - leagueName (string): nombre de la liga.
  - year (int): año de la liga.
  - east (EastConference): conferencia del este.
  - west (WestConference): conferencia del oeste.
- **Métodos**:
  - setEast(EastConference e), setWest(WestConference w): asigna las conferencias.
  - showInfo(): muestra información de la liga y sus conferencias.


## Qué hace el programa

- Permite **crear jugadores y un coach de manera dinámica**.
- Permite **crear un equipo** y asignarle jugadores y coach.
- Permite **crear conferencias** y agregar equipos a ellas.
- Permite **crear una liga** y asignar las conferencias.
- Muestra información de cada entidad y simula que el balón rebota.


## Limitaciones

- Número máximo: 100 jugadores por equipo y 100 equipos por conferencia.
- Los datos deben ser creados **desde el código**; no hay entrada de usuario ni persistencia.
- No valida datos duplicados o erróneos.
- Implementación en headers; no está separada en .cpp.
