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
| battery   |  ❌  included extensive use of optarg and unsafe sections - discarded |   ❌       |   ❌|   ❌ |
| clock   |  ❌ Compiles after a dependency for `getopts` is added  | ✅        | ✅  | [clock_run.mp4](clock_run.mp4) |
| exist   |  ✅    | ✅        |  ✅ | [exist_run.mp4](exist_run.mp4) |
| narg   |  ✅   | ✅        |  ✅  | [narg_run.mp4](narg_run.mp4) |
| temp   |  ✅   | ✅        |  ❌ The translation attempts to add an index onto the end of the temperature path and also tries to use `print!("{}", format.replace("%f", &format!("{:.3}", temp / 1000.0)));` but replace doesn't respect formatting rules like printf-style placeholders. This executes correctly once the index and is removed and the print is changed to `print!("{:.3}", temp / 1000.0);`  | [temp_run.mp4](temp_run.mp4) |
| uq   |  ✅   | ✅        | ✅  | [uq_run.mp4](uq_run.mp4) |
| volume   |  ❌  Requires addition of a dependency, two use statements, and several formatting fixes due to `{}` being excluded to compile,   |   ❌  core dumps due to `volume: hcontrol.c:807: snd_hctl_elem_info: Assertion `elem' failed.`      |   ❌ |   [volume_run.mp4](volume_run.mp4) |
