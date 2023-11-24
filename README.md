# dbg.h - Debug macros for C and C++

Defines macros useful for quick printf debugging. Useful if you do not like to write `printf("value: %d\n", value);` everytime you want to debug a variable. Instead

```
DBG(value);
```

will neatly output

```
value: 7
```

without the user having to worry about what type `value` is and about writing long lines just to debug. For C, the macro uses C11's `_Generic` feature to determine the variables type and `printf` for printing; for C++, it uses `std::cout`.

The macros `HERE()` to print the line "here" and `MSG(x)` to print a line containing `x` are also defined.

The macros can also be shortened to their first letter, respectively.
