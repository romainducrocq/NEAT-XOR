# [C++] XOR PROBLEM with NEAT and TidyVolve

- My very own NEAT framework in C++ (it's neat & tidy): https://github.com/romainducrocq/TidyVolve
- NEAT-Python documentation XOR example: https://neat-python.readthedocs.io/en/latest/xor_example.html

****

## How to _

`cd bin`

### Install: 
`./make.sh` or  
```
sudo apt-get update
sudo apt-get install g++ cmake valgrind libgtest-dev

cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp -v lib/*.a /usr/lib
```

### Run: 
`./app.sh` or  
```
./build.sh -R
./compile.sh
./run.sh -m train -g 300 -t 0 -n 0 -p plt -s sav
./run.sh -m eval -e 10 -t 0 -n 0 -s sav
```

### Train
`./train.sh` or  
- **Debug**: `./build.sh -D && ./compile.sh && ./run.sh -m train -g 300 -t 0 -n 0 -p plt -s sav`  
- **Release**: `./build.sh -R && ./compile.sh && ./run.sh -m train -g 300 -t 0 -n 0 -p plt -s sav`  

### Eval
`./eval.sh` or  
- **Release**: `./build.sh -R && ./compile.sh && ./run.sh -m eval -e 10 -t 0 -n 0 -s sav`  

### Play
`./play.sh` or  
- **Release**: `./build.sh -R && ./compile.sh && ./run.sh -m play -e 10`  

### Test
`./test.sh` or  
- **Release**: `./build.sh -R && ./compile.sh && ./run.sh -m test`  

### Memcheck
`./memcheck.sh <args>`  
- **Example**: `./memcheck.sh -m train -g 15 -t 0 -n 0`  

### Log
`./log.sh <cmd>`
- **Example**: `./log.sh ./train.sh` `./log.sh ./eval.sh`

### Help
`./help.sh`  
```
usage: apps/exec [-h] [-m MOD] [-g GEN] [-e EPO] [-t STP] [-n NOP] [-p PLT] [-s SAV]

NEAT XOR

optional args:
  -h      Print help and exit
  -m MOD  Set mode < train | eval | play | test >
  params:
  -g GEN  [train]       Set number generation (0=inf)
  -e EPO  [eval, play]  Set number epoch      (0=inf)
  -t STP  [train, eval] Set number max step   (0=inf)
  -n NOP  [train, eval] Set number max noop   (0=inf)
  utils:
  -p PLT  [train]       Set file name plot plt
  -s SAV  [train, eval] Set file name save sav
```
> Hyperparameter configuration file: `include/env/conf.hpp`

****

## Demo

`cd bin && ./app.sh`

```
-------------------------------TRAIN-------------------------------

Time: 6690.15ms

log/plots/
```

![Demo](log/plots/demo.jpg)

```
-------------------------------EVAL--------------------------------

EPOCH   : 1 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4
   |  X  | Y | H |
---|-----|---|---|
#1 | 1 0 | 1 | 1 |
#2 | 0 0 | 0 | 0 |
#3 | 1 1 | 0 | 0 |
#4 | 0 1 | 1 | 1 |
------------------

EPOCH   : 2 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4
   |  X  | Y | H |
---|-----|---|---|
#1 | 0 0 | 0 | 0 |
#2 | 1 1 | 0 | 0 |
#3 | 1 0 | 1 | 1 |
#4 | 0 1 | 1 | 1 |
------------------

EPOCH   : 3 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4
   |  X  | Y | H |
---|-----|---|---|
#1 | 1 0 | 1 | 1 |
#2 | 1 1 | 0 | 0 |
#3 | 0 1 | 1 | 1 |
#4 | 0 0 | 0 | 0 |
------------------

EPOCH   : 4 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4
   |  X  | Y | H |
---|-----|---|---|
#1 | 1 1 | 0 | 0 |
#2 | 0 1 | 1 | 1 |
#3 | 0 0 | 0 | 0 |
#4 | 1 0 | 1 | 1 |
------------------

EPOCH   : 5 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4
   |  X  | Y | H |
---|-----|---|---|
#1 | 0 1 | 1 | 1 |
#2 | 1 0 | 1 | 1 |
#3 | 1 1 | 0 | 0 |
#4 | 0 0 | 0 | 0 |
------------------

EPOCH   : 6 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4
   |  X  | Y | H |
---|-----|---|---|
#1 | 1 0 | 1 | 1 |
#2 | 1 1 | 0 | 0 |
#3 | 0 0 | 0 | 0 |
#4 | 0 1 | 1 | 1 |
------------------

EPOCH   : 7 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4
   |  X  | Y | H |
---|-----|---|---|
#1 | 0 0 | 0 | 0 |
#2 | 1 0 | 1 | 1 |
#3 | 1 1 | 0 | 0 |
#4 | 0 1 | 1 | 1 |
------------------

EPOCH   : 8 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4
   |  X  | Y | H |
---|-----|---|---|
#1 | 1 1 | 0 | 0 |
#2 | 0 0 | 0 | 0 |
#3 | 1 0 | 1 | 1 |
#4 | 0 1 | 1 | 1 |
------------------

EPOCH   : 9 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4
   |  X  | Y | H |
---|-----|---|---|
#1 | 0 0 | 0 | 0 |
#2 | 0 1 | 1 | 1 |
#3 | 1 0 | 1 | 1 |
#4 | 1 1 | 0 | 0 |
------------------

EPOCH   : 10 / 10
SUCCESS : 4 / 4
RATE    : 1
MVG AVG : 4
   |  X  | Y | H |
---|-----|---|---|
#1 | 1 0 | 1 | 1 |
#2 | 1 1 | 0 | 0 |
#3 | 0 0 | 0 | 0 |
#4 | 0 1 | 1 | 1 |
------------------

Time: 0.368649ms
```

@romainducrocq
