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
| clock   |  ✅       | ✅        | ❌ The quotes must be manually removed from `let mut format = "FORMAT".to_string();` so that it is recognized as a const and not an ascii string. | [clock_run.mp4](clock_run.mp4) |
| exist   |  ❌ our logic to detect double imports of use statements does not recognize that `use std::io::Write;` is covered by `use std::io::{self, BufRead, Write};`  so the first import must be commented out for this to compile   | ✅        |  ✅ | [exist_run.mp4](exist_run.mp4) |
| temp   |  ❌ Three double imported use statements must be removed for this to compile.   | ✅        |  ❌ The translation attempts to use format.replace as a format string substitution, but that will not work. The format statement has to be edited from the println so that the proper values are substituded in.  | [temp_run.mp4](temp_run.mp4) |
