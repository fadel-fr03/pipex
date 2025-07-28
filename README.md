# pipex

![Language](https://img.shields.io/badge/language-C-blue)
![Status](https://img.shields.io/badge/build-passing-brightgreen)

`pipex` is a 42 school project that replicates shell piping behavior (`< file cmd1 | cmd2 > file`) by manually handling UNIX system calls like `fork()`, `pipe()`, `dup2()`, and `execve()`. It also features a bonus version that supports multiple pipes and a `here_doc` mode.

---

## 📌 Table of Contents

* [About](#about)
* [Features](#features)
* [Project Structure](#project-structure)
* [How It Works](#how-it-works)
* [How to Compile](#how-to-compile)
* [Usage Examples](#usage-examples)
* [Bonus Part](#bonus-part)
* [Code Snippets](#code-snippets)
* [Learnings](#learnings)
* [License](#license)

---

## 📖 About

The goal of this project is to:

* Understand how UNIX pipelines work internally.
* Practice working with `fork()`, `execve()`, `pipe()`, and file descriptors.
* Reinforce understanding of argument parsing, error handling, and memory management in C.

The program emulates the following shell behavior:

```bash
< infile cmd1 | cmd2 > outfile
```

---

## ✨ Features

### Mandatory:

* Execution of two commands in a pipeline.
* File redirection using `infile` and `outfile`.
* Proper error management.
* Usage of `execve()` for command execution.
* Manual splitting of PATH and resolution of executables.

### Bonus:

* Support for **unlimited commands** (multi-pipe chains).
* Support for **here\_doc** (similar to shell heredoc).
* Built-in custom implementation of `ft_split`, `ft_strlen`, and others from `libft`.

---

## 📁 Project Structure

```bash
.
├── inc/pipex.h                    # Header for core functionality
├── inc_bonus/pipex_bonus.h        # Header for bonus features
├── libft/                         # Custom standard C library
│   ├── inc/libft.h
│   └── src/*.c                    # Reimplementation of common C functions
├── src/
│   ├── pipex.c                    # Entry point for mandatory pipex
│   ├── exec_utils.c               # Path resolving, command exec helpers
│   ├── utils.c                    # Error handlers, string tools
├── src_bonus/
│   ├── pipex_bonus.c              # Entry point for bonus pipex
│   ├── exec_utils.c               # Bonus exec helpers
│   ├── utils_bonus.c              # Bonus utility helpers
│   ├── handle_errors.c            # Custom error management
│   └── here_doc.c                 # Implementation of heredoc behavior
```

---

## ⚙️ How It Works

* Input file is opened and its `fd` is used as the `stdin` for the first command.
* Pipe is created using `pipe()` to connect each command in the chain.
* `fork()` is used to spawn a process per command.
* File descriptors are duplicated with `dup2()` to set up correct input/output redirections.
* Executable path is resolved using `PATH` environment variable.
* Final output is written to the `outfile`.

---

## 🧪 How to Compile

### Mandatory:

```bash
make
./pipex infile "cmd1" "cmd2" outfile
```

### Bonus:

```bash
make bonus
./pipex infile "cmd1" "cmd2" ... "cmdn" outfile
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

---

## 🔍 Usage Examples

### Mandatory:

```bash
./pipex infile "grep hello" "wc -l" outfile
```

This behaves like:

```bash
grep hello < infile | wc -l > outfile
```

### Bonus:

```bash
./pipex_bonus infile "ls -l" "grep pipex" "wc -l" outfile
```

Executes:

```bash
ls -l < infile | grep pipex | wc -l > outfile
```

With heredoc:

```bash
./pipex_bonus here_doc EOF "cat" "wc -l" outfile
```

Then input:

```bash
line 1
line 2
EOF
```

Acts like:

```bash
cat << EOF | wc -l > outfile
line 1
line 2
EOF
```

---

## 🚀 Bonus Part

The bonus version introduces support for:

* **Here Document**: Emulates shell's heredoc input from terminal.
* **Multiple Pipes**: Automatically builds pipelines dynamically based on number of commands.

It reads input from stdin until it finds the `LIMITER` string and feeds it as input to the pipeline.

---

## 👀 Code Snippets

### Command Execution Logic

```c
void execute_cmd(char *cmd, char **envp)
{
    char **args = ft_split(cmd, ' ');
    char *path = find_cmd_path(args[0], envp);
    if (!path)
        exit_with_error("command not found");
    execve(path, args, envp);
}
```

### Setting up a pipe chain

```c
pipe(fd);
if (fork() == 0)
{
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    execute_cmd(cmd1, envp);
}
else
{
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    execute_cmd(cmd2, envp);
}
```

---

## 📚 Learnings

* Mastery of file descriptors, piping, and redirection.
* Familiarity with process creation and management using `fork()` and `wait()`.
* Understanding how `execve()` interacts with `PATH` and arguments.
* Parsing arguments safely, handling edge cases and heredoc limitations.
* Improving C project structure: separation of logic, error handling, and utilities.

---

## 📄 License

This project is part of the 42 School curriculum and is meant for educational use.

---

## 💬 Questions?

Feel free to fork, clone, or contact me for questions, improvements, or suggestions!
