# Project source

[Coreutils GitHub project source](http://git.savannah.gnu.org/gitweb/?p=coreutils.git)


# Project build steps

```
bpc-translate generate-replacement --cc-override $(pwd)/bpc-gcc $(pwd)/coreutils.toml /usr/bin/gcc $(pwd) -- make
```


## Build file

Because of the size of the projet, translation is demonstrated with a few small independent project files which are extracted from the larger coreutils.toml.

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/coreutils_[binaryname] -a /tmp/artifacts.zip --model openai /home/coder/Documents/GitHub/coreutils/[binaryname].toml
```

# Video demonstration
| Binary  | Rust Source                                       | Build File                              | Compiles?                                                                    | Executes? | Accuracy? | Video                              |
|---------|---------------------------------------------------|-----------------------------------------|-----------------------------------------------------------------------------|----------|-----------|------------------------------------|
| cat     | [coreutils_cat.tgz](cat/coreutils_cat.tgz)        | [cat.toml](cat/cat.toml)                | ❌ The [[bin]] target just needed to be added to Cargo.toml to compile        | ✅        | ✅         | [cat.mp4](cat/cat.mp4)             |
| true    | [coreutils_true.tgz](true/coreutils_true.tgz)      | [true.toml](true/true.toml)             | ✅                                                                             | ✅        | ✅         | [true.mp4](true/true.mp4)          |

# Notes

Fails to properly process details such as non-function related #defines.   
