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

[hangman.mp4](hangman.mp4)

# Examples 

[hangman](hangman.png) C and Rust comparison

# Notes

Translates cleanly on first pass:

```
2025-02-07T20:33:12.786895Z  INFO main bpc_translate: Creating initial commit in git repository in `/home/coder/Documents/GitHub/demo/hangman`
2025-02-07T20:33:13.732379Z  INFO main bpc_translate: Tagging initial commit with 'Initial first pass translation results' in `/home/coder/Documents/GitHub/demo/hangman`
2025-02-07T20:33:16.126307Z  INFO main bpc_translate: 🎯 No compilation errors found, skipping refactoring!🎯
2025-02-07T20:33:16.126321Z  INFO main bpc_translate: Running rustfmt on all Rust files in `/home/coder/Documents/GitHub/demo/hangman`
2025-02-07T20:33:16.158953Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/hangman/src/hangman_c.rs`
2025-02-07T20:33:16.189417Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/hangman/src/bpc_prelude.rs`
2025-02-07T20:33:16.220219Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/hangman/src/lib.rs`
2025-02-07T20:33:16.220233Z  INFO main bpc_translate: rustfmt completed successfully on all files
2025-02-07T20:33:16.220238Z  INFO main bpc_translate: rustfmt completed successfully
2025-02-07T20:33:16.220241Z  INFO main bpc_translate: Performing final formatting commit
2025-02-07T20:33:16.220244Z  INFO main bpc_translate: Committing changes to Git with the message 'Formatting'
2025-02-07T20:33:17.732636Z  INFO main bpc_translate: Finished translating hangman

====== Translation Metrics Summary ======
Total Rust lines generated or modified: 110
Total original C lines: 100
Ratio of Rust lines to C lines: 110 : 100
Total C functions: 3
Total Rust functions: 3
Functions covered: 3
Number of refactors: 0 out of 15 iterations (0 total function refactors)
Function coverage percentage: 100.00%

Number of errors found during cargo check: 0
Error density: 0.00%
=========================================

```

