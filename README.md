Damas Internacionales

Proyecto realizado por: Dilan Stiven Muñoz Sanchez

Este proyecto recrea el juego de Damas Internacionales. El tablero es de 10x10 casillas y cada jugador comienza con 20 fichas. El objetivo es capturar o bloquear todas las piezas del oponente.

Características implementadas:

- Tablero de 10x10 con casillas alternadas.
- Dos jugadores, cada uno con 20 fichas diferenciadas por color.
- Sistema de turnos.
- Movimiento en diagonal hacia adelante para fichas normales.
- Captura obligatoria cuando sea posible.
- Capturas múltiples encadenadas en el mismo turno.
- Coronación a Dama al llegar al extremo contrario.
- La Dama se mueve y captura hacia adelante y hacia atrás.
- Validación para evitar movimientos inválidos.
- El juego se controla con el mouse de forma visual.

Estructura del proyecto:

DChinasClean
│
├─ CMakeLists.txt
│
├─ README.md
│
└─ src
   ├─ main.cpp
   ├─ boardview.h
   └─ boardview.cpp

Este proyecto permite jugar una partida completa desde una interfaz gráfica sencilla.