# a base problem

how make a c/c++ file excutable. <br>

when we use ide to develop, we don't consider the process behind our kick the run button. <br>

# gcc/g++
in our project, only one or two file is c/c++ file. we can use gcc/g++ command to compile files and output the excutable file.

``` bash
gcc a.c b.c -o a.exe b.exe
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
