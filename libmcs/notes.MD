# Project source

https://gitlab.com/gtd-gmbh/libmcs


# Translated Rust source

[rust_libmcs.tgz](rust_libmcs.tgz)

# Project build steps

```
bpc-translate generate-replacement --cc-override $(pwd)/bpc-gcc $(pwd)/libmcs.toml /usr/bin/gcc $(pwd) -- ./configure --cross-compile $(pwd)/bpc-
make
```

## Build file

[libmcs.toml](libmcs.toml)

# Translation steps

```
BPC_LOG=info bpc-translate translate -m /home/coder/Documents/GitHub/demo/lifted -o /home/coder/Documents/GitHub/demo/lib-mcs -a /tmp/libmcs-artifacts.zip --model openai /home/coder/Documents/GitHub/libmcs/libmcs.toml
```

# Video demonstration

[libmcs.mp4](libmcs.mp4)

# Examples 

- [libm/mathf/acosf](libm_mathf_acosf.png): C and Rust source comparison
- [libm/mathf/hypotf](libm_mathf_hypotf.png): C and Rust source comparison
- [libm/mathf/rintf](libm_mathf_rintf.png): C and Rust source comparison
- [libm/mathd/atan2d](libm_mathd_atan2d.png): C and Rust source comparison
- [libm/mathd/j0d](libm_mathd_j0d.png): C and Rust source comparison

# Notes

Produces accurate code for most functions present locally, but fails to pick up and properly handle the static inline functions. 

```
2025-02-10T15:51:18.073564Z  INFO main bpc_translate: rustfmt failed
2025-02-10T15:51:18.073573Z  INFO main bpc_translate: Performing final formatting commit
2025-02-10T15:51:18.073577Z  INFO main bpc_translate: Committing changes to Git with the message 'Formatting'
2025-02-10T15:51:18.079497Z  INFO main bpc_translate: Refactoring completed successfully with 15 attempts
2025-02-10T15:51:22.607122Z  INFO main bpc_translate: Finished translating lib-mcs

====== Translation Metrics Summary ======
Total Rust lines generated or modified: 7914
Total original C lines: 9607
Ratio of Rust lines to C lines: 7914 : 9607
Total C functions: 67
Total Rust functions: 348
Functions covered: 66
Number of refactors: 15 out of 15 iterations (294 total function refactors)
Function coverage percentage: 98.51%

Number of errors found during cargo check: 2
Error density: 0.03%
=========================================
```

Example of a failed static inline function `__j0_p()` present in global context but not found during transation of `src/libm/mathd/j0d.c`

```
static inline double __j0_p(double x)
{
    const double *p, *q;
    double z, r, s;
    int32_t ix;
    GET_HIGH_WORD(ix, x);
    ix &= 0x7fffffff;

    if (ix >= 0x41b00000)    {
        return one;
    } else if (ix >= 0x40200000) {
        p = __j0_pr8;
        q = __j0_ps8;
    } else if (ix >= 0x40122E8B) {
        p = __j0_pr5;
        q = __j0_ps5;
    } else if (ix >= 0x4006DB6D) {
        p = __j0_pr3;
        q = __j0_ps3;
    } else {
        p = __j0_pr2;
        q = __j0_ps2;
    }

    z = one / (x * x);
    r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
    s = one + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
    return one + r / s;
}

``` 

is incorrectlly replaced with

```
fn j0_p(_x: f64) -> f64 {
    0.0
}
```
These static inline functions are not accounted for in the C 'function count' metrics which is why the number of generated rust functions is much higher.
