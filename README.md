# mindbonk
a brainfuck interpreter made in C++, with a live interpreter and running code from `stdin`.


## running
after compilation, just run:
```sh
./bin/brainfuck [-|file]
```
where `file` is the file to run, or `-` for stdin


## compiling

### with `make`
just run `sudo make` in the current active directory

### manually
compile `interpreter.cpp` and `main.cpp` to `bin/brainfuck` together

here's the way with `g++`: `g++ -std=c++11 -o bin/brainfuck interpreter.cpp main.cpp`

## contributing
feel free to contribute, if you want to!

to contribute, just fork the repository, make a branch, commit all your changes and make a pull request!

but please, use the following commit message format:
```
type(scope): description
```

where:
- `type` is the type of change you made (e.g. bug, feat, refactor, docs, etc.)
- `scope` are the files you are editing (e.g. pekofy, reactions, bot, etc.)
- `description` is a short description of the change (e.g. add a new status message)
