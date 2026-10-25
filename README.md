# 42 Warsaw — Common Core Curriculum 🏊‍♂️💻

![42 School](https://img.shields.io/badge/42-Warsaw-000000?style=for-the-badge&logo=42&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

A unified monorepo containing my low-level systems programming, algorithmic, system administration, and Python engineering projects completed as part of the **42 Warsaw** Common Core curriculum.

---

## ⚡ About 42 & Code Standards

At **42**, learning is entirely project-based and peer-evaluated—with no teachers or lectures. Every project in this repository adheres to strict engineering constraints:

- **The Norm (C Projects):** Strict coding standard limiting functions to a maximum of 25 lines, 4 parameters, and 5 variables per function. Forbids `for`, `do...while`, `switch`, `case`, `goto`, and ternary operators to enforce clean, modular control flow.
- **Zero Memory Leaks:** All dynamically allocated memory (`malloc`) is manually managed and verified against leaks using `Valgrind` / `leaks`.
- **Built from Scratch:** Use of external libraries (and most standard `<stdlib.h>` / `<string.h>` functions) is prohibited unless implemented manually in `libft`.
- **Python Standards:** Strict adherence to `flake8` / PEP 8, static type hinting (`typing`), docstrings, and robust exception handling.

---

## 🗂️ Projects Overview

### 🛠️ Low-Level C & Algorithms

| Project | Milestone | Description | Key Concepts |
| :--- | :---: | :--- | :--- |
| **[libft](./libft)** | 0 | Custom implementation of standard C library functions (`libc`), string utilities, and linked lists. | `Pointers`, `Memory Allocation`, `Linked Lists`, `Makefile` |
| **[ft_printf](./ft_printf)** | 1 | Custom recreation of the standard `printf()` function handling multiple format specifiers. | `Variadic Functions`, `Formatted I/O`, `Parsing` |
| **[get_next_line](./get_next_line)** | 1 | Function reading and returning a line from single or multiple file descriptors using a custom `BUFFER_SIZE`. | `Static Variables`, `File Descriptors`, `Buffered I/O` |
| **[push_swap](./push_swap)** | 1 | Optimized sorting algorithm operating on two stacks (`a` and `b`) using a strictly limited instruction set. | `Sorting Algorithms`, `Data Structures`, `Complexity` |

---

### 🐧 System Administration & Virtualization

| Project | Milestone | Description | Key Concepts |
| :--- | :---: | :--- | :--- |
| **[Born2beRoot](./Born2beRoot)** | 1 | Hardened Linux server setup with encrypted LVM partitions, strict `sudo` policies, SSH hardening, UFW firewall, AppArmor, and automated `cron` monitoring scripts. | `Linux`, `LVM`, `UFW`, `SSH`, `Bash`, `Security` |

---

### 🐍 Python Engineering & Data Science

| Project / Module | Description | Key Concepts |
| :--- | :--- | :--- |
| **[Python Modules 00–09](./python_modules)** | 10-module series covering modern Python engineering from core syntax to data pipelines and package distribution. | `OOP`, `NumPy`, `Pandas`, `Pydantic`, `Packaging` |
| **[a_maze_ing](./a_maze_ing)** | Standalone Python package for procedural maze generation and terminal visualization (Kruskal, Prim, Wilson algorithms). | `Graph Algorithms`, `OOP Design`, `CLI`, `Poetry` |

#### 🔍 Python Modules (00–09) Breakdown:
- **Module 00 (Starting):** Core data structures, string formatting, CLI argument parsing, and foundational algorithms.
- **Module 01 (Array):** 2D array slicing, broadcasting, and RGB image manipulation using **NumPy**.
- **Module 02 (DataTable):** Loading, cleaning, filtering, and visualizing real-world datasets using **Pandas** and **Matplotlib**.
- **Module 03 (OOP):** Object-Oriented Programming, inheritance, abstract base classes (`ABC`), properties, and Method Resolution Order (MRO).
- **Module 04 (Dodgy):** Functional programming, closures, `*args` / `**kwargs`, custom decorators, context managers, and `@dataclass`.
- **Modules 05–09 (Advanced Engineering & Data):** Custom iterators/generators, runtime data validation with **Pydantic**, design patterns, and building installable Python packages (`pyproject.toml` / `requirements.txt`).

---

## 🚀 Usage & Compilation

**C Projects** — Each C project includes a `Makefile` supporting standard rules (`all`, `clean`, `fclean`, `re`, `bonus`) and compiles with `-Wall -Wextra -Werror`:

```bash
cd push_swap
make
./push_swap 4 67 3 87 23
```

**Python Projects** — Python modules and packages are structured for isolated virtual environments (`venv` or `Poetry`):

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

---

## 👤 Author

**Kamil**
- GitHub: [@kdzwigal](https://github.com/kdzwigal)
- Education: **42 Warsaw** & **WWSI (Warsaw School of Computer Science)**
