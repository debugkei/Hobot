# Hobot
This is my project, more like a code along with TheCherno's game engine series, in which I'm trying to implement a game engine.  
For now I'll not accept any pull requests.  
Also it will not have releases yet.

# How to compile?
For compiling, the project uses premake.  
Right now the premake project config file was only tested on Windows with MSVC and mingw gcc.  
Premake can be used to generate project files for make, or vs2022, or xcode.  
Just execute premake in project directory:  
> path/to/premake5 what_generating_for  

# Platforms
So far I only used Windows with vs code and vs2022.  
My goal is to make it cross platform.  
Goal wasnt achieved yet.

# Vendors/Dependencies
I used:
* premake, its license can be found in vendor/premake.
* glfw3-4, its license can be found in Hobot/vendor/glfw-3.4.  
