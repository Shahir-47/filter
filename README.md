# Filter

## Overview

**Filter** is a program that applies various filters to 24-bit BMP (Bitmap) images. It supports grayscale, sepia, reflection, and blur filters. The program processes the image pixel by pixel and generates a new image file with the applied effect.

By modifying the RGB values in the pixels of a BMP file, **Filter** demonstrates image manipulation through low-level programming in C.

---

## Features

- **Grayscale**: Converts an image to black-and-white shades.
- **Sepia**: Applies an old-timey, reddish-brown filter.
- **Reflection**: Mirrors the image horizontally.
- **Blur**: Applies a box blur to smooth the image.

---

## Prerequisites

Before using **Filter**, ensure you have the following:
1. A C compiler (`clang` or `gcc`).
2. `make` build tool.

Follow these steps to install them based on your operating system:

### Installing Clang and Make

#### Ubuntu/Linux
1. Update your package list:
   ```bash
   sudo apt update
   ```
2. Install Clang and Make:
   ```bash
   sudo apt install clang make
   ```
3. Verify installation:
   ```bash
   clang --version
   make --version
   ```

#### macOS
1. Install Xcode Command Line Tools:
   ```bash
   xcode-select --install
   ```
2. Verify installation:
   ```bash
   clang --version
   make --version
   ```

#### Windows
1. Download the LLVM installer from the [official LLVM website](https://llvm.org/builds/).
2. Run the installer and follow the setup instructions.
3. Add the LLVM `bin` directory (e.g., `C:\Program Files\LLVM\bin`) to your system's `PATH` environment variable:
   - Open "Environment Variables" in Windows settings.
   - Edit the `Path` variable and add the directory.
4. Install `Make` via [Chocolatey](https://chocolatey.org/) or [MinGW](https://www.mingw-w64.org/).
5. Verify installation:
   ```cmd
   clang --version
   make --version
   ```

---

## Usage

### Step 1: Compile the Program
Use the provided `Makefile` to compile the program:
```bash
make filter
```

This will generate an executable file named `filter`.

### Step 2: Run the Program
Run the program using the following syntax:
```bash
./filter [FILTER_OPTION] infile.bmp outfile.bmp
```

### Filters
- `-g`: Apply grayscale filter.
- `-s`: Apply sepia filter.
- `-r`: Apply reflection filter.
- `-b`: Apply blur filter.

### Parameters
- **infile.bmp**: Path to the input BMP file.
- **outfile.bmp**: Path where the filtered image will be saved.

### Examples
#### Apply Grayscale
```bash
./filter -g images/yard.bmp out.bmp
```

#### Apply Sepia
```bash
./filter -s images/yard.bmp out.bmp
```

#### Apply Reflection
```bash
./filter -r images/yard.bmp out.bmp
```

#### Apply Blur
```bash
./filter -b images/yard.bmp out.bmp
```

---

## Project Structure

```
├── filter/
│   ├── helpers.h
│   ├── helpers.c
│   ├── Makefile
│   ├── images/
│   │   ├── courtyard.bmp
│   │   ├── stadium.bmp
│   │   ├── yard.bmp
│   │   └── tower.bmp
│   ├── filter.c
│   ├── bmp.h
└── README.md
```

- **`helpers.h`**: Function prototypes for the filters.
- **`helpers.c`**: Implements the grayscale, sepia, reflection, and blur filters.
- **`filter.c`**: Main program logic for applying filters and handling BMP files.
- **`bmp.h`**: Defines data structures and types for BMP file handling.
- **`Makefile`**: Automates the build process.
- **`images/`**: Sample BMP files for testing.

---

## Filters in Detail

### 1. **Grayscale**
Converts an image to black-and-white shades by averaging the red, green, and blue values for each pixel. The resulting value is applied to all three color channels.

### 2. **Sepia**
Applies a reddish-brown filter using the following formula:
```
sepiaRed = .393 * red + .769 * green + .189 * blue
sepiaGreen = .349 * red + .686 * green + .168 * blue
sepiaBlue = .272 * red + .534 * green + .131 * blue
```
Values exceeding 255 are capped at 255.

### 3. **Reflection**
Reflects the image horizontally by swapping pixels on the left side with those on the right side for each row.

### 4. **Blur**
Applies a box blur by averaging the RGB values of a pixel and its neighbors in a 3x3 grid. Edge pixels use only available neighbors.

---

## Development Notes

- **Dependencies**: Standard C libraries (`stdio.h`, `stdlib.h`, `math.h`).
- **Compatibility**: Works on Unix-like systems (Linux, macOS) and Windows (with MinGW or WSL).
- **Manual Compilation**: If `make` is unavailable:
  ```bash
  clang -std=c11 -Wall -Werror -o filter filter.c helpers.c -lm
  ```

---

## Testing

### Test Files
The `images/` directory contains sample BMP files for testing, such as:
- `yard.bmp`
- `courtyard.bmp`
- `stadium.bmp`

### Running Tests
To test the program, use:
```bash
./filter -g images/yard.bmp out.bmp
```

Inspect the output image (`out.bmp`) to confirm the filter was applied correctly.

---

## Authors

Developed by [Shahir Ahmed](https://github.com/Shahir-47/).

## License

This project is licensed under the [MIT License](LICENSE).
