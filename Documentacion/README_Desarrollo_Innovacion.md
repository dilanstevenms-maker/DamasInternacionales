Documentación del proyecto

Este proyecto es una versión visual del juego de Damas Internacionales hecha en C++ usando Qt para la interfaz gráfica. La idea es que se pueda jugar de forma sencilla con el mouse: seleccionar una ficha y moverla haciendo clic, viendo todo en pantalla sin escribir coordenadas.

Entorno donde se desarrolló

Windows con Visual Studio 2022.

C++ como lenguaje.

Qt para la interfaz gráfica.

CMake como sistema de construcción.

GitHub Desktop para el control de versiones.

Cómo abrir y compilar en Windows (paso a paso, sin terminal)

Antes de abrir el proyecto, hay que dejar listo Visual Studio con C++, instalar Qt y la extensión oficial de Qt para Visual Studio. Sigue estos pasos en orden.

Instalar Visual Studio 2022 con C++

Descarga Visual Studio 2022 desde: https://visualstudio.microsoft.com/

Al instalar, marca la carga de trabajo “Desarrollo para escritorio con C++”.

Finaliza la instalación y abre Visual Studio para confirmar que quedó activo.

Instalar Qt para Windows

Descarga el instalador oficial de Qt desde: https://www.qt.io/download-qt-installer

Durante la instalación, elige una versión de Qt compatible con Visual Studio 2022 en 64 bits. Por ejemplo, “Qt 6.x MSVC 2019/2022 64-bit”.

Completa la instalación y toma nota de la carpeta donde quedó Qt (la necesitarás para que Visual Studio lo encuentre).

Instalar la extensión “Qt Visual Studio Tools”

Abre Visual Studio.

En el menú, entra a Extensiones, luego a Administrar extensiones.

Busca “Qt Visual Studio Tools” e instálala.

Si te lo pide, reinicia Visual Studio.

Registrar Qt en Visual Studio

En Visual Studio, entra a: Qt VS Tools, luego Qt Versions u Opciones de Qt.

Agrega una “Qt Version” indicando la carpeta donde se instaló Qt (por ejemplo, la carpeta que contiene los binarios y librerías de Qt para MSVC 64 bits).

Guarda la configuración.

Abrir y compilar el proyecto

Descarga o clona el repositorio del proyecto.

Si tu repositorio tiene un archivo de solución de Visual Studio (por ejemplo, DamasInternacionales.sln), ábrelo directamente.

Verifica que la plataforma sea x64 y elige la configuración Debug o Release.

En el menú de Qt VS Tools, asegúrate de que la “Qt Version” registrada esté seleccionada para este proyecto.

Compila desde Visual Studio. Si Qt y la extensión están bien configurados, debería compilar sin cambios.

Notas útiles en Windows

Si el proyecto no usa un archivo .sln, también puedes abrir la carpeta del proyecto en Visual Studio y dejar que detecte el CMakeLists.txt. En ese caso, asegúrate de que Visual Studio esté usando el kit de CMake con el compilador de Visual Studio 2022 en 64 bits y que Qt esté registrado en Qt VS Tools.

Si Visual Studio no encuentra Qt, revisa que instalaste la variante “MSVC 64-bit” y no la de MinGW, y que registraste la ruta correcta en Qt VS Tools.

Enlaces de referencia para Windows

Visual Studio 2022: https://visualstudio.microsoft.com/

Qt (instalador oficial): https://www.qt.io/download-qt-installer

CMake (si lo necesitas aparte): https://cmake.org/download/

Cómo compilar y ejecutar en Linux (paso a paso, sin terminal)

En Linux necesitas tres piezas: un compilador C++, CMake y Qt. Todo puede instalarse desde el centro de software de tu distribución o desde los enlaces oficiales.

Instalar un compilador C++ y CMake

Busca en tu centro de software “C++” y “CMake” e instálalos.

Si prefieres enlaces oficiales:

CMake: https://cmake.org/download/

Instalar Qt en Linux

Opción recomendada: usa el instalador oficial de Qt y elige la versión para Linux en 64 bits.

Qt instalador oficial: https://www.qt.io/download-qt-installer

Alternativa: instalar Qt desde el centro de software de tu distribución buscando “Qt Base” o “Qt6 Base”.

Preparar el proyecto

Descarga o clona el repositorio del proyecto.

Asegúrate de tener Qt y CMake instalados.

Abre una carpeta de construcción con tu herramienta gráfica favorita (por ejemplo, CMake GUI) y señala:

La carpeta donde está el código del proyecto.

Una carpeta vacía donde se van a generar los archivos de construcción.

En CMake GUI, configura el generador para tu compilador de 64 bits y verifica que detecte Qt. Si no lo detecta automáticamente, agrega la ruta de Qt en las opciones de CMake GUI (variable CMAKE_PREFIX_PATH) señalando la carpeta donde está instalado Qt.

Compilar y ejecutar

Genera los archivos de construcción con CMake GUI.

Abre el proyecto que te genere CMake en tu IDE, o usa el botón de “Generate” y “Open Project” de la propia herramienta.

Compila el proyecto y ejecuta el binario resultante. Si Qt está correctamente instalado, no es necesario modificar el código.

Enlaces de referencia para Linux

Qt (instalador oficial): https://www.qt.io/download-qt-installer

CMake: https://cmake.org/download/

Uso del programa

Haz clic sobre una ficha para seleccionarla.

Luego haz clic en la casilla a la que quieres moverla.

El turno cambia automáticamente.

Si hay una captura obligatoria, el juego la exige.

Si se puede capturar varias veces en el mismo turno, el juego mantiene la jugada hasta finalizar.

Cuando una ficha llega al extremo contrario del tablero, se convierte en Dama.

El turno actual se muestra en la parte superior de la ventana.

Innovaciones implementadas

Interfaz visual en vez de consola, más clara y didáctica.

Todo se opera con el mouse, sin coordenadas ni comandos.

El tablero se actualiza solo después de cada jugada.

Fichas con color y forma para distinguir a cada jugador fácilmente.

Por qué se eligieron estas innovaciones

Una interfaz visual hace el juego más accesible. Es más fácil entender qué está pasando, ver las capturas, notar cuándo una ficha es coronada y seguir los turnos. La experiencia es más natural: se observa el tablero, se hace clic y se juega sin complicaciones.