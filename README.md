<p align="center">
  <img src="https://i.ibb.co/XXzrs4z/ttlogo2.png" />
</p>
  
# Type Tester
  
Type Tester is a Cinder application to practice typing and record your WPM score.

## Dependencies

 - [cinder](https://libcinder.org/)
 - [cmake](https://cmake.org/)
 - [gcc](https://gcc.gnu.org/) / [clang](https://clang.llvm.org/) / [vscode](https://www.visualstudio.com/)
 - The game also uses, by default, fonts [Futura](https://fonts.adobe.com/fonts/futura-pt) and [Sequel 100 Black](https://www.myfonts.com/fonts/ogj-typedesign/sequel-100-black/).

## Get started

```console
$ mkdir build
$ cd build/
$ cmake ..
$ make
$ ./typer-app
```

Press ``enter`` to start the game and to refresh the prompt. Start typing to track your WPM!

## Customization
You can supply custom prompts to be randomly chosen from in ``prompts.txt``.

Simply follow the formatting of the existing prompts by adding yours on a new line, followed by two dashes (`--`) on a new line.
