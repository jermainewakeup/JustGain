# JustGain

A lightweight, cross-platform **gain** plug-in built with JUCE.

|            | Details |
|------------|---------|
| **Format** | VST3 / AU |
| **Range**  | 0 dB → +18 dB |
| **Latency**| 0 samples |
| **Build**  | CMake + C++20 |
| **License**| MIT |

---
## Features
- Clean gain with no added coloration

- Smooth knob taper and double-click to reset

- Bypass switch, parameter automation

---
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
---
## Build

```bash
# clone with JUCE submodule
git clone --recurse-submodules https://github.com/jermainewakeup/justgain.git
cd justgain

# configure & build
cmake -Bbuild -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release

# install to your user plug-in folder
cmake --install build
