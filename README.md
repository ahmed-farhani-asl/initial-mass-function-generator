# IMF Generator

This C++ program generates an **Initial Mass Function (IMF)** for a stellar population. It can generate the IMF based on either the **number of stars** or the **total cluster mass**.

---

## Features

- **IMF Generation**: Generates an IMF using a random sampling approach.
- **Two Modes**:
  - `imf_num()`: Generates IMF based on the number of stars.
  - `imf_mass()`: Generates IMF based on the total cluster mass.
- **Output**: Writes the IMF data to a file for further analysis.

---

## Usage

1. **Compile and run the code**:
   ```bash
   g++ -o imf_generator imf_generator.cpp
   ./imf_generator
   ```
