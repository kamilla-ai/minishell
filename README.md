101/100
# Minishell

Minishell is a simple, custom shell implementation project designed to mimic the behavior of a UNIX shell. It provides fundamental features like executing commands, handling environment variables, and managing input/output redirections. This project is typically part of a curriculum to learn system programming, process management, and parsing in a UNIX-like environment.

## Features

Minishell includes the following features:

1. **Interactive Prompt**: Displays a prompt where users can input commands.
2. **Command Execution**: Supports executing commands from the system PATH and built-in shell commands.
3. **Built-in Commands**:
    - `echo` with options like `-n`.
    - `cd` to change the current working directory.
    - `pwd` to print the current working directory.
    - `export` to set environment variables.
    - `unset` to remove environment variables.
    - `env` to display the environment.
    - `exit` to terminate the shell.
4. **Environment Variables**: Handles the `$` symbol for variable expansion.
5. **Redirections**: Supports input (`<`), output (`>`), and append (`>>`) redirections.
6. **Pipes**: Allows chaining commands using `|`.
7. **Signal Handling**: Gracefully handles signals like `Ctrl+C`, `Ctrl+Z`, and `Ctrl+\`.
8. **Error Management**: Displays appropriate error messages for invalid commands or syntax.
9. **Path Resolution**: Resolves executable commands using the system PATH.

## Installation

To build and run Minishell, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/kamilla-ai/minishell.git
   cd minishell
   ```

2. Build the project:
   ```bash
   make
   ```

3. Run Minishell:
   ```bash
   ./minishell
   ```

## Usage

1. Start the shell:
   ```bash
   ./minishell
   ```

2. Type commands like you would in a normal shell:
   ```bash
   echo "Hello, world!"
   pwd
   ls | grep minishell
   export VAR=test
   echo $VAR
   ```

3. Exit the shell:
   ```bash
   exit
   ```

## Directory Structure

```plaintext
minishell/
├── src/                # Source files for the project
├── includes/           # Header files
├── Makefile            # Build script
└── README.md           # Project documentation
```

## Requirements

Minishell has been implemented and tested on the following:
- macOS/Linux
- GCC/Clang compiler

It assumes familiarity with:
- Process management (`fork`, `exec`, `wait`)
- File descriptors and redirection
- UNIX signals
- Dynamic memory management

## Examples

### Basic Commands
```bash
> echo "Minishell is awesome!"
Minishell is awesome!
> pwd
/home/user/minishell
```

### Pipes and Redirections
```bash
> ls | grep minishell > output.txt
> cat output.txt
minishell.c
minishell.h
```

### Environment Variables
```bash
> export NAME=Minishell
> echo $NAME
Minishell
> unset NAME
> echo $NAME

```
