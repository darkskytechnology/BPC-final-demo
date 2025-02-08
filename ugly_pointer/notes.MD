# Project source

[ugly_pointer.c](ugly_pointer.c)


# Translated Rust source

[ugly_pointer.tgz](ugly_pointer.tgz)

# Project build steps

Not necessary

## Build file

Not necessary

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/ugly_pointer -a /tmp/ugly_pointer-artifacts.zip --model openai /home/coder/Documents/GitHub/ugly_pointer/ugly_pointer.c
```

# Video demonstration

[ugly_pointer.mp4](ugly_pointer.mp4)

# Examples 

[ugly_pointer](ugly_pointer.png) C and Rust comparison

# Notes

Translates cleanly on first pass:

```
2025-02-08T00:41:28.045440Z  INFO main bpc_translate: Creating initial commit in git repository in `/home/coder/Documents/GitHub/demo/ugly_pointer`
2025-02-08T00:41:29.005775Z  INFO main bpc_translate: Tagging initial commit with 'Initial first pass translation results' in `/home/coder/Documents/GitHub/demo/ugly_pointer`
2025-02-08T00:41:29.137163Z  INFO main bpc_translate: 🎯 No compilation errors found, skipping refactoring!🎯
2025-02-08T00:41:29.137185Z  INFO main bpc_translate: Running rustfmt on all Rust files in `/home/coder/Documents/GitHub/demo/ugly_pointer`
2025-02-08T00:41:29.170228Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/ugly_pointer/src/bpc_prelude.rs`
2025-02-08T00:41:29.201524Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/ugly_pointer/src/lib.rs`
2025-02-08T00:41:29.232511Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/ugly_pointer/src/ugly_pointer_c.rs`
2025-02-08T00:41:29.232526Z  INFO main bpc_translate: rustfmt completed successfully on all files
2025-02-08T00:41:29.232530Z  INFO main bpc_translate: rustfmt completed successfully
2025-02-08T00:41:29.232532Z  INFO main bpc_translate: Performing final formatting commit
2025-02-08T00:41:29.232534Z  INFO main bpc_translate: Committing changes to Git with the message 'Formatting'
2025-02-08T00:41:30.203515Z  INFO main bpc_translate: Finished translating ugly_pointer

====== Translation Metrics Summary ======
Total Rust lines generated or modified: 41
Total original C lines: 42
Ratio of Rust lines to C lines: 41 : 42
Total C functions: 5
Total Rust functions: 5
Functions covered: 5
Number of refactors: 0 out of 15 iterations (0 total function refactors)
Function coverage percentage: 100.00%

Number of errors found during cargo check: 0
Error density: 0.00%
=========================================
```
