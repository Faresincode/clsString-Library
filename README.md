# clsString-Library
Comprehensive C++ String Manipulation Library

# clsString - The Ultimate C++ String Manipulation Library

<div align="center">

**A comprehensive, header-only C++ library for advanced string processing and text manipulation**

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C++-11%2B-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B11)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/)

</div>

---

## Why clsString?

Traditional C++ string operations can be verbose and cumbersome. **clsString** transforms string manipulation into an intuitive, powerful experience with over **100+ methods** covering every aspect of text processing you'll ever need.

```cpp
// Before (Standard C++)
std::string text = "hello world programming";
std::transform(text.begin(), text.end(), text.begin(), ::toupper);
// Complex logic for word capitalization...

// After (clsString)
clsString str("hello world programming");
str.ToUpperWords();  // "Hello World Programming"
```

## Features at a Glance

<table>
<tr>
<td width="50%">

### Core Operations
- **Text Analysis**: Character classification, pattern matching
- **Case Manipulation**: Upper, lower, title case transformations
- **String Transformation**: Reverse, trim, pad, wrap text
- **Search & Replace**: Advanced find/replace with multiple options
- **Text Parsing**: Split strings, join arrays, extract substrings

</td>
<td width="50%">

### Advanced Features
- **Number Conversion**: Integer to text ("123" → "One Hundred Twenty Three")
- **Date/Time Helpers**: Day names, month names, abbreviations
- **Encryption**: Simple character-shift cipher
- **Text Cleaning**: Remove duplicates, punctuation, extra spaces
- **Random Generation**: Characters and numbers within ranges

</td>
</tr>
</table>

---

## Quick Start

### Installation
```bash
# Simply download and include the header file
wget https://github.com/yourusername/clsString/raw/main/clsString.h
```

### Basic Usage
```cpp
#include "clsString.h"
#include <iostream>

int main() {
    // Create and manipulate strings effortlessly
    clsString text("Hello World");
    
    std::cout << text.CountVowels() << std::endl;        // 3
    std::cout << text.ToUpperAll() << std::endl;         // "HELLO WORLD"
    std::cout << text.MostFrequentChar() << std::endl;   // 'l'
    std::cout << text.IsPalindrome() << std::endl;       // false
    
    // Static methods for one-off operations
    std::cout << clsString::NumberToText(1500) << std::endl;  // "One Thousand Five Hundred"
    
    return 0;
}
```

---

## Comprehensive API Reference

### Text Analysis & Validation
<details>
<summary>Click to expand</summary>

| Method | Description | Example |
|--------|-------------|---------|
| `IsVowel(char)` | Check if character is vowel | `IsVowel('a')` → `true` |
| `IsPalindrome(string)` | Check if text reads same backwards | `IsPalindrome("racecar")` → `true` |
| `IsEmpty(string)` | Check if string is empty | `IsEmpty("")` → `true` |
| `IsAlphabet(string)` | Check if contains only letters | `IsAlphabet("Hello")` → `true` |
| `IsStringNumbers(string)` | Check if contains only digits | `IsStringNumbers("123")` → `true` |
| `Contains(string, substring)` | Check if contains substring | `Contains("Hello", "ell")` → `true` |

</details>

### Case Operations
<details>
<summary>Click to expand</summary>

| Method | Description | Example |
|--------|-------------|---------|
| `ToUpperAll(string)` | Convert entire string to uppercase | `ToUpperAll("hello")` → `"HELLO"` |
| `ToLowerAll(string)` | Convert entire string to lowercase | `ToLowerAll("HELLO")` → `"hello"` |
| `ToUpperWords(string)` | Capitalize first letter of each word | `ToUpperWords("hello world")` → `"Hello World"` |
| `InvertChar(char)` | Toggle character case | `InvertChar('a')` → `'A'` |
| `InvertAllStringLetterCase(string)` | Toggle case of all letters | `InvertAllStringLetterCase("Hello")` → `"hELLO"` |

</details>

### Counting & Statistics
<details>
<summary>Click to expand</summary>

| Method | Description | Example |
|--------|-------------|---------|
| `Length(string)` | Get string length | `Length("Hello")` → `5` |
| `CountWords(string)` | Count number of words | `CountWords("Hello World")` → `2` |
| `CountVowels(string)` | Count vowels in string | `CountVowels("Hello")` → `2` |
| `CountChar(string, char)` | Count specific character | `CountChar("Hello", 'l')` → `2` |
| `CountCapitalLetters(string)` | Count uppercase letters | `CountCapitalLetters("Hello")` → `1` |
| `MostFrequentChar(string)` | Find most common character | `MostFrequentChar("Hello")` → `'l'` |

</details>

### String Manipulation
<details>
<summary>Click to expand</summary>

| Method | Description | Example |
|--------|-------------|---------|
| `Reverse(string)` | Reverse string | `Reverse("Hello")` → `"olleH"` |
| `Trim(string)` | Remove leading/trailing spaces | `Trim("  Hello  ")` → `"Hello"` |
| `PadLeft(string, length, char)` | Add padding to left | `PadLeft("Hi", 5, '*')` → `"***Hi"` |
| `Insert(string, text, index)` | Insert text at position | `Insert("Hello", "X", 2)` → `"HeXllo"` |
| `ReplaceWord(string, old, new)` | Replace word occurrences | `ReplaceWord("Hi there", "Hi", "Hello")` → `"Hello there"` |
| `RemoveChar(string, char)` | Remove all instances of character | `RemoveChar("Hello", 'l')` → `"Heo"` |

</details>

### Advanced Operations
<details>
<summary>Click to expand</summary>

| Method | Description | Example |
|--------|-------------|---------|
| `SplitString(string, delimiter)` | Split into vector | `SplitString("a,b,c", ",")` → `{"a","b","c"}` |
| `JoinString(vector, delimiter)` | Join vector elements | `JoinString({"a","b"}, "-")` → `"a-b"` |
| `NumberToText(int)` | Convert number to words | `NumberToText(123)` → `"One Hundred Twenty Three"` |
| `Encrypt(string, key)` | Simple character shift | `Encrypt("ABC", 1)` → `"BCD"` |
| `WordWrap(string, width)` | Wrap text to width | `WordWrap("Long text here", 5)` → `"Long\ntext\nhere"` |
| `RandomChar(from, to)` | Generate random character | `RandomChar(65, 90)` → Random A-Z |

</details>

---

## Real-World Examples

### Text Processing Pipeline
```cpp
clsString processor("  HELLO world! This is a TEST.  ");

// Clean and format text
std::string result = processor
    .Trim()                           // Remove spaces
    .ToLowerAll()                     // Make lowercase
    .ToUpperWords()                   // Title case
    .RemovePunct()                    // Remove punctuation
    .RemoveExtraSpaces();             // Clean spacing

// Result: "Hello World This Is A Test"
```

### Data Analysis
```cpp
clsString analyzer("The quick brown fox jumps over the lazy dog");

// Analyze text properties
std::cout << "Length: " << analyzer.Length() << std::endl;                    // 43
std::cout << "Words: " << analyzer.CountWords() << std::endl;                 // 9
std::cout << "Vowels: " << analyzer.CountVowels() << std::endl;               // 11
std::cout << "Most frequent: " << analyzer.MostFrequentChar() << std::endl;   // 'o'
std::cout << "Longest word: " << analyzer.LongestWord() << std::endl;         // "jumps"
```

### CSV Processing
```cpp
std::string csvData = "John,25,Engineer;Jane,30,Designer;Bob,35,Manager";
auto records = clsString::SplitString(csvData, ";");

for (const auto& record : records) {
    auto fields = clsString::SplitString(record, ",");
    std::cout << "Name: " << fields[0] << ", Age: " << fields[1] 
              << ", Job: " << fields[2] << std::endl;
}
```

### Number Formatting
```cpp
// Convert numbers to readable text
std::cout << clsString::NumberToText(1001) << std::endl;     // "One Thousand One"
std::cout << clsString::NumberToText(1500000) << std::endl;  // "One Million Five Hundred Thousand"

// Date helpers
std::cout << clsString::WeekDayName(1) << std::endl;         // "Sunday"
std::cout << clsString::MonthName(12) << std::endl;          // "December"
```

---

## Performance & Compatibility

### System Requirements
- **C++ Standard**: C++11 or later
- **Platform**: Windows (uses `__declspec(property)`)
- **Dependencies**: Standard library only
- **Size**: Single header file (~50KB)

### Performance Notes
- Most operations: **O(n)** time complexity
- Memory efficient with stack-based operations
- Custom implementations for educational value
- Zero external dependencies

---

## Installation & Usage

### Method 1: Direct Download
```bash
# Download the header file
curl -O https://raw.githubusercontent.com/yourusername/clsString/main/clsString.h

# Include in your project
#include "clsString.h"
```

### Method 2: Git Clone
```bash
git clone https://github.com/yourusername/clsString.git
cd clsString
# Copy clsString.h to your project directory
```

### Compilation
```bash
# Standard compilation
g++ -std=c++11 your_program.cpp -o your_program

# With optimizations
g++ -std=c++11 -O2 your_program.cpp -o your_program
```

---

## Examples & Tutorials

Check out the `examples/` directory for comprehensive usage examples:
- `basic_usage.cpp` - Essential operations
- `text_analysis.cpp` - Advanced text processing
- `data_processing.cpp` - Real-world data manipulation
- `encryption_demo.cpp` - Security operations

---

## Contributing

We welcome contributions! Here's how you can help:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/AmazingFeature`)
3. **Commit** your changes (`git commit -m 'Add AmazingFeature'`)
4. **Push** to the branch (`git push origin feature/AmazingFeature`)
5. **Open** a Pull Request

### Development Guidelines
- Follow existing code style
- Add unit tests for new features
- Update documentation
- Ensure backward compatibility

---

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## Support & Community

- **Issues**: [GitHub Issues](https://github.com/yourusername/clsString/issues)
- **Documentation**: [Wiki](https://github.com/yourusername/clsString/wiki)
- **Discussions**: [GitHub Discussions](https://github.com/yourusername/clsString/discussions)

---

<div align="center">

**Made with ❤️ for the C++ community**

[⬆ Back to top](#clsstring---the-ultimate-c-string-manipulation-library)

</div>
