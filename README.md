# Game_Engine

Initial project setup for building and developing with a standardized environment.

## Makefile

### Dependencies

- g++ with C++17 support
- make
- SDL2 (headers and libs)
- SDL2_ttf (headers and libs)
- zip (for dist-win)
- dpkg-deb (for dist-linux)
- mingw-w64 (for dist-win)

### Note about the binary name

The `NAME` value in the Makefile is only an initial placeholder.
You can change it later to your final game name without affecting the command structure.

### How to use

The Makefile is ready to cover the full development flow: build, clean, rebuild, and package distribution.

Main commands:

```bash
make
```
Builds everything in `src` and generates the executable defined by `NAME`.

```bash
make clean
```
Removes object files (`.o`).

```bash
make fclean
```
Removes object files and the executable defined by `NAME`.

```bash
make re
```
Rebuilds from scratch (`fclean + all`).

```bash
make folders
```
Creates the game folder structure defined in the Makefile.

### Folder structure created by make folders

This structure is important to keep the project organized and predictable for developers who will use the engine in the future.

```text
.
|-- includes/
|   `-- game/
|       |-- actors/
|       |-- sprites/
|       `-- utils/
`-- src/
	`-- game/
		|-- actors/
		|-- assets/
		|-- rooms/
		|-- sprites/
		`-- utils/
```

Suggested use for each folder:

- src/game/assets: game files (textures, fonts, audio, maps, etc.)
- src/game/actors: game actor/entity implementations
- src/game/sprites: sprite components and logic
- src/game/rooms: levels/rooms and scene management
- src/game/utils: game-specific utilities
- includes/game: base headers for the game domain
- includes/game/actors: actor headers
- includes/game/sprites: sprite headers
- includes/game/utils: utility headers

Recommended pattern:

- keep all declarations (`.hpp`) in `includes/game`
- keep all implementations (`.cpp`) in `src/game`
- keep mirrored names and subfolder structure between `includes` and `src`

Distribution:

```bash
make dist-linux
```
Generates a `.deb` package with binary and assets.

```bash
make dist-win
```
Generates a Windows build + copies DLLs + creates final zip.

### Recommended day-to-day flow

```bash
make
./<executable>
make clean
```

Quick tips:
- use `make re` when changing includes, compiler flags, or file structure
- use `make clean` frequently to keep the project lean
- use `dist-linux`/`dist-win` only when packaging a release

## Dev Container

The project includes a ready-to-use environment in `.devcontainer` to avoid manual dependency setup.

### Dependencies installed in the container

- build-essential, cmake, gdb, git, curl, wget
- pkg-config, zip, unzip
- libsdl2-dev, libsdl2-image-dev, libsdl2-ttf-dev, libsdl2-mixer-dev
- clang, clangd, lldb
- vulkan-tools, libvulkan-dev, vulkan-validationlayers-dev, spirv-tools
- mingw-w64 and x86_64-w64-mingw32 toolchain
- SDL2 and SDL2_ttf for Windows cross-compilation

### How to use

1. Open the project in VS Code.
2. Run the command `Dev Containers: Reopen in Container`.
3. Wait for the image build to finish.
4. In the container terminal, run `make`.

Quick-use commands inside the container:

```bash
make
./<executable>
make clean
```