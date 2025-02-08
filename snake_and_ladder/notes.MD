# Project source

[snake_and_ladder.c](snake_and_ladder.c) (
Project comes from [geeksforgeeks.org](https://www.geeksforgeeks.org/snake-and-ladder-game-in-c/))


# Translated Rust source

[snake_and_ladder.tgz](snake_and_ladder.tgz)

# Project build steps

Not necessary

## Build file

Not necessary

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/snake_and_ladder -a /tmp/snake-artifacts.zip --model openai /home/coder/Documents/GitHub/geeksforgeeks/snake_and_ladder/snake_and_ladder.c
```

# Video demonstration

[snake_and_ladder.mp4](snake_and_ladder.mp4)

# Examples 

[snake_and_ladder](snake_and_ladder.png) C and Rust comparison

# Notes  

Compiled cleanly after 3 refactoring iterations and completely eliminated the need for the global variables `player_1` and `player_2`:

```
2025-02-08T01:43:30.048836Z  INFO main bpc_translate: ✅ No more errors found on attempt 3. Stopping refactoring process.
2025-02-08T01:43:30.048850Z  INFO main bpc_translate: Running rustfmt on all Rust files in `/home/coder/Documents/GitHub/demo/snake_and_ladder`
2025-02-08T01:43:30.081749Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/snake_and_ladder/src/bpc_prelude.rs`
2025-02-08T01:43:30.112371Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/snake_and_ladder/src/lib.rs`
2025-02-08T01:43:30.142474Z  INFO main bpc_translate: rustfmt completed successfully for `/home/coder/Documents/GitHub/demo/snake_and_ladder/src/snake_and_ladder_c.rs`
2025-02-08T01:43:30.142490Z  INFO main bpc_translate: rustfmt completed successfully on all files
2025-02-08T01:43:30.142497Z  INFO main bpc_translate: rustfmt completed successfully
2025-02-08T01:43:30.142499Z  INFO main bpc_translate: Performing final formatting commit
2025-02-08T01:43:30.142502Z  INFO main bpc_translate: Committing changes to Git with the message 'Formatting'
2025-02-08T01:43:31.042260Z  INFO main bpc_translate: Refactoring completed successfully with 3 attempts
2025-02-08T01:43:31.073054Z  INFO main bpc_translate: Finished translating snake_and_ladder

====== Translation Metrics Summary ======
Total Rust lines generated or modified: 104
Total original C lines: 111
Ratio of Rust lines to C lines: 104 : 111
Total C functions: 4
Total Rust functions: 4
Functions covered: 4
Number of refactors: 3 out of 15 iterations (5 total function refactors)
Function coverage percentage: 100.00%

Number of errors found during cargo check: 0
Error density: 0.00%
=========================================

```

See the video - there was a runtime error due to Rust's safety checks on the first execution:
```
     Running `target/debug/snake_and_ladder`
Snake and Ladder Game

_player 1, press Enter to roll the die...

You rolled a 1.
Player 1 is now at square 1.

100    99    98    97    96    95    94    93    92    91    

81    82    83    84    85    86    87    88    89    90    

80    79    78    77    76    75    74    73    72    71    

61    62    63    64    65    66    67    68    69    70    

60    59    58    57    56    55    54    53    52    51    

41    42    43    44    45    46    47    48    49    50    

40    39    38    37    36    35    34    33    32    31    

21    22    23    24    25    26    27    28    29    30    

20    19    18    17    16    15    14    13    12    11    

#P1    2    3    4    5    6    7    8    9    10    

thread 'main' panicked at src/snake_and_ladder_c.rs:46:17:
attempt to subtract with overflow
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
```
This required a manual edit to insert bounds checking to replace: `iter_r_l -= 30;` with
```
if iter_r_l >= 30 { 
   iter_r_l -= 30; 
} else {
   iter_r_l = 0; 
}
```

