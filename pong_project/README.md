## Linux
## Linux users need to install the following packages:

`sudo apt-get install libsdl2-dev`

`sudo apt-get install libsdl2-ttf-dev`

`sudo apt-get install libsdl2-mixer-dev`

**Compile on Linux by:**

**Ensuring you are in the root directory of the project**

`mkdir build && cd build`

`cmake ..`

`make`

To run the game after compiling, run the following command:

`./pong`



## MacOS

## MacOS users need to install the following packages:

`brew install sdl2`

`brew install sdl2_ttf`

`brew install sdl2_mixer`

**You also need to install the packages from the sdl website, and copy them to /Library/Frameworks, because the ones in opt/homebrew work with the includes, but you still need to link to the frameworks.**

**View the deprecated Makefile for more information on MacOS compiling.**

**Compile on MacOS by:**

**Ensuring you are in the root directory of the project**

`mkdir build && cd build`

`cmake ..`

`make`

**To run the game after compiling, run the following command:**

`./pong`
