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

| Binary  | Rust Source | Build File | Compiles? | Executes? | Accurancy? | Video |
|---------|-----------|-----------|------------|-------|
| cat without header files   | [Without headers](cat/coreutils_cat_without_includes.tgz) | [cat_without_headers.toml](cat/cat_without_includes.toml) | ❌  The [[bin]] target just needed to be added to Cargo.toml to compile | ✅    |  ✅   |  [cat_without_includes.mp4](cat/cat_without_includes.mp4) |
| cat with header files   | [With headers](cat/coreutils_cat_with_includes.tgz) | [cat_with_headers.toml](cat/cat_with_includes.toml) | ❌   | ✅    |  ✅   |  [cat_with_includes.mp4](cat/cat_with_includes.mp4) |
