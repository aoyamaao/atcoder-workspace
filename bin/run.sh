#!/bin/zsh

CPP_STANDARD="c++20"
INPUT_FILE="input.txt"

DEBUG_MODE=0
TIME_MODE=0

while [[ "$1" =~ ^- ]]; do
  case "$1" in
    -d)
      DEBUG_MODE=1
      shift
      ;;
    -s)
      TIME_MODE=1
      shift
      ;;
    *)
      echo "Unknown option: $1"
      exit 1
      ;;
  esac
done

if [ $# -eq 0 ]; then
  echo "Usage: $(basename "$0") [-d] [-s] <source_file.cpp>"
  exit 1
fi
SOURCE_FILE=$1

if [ ! -f "$SOURCE_FILE" ]; then
  echo "Error: Source file '$SOURCE_FILE' not found."
  exit 1
fi

PROJECT_ROOT=$(git rev-parse --show-toplevel 2>/dev/null)
if [ $? -ne 0 ]; then
  echo "Error: Not a git repository."
  PROJECT_ROOT="."
fi

EXECUTABLE_NAME=$(basename "$SOURCE_FILE" .cpp)

if [ "$DEBUG_MODE" -eq 1 ]; then
  printf "%-12s: %s (version: %s) -> %s\n" "Compiling" "$SOURCE_FILE" "$CPP_STANDARD" "$EXECUTABLE_NAME"
fi

COMPILE_ERROR=$(clang++ "$SOURCE_FILE" -std="$CPP_STANDARD" -I"$PROJECT_ROOT" -o "$EXECUTABLE_NAME" 2>&1)
if [ $? -ne 0 ]; then
  echo "--- Compile Failed ---"
  echo "$COMPILE_ERROR"
  exit 1
fi


zmodload zsh/datetime

# 実行前の時間を記録
start_time=$EPOCHREALTIME

# デバッグモードが有効な場合のみ実行ログを出力
if [ "$DEBUG_MODE" -eq 1 ]; then
  printf "%-12s: %s with %s\n" "Running" "$EXECUTABLE_NAME" "$INPUT_FILE"
  printf "%-12s: " "Execution"
fi

# 実行
./"$EXECUTABLE_NAME" < "$INPUT_FILE"

# 実行後の時間を記録
end_time=$EPOCHREALTIME


# 実行可能ファイルを削除
rm "$EXECUTABLE_NAME"
if [ "$DEBUG_MODE" -eq 1 ]; then
  printf "%-12s: %s\n" "Cleaned up" "$EXECUTABLE_NAME"
fi

# 時間計測モードが有効な場合のみ実行時間を表示
if [ "$TIME_MODE" -eq 1 ]; then
  duration=$(($end_time - $start_time))
  duration_ms=$(($duration * 1000))
  printf "%.0fms\n" $duration_ms
fi
