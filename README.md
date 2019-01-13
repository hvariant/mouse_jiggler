# mouse jiggler

To build:

```
mkdir build
cmake -T host=x64 -G "Visual Studio 15 2017" -A x64 ..
cmake --build . --target jiggler --config Release
```

The executable will be placed in `build/jiggler/Release/jiggler.exe`.