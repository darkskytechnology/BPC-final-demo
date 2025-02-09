# Project source

[sutils_c.tgz](sutils_c.tgz) [GitHub project source](https://github.com/baskerville/sutils)


# Translated Rust source

As described in the Milestone report, OpenAI occassionally has challenges with ioctls, so the essid target was translated seperately:

- [sutils.tgz](sutils.tgz) (Excludes essid)
- [sutils_essid.tgz](sutils_essid.tgz) (Essid alone)

# Project build steps

```
bpc-translate generate-replacement --cc-override $(pwd)/bpc-gcc $(pwd)/sutils.toml /usr/bin/gcc $(pwd) -- make
```

Then added `/home/coder/Documents/GitHub/sutils/common.h` to `ignores = []`

## Build file

- [sutils.toml](sutils.toml) (Excludes essid)
- [essid.toml](essid.toml) (Essid alone)

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/sutils -a /tmp/snake-artifacts.zip --model openai /home/coder/Documents/GitHub/sutils/sutils.toml
```

# Video demonstration

- [sutils.mp4](sutils.mp4) (Excludes essid)
- [essid_translate_run.mp4] (Essid alone)

| Binary  | Compiles? | Executes? | Accurancy? | Video |
|---------|-----------|-----------|------------|-------|
| battery   |  ✅  | ✅    |   A change has to be made to replace the CONST derived from a global variable to enable index-based replacement. Not tested on a computer with a battery, but appears correct following the formatting change.   [battery_run.mp4](battery_run.mp4) |
| clock   |  ❌ Compiles after a dependency for `getopts` is added  | ✅        | ✅  | [clock_run.mp4](clock_run.mp4) |
| essid   |  ✅    | ✅        |  ❌ Requires a replacement of the UDP socket `let sock_fd = std::net::UdpSocket::bind("0.0.0.0:0").expect("Failed to create socket").as_raw_fd();` to `let sock_fd = unsafe {libc::socket(libc::AF_INET, libc::SOCK_DGRAM, 0)}; if sock_fd == -1 { eprintln!("Failed to create socket: {}" std::io::Error::last_os_error()); std::process::exit(libc::EXIT_FAILURE);}` | [essid_translate_run.mp4](essid_translate_run.mp4) |
| exist   |  ✅    | ✅        |  ✅ | [exist_run.mp4](exist_run.mp4) |
| narg   |  ✅   | ✅        |  ✅  | [narg_run.mp4](narg_run.mp4) |
| temp   |  ✅   | ✅        |  ❌ The translation attempts to add an index onto the end of the temperature path and also tries to use `print!("{}", format.replace("%f", &format!("{:.3}", temp / 1000.0)));` but replace doesn't respect formatting rules like printf-style placeholders. This executes correctly once the index and is removed and the print is changed to `print!("{:.3}", temp / 1000.0);`  | [temp_run.mp4](temp_run.mp4) |
| uq   |  ✅   | ✅        | ✅  | [uq_run.mp4](uq_run.mp4) |
| volume   |  ❌  Requires addition of a dependency, two use statements, and several formatting fixes due to `{}` being excluded to compile,   |   ❌  core dumps due to `volume: hcontrol.c:807: snd_hctl_elem_info: Assertion `elem' failed.`      |   ❌ |   [volume_run.mp4](volume_run.mp4) |
