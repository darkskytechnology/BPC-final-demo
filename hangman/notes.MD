# Project source

[hangman.c](hangman.c) (
Project comes from [geeksforgeeks.org](https://www.geeksforgeeks.org/hangman-game-in-c/))


# Translated Rust source

[hangman.tgz](hangman.tgz)

# Project build steps

Not necessary

## Build file

Not necessary

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/hangman -a /tmp/hangman-artifacts.zip --model openai /home/coder/Documents/GitHub/geeksforgeeks/hangman/hangman.c
```

# Video demonstration

- [Clean translation no runtime errors](hangman.mp4) 
- [Clean translation with runtime errors](hangman_runtime_error.mp4) 

# Examples 

[hangman](hangman.png) C and Rust comparison

# Notes

Translates cleanly on first pass:

```
2025-02-08T00:08:50.436922Z  INFO main bpc_translate: Creating initial commit in git repository in `/home/coder/Documents/GitHub/demo/hangman`
2025-02-08T00:08:51.407801Z  INFO main bpc_translate: Tagging initial commit with 'Initial first pass translation results' in `/home/coder/Documents/GitHub/demo/hangman`
2025-02-08T00:08:53.797953Z  INFO main bpc_translate: 🎯 No compilation errors found, skipping refactoring!🎯
2025-02-08T00:08:53.797968Z  INFO main bpc_translate: Running rustfmt on all Rust files in `/home/coder/Documents/GitHub/demo/hangman`
2025-02-08T00:08:53.830029Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/hangman/src/hangman_c.rs`
2025-02-08T00:08:53.860512Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/hangman/src/bpc_prelude.rs`
2025-02-08T00:08:53.891191Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/hangman/src/lib.rs`
2025-02-08T00:08:53.891205Z  INFO main bpc_translate: rustfmt completed successfully on all files
2025-02-08T00:08:53.891209Z  INFO main bpc_translate: rustfmt completed successfully
2025-02-08T00:08:53.891211Z  INFO main bpc_translate: Performing final formatting commit
2025-02-08T00:08:53.891213Z  INFO main bpc_translate: Committing changes to Git with the message 'Formatting'
2025-02-08T00:08:54.824780Z  INFO main bpc_translate: Finished translating hangman

====== Translation Metrics Summary ======
Total Rust lines generated or modified: 109
Total original C lines: 99
Ratio of Rust lines to C lines: 109 : 99
Total C functions: 3
Total Rust functions: 3
Functions covered: 3
Number of refactors: 0 out of 15 iterations (0 total function refactors)
Function coverage percentage: 100.00%

Number of errors found during cargo check: 0
Error density: 0.00%
=========================================
```
