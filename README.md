# [C++] XOR PROBLEM with NEAT and TidyVolve

- My very own NEAT framework in C++ (by & for myself): https://github.com/romainducrocq/TidyVolve
- NEAT-Python documentation XOR example: https://neat-python.readthedocs.io/en/latest/xor_example.html

****

## How to _

`cd bin`
- **Install**: `./make.sh` or  
```
sudo apt-get update
sudo apt-get install g++ cmake valgrind libgtest-dev

cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp -v lib/*.a /usr/lib
```

- **Run**: `./app.sh` or  
```
./build.sh -R
./compile.sh
./run.sh -m train -g 300 -n 0 -p plt -s sav
./run.sh -m eval -e 10 -n 0 -s sav
```

### Train
- **Memcheck**: `./build.sh -D && ./compile.sh && ./memcheck.sh -m train -g 15 -n 0`  
- **Debug**: `./build.sh -D && ./compile.sh && ./run.sh -m train -g 300 -n 0 -p plt -s sav`  
- **Release**: `./build.sh -R && ./compile.sh && ./run.sh -m train -g 300 -n 0 -p plt -s sav`  
or `./train.sh`  

### Eval
- **Release**: `./build.sh -R && ./compile.sh && ./run.sh -m eval -e 10 -n 0 -s sav`  
or `./eval.sh`  

### Play
- **Release**: `./build.sh -R && ./compile.sh && ./run.sh -m play -e 10`  
or `./play.sh`  

### Test
- **Release**: `./build.sh -R && ./compile.sh && ./run.sh -m test`  
or `./test.sh`  

```
usage: apps/exec [-h] [-m MOD] [-g GEN] [-e EPO] [-n NUM] [-p PLT] [-s SAV]

NEAT XOR

optional args:
  -h      Print help and exit
  -m MOD  Set mode < train | eval | play | test >
  params:
  -g GEN  [train]       Set generation number (0=inf)
  -e EPO  [eval, play]  Set epoch number      (0=inf)
  -n NUM  [train, eval] Set max step number   (0=inf)
  utils:
  -p PLT  [train]       Set plot log file name
  -s SAV  [train, eval] Set save sav file name
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
