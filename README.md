# printf-42
### conversions to recreate

Name  | Status
------------- | -------------
%c Prints a single character     |  ✅ 
%s Prints a string   |  ✅ 
%p The void * pointer argument |
%d Prints a decimal (base 10) number|
%i Prints an integer in base 10| 
%u Prints an unsigned decimal (base 10) number| 
%x Prints a number in hexadecimal (base 16) lowercase format| 
%X Prints a number in hexadecimal (base 16) uppercase format |
%% Prints a percent sign |  ✅ 
 
recreation of printf function

### Why Variadic Functions are Used
*Ordinary C functions take a fixed number of arguments.* When you define a function, you specify the data type for each argument. Every call to the function should supply the expected number of arguments, with types that can be converted to the specified ones. Thus, if the function ‘foo’ is declared with `int foo (int, char *);` then you must call it with two arguments, a number (any kind will do) and a string pointer.

*But some functions perform operations that can meaningfully accept an unlimited number of arguments.* <br/>
<br />
**Variadic functions are functions that can take a variable number of arguments.** <br />
In C programming, a variadic function adds flexibility to the program. It takes one fixed argument and then any number of arguments can be passed. The variadic function consists of at least one fixed variable and then an ellipsis(…) as the last parameter.

##### Syntax:

`int function_name(data_type variable_name, ...);` <br />
Values of the passed arguments can be accessed through the header file named as:

``` c
#include <stdarg.h>
``` 


#### It includes the following methods: 

| **Methods**  | **Description** |
| ------------- |:-------------:|
| va_start(va_list ap, argN)    | This enables access to variadic function arguments. where *va_list* will be the pointer to the last fixed argument |
| va_arg(va_list ap, type)    | This one accesses the next variadic function argument.|
| va_copy(va_list dest, va_list src)      | This makes a copy of the variadic function arguments.|
| va_end(va_list ap)	     | This ends the traversal of the variadic function arguments.     |
#### GNU version of `printf`
``` c
__printf (const char *format, ...)
{
   va_list arg;
   int done;

   va_start (arg, format);
   done = vfprintf (stdout, format, arg);
   va_end (arg);

   return done;
}
```
