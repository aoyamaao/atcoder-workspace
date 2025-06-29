#!/bin/zsh

CPP_STANDARD="c++20"
INPUT_FILE="input.txt"

DEBUG_MODE=0
# 最初の引数が -d であればデバッグモードを有効にする
if [ "$1" = "-d" ]; then
  DEBUG_MODE=1
  shift
fi

if [ $# -eq 0 ]; then
  echo "Usage: $(basename "$0") [-d] <source_file.cpp>"
  exit 1
fi
SOURCE_FILE=$1

if [ ! -f "$SOURCE_FILE" ]; then
  echo "Error: Source file '$SOURCE_FILE' not found in the current directory."
  exit 1
fi

# パスの解決
PROJECT_ROOT=$(git rev-parse --show-toplevel 2>/dev/null)
if [ $? -ne 0 ]; then
  echo "Error: Not a git repository. Assuming current directory is project root for -I flag."
  PROJECT_ROOT="."
fi

EXECUTABLE_NAME=$(basename "$SOURCE_FILE" .cpp)


# コンパイルを実行し、失敗した場合はエラーメッセージを表示して終了
COMPILE_ERROR=$(clang++ "$SOURCE_FILE" -std="$CPP_STANDARD" -I"$PROJECT_ROOT" -o "$EXECUTABLE_NAME" 2>&1)
if [ $? -ne 0 ]; then
  echo "--- Compile Failed ---"
  echo "$COMPILE_ERROR"
  exit 1
fi

# デバッグモードが有効な場合のみ、詳細ログを出力
if [ "$DEBUG_MODE" -eq 1 ]; then
  printf "%-12s: %s (version: %s) -> %s\n" "Compiling" "$SOURCE_FILE" "$CPP_STANDARD" "$EXECUTABLE_NAME"
  printf "%-12s: %s with %s\n" "Running" "$EXECUTABLE_NAME" "$INPUT_FILE"
  printf "%-12s: " "Execution"
fi

# 後片付け
./"$EXECUTABLE_NAME" < "$INPUT_FILE"
rm "$EXECUTABLE_NAME"

# デバッグモードの最後のログ
if [ "$DEBUG_MODE" -eq 1 ]; then
  printf "%-12s: %s\n" "Cleaned up" "$EXECUTABLE_NAME"
fi
