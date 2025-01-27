# Project source

https://gitlab.com/gtd-gmbh/libmcs


# Translated Rust source

[rust_libmcs.tgz](rust_libmcs.tgz)

# Project build steps

```
bpc-translate generate-replacement --cc-override $(pwd)/bpc-gcc $(pwd)/libmcs.toml /usr/bin/gcc $(pwd) -- ./configure --cross-compile $(pwd)/bpc-
make
```

## Build file

[libmcs.toml](libmcs.toml)

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/lib-mcs -a /tmp/libmcs-artifacts.zip --model openai /home/coder/Documents/GitHub/libmcs/libmcs.toml
```

# Video demonstration

demo

# Examples 

- libm/mathf/acosf ![lib_mathf_acosf.jpg](lib_mathf_acosf.jpg): C and Rust source comparison
- libm/mathf/rintf ![lib_mathf_rinf.jpg](lib_mathf_rinf.jpg): C and Rust source comparison
- libm/mathd/atan2d ![lib_mathd_atan2d.jpg](lib_mathd_atan2d.jpg): C and Rust source comparison





