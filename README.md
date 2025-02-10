# Bulletproof Code (BPC) Final Demonstration Translation Examples

Welcome to the Bulletproof Code (BPC) final demonstration translation example repository. This repository provides sample translation projects and their results. Each top-level directory represents an individual example project, containing both the original C code (or project link) and the translated Rust code generated by BPC. 

| Project  | Complexity | Notes | Status |
|-------|-----|--------------|------------|
| [rock paper scissors](https://github.com/darkskytechnology/BPC-final-demo/blob/main/rock_paper_scissors/notes.MD) | Single source file | Translates cleanly on first pass  | ✅ |
| [hangman game](https://github.com/darkskytechnology/BPC-final-demo/blob/main/hangman/notes.MD)  | Single source file  | Translates cleanly on first pass  | ✅ |
| [snake and ladder game](https://github.com/darkskytechnology/BPC-final-demo/blob/main/snake_and_ladder/notes.MD)  | Single source file  | Compiles cleanly after three refactoring iterations, but requires one manual edit to add an underflow check that is required for runtime safety.  | ✅ |
| [sorting algorithms](https://github.com/darkskytechnology/BPC-final-demo/blob/main/sorting/notes.MD)  | Single source file  | Translates cleanly on first pass  | ✅ |
| [ugly pointer](https://github.com/darkskytechnology/BPC-final-demo/blob/main/ugly_pointer/notes.MD) | Single source file | Translates cleanly on first pass  | ✅ |
| [sutils](https://github.com/darkskytechnology/BPC-final-demo/blob/main/sutils/notes.MD)  | Multiple binary targets  | Mixed results, but overall very positive. Three targets compiled and executed accurately without any intervention. Three more compiled and executed, but required minor adjustments to obtain runtime accuracy. One required a manual addition of a dependency to compile, but then executed accurately. One was unable to compile or execute without larger manual refactoring. See the [project page](https://github.com/darkskytechnology/BPC-final-demo/blob/main/sutils/notes.MD) for details.  | 🟡 |
| [libmcs](https://github.com/darkskytechnology/BPC-final-demo/blob/main/libmcs/notes.MD)  | Library  | Mixed results. Code produced could serve as a good starting point for transitioning this into a Rust library, but due to lack of global context, building the complete library using the tool is not yet feasible. See the [project page](https://github.com/darkskytechnology/BPC-final-demo/blob/main/sutils/notes.MD) for details.  | 🟡 |
## Acknowledgment of Support and Disclaimer
**Support:** This material is based upon work supported by the Defense Advanced Research Projects Agency (DARPA) under Small Business Innovative Research (SBIR) Contract numbers HR001122C0048/HR001123C0078.

**Disclaimer:** Any opinions, findings and conclusions or recommendations expressed in this material are those of the 
author(s) and do not necessarily reflect the views of DARPA. 

---

Reach out to sandy@darkskytechnology.com if you have questions. 
