<h1 align="center">Physcis Engine</h1>
<h4 align="center">Not Actually a Physics Engine</h4>

<h3>Description</h3>
Physcis Engine is a 3D game engine, using GLFW for OpenGL.<br>
It's written by me (Adam Wallberg), and is only a small hobby project.<br>

<h3>Planned Features</h3>
  - "Fully independent" math library (no glm or similar third party libraries)
    including own vector and matrix classes.
  - Deferred rendering with some fancy postFX. 'Tis my forte.
  - Some sort of python scripting.
  - Component based input system. 
  - Event based communication.
  
<h3>Setup</h3>
For now the process is not fully optimized, but here's how to do it:
  1. Change "generate_project_files.ps1", so that it builds for your IDE.
  2. Change the includedirs in "premake5.lua", so that they match what you need. 
     Note: I can't guarantee that it will work for anything else than Visual Studio 
     Community 2013/2015, since that is what I've used, and haven't tried with anything else.
  3. Run "generate_project_files.ps1" with powershell. If it complains about the execution policy,
     set it to unrestricted. <a href="https://technet.microsoft.com/en-us/library/ee176961.aspx">check this out.</a>
  4. Tadaa! Solution files! :D
