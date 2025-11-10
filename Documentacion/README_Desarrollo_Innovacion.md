Documentación del desarrollo e innovación

Este documento explica cómo se configuró el entorno de trabajo, qué herramientas fueron necesarias para ejecutar el proyecto y cuáles fueron los aspectos adicionales implementados para mejorar la experiencia del juego.

Entorno utilizado
Se trabajó con Visual Studio 2022 como editor principal, utilizando el lenguaje C++ y Qt para la interfaz gráfica. El proyecto utiliza CMake como sistema de construcción y GitHub Desktop para control de versiones y almacenamiento del repositorio.

Configuración del entorno de desarrollo

Visual Studio 2022
Es necesario tener instalada la herramienta de desarrollo en C++ en Visual Studio 2022. Para verificarlo se abre Visual Studio Installer, se selecciona modificar y se habilita la opción Desarrollo para escritorio con C++.

Extensión Qt Visual Studio Tools
La extensión permite que Visual Studio reconozca y trabaje con proyectos que utilizan Qt. Para instalarla se abre Visual Studio, se entra a Extensiones y luego Administrar extensiones. Se busca Qt Visual Studio Tools, se instala y se reinicia Visual Studio.

Instalación de Qt
La extensión no incluye Qt. Por eso es necesario instalar las librerías completas. Para hacerlo se descarga Qt desde la página oficial https://www.qt.io/download. Durante la instalación se elige una versión compatible con Visual Studio 2022. Después de instalar Qt se abre Visual Studio y en el menú Qt VS Tools se selecciona Opciones de Qt para agregar la ruta donde está instalado Qt.

GitHub Desktop
Se utilizó GitHub Desktop para clonar el repositorio, copiar el proyecto dentro de la carpeta clonada, registrar los cambios mediante commits y subirlos con Push origin. Esto permite tener historial y asegurar que el proyecto se puede recuperar y compartir.

Innovaciones implementadas

Interfaz gráfica mediante Qt, lo que permite jugar visualmente sin consola.
Movimientos mediante el mouse. El usuario selecciona y mueve fichas con clics.
Aplicación de reglas del juego como turnos, movimientos válidos y coronación.
Actualización automática del tablero. Cuando una ficha se mueve o es capturada el tablero refleja el cambio al instante sin acciones adicionales del usuario.

Estas características permiten que el juego sea más claro, fácil de usar y agradable visualmente en comparación con una versión por consola.

