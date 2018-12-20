# OpenWorld
Open World Full Survical C++ Game

# Project Settings
-Include Directories
$(SolutionDir)Dependencies\GLFW\include;$(SolutionDir)Dependencies\FreeImage\include;$(SolutionDir)Dependencies\GLEW\include;$(IncludePath)
-Library Directories
$(SolutionDir)Dependencies\FreeImage\lib;$(SolutionDir)Dependencies\GLFW\lib-vc2015;$(SolutionDir)Dependencies\GLEW\lib;$(LibraryPath)
-Additional Dependencies
glfw3.lib;glew32s.lib;opengl32.lib;FreeImage.lib;%(AdditionalDependencies)
