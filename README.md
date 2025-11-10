## Libft Tester
> This repository contains a set of custom unit tests designed to verify the correct behavior of functions in the libft project.  
The goal is to help ensure compliance and robustness of each function. Since it's made in two days, don't blindly trust it.

---

## Installation

Clone this repository inside your `libft` folder

```bash
git clone https://github.com/leonardecavele/libft-tester
```

---

## Commands

**Run the following command to compile all tests**
```bash
make
```

**Test only the mandatory part**
```bash
make m
```

**Test only the bonus part**
```bash
make b
```

**Run a specific test**
```bash
make ft_{function name}.test
# example: make ft_strlen.test
```

**Try to make your libft relink**
```bash
make r
```

**Try to make your libft relink with bonuses**
```bash
make rb
```

**Check missing and extra files of your libft excluding bonuses**
```bash
make check
```

**Check missing and extra files of your libft including bonuses**
```bash
make checkb
```

**Check the norm of your libft**
```bash
make n
```

**Rebuild the libft**
```bash
make libft.a
```

**Clean the tests files in bin directory**
```bash
make clean
```

**Clean the tests files in bin directory and delete libft.a**
```bash
make fclean
```
