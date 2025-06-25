# JustGain

A lightweight, cross-platform **gain** plug-in built with JUCE.

|            | Details |
|------------|---------|
| **Format** | VST3 / AU / LV2 |
| **Range**  | 0 dB → +18 dB |
| **Latency**| 0 samples |
| **Build**  | CMake + C++20 |
| **License**| MIT |

---

## Build & Install

```bash
# clone with JUCE submodule
git clone --recurse-submodules https://github.com/jermainewakeup/justgain.git
cd jusgain

# configure & build
cmake -Bbuild -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release

# install to your user plug-in folder
cmake --install build
