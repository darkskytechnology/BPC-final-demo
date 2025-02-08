# Project source

[rock_paper_scissors.c](rock_paper_scissors.c) (
Project comes from [geeksforgeeks.org](https://www.geeksforgeeks.org/rock-paper-scissor-in-c/))


# Translated Rust source

[rock_paper_scissors.tgz](rock_paper_scissors.tgz)

# Project build steps

Not necessary

## Build file

Not necessary

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/rock_paper_scissors -a /tmp/rps-artifacts.zip --model openai /home/coder/Documents/GitHub/geeksforgeeks/rock_paper_scissors/rock_paper_scissors.c
```

# Video demonstration

[rock_paper_scissors.mp4](rock_paper_scissors.mp4)

# Examples 

[rock_paper_scissors](rock_paper_scissors.png) C and Rust comparison

# Notes

Translates cleanly on first pass:

```
2025-02-08T00:25:07.395428Z  INFO main bpc_translate: Creating initial commit in git repository in `/home/coder/Documents/GitHub/demo/rock_paper_scissors`
2025-02-08T00:25:08.357469Z  INFO main bpc_translate: Tagging initial commit with 'Initial first pass translation results' in `/home/coder/Documents/GitHub/demo/rock_paper_scissors`
2025-02-08T00:25:10.745773Z  INFO main bpc_translate: 🎯 No compilation errors found, skipping refactoring!🎯
2025-02-08T00:25:10.745786Z  INFO main bpc_translate: Running rustfmt on all Rust files in `/home/coder/Documents/GitHub/demo/rock_paper_scissors`
2025-02-08T00:25:10.778961Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/rock_paper_scissors/src/bpc_prelude.rs`
2025-02-08T00:25:10.813286Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/rock_paper_scissors/src/lib.rs`
2025-02-08T00:25:10.845153Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/rock_paper_scissors/src/rock_paper_scissors_c.rs`
2025-02-08T00:25:10.845171Z  INFO main bpc_translate: rustfmt completed successfully on all files
2025-02-08T00:25:10.845176Z  INFO main bpc_translate: rustfmt completed successfully
2025-02-08T00:25:10.845179Z  INFO main bpc_translate: Performing final formatting commit
2025-02-08T00:25:10.845182Z  INFO main bpc_translate: Committing changes to Git with the message 'Formatting'
2025-02-08T00:25:11.773621Z  INFO main bpc_translate: Finished translating rock_paper_scissors

====== Translation Metrics Summary ======
Total Rust lines generated or modified: 54
Total original C lines: 47
Ratio of Rust lines to C lines: 54 : 47
Total C functions: 2
Total Rust functions: 2
Functions covered: 2
Number of refactors: 0 out of 15 iterations (0 total function refactors)
Function coverage percentage: 100.00%

Number of errors found during cargo check: 0
Error density: 0.00%
=========================================
```
