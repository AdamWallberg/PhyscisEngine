![alt tag](game/data/images/logotype/ph_banner.png)
<h1 align="center">Physcis Engine</h1>
<h4 align="center">Not Actually a Physics Engine</h4>

<h3>Description</h3>
Physcis Engine is a 3D game engine, using GLFW for OpenGL.<br>
It's written by me (Adam Wallberg), and is only a small hobby project.<br>

<h3>Implemented Features</h3> 
  - Premake5 project setup.
  - Component based input system. (Not complete yet.)
  - 2D and 3D vectors, and some basic math functions.
  - JSON loading and parsing using modern json. <a href="https://github.com/nlohmann/json">github.com/nlohmann/json</a>
  - Window creating using GLFW.
  - Memory tracking and leak detection.

<h3>Planned Features</h3>
  - "Fully independent" math library (no glm or similar third party libraries)
    including own vector and matrix classes.
  - Deferred rendering with some fancy postFX. 'Tis my forte.
  - Some sort of python scripting.
  - Event based communication.
  
<h3>Setup</h3>
Heads up: the project can probably only compile using visual studio community 2015, mostly because of the json library.

  1. Install the FBX SDK, and link to it in premake5.lua.
  2. Run "generate_project_files.ps1" with powershell. If it complains about the execution policy,
     set it to unrestricted. <a href="https://technet.microsoft.com/en-us/library/ee176961.aspx">check this out.</a>
  3. Tadaa! Solution files! :D
