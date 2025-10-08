[![CI](https://github.com/jermainewakup/JustGain/actions/workflows/ci.yml/badge.svg)](https://github.com/<USER>/<REPO>/actions/workflows/ci.yml)

# JustGain

A lightweight, cross-platform **gain** audio plug-in built with JUCE.

|            | Details                                 |
|------------|-----------------------------------------|
| **Formats**| VST3 (Windows/macOS/Linux), AU (macOS)  |
| **Range**  | 0 dB → +18 dB *(no attenuation)*        |
| **Latency**| 0 samples                               |
| **Build**  | CMake + C++20                           |
| **License**| MIT                                     |

## Features
- Clean gain with no added coloration
- Smooth knob taper and double-click to reset
- Bypass switch, parameter automation

## Prerequisites
- **CMake ≥ 3.22**
- **Toolchain**
  - **Windows:** MSVC (Visual Studio 2022 Build Tools)
  - **macOS:** Xcode + Command Line Tools
  - **Linux:** `gcc` or `clang`, `build-essential`, `pkg-config`
- **Submodules:** JUCE (cloned via `--recurse-submodules`)

Install CMake on Windows:
```bat
winget install --id Kitware.CMake -e
```

## Build
```cmd
# 1) Clone with JUCE submodule
git clone --recurse-submodules https://github.com/jermainewakeup/justgain.git
cd justgain

# 2) Configure (choose ONE generator)

# Windows (Visual Studio 2022, x64):
cmake -S . -B build -G "Visual Studio 17 2022" -A x64

# macOS (Xcode):
# cmake -S . -B build -G Xcode

# Any OS (Ninja, single-config):
# cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release

# 3) Build
cmake --build build --config Release
```
