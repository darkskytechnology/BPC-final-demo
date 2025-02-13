# Project source

[libyaml GitHub project source](https://github.com/yaml/libyaml) [source after preprocessing](libyaml_after_preprocessing.tgz)

# Project build steps

```
bpc-translate generate-replacement --ignore --cc-override $(pwd)/bpc-gcc $(pwd)/libyaml.toml /usr/bin/gcc $(pwd) -- ./configure
make -C src
```

## Build file

[libyaml.toml](libyaml.toml)

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/libyaml -a /tmp/artifacts.zip --model openai /home/coder/Documents/GitHub/libyaml/libyaml.toml
```
# Generated Rust

[libyaml.tgz](libyaml.tgz)

# Video Demonstration

[libyaml](libyaml.mp4)

# Example Comparisons

| File  | C and Rust comparison |
|-------|-----------------------|
| api   | [api](api.png)        |
| dumper | [dumper](dumper.jpg) |
| emitter | failed |
| loader | [loader](loader.jpg) |
| parser | [parser](parser.jpg) |
| reader | [reader](reader.png) |
| scanner | [scanner](scanner.jpg) |
| writer | [writer](writter.png) |

# Notes

Does not commpile out of the box, but most code is valid and provides an excellent starting point for manual correction.
