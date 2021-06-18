This application launches a series of commands to read a group of pif
files into IMAlign, align them and then save them as an IMAlign project.

The PifGroup_Tool directory found in the goodies\PolyWorksSDK\samples\data
directory contains appropriate pif files.

The *.h and *.c files needed for compiling this sample can be found
in the goodies\PolyWorksSDK\include\PolyWorksSDK\COM directory.

For more details, please refer to section 1, "Developing External Modules", of the
PolyWorks SDK Reference Guide in the documentation directory.

This sample code was developed and tested with 
Microsoft Visual Studio 2013 and 2017.

Changes note:

If you built your own application based on an earlier version of this framework, we recommend that you use
a file differences tracking tool (such as WinDiff or Araxis Merge) to compare the content of this version
of the framework with the content of the framework you used to build you application. This way, you'll better
be able to see what part of the code was changed and decide whether you want to apply similar changes to
your own application.

Changes in V2021 IR1:

Replacement of raw pointers with CComPtr.
Code updated to use nullptr instead of NULL when possible for type safety.

Changes in V2019:

Added Visual Studio 2017 support by including .vcxproj project file.
Visual Studio 2013 support is still available through .vcxproj.VS2013 project file.
Removed VisualStudio 2010 support by removing .vcxproj.VS2010 file.

