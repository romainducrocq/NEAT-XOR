### Simple XOR PROBLEM with NEAT

- The NeuroEvolution of Augmenting Topologies (NEAT) User Page: http://www.cs.ucf.edu/~kstanley/neat.html
- MarI/O - Machine Learning for Video Games (SethBling): https://www.youtube.com/watch?v=qv6UVOQ0F44 
- NEAT-Python documentation XOR example: https://neat-python.readthedocs.io/en/latest/xor_example.html

****

### Run

`cd bin`
- **Install**: `sudo apt-get update && apt-get install g++ cmake valgrind` or `./make.sh`  
- **Release**: `./build.sh -R && ./compile.sh && ./run.sh -g 300 -p 150`  
- **Debug**: `./build.sh -D && ./compile.sh && ./run.sh -g 300 -p 150`  
- **Memcheck**: `./build.sh -D && ./compile.sh && ./memcheck.sh -g 15 -p 15 && cat apps/out.txt`  

```
usage: apps/exec [-h] [-g GEN] [-p POP]

NEAT XOR

optional args:
  -h      Print help and exit
  -g GEN  Set generation number
  -p POP  Set population size
```
> Hyperparameter configuration file: `include/env/conf.hpp`

****

### Demo

`cd bin && ./app.sh`

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
