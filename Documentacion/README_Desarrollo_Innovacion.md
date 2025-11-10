Documentación del proyecto

Este documento describe el entorno utilizado, la configuración necesaria para ejecutar el proyecto y los elementos adicionales implementados durante el desarrollo.

Entorno de trabajo utilizado
Se trabajó con Visual Studio 2022 utilizando el lenguaje C++. Para la interfaz gráfica se empleó Qt. El sistema de construcción utilizado fue CMake y para control de versiones se usó GitHub Desktop.

Configuración del entorno de desarrollo

Visual Studio 2022
Debe estar instalada la opción Desarrollo para escritorio con C++. Esto se verifica en Visual Studio Installer, seleccionando modificar en Visual Studio 2022 y activando la herramienta mencionada.

Extensión Qt en Visual Studio
Se usó la extensión Qt Visual Studio Tools para poder trabajar con Qt dentro de Visual Studio. Para instalarla se abre Visual Studio, se va a Extensiones, luego Administrar extensiones, se busca Qt Visual Studio Tools, se instala y se reinicia Visual Studio.

Instalación de Qt
Es necesario tener instalada la biblioteca de Qt. Se descarga desde el sitio oficial https://www.qt.io/download. Durante la instalación se selecciona una versión compatible con Visual Studio 2022. Después de instalar Qt se abre Visual Studio y en Qt VS Tools se selecciona Opciones de Qt para registrar la ruta donde quedó instalado Qt.

GitHub Desktop
Se utilizó para clonar el repositorio, copiar el proyecto dentro de la carpeta clonada, registrar cambios mediante commits y subirlos utilizando Push origin.

Cómo abrir y ejecutar el proyecto

1. Clonar el repositorio desde GitHub.
2. Abrir el archivo DamasInternacionales.sln en Visual Studio 2022.
3. Seleccionar la configuración Debug o Release.
4. Seleccionar la plataforma x64.
5. Ejecutar con F5 o Ctrl + F5.

Uso del programa
El juego se maneja con el mouse. Se hace clic en una ficha para seleccionarla y luego se hace clic en la casilla a la que se desea mover. El turno cambia automáticamente entre jugadores. Si una ficha llega al extremo contrario del tablero se convierte en Dama de manera automática. Si existe una captura disponible, esta se debe realizar para continuar.

Innovaciones implementadas
- Se desarrolló una interfaz gráfica para jugar de forma visual en lugar de usar una consola. 
- Los movimientos se realizan con clics del mouse, lo cual facilita la interacción.
- El tablero se actualiza automáticamente después de cada jugada, reflejando cambios de forma inmediata.
- las fichas tienen color y forma.

