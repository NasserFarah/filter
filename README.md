grep-like Text Filter with Character Replacement

This program is a simple text filtering utility that reads from standard input (stdin), searches for occurrences of a user-specified string, and replaces all characters of matched patterns with asterisks (*, ASCII 42).

Functionality


Input: Reads text from standard input in chunks of up to 100,000 bytes

Pattern Matching: Searches for exact string matches of the pattern provided as a command-line argument

Replacement: When a match is found, all characters in that match are replaced with * characters

Output: Prints the modified text to standard output, followed by a newline after each buffer


Usage

bash./program "pattern" < input_file

echo "hello world hello" | ./program "hello"

```

### How It Works

1. Takes a single command-line argument (the filter pattern)
2. Reads input from stdin in 100KB chunks
3. Scans each chunk for occurrences of the pattern
4. Replaces matched substrings character-by-character with asterisks
5. Outputs the modified buffer
6. Continues until EOF is reached

### Example

**Input:**
```
The quick brown fox jumps over the lazy dog

Command:

echo "The quick brown fox jumps over the lazy dog" | ./program "fox"

```

**Output:**
```
The quick brown *** jumps over the lazy dog

Technical Details


Buffer Size: 100,000 bytes

Pattern Matching: Uses nested loops to find consecutive character matches

Error Handling: Prints error messages if read() fails
