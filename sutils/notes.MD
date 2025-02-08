# Project source

[sutils](ugly_pointer.c)


# Translated Rust source

Raw results from automation: [sutils.automated.tgz](sutils.automated.tgz)

# Project build steps

```
bpc-translate generate-replacement --cc-override $(pwd)/bpc-gcc $(pwd)/sutils.toml /usr/bin/gcc $(pwd) -- make
```
Then added `/home/coder/Documents/GitHub/sutils/common.h` to `ignores = []`

## Build file

[sutils.toml](sutils.toml)

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/sutils -a /tmp/snake-artifacts.zip --model openai /home/coder/Documents/GitHub/sutils/sutils.toml
```

# Video demonstration

| Binary  | Compiles? | Executes? | Accurancy? | Video |
|---------|-----------|-----------|------------|-------|
| clock   |  ❌ Compiles after a double import is manually removed for `use std::io::Write;`.  | ✅        | ✅  | [clock_run.mp4](clock_run.mp4) |
| exist   |  ✅    | ✅        |  ✅ | [exist_run.mp4](exist_run.mp4) |
| narg   |  ✅   | ✅        |  ✅  | [narg_run.mp4](narg_run.mp4) |
| temp   |  ✅   | ✅        |  ❌ The translation attempts to use format.replace as a format string substitution, but that will not work in Rust. The format statement has to be edited from the println so that the proper values are substituded in.  | [temp_run.mp4](temp_run.mp4) |
| uq   |  ❌ Compiles after a double import is manually removed for `use std::io::Write;`.  | ✅        | ✅  | [uq_run.mp4](uq_run.mp4) |
