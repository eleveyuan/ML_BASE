# a base problem

how to make a c/c++ file excutable. <br>

when we use ide to develop, we don't consider the process after our kick the run button. <br>

# gcc/g++
in a c/c++ project, only one or two file is c/c++ file. we can use gcc/g++ command to compile files and output the excutable file. 

there are example on windows platform. on linux/unix platform, we should subsitute 'main.exe' with 'main', or aother name you love.

``` bash
gcc a.c b.c -o main.exe
``` 

## parameters of command gcc/g++

'-E' only preprocess c file 
``` bash
gcc -E a.c -o a.i
```

'-S' only compile file 
``` bash
gcc -S a.i
```

'-c' compile and assemble file
``` bash
gcc -c a.s
```

generate a excutable file
``` bash
gcc  a.o -o a.exe
```

# cmake
when we accout a project, that includes hundreds of files. if we don't know **cmake**, we'd better run. uhhh

- tutorial 
https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html

- interaction
https://cmake.org/cmake/help/latest/guide/user-interaction/index.html


a example on window platform, as follow 

``` bash
cmake -G "MinGW Makefiles" -D CMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe .
```

attention:
1. '-G' points to a source generator, i use mingw
2. '-D' points what compiler you needed\
3. '/' don't use '\', could cause a parse error, "Invalid character escape" (fxck these characters)