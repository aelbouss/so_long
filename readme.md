# so_long

A lightweight 2D top-down maze game developed in C using the 42 MiniLibX graphics library. The player navigates a maze, gathers all collectibles, and heads to the exit in the lowest possible number of moves.

---

## Overview

The project serves as an introduction to window management, sprite rendering, event loops, and input validation:

* Reads and parses `.ber` configuration files.
* Validates map solvability using a flood fill algorithm prior to window creation.
* Converts `.xpm` textures into screen buffers and draws them dynamically.
* Captures keyboard and window hooks for fluid, real-time navigation.
* Maintains strict resource management to prevent memory and file descriptor leaks.

---

## Technical Flow

1. **Parsing and Solvability:** The program reads the `.ber` map with `get_next_line`, builds a 2D grid, and ensures it is rectangular, surrounded by walls, and contains the required elements (`P`, `E`, `C`). A flood fill traversal guarantees a valid path exists to all items and the exit.
2. **Initialization:** Connects to the graphical display server (`mlx_init`), allocates an appropriately sized window, and loads all `.xpm` sprite assets into memory.
3. **Event Loop:** Listens for keyboard inputs (`W`, `A`, `S`, `D` and arrow keys) to process coordinate shifts, check collision boundaries, update the step count in the console, and redraw modified tiles.
4. **Clean Exit:** Destroys all loaded image instances, closes the window and display connection, and frees all allocated structures upon pressing `ESC` or clicking the close button.

---

## Controls

| Input | Target Action |
| --- | --- |
| `W` / `Up Arrow` | Move forward / up |
| `A` / `Left Arrow` | Move left |
| `S` / `Down Arrow` | Move backward / down |
| `D` / `Right Arrow` | Move right |
| `ESC` | Terminate program cleanly |
| Window `Close` (`X`) | Exit application |

---

## Map Configuration

Map files must end with the `.ber` extension and consist only of the following five elements:

| Component | Identifier | Requirement |
| --- | --- | --- |
| Wall | `1` | Must completely enclose the exterior perimeter |
| Empty Floor | `0` | Walkable space |
| Collectible | `C` | At least 1 present on the map |
| Exit | `E` | Exactly 1 exit door |
| Player Start | `P` | Exactly 1 starting coordinate |

```text
1111111111111
1P00100C000E1
1000000000001
10C00010C0001
1111111111111

```

---

## Prerequisites & MiniLibX Setup

### 1. System Dependencies

**Linux (Debian / Ubuntu / Kali):**

```bash
sudo apt update
sudo apt install -y gcc make libx11-dev libxext-dev libbsd-dev

```

**macOS:**

```bash
xcode-select --install

```

---

### 2. Installing MiniLibX

If MiniLibX is not included in the repository as a submodule, clone and compile the version matching your operating system inside the project root:

**Linux (X11 Version):**

```bash
git clone https://github.com/42Paris/minilibx-linux.git mlx
cd mlx
make
cd ..

```

**macOS (Metal / OpenGL Version):**

```bash
git clone https://github.com/42Paris/minilibx_opengl.git mlx
cd mlx
make
cd ..

```

---

## Installation & Execution

### 1. Build the Game

```bash
git clone https://github.com/your-username/so_long.git
cd so_long
make

```

### 2. Run a Map

```bash
./so_long maps/valid/map.ber

```

### 3. Cleanup Rules

* `make clean` removes compiled object files (`.o`).
* `make fclean` removes object files and the final binary.
* `make re` performs a complete recompilation.
