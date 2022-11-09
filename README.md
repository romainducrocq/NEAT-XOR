### Simple XOR PROBLEM with NEAT

- The NeuroEvolution of Augmenting Topologies (NEAT) User Page: http://www.cs.ucf.edu/~kstanley/neat.html
- MarI/O - Machine Learning for Video Games (SethBling): https://www.youtube.com/watch?v=qv6UVOQ0F44 
- NEAT-Python documentation XOR example: https://neat-python.readthedocs.io/en/latest/xor_example.html

****

### Build

- **Dep**: `sudo apt-get update && apt-get install g++ cmake valgrind`  
- **Run**: `cd bin && ./build.sh && ./compile.sh && ./run.sh -g 300 -p 150`   
- **(Valgrind Memcheck)**: `cd bin && ./build.sh && ./compile.sh && ./debug.sh -g 15 -p 15 && cat apps/out.txt`  

```
usage: apps/exec [-h] [-g GEN] [-p POP]

NEAT XOR

optional args:
  -h      Print this help and exit
  -g GEN  Set generation number
  -p POP  Set population size
```

****

#### Demo

```
-------------------------------EVAL--------------------------------

EPOCH   : 1 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4

EPOCH   : 2 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4

EPOCH   : 3 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4

EPOCH   : 4 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4

EPOCH   : 5 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4

EPOCH   : 6 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4

EPOCH   : 7 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4

EPOCH   : 8 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4

EPOCH   : 9 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4

EPOCH   : 10 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4

Time: 0.091006ms
```

@romainducrocq
