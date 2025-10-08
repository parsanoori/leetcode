# 🧩 My LeetCode Solutions

I’m documenting my **LeetCode** journey here — to track progress, stay consistent, and share different C++ approaches to algorithmic problem-solving.

---

## 📂 Project Structure

The structure of this repository is simple and organized:

* Each problem has its own folder named after the question ID and title (e.g., `001-two-sum/`).
* Each folder contains:

  * One or more `.cpp` solution files (e.g., `v1.cpp`, `v2.cpp`).
  * A dedicated `CMakeLists.txt` file for building that problem individually.

Example:

```
.
├── 001-regex-dp/
│   ├── v1-forward-dp.cpp
│   ├── v2-backward-dp.cpp
│   └── CMakeLists.txt
└── README.md
```

---

## ⚙️ Build & Run

Each folder can be built independently using **CMake**:

```
cd 001-two-sum
mkdir build && cd build
cmake ..
make
./main
```

Alternatively, you can compile directly with **g++**:

```
g++ -std=c++17 v1.cpp -o main && ./main
```

> 💡 Note: This repository only contains **C++** solutions.

---

## 🗓️ Progress Tracker

| Difficulty | Solved | In Progress | Total |
| ---------- | ------ | ----------- | ----- |
| Easy       | —      | —           | —     |
| Medium     | —      | —           | —     |
| Hard       | —      | —           | —     |

*(This table will be updated as I make progress.)*

---

## 🏗️ Future Plans

* Add automated progress tracking via a simple script or GitHub Action

---

## 📜 License

This repository is released under the [MIT License](LICENSE).

