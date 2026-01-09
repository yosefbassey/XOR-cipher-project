# XOR Cipher & Breaker Suite

## Overview
This project explores the mechanics of Stream Ciphers and their vulnerabilities to Frequency Analysis. It includes:
1. **The Cipher:** A tool to encrypt files using XOR logic.
2. **The Breaker:** An automated tool that cracks single-byte XOR encryption using statistical analysis (frequency distribution).

## Technical Concepts
* **Bitwise Operations:** Using XOR (^) for reversible encryption.
* **File I/O:** Reading/Writing raw binary streams in C.
* **Cryptanalysis:** Breaking encryption by analyzing byte frequency (detecting the most common character).

## Usage
1. Compile the Cipher: `gcc cipher.c -o cipher`
2. Encrypt a file: `cipher plain.txt hidden.bin`
3. Compile the Breaker: `gcc breaker.c -o breaker`
4. Crack the code: `breaker hidden.bin`

## Disclaimer
The XOR cipher (unless used as a One-Time Pad with a truly random key equal to the message length) is not cryptographically secure against modern attacks. This tool is intended for educational purposes or simple obfuscation, not for securing sensitive data.