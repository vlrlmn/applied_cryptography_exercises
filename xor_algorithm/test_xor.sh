#!/bin/bash

KEY="mykey"
INPUT_FILE="input.txt"
ENCRYPT_FILE="output.enc"
DECRYPT_FILE="decrypted.txt"
EXEC="./xor_encryption"

echo "1) Compiling..."

make

if [ $? -ne 0 ]; then
    echo "Error compiling..."
    exit 1
fi

echo "2) Creating input file..."
echo "Hello, secret world!" > "$INPUT_FILE"

echo "4) Encryption..."
$EXEC "$KEY" "$INPUT_FILE" "$ENCRYPT_FILE"

echo "5) Decryption..."
$EXEC "$KEY" "$ENCRYPT_FILE" "$DECRYPT_FILE" 

echo -e "\n~~~~~~~~Result~~~~~~~~~"
cat "$DECRYPT_FILE"