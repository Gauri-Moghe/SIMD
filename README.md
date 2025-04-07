
# SIMD - LU Decomposition Optimization

This project demonstrates how Single Instruction, Multiple Data (SIMD) techniques using AVX2 intrinsics can significantly accelerate LU Decomposition of large matrices in C++.

---

## 📌 Overview

LU Decomposition breaks a square matrix **A** into:
- Lower triangular matrix **L**
- Upper triangular matrix **U**

This repo compares two implementations:
- **Non-Optimized**: Traditional nested loop approach
- **SIMD-Optimized**: Uses AVX2 intrinsics for parallel processing

---

## 📁 Files

| File                | Description |
|---------------------|-------------|
| `non_optimized.cpp` | Standard LU decomposition using loops |
| `optimized.cpp`     | SIMD-accelerated LU decomposition using AVX2 intrinsics |
| `SIMD_report.pdf`   | Report explaining the algorithm, optimizations, and achieved speedup |

---

## 🚀 Performance

The optimized version demonstrated a **~4.63x speedup** over the non-optimized version on a 4000x4000 matrix.

---

## 🛠️ Compilation & Execution

### ✅ Compile Non-Optimized Version

```bash
g++ -O3 -o non_optimized non_optimized.cpp
./non_optimized
```

### ⚡ Compile SIMD-Optimized Version

Requires a compiler that supports AVX2 (e.g., GCC):

```bash
g++ -O3 -mavx2 -o optimized optimized.cpp
./optimized
```

---

## 📊 SIMD Techniques Used

- AVX2 Intrinsics (`<immintrin.h>`)
- 256-bit registers (`__m256`)
- Parallel multiplication, subtraction, and division
- Loop unrolling for performance
- Targeted compile flags for hardware acceleration

---

## 📚 References

- [LU Decomposition – Tutorialspoint](https://www.tutorialspoint.com/cplusplus-program-to-perform-lu-decomposition-of-any-matrix)
- AVX2 Intrinsics: Intel / GCC documentation

---

## 🧑‍💻 Author

**Gauri Shashank Moghe**  
Graduate Student – Computer Science  
Specialized in AI, ML, and High-Performance Computing  
