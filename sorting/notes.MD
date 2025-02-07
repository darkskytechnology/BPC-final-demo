# Project source

[sorting.c](sorting.c)


# Translated Rust source

[sorting.tgz](sorting.tgz)

# Project build steps

Not necessary

## Build file

Not necessary

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/sorting -a /tmp/sorting-artifacts.zip --model openai /home/coder/Documents/GitHub/sorting_algorithms
```

# Video demonstration

[sorting.mp4](sorting.mp4)

# Examples 

[sorting](sorting.png) C and Rust comparison

# Notes

Translates cleanly on the first pass:
```
2025-02-07T20:14:32.385888Z  INFO main bpc_translate: Tagging initial commit with 'Initial first pass translation results' in `/home/coder/Documents/GitHub/demo/sorting_refactor`
2025-02-07T20:14:34.805606Z  INFO main bpc_translate: 🎯 No compilation errors found, skipping refactoring!🎯
2025-02-07T20:14:34.805621Z  INFO main bpc_translate: Running rustfmt on all Rust files in `/home/coder/Documents/GitHub/demo/sorting_refactor`
2025-02-07T20:14:34.837998Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/sorting_refactor/src/bpc_prelude.rs`
2025-02-07T20:14:34.868173Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/sorting_refactor/src/lib.rs`
2025-02-07T20:14:34.899800Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/sorting_refactor/src/sorting_c.rs`
2025-02-07T20:14:34.899812Z  INFO main bpc_translate: rustfmt completed successfully on all files
2025-02-07T20:14:34.899817Z  INFO main bpc_translate: rustfmt completed successfully
2025-02-07T20:14:34.899820Z  INFO main bpc_translate: Performing final formatting commit
2025-02-07T20:14:34.899824Z  INFO main bpc_translate: Committing changes to Git with the message 'Formatting'
2025-02-07T20:14:36.376172Z  INFO main bpc_translate: Finished translating sorting_refactor

====== Translation Metrics Summary ======
Total Rust lines generated or modified: 147
Total original C lines: 188
Ratio of Rust lines to C lines: 147 : 188
Total C functions: 10
Total Rust functions: 10
Functions covered: 10
Number of refactors: 0 out of 15 iterations (0 total function refactors)
Function coverage percentage: 100.00%

Number of errors found during cargo check: 0
Error density: 0.00%
=========================================

```




