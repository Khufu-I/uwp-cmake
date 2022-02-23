# C++/UWP CMake app using CMake
Basic example using standard C++ and CMake to build an UWP app using the Windows 11 or 10 SDK. This sample app uses Windows UI controls which come with the Windows SDK instead of WinUI controls which are distributed via Nuget. This sample app doesn't use XAML files or the cppwinrt generators to simplify coding and build steps. This project aspires to code UI using simple C++ in the [fluent-style pattern](https://github.com/microsoft/cppwinrt/pull/1114).

## Getting started

### Prerequisites
Downldoad the latest [Visual Studio](https://www.visualstudio.com/) and follow the setup. The following components are required:
* Universal Windows Platform development
* Windows 11 SDK
* C++ (v143) Universal Windows Platform Tools
* C++ CMake tools for Windows

### Build and Run
Using Visual Studio command prompt execute 
```batch
:: Generate Visual Studio project files
cmake . -Bbuild
```

#### Visual Studio
Open **uwp-cmake.sln** Visual Studio solution in the build folder. Press **F5** to build and run the project.

#### CMake
Using Visual Studio command prompt execute 
```batch
:: Generate Visual Studio project files
cmake . -Bbuild
:: Build project
cmake --build build
:: Install UWP app
DeployAppRecipe build/Debug/uwp-cmake.build.appxrecipe
:: Run app 
explorer shell:appsFolder\Khufu-I.uwp-cmake_71v9806nvp60t!App
```

### Uninstall
Using Visual Studio command prompt execute 
```batch
:: Remove app
winget uninstall Khufu-I.uwp-cmake_71v9806nvp60t
:: Clean up build artifacts and generated files
rmdir /s build
```

## References

### CMake references
- https://github.com/coderox/CMakeXamlSandbox/blob/master/CMakeLists.txt
- https://github.com/NativeScript/windows-runtime/blob/master/Source/TestRunner/CMakeLists.txt
- https://github.com/woraphatman/woraphat/blob/ad85ad19c946bbf9299e1fdd6b785f289335b123/winuwp/runner_uwp/CMakeLists.txt

### Splash screen & logos
- [App icons and logos](https://docs.microsoft.com/en-us/windows/apps/design/style/app-icons-and-logos)
- [Tailor your resources](https://docs.microsoft.com/en-us/windows/uwp/app-resources/tailor-resources-lang-scale-contrast#shell-light-theme-and-unplated-resources)
- [Assets tailored for scale, theme, high contrast, and others](https://docs.microsoft.com/en-us/windows/uwp/app-resources/images-tailored-for-scale-theme-contrast)